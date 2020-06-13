
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Capturo del usuario un valor entero
 *
 * \param pResultado es la direccion de memoria donde almaceno el resultado
 * \param pMensaje es la consigna que recibe el usuario por pantalla
 * \param pMensajeError es el mensaje de error que recibe el usuario por pantalla
 * \param minimo es el valor minimo del rango aceptado
 * \param maximo es el valor maximo del rango aceptado
 * \param reintentos es la cantidad de veces que el usuario puede ingresar la informacion requerida
 * \return 0 si pudo conseguir el dato; -1 si hubo algun error
 *
 */
int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
        int retorno;
		int bBuffer;
		int i;
		int datoOk;
		char buffer[255];

	if(	pResultado != NULL &&
		pMensaje != NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos > 0)
	{
		do
		{
			retorno = -1;
			datoOk = 1;
			i = 0;
			printf("%s",pMensaje);
			fflush(stdin);
			fgets(buffer,sizeof(buffer),stdin);
			buffer[strlen(buffer)-1]='\0';

			while(buffer[i] != '\0')
			{
				if(buffer[i] < '0' || buffer[i] > '9')
				{
					datoOk = 0;
				}
				i++;
			}
			if(datoOk)
			{
				bBuffer=atoi(buffer);
				if(bBuffer >= minimo && bBuffer <= maximo)
				{
					*pResultado = bBuffer;
					retorno = 0;
					break;
				}
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/** \brief Capturo del usuario un valor de cadena de caracteres
 *
 * \param pResultado es la direccion de memoria donde almaceno el resultado
 * \param pMensaje es la consigna que recibe el usuario por pantalla
 * \param pMensajeError es el mensaje de error que recibe el usuario por pantalla
 * \param minimo es el valor minimo del rango aceptado
 * \param maximo es el valor maximo del rango aceptado
 * \param reintentos es la cantidad de veces que el usuario puede ingresar la informacion requerida
 * \return 0 si pudo conseguir el dato; -1 si hubo algun error
 *
 */
int getString(char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer[255];

	if(		pResultado != NULL &&
			pMensaje != NULL &&
			pMensajeError != NULL &&
			minimo < maximo &&
			reintentos > 0)
	{
		do
		{
			printf("%s",pMensaje);
			fflush(stdin);
			fgets(buffer,sizeof(buffer),stdin);
			buffer[strlen(buffer)-1]='\0';
			if(strlen(buffer)<=maximo && strlen(buffer)>=minimo)
			{
				strncpy(pResultado,buffer,maximo+1);
				retorno = 0;
				break;
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/** \brief Capturo del usuario un caracter
 *
 * \param resultado es la direccion de memoria donde almaceno el resultado
 * \param mensaje es la consigna que recibe el usuario por pantalla
 * \param mensajeError es el mensaje de error que recibe el usuario por pantalla
 * \param minimo es el valor minimo del rango aceptado
 * \param maximo es el valor maximo del rango aceptado
 * \param reintentos es la cantidad de veces que el usuario puede ingresar la informacion requerida
 * \return 0 si pudo conseguir el dato; -1 si hubo algun error
 *
 */
char getChar(char *resultado,
			char *mensaje,
			char *mensajeError,
			char minimo,
			char maximo,
			int reintentos)
{
	int retorno = -1;
	char buffer;
	if(	resultado != NULL &&
		mensaje	!= NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin); // en windows es fflush
			if(scanf("%c",&buffer)==1)
			{
				if(buffer == minimo || buffer == maximo)
				{
					retorno = 0;
					*resultado = buffer;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/** \brief Imprimie el menu en pantalla
 *
 * \param void
 * \return o si fue exitosa, -1 si hubo algun error
 *
 */
int funcionMenu(void)
{
        int retorno;
	    int opcion;
        int listaEmpleadosVacia;
        int ll_creada;
        int cargaBin;

	    retorno = -1;
	    listaEmpleadosVacia = 1;
		ll_creada = 0;
        cargaBin = 0;
   		LinkedList* listaEmpleados = ll_newLinkedList();
   		ll_creada = 1;
	    do{
			if(getInt(&opcion,"\n\nSeleccione la opcion deseada:\n\t  1- Cargar los datos de los empleados(modo txt)\n\t  2- Cargar los datos de los empleados(modo binario)\n\t  3- Alta Empleado\n\t  4- Modificar Empleado\n\t  5- Baja Empleado\n\t  6- Listar Empleados\n\t  7- Ordenar Empleados\n\t  8- Guardar los datos (modo txt)\n\t 9- Guardar los datos (modo binario) \n\t 10 - Salir\n","Ha ingresado una opcion invalida, reintente.",1,10,2)==0)
	        {
				switch(opcion)
	            {
	                case 1:
	                	if(controller_loadFromText("data.csv",listaEmpleados))
	                	{
	                		listaEmpleadosVacia = 0;
	                		printf("\n\t\tDatos Cargados correctamente.\n\n");
	                	}
                        break;
	                case 2:
	                    if(cargaBin == 1)
                        {
                            if(controller_loadFromBinary("data.bin",listaEmpleados))
                            {
                                listaEmpleadosVacia = 0;
                                printf("\n\t\tDatos Cargados correctamente.\n\n");
                                break;
                            }
                        }
                        printf("No hay datos de tipo binario para cargar.\n");
	                    break;
	                case 3:
	                	controller_addEmployee(listaEmpleados);
	                	if(listaEmpleadosVacia)
	                	{
	                	    listaEmpleadosVacia = 0;
	                	}
	                	break;
	                case 4:
	                	if(listaEmpleadosVacia == 1)
                        {
                            printf("No hay Empleados para ser modificados.\n");
                            break;
                        }
	                	controller_editEmployee(listaEmpleados);
	                    break;
	                case 5:
	                    if(listaEmpleadosVacia == 1)
                        {
                            printf("No hay Empleados para dar de baja.\n");
                            break;
                        }
	                    controller_removeEmployee(listaEmpleados);
	                	break;
	                case 6:
	                	if(listaEmpleadosVacia == 1)
	                	{
	                		printf("\t\tNo se pueden listar empleados porque no hay datos que mostrar.\n\n");
	                		break;
	                	}
	                	controller_ListEmployee(listaEmpleados);
	                    break;
	                case 7:
	                	if(listaEmpleadosVacia == 1)
	                	{
	                		printf("\t\tNo se pueden listar empleados porque no hay datos que mostrar.\n\n");
	                		break;
	                	}
	                	controller_sortEmployee(listaEmpleados);
	                    break;
	                case 8:
	                	if(listaEmpleadosVacia && !ll_creada)
                        {
                            printf("No hay informacion para exportar a un archivo.\n\n");
                            break;
                        }
                        controller_saveAsText("data.csv", listaEmpleados);
	                	printf("\t\tDatos almacenados en modo Texto correctamente.\n");
	                    break;
	                case 9:
	                	if(controller_saveAsBinary("data.bin",listaEmpleados))
                        {
                            printf("\t\tDatos almacenados en modo Binario correctamente.\n");
                            cargaBin = 1;
                        }
	                	break;
	                }
	        }
	    }while(opcion != 10);
	    retorno = 0;
	    return retorno;
}

/** \brief Valida si lo ingresa es un caracter valido
 *
 * \param buffer es la direccion de memoria donde se almaceno el caracter ingresado a validar
 * \return 0 si la validacion fue exitosa; -1 si hubo algun error
 *
 */
int esSoloChar(char *buffer){
    int i;
    int retorno;
    int datoOk;
    retorno = -1;

    if(buffer != NULL)
    {
        i = 0;
        datoOk = 1;
        while(buffer[i] != '\0')
        {
            if((buffer[i] != ' ') && (buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z'))
            {
                datoOk = 0;
            }
            i++;
        }
        if(datoOk)
        {
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Valida si lo ingresa es una cadena alfanumerica
 *
 * \param buffer es la direccion de memoria donde se almaceno el valor ingresado a validar
 * \return 0 si la validacion fue exitosa; -1 si hubo algun error
 *
 */
int esAlfaNumerico (char *buffer){
    int i;
    int retorno;
    int datoOk;

    if(buffer != NULL)
    {
        i = 0;
        retorno = -1;
        datoOk = 1;
        while(buffer[i] != '\0')
        {
            if((buffer[i] != ' ') && (buffer[i] != '-') && (buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && (buffer[i] < '0' || buffer[i] > '9'))
            {
                datoOk = 0;
            }
            i++;
        }
        if(datoOk)
        {
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Valida si lo ingresado es un numero valido
 *
 * \param buffer es la direccion de memoria donde se almaceno el valor ingresado a validar
 * \return 0 si la validacion fue exitosa; -1 si hubo algun error
 *
 */
int esNumerico(char *buffer)
{
    int i;
    int retorno;
    int datoOk;

    if(buffer != NULL)
    {
        i = 0;
        retorno = -1;
        datoOk = 1;
        while(buffer[i] != '\0')
        {
            if(buffer[i] < '0' || buffer[i] > '9')
            {
                datoOk = 0;
            }
            i++;
        }
        if(datoOk)
        {
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Valida si lo ingresa es un caracter o un espacio
 *
 * \param buffer es la direccion de memoria donde se almaceno el valor ingresado a validar
 * \return 0 si la validacion fue exitosa; -1 si hubo algun error
 *
 */
int isCharOrSpace(char buffer[])
{
    int retorno = -1;
    int errorCarga;

    for(int i=0;i<strlen(buffer);i++)
    {
        if((buffer[i]>='A' && buffer[i]<='Z') || (buffer[i]>='a' && buffer[i]<='z') || buffer[i]==' ' || buffer[i]=='\0')
        {
            errorCarga = 0;
        }
        else
        {
            errorCarga = -1;
            break;
        }
    }
    if(errorCarga == 0)
    {
        retorno = 0;
    }
    return retorno;
}

/** \brief Capturo del usuario un caracter dentro de un rango de caracteres
 *
 * \param resultado es la direccion de memoria donde almaceno el resultado
 * \param mensaje es la consigna que recibe el usuario por pantalla
 * \param mensajeError es el mensaje de error que recibe el usuario por pantalla
 * \param minimo es el valor minimo del rango aceptado
 * \param maximo es el valor maximo del rango aceptado
 * \param reintentos es la cantidad de veces que el usuario puede ingresar la informacion requerida
 * \return 0 si pudo conseguir el dato; -1 si hubo algun error
 *
 */
char getCharVarios(char *resultado,
			char *mensaje,
			char *mensajeError,
			char minimo,
			char maximo,
			int reintentos)
{
	int retorno = -1;
	char buffer;
	if(	resultado != NULL &&
		mensaje	!= NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			if(scanf("%c",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = 0;
					*resultado = buffer;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}
