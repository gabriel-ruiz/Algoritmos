#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivos.c"

/*================ PROTOTIPOS ================*/
void add_cocinero(char *user);
void view_cocinero(char *user);
void add_consumidor(char *user);
void view_consumidor(char *user);
void add_ingredientes(char *user);
void view_ingredientes(char *user);
void add_platillo(char *user);
void view_platillo(char *user);
/*============================================*/

/*=================== OPCIONES ADMINISTRADOR -> COCINERO ===================*/
void view_cocinero(char *user)
{
	int opc;
	char opchar[100];
	
	system ("clear");
	printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nADMINISTRADOR\nUSER: %s", user);
	printf ("\n============================================================\n");
	printf ("LISTA DE COCINEROS");
	printf ("\n------------------------------------------------------------\n");
	
	read_cook_bd();
	
	printf ("\n============================================================\n");
	printf ("Cualquier Tecla + <ENTER>: ");
	scanf  ("%s", opchar);
	opc = atoi (opchar);
}

void add_cocinero(char *user)
{
	char conf;
	Cocinero *chef = malloc(sizeof(Cocinero));
	
	system ("clear");
	printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nADMINISTRADOR\nUSER: %s", user);
	printf ("\n============================================================\n");
	printf ("INGRESAR NUEVO COCINERO");
	printf ("\n------------------------------------------------------------\n");
	printf ("RUT: ");			scanf ("%s", chef->rut);
	printf ("NOMBRE: ");		scanf ("%s", chef->nombre_cocinero);

	do{			
		system ("clear");
		printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nADMINISTRADOR\nUSER: %s", user);
		printf ("\n============================================================\n");
		printf ("DATOS COCINERO INGRESADO");
		printf ("\n------------------------------------------------------------\n\n");
		printf ("RUT:\t");
		print_rut(chef->rut);
		printf ("\nNOMBRE:\t%s\n", chef->nombre_cocinero);
		printf ("\n------------------------------------------------------------\n");
		printf ("¿Los datos son correctos?S/N: ");
		scanf  ("%s", &conf);	
	}while ( conf != 'n' && conf != 'N' && conf != 's' && conf != 'S' );
	
	if ( conf == 'n' || conf == 'N')
		add_cocinero(user);
	else	
		add_cook_bd(chef);

free(chef);	
}
/*==========================================================================*/


/*================== OPCIONES ADMINISTRADOR -> CONSUMIDOR ==================*/
void view_consumidor(char *user)
{
	int opc;
	char opchar[100];
	
	system ("clear");
	printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nADMINISTRADOR\nUSER: %s", user);
	printf ("\n============================================================\n");
	printf ("LISTA DE CLIENTES");
	printf ("\n------------------------------------------------------------\n\n");
	
	read_client_bd();
	
	printf ("\n============================================================\n");
	printf ("Cualquier Tecla + <ENTER>: ");
	scanf  ("%s", opchar);
	opc = atoi (opchar);
}
/*
void hacer_pedido(char *user)
{
	int opc;
	char opchar[100];
	
	system ("clear");
	printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nADMINISTRADOR\nUSER: %s", user);
	printf ("\n============================================================\n");
	printf ("VENTA DE PLATILLOS");
	printf ("\n------------------------------------------------------------\n");
	printf ("");
	
	
	printf ("\n============================================================\n");
	printf ("Opcion: ");
	scanf  ("%s", opchar);
	opc = atoi (opchar);
}
*/
void add_consumidor(char *user)
{
	char conf;
	Consumidor *cliente = malloc(sizeof(Consumidor));
	
	system ("clear");
	printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nADMINISTRADOR\nUSER: %s", user);
	printf ("\n============================================================\n");
	printf ("INGRESAR NUEVO CLIENTE");
	printf ("\n------------------------------------------------------------\n");
	cliente->id_consumidor = id_valida_consumidor("consumidor.ari");
	printf ("RUT: ");			scanf  ("%s", cliente->rut);
	printf ("NOMBRE: ");		scanf  ("%s", cliente->nombre);
	printf ("TELEFONO: ");		scanf  ("%s", cliente->telefono);
	
	do{
		system ("clear");
		printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nADMINISTRADOR\nUSER: %s", user);
		printf ("\n============================================================\n");
		printf ("DATOS CLIENTE INGRESADO");
		printf ("\n------------------------------------------------------------\n");
		printf ("ID-ASIGNADO:\t\t%d\n    RUT:\t\t", cliente->id_consumidor);
		print_rut(cliente->rut);
		printf("\n    NOMBRE:\t\t%s\n    TELEFONO:\t\t%s\n", cliente->nombre, cliente->telefono );		printf ("\n------------------------------------------------------------\n");
		printf ("¿Los datos son correctos?S/N: ");
		scanf  ("%s", &conf);
	}while ( conf != 'n' && conf != 'N' && conf != 's' && conf != 'S' );
	
	if ( conf == 'n' || conf == 'N')
		add_consumidor(user);
	else
		add_client_bd(cliente);
	
free(cliente);
}
/*==========================================================================*/


/*================= OPCIONES ADMINISTRADOR -> INGREDIENTES =================*/
void view_ingredientes(char *user)
{
	int opc;
	char opchar[100];
	
	system ("clear");
	printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nADMINISTRADOR\nUSER: %s", user);
	printf ("\n============================================================\n");
	printf ("LISTA DE INGREDIENTES");
	printf ("\n------------------------------------------------------------\n");
	
	read_ing_bd();
	
	printf ("\n============================================================\n");
	printf ("Cualquier Tecla + <ENTER>: ");
	scanf  ("%s", opchar);
	opc = atoi (opchar);
}

void add_ingredientes(char *user)
{
	char conf;
	Ingredientes *ing = malloc(sizeof(Ingredientes));
	
	system ("clear");
	printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nADMINISTRADOR\nUSER: %s", user);
	printf ("\n============================================================\n");
	printf ("INGRESAR NUEVO INGREDIENTE");
	printf ("\n------------------------------------------------------------\n");
	ing->id_ingrediente = id_valida("ingredientes.ari");
	printf ("STOCK: ");			scanf  ("%d", &ing->stock);
	printf ("COSTO: ");			scanf  ("%d", &ing->costo);
	printf ("NOMBRE: ");		scanf  ("%s", ing->nombre_ingrediente);

	
	do{
		system ("clear");
		printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nADMINISTRADOR\nUSER: %s", user);
		printf ("\n============================================================\n");
		printf ("DATOS INGREDIENTE INGRESADO");
		printf ("\n------------------------------------------------------------\n");
		printf ("ID-ASIGNADO:\t%d\nSTOCK:\t\t%d\nCOSTO:\t\t%d\nNOMBRE:\t\t%s", ing->id_ingrediente, ing->stock, ing->costo, ing->nombre_ingrediente);
		printf ("\n------------------------------------------------------------\n");
		printf ("\n¿Los datos son correctos?S/N: ");
		scanf  ("%s", &conf);
	}while ( conf != 'n' && conf != 'N' && conf != 's' && conf != 'S' );
	
	if ( conf == 'n' || conf == 'N')
		add_ingredientes(user);
	else
		add_ing_bd(ing);

free(ing);
}
/*===========================================================================*/



/*================== OPCIONES COCINERO -> PLATILLOS ===================*/
void view_platillo(char *user)
{
	int opc;
	char opchar[100];
	
	system ("clear");
	printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nCOCINERO\nUSER: %s", user);
	printf ("\n============================================================\n");
	printf ("LISTA PLATILLOS");
	printf ("\n------------------------------------------------------------\n");
	
	read_plato_bd();
	
	printf ("\n============================================================\n");
	printf ("Cualquier Tecla + <ENTER>: ");
	scanf  ("%s", opchar);
	opc = atoi (opchar);
}

void add_platillo(char *user)
{		
	int i;
	char cant[100];	
	Plato *platillo = malloc(sizeof(Plato));
	Plato_ingredientes *plato_ing; 
	Ingredientes *ing = malloc(sizeof(Ingredientes));
	FILE *arch;
	
	if((arch = fopen("ingredientes.ari", "rb")) == NULL)
	{
		system ("clear");
		printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nCOCINERO\nUSER: %s", user);
		printf ("\n============================================================\n");
		printf ("CREAR NUEVO PLATILLO");
		printf ("\n------------------------------------------------------------\n");
		printf ("\nSIN INGREDIENTES, AVISAR AL ADMINISTRADOR\n");
	}
	else
	{
		platillo->id_plato = id_valida_plato("platos.ari");
		strcpy (platillo->rut_cocinero, user);
		platillo->costo_preparar = 0;
		
		system ("clear");
		printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nCOCINERO\nUSER: %s", user);
		printf ("\n============================================================\n");
		printf ("CREAR NUEVO PLATILLO");
		printf ("\n------------------------------------------------------------\n");
		printf ("\nNOMBRE DEL PLATO: ");				scanf ("%s", platillo->nombre);
		
		while(1)
		{
			printf ("\nCANTIDAD DE INGREDIENTES:");		scanf ("%s",cant);
			if( atoi(cant) )
			{
				platillo->cant_ingredientes = atoi(cant);
				break;
			}
			else
			{
			printf ("\nVALOR INVALIDO INGRESE CUALQUIER TECLA Y PRESIONE <ENTER>\n");
			scanf  ("%s",cant);
			}	
		}
	
		plato_ing = malloc((sizeof(Plato_ingredientes)) * (platillo->cant_ingredientes));
		
		for( i=0 ; i<platillo->cant_ingredientes ; i++ )
		{
			system ("clear");
			printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nCOCINERO\nUSER: %s", user);
			printf ("\n============================================================\n");
			printf ("NUEVO PLATILLO ->%s", platillo->nombre);
			printf ("\n------------------------------------------------------------\n");
			printf ("[ID] INGREDIENTE\n");
			
			rewind(arch);
			while(fread (ing, sizeof(Ingredientes), 1, arch))
				printf (" %d\t %s\n", ing->id_ingrediente, ing->nombre_ingrediente);
			
			printf ("\n------------------------------------------------------------\n");
			
			printf ("ID-INGREDIENTE %d: ", i+1);		scanf  ("%s",cant);
			plato_ing[i].id_ingrediente = atoi(cant);
			
			printf ("CANTIDAD: ");						scanf  ("%s",cant);
			plato_ing[i].cantidad = atoi(cant);
			
			rewind(arch);
			while(fread (ing, sizeof(Ingredientes), 1, arch))
			{
				if(ing->id_ingrediente == plato_ing[i].id_ingrediente)
				{
					platillo->costo_preparar = platillo->costo_preparar + ing->costo * plato_ing[i].cantidad;
					break;
				}
			}		
		}
			
		platillo->precio_venta = platillo->costo_preparar * 1.3;
		
		add_plato_bd(platillo, plato_ing);
		fclose(arch);
		
		free(plato_ing);
	}	
free(ing);	
free(platillo);
}
/*=====================================================================*/
