#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "opciones.c"

/*================ PROTOTIPOS ================*/
void login(void);
void admin(char *user);
void mnu_admin1(char *user);	/* COCINEROS */
void mnu_admin2(char *user);	/* INGREDIENTES */
void mnu_admin3(char *user);	/* CLIENTES */
void cocinero(char *user);
/*============================================*/

void login(void)
{
	int opcmnu, conf;
	char opchar[100];
	char usr[100];
	char *user = (char *)malloc(sizeof(100));
	char *pass = (char *)malloc(sizeof(100));
	char *rut  = (char *)malloc(sizeof(100));
	
	system ("clear");
	printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\n");
	printf ("\n============================================================\n");
	printf ("\n[1] Ingresar como Administrador.");
	printf ("\n[2] Ingresar como Cocinero.");
	printf ("\n[3] Salir.");
	printf ("\n\n============================================================\n");
	printf ("Opcion: ");
	scanf  ("%s", opchar);
	opcmnu = atoi (opchar);
	
	switch (opcmnu)
	{
		case 1: 
			system ("clear");
			printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\n\nADMINISTRADOR");
			printf ("\n============================================================\n");
			user = check_admin_file(usr);
			conf = check_admin();
			
			if (conf == 1)
			{
				admin(user);
				break;
			}
			else
			{
				printf ("\n\nDATOS INCORRECTOS");
				login();
			}
			
		case 2: 
			system ("clear");
			printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\n\nCOCINERO");
			printf ("\n============================================================\n");
			conf = check_cook(user);

			if (conf == 1)
			{
				cocinero(user);
				break;
			}
			else
			{
				printf ("\n\nDATOS INCORRECTOS");
				login();
			}
		case 3:
			system("clear");
			exit(0);
		default: 	login();
	}
free(user);
free(rut);
free(pass);
}

/*==================================== ADMINISTRADOR ====================================*/
void admin(char *user)
{
	int opc;
	char opchar[100];
	
	system ("clear");
	printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nADMINISTRADOR\nUSER: %s", user);
	printf ("\n============================================================\n");
	printf ("\n[1] Cocineros.");
	printf ("\n[2] Ingredientes.");
	printf ("\n[3] Clientes.");
	printf ("\n[4] Cerrar Sesion.");
	printf ("\n\n============================================================\n");
	printf ("Opcion: ");
	scanf  ("%s", opchar);
	opc = atoi (opchar);
	
	switch (opc)
	{
		case 1: mnu_admin1(user);	break;
		case 2: mnu_admin2(user);	break;
		case 3: mnu_admin3(user);	break;
		case 4: login();
		default: admin(user);
	}
}

void mnu_admin1(char *user)
{
	int opc;
	char opchar[100];
	
	system ("clear");
	printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nADMINISTRADOR\nUSER: %s", user);
	printf ("\n============================================================\n");
	printf ("ADMINISTRADOR -> Cocineros");
	printf ("\n------------------------------------------------------------\n");
	printf ("\n[1] Ver Lista Completa de Cocineros.");
	printf ("\n[2] Agregar Nuevo Cocinero.");
	printf ("\n[3] Volver.");
	printf ("\n\n============================================================\n");
	printf ("Opcion: ");
	scanf  ("%s", opchar);
	opc = atoi (opchar);
		
	switch (opc)
	{
		case 1: view_cocinero(user);	mnu_admin1(user);	break;
		case 2: add_cocinero(user);		mnu_admin1(user);	break;
		case 3: admin(user);
		default: mnu_admin1(user);
	}
	
}

void mnu_admin2(char *user)
{
	int opc;
	char opchar[100];
	
	system ("clear");
	printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nADMINISTRADOR\nUSER: %s", user);
	printf ("\n============================================================\n");
	printf ("ADMINISTRADOR -> Ingredientes");
	printf ("\n------------------------------------------------------------\n");
	printf ("\n[1] Ver Lista de Ingredientes.");
	printf ("\n[2] Agregar/Actualizar Ingrediente.");
	printf ("\n[3] Volver.");
	printf ("\n\n============================================================\n");
	printf ("Opcion: ");
	scanf  ("%s", opchar);
	opc = atoi (opchar);
	
	switch (opc)
	{
		case 1: view_ingredientes(user);	mnu_admin2(user);	break;
		case 2: add_ingredientes(user);		mnu_admin2(user);	break;
		case 3: admin(user);
		default: mnu_admin2(user);
	}
}

void mnu_admin3(char *user)
{
	int opc;
	char opchar[100];
	
	system ("clear");
	printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nADMINISTRADOR\nUSER: %s", user);
	printf ("\n============================================================\n");
	printf ("ADMINISTRADOR -> Clientes");
	printf ("\n------------------------------------------------------------\n");
	printf ("\n[1] Ver Lista de Clientes.");
	printf ("\n[2] Agregar Nuevo Cliente.");
	printf ("\n[3] Volver.");
	printf ("\n\n============================================================\n");
	printf ("Opcion: ");
	scanf  ("%s", opchar);
	opc = atoi (opchar);
	
	switch (opc)
	{
		case 1: view_consumidor(user);	mnu_admin3(user);	break;
		case 2: add_consumidor(user);	mnu_admin3(user);	break;
		case 3: admin(user);
		default: mnu_admin3(user);
	}
}
/*=======================================================================================*/


/*====================================== COCINERO =======================================*/
void cocinero(char *user)
{	
	int opc;
	char opchar[100];
	
	system ("clear");
	printf ("\t\t**RESTAURANT \"LOS BEMOLES\"**\nCOCINERO\nUSER: %s", user);
	printf ("\n============================================================\n");
	printf ("\n[1] Ver Lista de Ingredientes.");
	printf ("\n[2] Ver Lista de Platillos.");
	printf ("\n[3] Crear Platillos.");
	printf ("\n[4] Cerrar Sesion.");
	printf ("\n\n============================================================\n");
	printf ("Opcion: ");
	scanf  ("%s", opchar);
	opc = atoi (opchar);
	
	switch (opc)
	{
		case 1: view_ingredientes(user);	cocinero(user);		break;
		case 2: view_platillo(user);		cocinero(user);		break;
		case 3: add_platillo(user);			cocinero(user);		break;
		case 4: login();
		default: cocinero(user);
	}
	
}
/*=======================================================================================*/
