#include <stdio.h>
#include <stdlib.h>

/*============================= ESTRUCTURAS =============================*/
typedef struct
{
	char user[100];
	char pass[100];
}Usuario;

typedef struct
{
	char rut[10];
	char nombre_cocinero[100];
}Cocinero;

typedef struct
{
	int id_consumidor;
	char rut[10];
	char nombre[100];
	char telefono[10];
}Consumidor;

typedef struct
{
	int id_venta;
	int id_consumidor;
	int id_plato;
	int cantidad;
	char fecha[10];
	char hora[5];
}Plato_vendido;

typedef struct
{
	int id_ingrediente;
	int stock;
	int costo;
	char nombre_ingrediente[100];
}Ingredientes;

typedef struct
{
	int id_plato;
	char rut_cocinero[10];
	int costo_preparar;
	int precio_venta;
	int cant_ingredientes;
	char nombre[100];
}Plato;

typedef struct
{
	int id_ingrediente;
	int cantidad;
}Plato_ingredientes;
/*=======================================================================*/

/*================ PROTOTIPOS ================*/
void add_cook_bd(Cocinero *chef);
void add_client_bd(Consumidor *cliente);
void add_ing_bd(Ingredientes *ing);
void add_plato_bd(Plato *platillo, Plato_ingredientes *plato_ing);
void read_cook_bd();
void read_client_bd();
void read_ing_bd();
void read_plato_bd();
void print_rut(char *rut);
char* check_admin_file(char user[100]);
int check_admin();
int check_cook(char *user);
void new_cook_file();
char letra_M(char sup);
int str_compare(char *strg1,char *strg2);
int id_valida(char *archivo);
int id_valida_consumidor(char *archivo);
int id_valida_plato(char *archivo);
/*============================================*/

/*============================= FUNCIONES DE ESCRITURA =============================*/
/*=========== COCINERO ===========*/
void add_cook_bd(Cocinero *chef)
{
	int i = 0, mod;
	char modulo[3];
	Cocinero *cheftmp = malloc(sizeof(Cocinero));
	FILE *arch, *archtmp;
	
	while(chef->rut[i]!='-')
		i++;
	
	modulo[0]=chef->rut[i-2];
	modulo[1]=chef->rut[i-1];
	modulo[2]='\0';
	mod = atoi(modulo);
	
	if(!(arch = fopen("cocinero.ari", "rb")))
	{
		new_cook_file();
		arch = fopen("cocinero.ari", "rb");
	}
	/* ================== INSERCCION DE DATOS ==================*/
	archtmp = fopen("temp.ari", "wb");
	for( i=0 ; i<mod ; i++ )
	{
		fread  (cheftmp, sizeof(Cocinero), 1, arch);
		fwrite (cheftmp, sizeof(Cocinero), 1, archtmp);
	}
	
	fread  (cheftmp, sizeof(Cocinero), 1, arch);
	fwrite (chef, sizeof(Cocinero), 1, archtmp);
	
	for ( i=mod+1 ; i<100 ; i++ )
	{
		fread  (cheftmp, sizeof(Cocinero), 1, arch);
		fwrite (cheftmp, sizeof(Cocinero), 1, archtmp);
	}
	/* =========================================================*/
	
fclose(arch);
fclose(archtmp);
free(cheftmp);
remove("cocinero.ari");
rename("temp.ari","cocinero.ari"); 
}
/*================================*/

/*========== CONSUMIDOR ==========*/
void add_client_bd(Consumidor *cliente)
{
	Consumidor *clientetmp = malloc(sizeof(Consumidor));
	FILE *arch, *archtmp;
	
	if(!(arch = fopen("consumidor.ari", "rb")))
	{
		arch = fopen("consumidor.ari", "wb");
		fwrite (cliente, sizeof(Consumidor), 1, arch);
		fclose(arch);
	}
	else
	{
		archtmp = fopen("temp.ari", "wb");
		while(fread  (clientetmp, sizeof(Consumidor), 1, arch) )
		{
			fwrite (clientetmp, sizeof(Consumidor), 1, archtmp);
		}
		fwrite (cliente, sizeof(Consumidor), 1, archtmp);
		
		fclose(arch);
		fclose(archtmp);
		remove("consumidor.ari");
		rename("temp.ari","consumidor.ari"); 
	}
	
free(clientetmp);
}
/*================================*/

/*========= INGREDIENTES =========*/
void add_ing_bd(Ingredientes *ing)
{
	int comp;
	Ingredientes *ingtmp = malloc(sizeof(Ingredientes));
	FILE *arch, *archtmp;

	if(!(arch = fopen("ingredientes.ari", "rb")))
	{
		arch = fopen("ingredientes.ari", "wb");
		fwrite (ing, sizeof(Ingredientes), 1, arch);
		fclose (arch);
	}
		
	else
	{
		comp = 0;
		archtmp = fopen("temp.ari", "wb");
		while(1)
		{
			fread (ingtmp, sizeof(Ingredientes), 1, arch);
			comp = str_compare (ing->nombre_ingrediente, ingtmp->nombre_ingrediente);
			
			if( feof(arch) )
				{
					fwrite (ing, sizeof(Ingredientes), 1, archtmp);
					break;
				}
			else
			{
				if( comp == 1 )
					fwrite (ingtmp, sizeof(Ingredientes), 1, archtmp);
				
				if( comp == 2 )
				{
					fwrite (ing, sizeof(Ingredientes), 1, archtmp);
					fwrite (ingtmp, sizeof(Ingredientes), 1, archtmp);
					fread  (ingtmp, sizeof(Ingredientes), 1, arch);
					break;
				}
				
				if( comp == 0 )
				{
					ingtmp->stock = ingtmp->stock + ing->stock;
					ingtmp->costo = ing->costo;
					fwrite (ingtmp, sizeof(Ingredientes), 1, archtmp);
					fread  (ingtmp, sizeof(Ingredientes), 1, arch);
					break;	
				}
			}
		}
		
		while( !feof(arch) )
		{
			fwrite (ingtmp, sizeof(Ingredientes), 1, archtmp);
			fread (ingtmp, sizeof(Ingredientes), 1, arch);
		}

		fclose(archtmp);
		fclose(arch);
		remove("ingredientes.ari");
		rename("temp.ari", "ingredientes.ari"); 
	}
free(ingtmp);
}
/*================================*/

/*========================= PLATO ==========================*/
void add_plato_bd(Plato *platillo,Plato_ingredientes *plato_ing)
{
	FILE *arch,*archtmp;
	Plato platillo_tmp;
	Plato_ingredientes plato_ing_tmp;
	int i;
	
	if((arch = fopen("platos.ari", "rb"))==NULL)
	{
		arch = fopen("platos.ari", "wb");
		
		fwrite ( platillo , sizeof(Plato), 1 ,arch );
		for( i=0 ; i<platillo->cant_ingredientes ; i++ )
		{
			fwrite(&plato_ing[i], sizeof(Plato_ingredientes), 1, arch);
		}
		fclose(arch);
	}
	else
	{
		archtmp = fopen("temp.ari", "wb");
		
		while(fread (&platillo_tmp, sizeof(Plato), 1, arch))
		{
			fwrite (&platillo_tmp, sizeof(Plato), 1, archtmp );		
		
			for( i=0 ; i<platillo_tmp.cant_ingredientes ; i++ )
			{
				fread (&plato_ing_tmp, sizeof(Plato_ingredientes), 1, arch);
				fwrite (&plato_ing_tmp, sizeof(Plato_ingredientes), 1, archtmp);
			}
		}	
		
		fwrite (platillo, sizeof(Plato), 1, archtmp);
		
		for( i=0 ; i<platillo->cant_ingredientes ; i++)
		{
			fwrite( &plato_ing[i] ,sizeof(Plato_ingredientes), 1, archtmp );
		}

		fclose(archtmp);
		fclose(arch);
		remove("platos.ari");
		rename("temp.ari", "platos.ari");
	}

}
/*==========================================================*/
/*==================================================================================*/



/*============================= FUNCIONES DE LECTURA =============================*/
/*=========== COCINERO ===========*/
void read_cook_bd()
{
	int i = 1, j;
	Cocinero *chef = malloc(sizeof(Cocinero));
	FILE *arch;
	
	if((arch = fopen("cocinero.ari", "rb")) != NULL)
	{	
		while(fread (chef, sizeof(Cocinero), 1, arch))
		{
			j = 0;
			printf ("\n[%d] RUT:\t",i);
			print_rut(chef->rut);
			printf ("\n    NOMBRE:\t%s\n", chef->nombre_cocinero);
			i++;
		}
		fclose(arch);
	}
	else
		printf ("\nNO HAY COINEROS REGISTRADOS");
		
free(chef);
}
/*================================*/

/*========== CONSUMIDOR ==========*/
void read_client_bd()
{
	int i = 1;
	Consumidor *cliente = malloc(sizeof(Consumidor));
	FILE *arch;
	
	if((arch = fopen("consumidor.ari", "rb")) != NULL)
	{	
		while(fread (cliente, sizeof(Consumidor), 1, arch))
		{
			printf ("[%d] ID-ASIGNADO:\t%d\n    RUT:\t\t", i, cliente->id_consumidor);
			print_rut(cliente->rut);
			printf("\n    NOMBRE:\t\t%s\n    TELEFONO:\t\t%s\n\n", cliente->nombre, cliente->telefono );
			i++;
		}
		fclose(arch);
	}
	else
		printf ("\nNO HAY CLIENTES REGISTRADOS");

		
free(cliente);
}
/*================================*/

/*========= INGREDIENTES =========*/
void read_ing_bd()
{
	int i = 1;
	Ingredientes *ing = malloc(sizeof(Ingredientes));
	FILE *arch;
	
	if((arch = fopen("ingredientes.ari", "rb")) != NULL)
	{		
		while(fread (ing, sizeof(Ingredientes), 1, arch))
		{
			printf ("\n[%d] ID-ASIGNADO:\t%d\n    STOCK:\t\t%d\n    COSTO:\t\t%d\n    NOMBRE:\t\t%s\n\n", i, ing->id_ingrediente, ing->stock, ing->costo, ing->nombre_ingrediente);
			i++;
		}
		fclose(arch);
	}
	else
		printf ("\nNO HAY INGREDIENTES REGISTRADOS");

free(ing);
}
/*================================*/

/*=========== PLATILLOS ==========*/
void read_plato_bd()
{
	int j,i = 1;
	Plato *platillo = malloc(sizeof(Plato));
	Plato_ingredientes plato_ing_tmp;
	FILE *arch;
		
	if((arch = fopen("platos.ari", "rb")) != NULL)
	{
		while(fread (platillo, sizeof(Plato), 1, arch))
		{
			
			printf ("\n[%d] ID-ASIGNADO:\t\t%d\n    RUT COCINERO:\t\t%s\n    COSTO DE PREPARACION:\t%d\n    PRECIO DE VENTA:\t\t%d\n    CANTIDAD DE INGREDIENTES:\t%d\n    NOMBRE:\t\t\t%s\n\n", i, platillo->id_plato, platillo->rut_cocinero, platillo->costo_preparar, platillo->precio_venta, platillo->cant_ingredientes, platillo->nombre);
			i++;
			for( j=0 ; j<platillo->cant_ingredientes ; j++ )
			{
				fread ( &plato_ing_tmp , sizeof(Plato_ingredientes) , 1 , arch);
				printf("\tID INGREDIENTE %d: %d\n",j,plato_ing_tmp.id_ingrediente);
			}
		}
		fclose(arch);
	}
	else
		printf ("\nNO HAY COINEROS REGISTRADOS");
		
free(platillo);
}
/*================================*/
/*================================================================================*/


/*======================= CONVERSORES Y VARIOS =============================*/
/*================ RUT ================*/
void print_rut(char *rut)
{
	int i = 0;
	
	while( rut[i]!='-' )
	{
		printf("%c", rut[i]);
		i++;
	}
	printf("%c", rut[i]);
	printf("%c", rut[i+1]);
}
/*=====================================*/

/*========== REGISTRO ADMIN INICIAL ===========*/
char* check_admin_file(char user[100])
{
	Usuario us;
	FILE *arch;

	if(!(arch = fopen("admin.pwd", "rb")))
	{
		arch = fopen("admin.pwd", "wb");
		printf ("\nPRIMER INICIO DE SESION - REGISTRE EL NUEVO ADMINISTRADOR\n");
		printf ("\nUSER: ");
		scanf  ("%s", us.user);
		printf ("PASS: ");
		scanf  ("%s", us.pass);
		fwrite (&us, sizeof(Usuario), 1, arch);
		strcpy(user, us.user);
		
		fclose (arch);
		return user;
	}
	
	fread (&us, sizeof(Usuario), 1, arch);
	strcpy(user, us.user);
	
	fclose (arch);
	return user;
}
/*=============================================*/

/*============== REVISA EL LOGIN ==============*/
int check_admin()
{
	Usuario us;
	char *usertmp = (char *)malloc(sizeof(100));
	char *passtmp = (char *)malloc(sizeof(100));	
	FILE *arch;

	arch = fopen("admin.pwd", "rb");

	fread (&us, sizeof(Usuario), 1, arch);

	system ("clear");
	printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nADMINISTRADOR\n");
	printf ("\n============================================================\n");
	printf ("SISTEMA DE LOGUEO");
	printf ("\n------------------------------------------------------------\n");
	printf ("\nUSER: ");
	scanf  ("%s", usertmp);
	printf ("PASS: ");
	scanf  ("%s", passtmp);
	
	if (strcmp(us.user, usertmp) == 0 && strcmp(us.pass, passtmp) == 0)
	{
		free(usertmp);
		free(passtmp);
		fclose (arch);
		return 1;	
	}
	
	free(usertmp);
	free(passtmp);
	fclose (arch);
	return 0;
}
/*=============================================*/

/*============== REVISA EL LOGIN ==============*/
int check_cook(char *user)
{
	int i = 0;
	Usuario us;
	Cocinero cook;
	char tmp[100];
	
	FILE *arch;

	arch = fopen("cocinero.ari", "rb");

	system ("clear");
	printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nCOCINERO\n");
	printf ("\n============================================================\n");
	printf ("SISTEMA DE LOGUEO");
	printf ("\n------------------------------------------------------------\n");
	printf ("\nUSER: ");
	scanf  ("%s", us.user);
	
	while (!feof(arch))
	{
		fread (&cook, sizeof(Cocinero), 1, arch);
		strcpy (tmp, cook.rut);
		while(tmp[i] != '-')
			i++;
		tmp[i+2] = '\0';
		if (strcmp(tmp, us.user) == 0)
		{
			strcpy (user, tmp);
			fclose (arch);
			return 1;
		}
	}	
	fclose (arch);
	return 0;
}
/*=============================================*/

/*================ ARCHIVO COCINERO VACIO ================*/
void new_cook_file()
{
	int i;
	Cocinero *chef = malloc(sizeof(Cocinero));
	FILE *arch;
	
	strcpy (chef->rut, "xxxxxxxx-x");
	strcpy (chef->nombre_cocinero, "No Registrado");
	arch = fopen("cocinero.ari", "wb+");
	for( i=0 ; i<100 ; i++ )
	{
		fwrite (chef, sizeof(Cocinero), 1, arch);
	}
	free(chef);
	fclose(arch);
}
/*========================================================*/

/*========= CONVERSION DE MINUSCULA A MAYUSCULA ==========*/
char letra_M(char sup)
{
	int ascii;
	ascii = (int)sup;
	if (ascii >=  97)
		ascii = ascii - 32;
	sup = (char)ascii;
	return sup;
}
/*========================================================*/

/*=================== COMPARA STRINGS ====================*/
int str_compare(char *strg1,char *strg2) 
{
	int i = 0;
    
	while( strg1[i]!='\0' )
    {
		if( strg1[i]!='\0' )
			strg1[i] = letra_M(strg1[i]);
		i++;
	}
	
	i = 0;
	while( strg2[i]!='\0' )
    {
		if( strg2[i]!='\0' )
			strg2[i] = letra_M(strg2[i]);
		i++;
	}
	
	if( strcmp( strg1, strg2 ) != 0 )
	{
		if( strcmp( strg1, strg2 ) > 0 )
			return(1); /* strg1>strg2 */
		else
			return(2);
	}else
		return(0);
}
/*========================================================*/

/*=========== ASIGNACION DE ID VALIDA PLATO (ID SIN USO) ===========*/
int id_valida(char *archivo)
{
	int i = 0, j = 0;
	FILE *arch;
	Ingredientes *tmp = malloc(sizeof(Ingredientes));
	
	if((arch = fopen(archivo, "rb")) != NULL)
	{	
		while(1)
		{
			rewind (arch);
			while( !feof(arch) )
			{
				fread(tmp, sizeof(Ingredientes), 1, arch);
				if( tmp->id_ingrediente == i )
				{
					i++;
					break;
				}
			}
			if(i==j)
				break;
			j++;
		}
		rewind(arch);
		fclose(arch);
	}

free(tmp);
return(i);
}
/*============================================================*/

/*=========== ASIGNACION DE ID VALIDA COSUMIDOR (ID SIN USO) ===========*/
int id_valida_consumidor(char *archivo)
{
	int i = 0, j = 0;
	FILE *arch;
	Consumidor *tmp = malloc(sizeof(Consumidor));
	
	if((arch = fopen(archivo, "rb")) != NULL)
	{	
		while(1)
		{
			rewind (arch);
			while( !feof(arch) )
			{
				fread(tmp, sizeof(Consumidor), 1, arch);
				if( tmp->id_consumidor == i )
				{
					i++;
					break;
				}
			}
			if(i==j)
				break;
			j++;
		}
		rewind(arch);
		fclose(arch);
	}

free(tmp);
return(i);
}
/*============================================================*/

/*=========== ASIGNACION DE ID VALIDA PLATO (ID SIN USO) =============*/
int id_valida_plato(char *archivo)
{
	int i = 0, j = 0,k;
	FILE *arch;
	Plato *platillo = malloc(sizeof(Plato));
	Plato_ingredientes plato_ing_tmp;
	
	if((arch = fopen(archivo, "rb")) != NULL)
	{	
		while(1)
		{
			rewind (arch);
			while(fread (platillo, sizeof(Plato), 1, arch))
			{
				
				if( platillo->id_plato == i )
				{
					i++;
					break;
				}
				for( k=0 ; k<platillo->cant_ingredientes ; k++ )
				{
					fread ( &plato_ing_tmp, sizeof(Plato_ingredientes), 1, arch);	
				}
			}
			if(i==j)
				break;
			j++;
		}
		rewind(arch);
		fclose(arch);
	}

free(platillo);
return(i);
}
/*====================================================================*/
/*==========================================================================*/
