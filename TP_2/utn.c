/*
 * utn.c
 *
 *  Created on: 30 Apr. 2020
 *  Author: Cristian Rosales
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "empleados.h"
#define EXIT_ERROR -1
#define EXIT_SUCCESS 0


/** \brief Imprime el Menu de Opciones
 *
 * \return Devuelve 0 si se recorrio el Menu, -1 si hubo algun error.
 *
 */
int funcionMenu(void)
{
    struct sEmployee aEmpleado[QTY_EMPLEADOS];
    struct sEmployee bEmpleado;
    int opcion;
	int retorno;
    int estructuraVacia;
    int bLugarLibre;
    float promedioSalarios;
    float salarioTotal;
    int salariosSobrePromedio;

    estructuraVacia = 1;
    retorno = EXIT_ERROR;
	do{
        if(getInt(&opcion,"\n\nSeleccione la opcion deseada:\n\t 1- Alta Empleado\n\t 2- Modificar Empleado\n\t 3- Baja Empleado\n\t 4- Listado de Empleado\n\t 5- Total y Promedio de Salarios. Q de Empleados con Salario > Promedio\n\t 6- Salir\n","Ha ingresado una opcion invalida, reintente.",1,6,0)==0)
        {

            switch(opcion)
            {
                case 1:
                    system("cls");
                    if(estructuraVacia==1)
                    {
                        initLugarLibreEmpleado(aEmpleado, QTY_EMPLEADOS);
                        estructuraVacia = 0;
                    }
                    bLugarLibre=buscarLugarLibreEmpleado(aEmpleado, QTY_EMPLEADOS);
                    if(bLugarLibre == -1)
                    {
                        printf("\nNo se pueden cargar mas empleados. La estructura no tiene mas espacios libres.\n\n");
                        break;
                    }
                    getEmpleadoStr(aEmpleado, bEmpleado,QTY_EMPLEADOS,3,bLugarLibre);
                    break;
                case 2:
                    system("cls");
                    if(estructuraVacia==1)
                    {
                        printf("\nNo es posible modificar empleados ya que la estructura se encuentra vacia. Reintente.\n\n\t");
                        break;
                    }
                    modificarEmpleadosPorId(aEmpleado, QTY_EMPLEADOS, bEmpleado);
                    break;
                case 3:
                    system("cls");
                    if(estructuraVacia==1)
                    {
                        printf("\nNo es posible dar de baja empleados ya que la estructura se encuentra vacia. Reintente.\n\n\t");
                        break;
                    }
                    bajaEmpleadosPorId(aEmpleado, QTY_EMPLEADOS);
                    break;
                case 4:
                    system("cls");
                    if(estructuraVacia==1)
                    {
                        printf("\nNo es posible listar empleados ya que la estructura se encuentra vacia. Reintente.\n\n\t");
                        break;
                    }
                    ordenarStructEmpleadosByNameOrLastName(aEmpleado, QTY_EMPLEADOS);
                    imprimirArrayEmpleados(aEmpleado, QTY_EMPLEADOS);
                    break;
                case 5:
                    system("cls");
                    if(estructuraVacia==1)
                    {
                        printf("\nNo es posible listar datos de empleados ya que la estructura se encuentra vacia. Reintente.\n\n\t");
                        break;
                    }
                    promedioArrayStruct(aEmpleado, QTY_EMPLEADOS, &promedioSalarios, &salarioTotal);
                    sueldosSobrePromedio(aEmpleado, QTY_EMPLEADOS, &salariosSobrePromedio, promedioSalarios);
                    printf("\n\n\tEl salario promedio es: $%.2f\n\tEl total de salarios es: %.2f\n\tHay un total de %d empleados con salario sobre el promedio.\n", promedioSalarios, salarioTotal, salariosSobrePromedio);
                    break;
            }
        }
    }while(opcion != 6);
    retorno = EXIT_SUCCESS;
    return retorno;
}

/** \brief Inicia el array con ceros
 *
 * \param array recibe el arrar a inicializar
 * \param limite recibe la cantidad de elemento del array
 * \param valor recibe el valor de id a ingresar en el array
 * \return devuelve 0 si el proceso fue exitoso, -1 si no se pudo inicializar el array
 *
 */
int initArrayInt(int array[],int limite,int valor )
{
	int i;
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			array[i]=valor+i;
		}

	}
	return retorno;
}

/** \brief Imprime por pantalla el array
 *
 * \param array recibe el array a recorrer e imprimir
 * \param limite recibe el tamaño del array
 * \return Devuelve 0 si el proceso se pudo completar, -1 si hubo algun error.
 *
 */
int imprimeArrayInt(int array[],int limite )
{
	int i;
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		printf("\n\n-------\n");
		for(i=0;i<limite;i++)
		{
			printf("%d\n",array[i]);
		}

	}
	return retorno;
}

/** \brief Valida un ingreso y devuelve el valor entero ingresado
 *
 * \param *pResultado es la direccion de memoria donde se almacenara el valor ingresado por el usuario
 * \param *pMensaje es la consigna que se le brindará al usuario
 * \param *pMensajeError mensaje de error que se brindara si el ingreso fue invalido
 * \param minimo es el valor minimo aceptado por la funcion
 * \param maximo es el valor maximo aceptado por la funcion
 * \param reintentos es el valor de reintentos que el usuario tiene disponibles en caso de ingresar un valor erroneo
 * \return devuelve 0 si el proceso fue exitoso o -1 si hubo algun error
 *
 */
/*int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno = -1;
	int buffer;
	do
	{
		printf("%s",pMensaje);
		fflush(stdin);
		if(scanf("%d",&buffer)==1 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
		reintentos--;
	}while(reintentos >= 0);
	return retorno;
}*/
int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
    int errorCarga;
	int retorno = EXIT_ERROR;
	char buffer[255];
	int bufferDos;
	do
		{
			printf("%s",pMensaje);
			fflush(stdin);
			fgets(buffer,sizeof(buffer),stdin);
			buffer[strlen(buffer)-1]='\0'; // con esto contamos el largo del string, y en la ultima posicion ponemos el "\0"
            for(int i=0;i<strlen(buffer);i++)
            {
                if(buffer[i]>='0' && buffer[i]<='9')
                {
                    errorCarga = 0;
                }
                else
                {
                    errorCarga = -1;
                    break;
                }
            }
			if(errorCarga==0)
            {
                bufferDos=atoi(buffer);
                if(bufferDos >= minimo && bufferDos <= maximo)
                {
                    //retorno = bufferDos;
                    *pResultado = bufferDos;
                    retorno = EXIT_SUCCESS;
                    break;
                }
            }
			printf("%s\n",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	return retorno;
}

/** \brief Recupera los valores para ingresar en el array por parte del usuario
 *
 * \param array es el array donde ingresaremos la informacion solicitada
 * \param limite es el tamaño del array a modificar
 * \param pMensaje es la consigna que se le brindara al usuario
 * \param pMensajeError es el mensaje de error que se le brindara al usuario en caso de un ingreso invalido
 * \param minimo es el valor minimo para que el usuario ingrese
 * \param maximo es el valor maximo para que el usuario ingrese
 * \param reintentos es la cantidad de reintentos que el usuario tiene para ingresar informacion en caso de error
 * \return devuelve 0 si el proceso fue exitoso o -1 si hubo algun error
 *
 */
int getArrayInt(	int array[],
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos)
{
	int i=0;
	int buffer;
	char respuesta = 'n';
	int retorno = EXIT_ERROR;
	if(array != NULL && limite > 0)
	{
		do
		{
			if(getInt(	&buffer,
						pMensaje,
						pMensajeError,
						minimo,
						maximo,
						reintentos) == 0)
			{
				array[i] = buffer;
				i++;
				limite--;
			}
			printf("Continuar? (s/n)");
			fflush(stdin);
			scanf("%c",&respuesta);
		}while(respuesta == 's' && limite > 0);
		retorno = EXIT_SUCCESS;
	}
	return retorno;
}

/** \brief Recupera el valor maximo existente en el array
 *
 * \param array es el array a recorrer
 * \param limite es el tamaño del array a recorrer
 * \param pResultado es la direccion de memoria donde se almacenara el valor maximo dentro del array
 * \return Devuelve 0 si se pudo resolver correctamente, -1 si hubo algun error.
 *
 */
int maximoArrayInt(int array[],int limite,int *pResultado)
{
	int i;
	int retorno = -1;
	int maximo;
	int posMaximo;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		maximo = array[0];
		posMaximo = 0;
		for(i=1;i<limite;i++)
		{
			if(array[i]>maximo)
			{
				maximo = array[i];
				posMaximo=i;
			}
		}
		*pResultado = posMaximo;
	}
	return retorno;
}

/** \brief Ordena el array indicado
 *
 * \param array es el array a ordenar
 * \param limite es el tamaño del array
 * \return devuelve 0 si se pudo ordenar, -1 si no se pudo ordenar exitosamente
 *
 */
int ordenarArrayInt(int array[],int limite)
{
	int i;
	int retorno = -1;
	int posMaximo;
	int auxiliar;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			maximoArrayInt(array+i,limite-i,&posMaximo);
			auxiliar = array[i];
			array[i]=array[posMaximo+i];
			array[posMaximo+i] = auxiliar;
		}
	}
	return retorno;
}

/** \brief Ordena el array en orden Ascendente
 *
 * \param array es el array a ordenar
 * \param limite es el tamaño del array a ordenar
 * \return Devuelve 0 si se pudo ordenar, -1 si no fue posible.
 *
 */
int ordenarArraySwapIntAsc(int array[],int limite)
{
	int i;
	int retorno = -1;
	int flagSwap;
	int buffer;
	if(array != NULL && limite > 0)
	{
		do{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i]>array[i+1])
				{
					flagSwap = 1;
					buffer = array[i];
					array[i]=array[i+1];
					array[i+1] = buffer;
				}
			}

		}while(flagSwap);
		retorno = EXIT_SUCCESS;

	}
	return retorno;
}

/** \brief Ordena el array en orden Descendente
 *
 * \param array es el array a ordenar
 * \param limite es el tamaño del array a ordenar
 * \return Devuelve 0 si se pudo ordenar, -1 si no fue posible.
 *
 */
int ordenarArraySwapIntDes(int array[] ,int limite)
{
	int i;
	int retorno = -1;
	int flagSwap;
	int buffer;
	if(array != NULL && limite > 0)
	{
		do{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i]<array[i+1])
				{
					flagSwap = 1;
					buffer = array[i];
					array[i]=array[i+1];
					array[i+1] = buffer;
				}
			}

		}while(flagSwap);
		retorno = EXIT_SUCCESS;

	}
	return retorno;
}

/** \brief Tomo el ingreso de datos por teclado indistintamente del tipo de datos necesario
 *
 * \param pResultado es la direccion de memoria donde almacenaremos el valor resultante del ingreso del usuario
 * \param pMensaje es la consigna que le daremos al usuario
 * \param pMensajeError es el mensaje de error que brindaremos en caso de un ingreso erroneo por parte del usuario
 * \param minimo es el valor minimo aceptado para la funcion
 * \param maximo es el valor maximo aceptado para la funcion
 * \param reintentos es la cantidad de reintentos que tiene el usuario en caso de haber ingresado un dato erroneamente
 * \return Devuelve 0 si el ingreso de datos fue exitoso, -1 si hubo algun error
 *
 */
int getString(char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = EXIT_ERROR;
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
			buffer[strlen(buffer)-1]='\0'; // con esto contamos el largo del string, y en la ultima posicion ponemos el "\0"
			if(strlen(buffer)<=maximo && strlen(buffer)>=minimo)
			{
				strncpy(pResultado,buffer,maximo+1);
				retorno = EXIT_SUCCESS;
				break;
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/** \brief Ordeno el array por insercion
 *
 * \param array es el array a ordenar
 * \param limite es el tamaño maximo del array
 * \return Devuelve 0 si se pudo ordenar, -1 si hubo algun error
 *
 */
int insertionSortArrayInt(int array[], int limite)
{
    int i;
    int j;
    int buffer;
    int retorno;
    retorno = EXIT_ERROR;
        for (i = 1; i < limite; i++)
        {
            buffer = array[i];
            j = i - 1;
            while (j >= 0 && array[j] > buffer)
            {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = buffer;
            retorno = EXIT_SUCCESS;
        }
    return retorno;
}

/** \brief Inicializa un array de cadena de caracteres
 *
 * \param array es el array a inicializar con la cantidad de caracteres por elemento
 * \param limite es el tamaño del array
 * \param valor es el campo que ingresaremos en el array de cadena de caracteres
 * \return Devuelve 0 si se pudo iniciar exitosamente, -1 si hubo algun error.
 *
 */
int initArrayStr(char array[][QTY_CARACTERES],int limite,int valor)
{
	int i;
	int retorno = EXIT_ERROR;
	char empty[QTY_CARACTERES];
	strncpy(empty,"Empty",valor);
	if(array != NULL && limite > 0 && valor > 0)
	{
		for(i=0;i<limite;i++)
		{
			strncpy(array[i],empty,valor);
		}
		retorno = EXIT_SUCCESS;
	}
	return retorno;
}

/** \brief Imprime por pantalla el array de cadena de caracteres
 *
 * \param array recibe el array a recorrer e imprimir con la cantidad de caracteres por elemento
 * \param limite recibe el tamaño del array
 * \return Devuelve 0 si el proceso se pudo completar, -1 si hubo algun error.
 *
 */
int imprimeArrayStr(char array[][QTY_CARACTERES], int limite)
{
	int i;
	int retorno = EXIT_ERROR;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			printf("%s \n", array[i]);
		}
		retorno = EXIT_SUCCESS;
	}
	return retorno;
}

/** \brief Recupera todos los datos necesarios para poder cargar un array de cadena de caracteres
 *
 * \param array es el array a cargar con la cantidad de caracteres por elemento
 * \param limite es el tamaño del array
 * \param pMensaje es la consigna que le mostraremos al usuario
 * \param pMensajeError es el mensaje de error que le mostraremos al usuario en casa de un ingreso incorrecto
 * \param minimo es el valor minimo aceptado por la funcion
 * \param maximo es el valor maximo aceptado por la funcion
 * \param reintentos es la cantidad de reintentos que tiene el usuario en caso de cometer un error en el ingreso
 * \return Devuelve 0 si pudo ingresarse la informacion correctamente, -1 si no pudo se cargada correctamente
 *
 */
int getArrayStr(	char array[][QTY_CARACTERES],
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos)
{
	int i=0;
	char buffer[255];
	char respuesta = 'n';
	int retorno = EXIT_ERROR;
		if( array != NULL &&
			limite > 0 &&
			pMensaje != NULL &&
			pMensajeError != NULL &&
			minimo < maximo &&
			reintentos > 0)
		{
			do
			{
				if(getString(buffer,
							pMensaje,
							pMensajeError,
							minimo,
							maximo,
							reintentos) == 0)
				{
					strncpy(array[i],buffer,QTY_CARACTERES);
					i++;
					limite--;
				}
				printf("Continuar? (s/n)");
				fflush(stdin);
				scanf("%c",&respuesta);
			}while(respuesta == 's' && limite > 0);
			retorno = EXIT_SUCCESS;
		}
	return retorno;
}

/** \brief Ordena un Array de Caracteres por Swap de manera Ascendente
 *
 * \param array recibe el array a ordenar con la cantidad de caracteres por elementos
 * \param limite recibe el tamaño del array
 * \return Devuelve 0 si pudo procesarle el ordenamiento exitosamente o -1 si hubo algun error.
 *
 */
int ordenarArraySwapStrAsc(char array[][QTY_CARACTERES],int limite)
{
	int i;
	int j;
	int retorno = EXIT_ERROR;
	int flagSwap;
	char buffer[255];
	if(array != NULL && limite > 0)
	{
		do{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)// siempre el -1 al limite para que no compare con la nada misma
			{
				j = i+1;
				if(strcmp(array[i],array[j])>0) //strcmp=0.1=2/strcmp>0.2>1/strcmp<0.1>2
				{
					flagSwap = 1;
					strncpy(buffer, array[i],QTY_CARACTERES);
					strncpy(array[i],array[j],QTY_CARACTERES);
					strncpy(array[j],buffer,QTY_CARACTERES);
				}
			}

		}while(flagSwap);
		retorno = EXIT_SUCCESS;
	}
	return retorno;
}

/** \brief Ordena un Array de Caracteres por Swap de manera Descendente
 *
 * \param array recibe el array a ordenar con la cantidad de caracteres por elementos
 * \param limite recibe el tamaño del array
 * \return Devuelve 0 si pudo procesarle el ordenamiento exitosamente o -1 si hubo algun error.
 *
 */
int ordenarArraySwapStrDesc(char array[][QTY_CARACTERES],int limite) // burbujeo desc -- Ordena Array STR DESC
{
	int i;
	int j;
	int retorno = EXIT_ERROR;
	int flagSwap;
	char buffer[255];
	if(array != NULL && limite > 0)
	{
		do{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)// siempre el -1 al limite para que no compare con la nada misma
			{
				j = i+1;
				if(strcmp(array[i],array[j])<0) // ACA
				{
					flagSwap = 1;
					strncpy(buffer,array[i],QTY_CARACTERES);
					strncpy(array[i],array[j],QTY_CARACTERES);
					strncpy(array[j],buffer, QTY_CARACTERES);
				}
			}

		}while(flagSwap);
		retorno = EXIT_SUCCESS;

	}
	return retorno;
}

/** \brief Ordena un Array de Caracteres y Enteros por burbujeo de manera Ascendente
 *
 * \param array recibe el array a ordenar con la cantidad de caracteres por elementos
 * \param arrayInt es el array de enteros por el cual se va a ordenar
 * \param limite recibe el tamaño del array
 * \return Devuelve 0 si pudo procesarle el ordenamiento exitosamente o -1 si hubo algun error.
 *
 */
int ordenarArraySwapStrIntAscByInt(char arrayChars[][QTY_CARACTERES],int arrayInt[],int limite)
{
	int i;
	int j;
	int retorno;
	int flagSwap;
	char bufferChars[255];
	int bufferInt;
	if(	arrayChars != NULL &&
		arrayInt != NULL &&
		limite > 0)
	{
		retorno = EXIT_ERROR;
		do{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)// siempre el -1 al limite para que no compare con la nada misma
			{
				j = i+1;
				if(arrayInt[i]>arrayInt[j]) //strcmp=0.1=2/strcmp>0.2>1/strcmp<0.1>2
				{
					flagSwap = 1;
					strncpy(bufferChars, arrayChars[i],QTY_CARACTERES);
					strncpy(arrayChars[i],arrayChars[j],QTY_CARACTERES);
					strncpy(arrayChars[j],bufferChars,QTY_CARACTERES);
					bufferInt = arrayInt[i];
					arrayInt[i]=arrayInt[j];
					arrayInt[j] = bufferInt;
				}
			}

		}while(flagSwap);
		retorno = EXIT_SUCCESS;
	}
	return retorno;
}

/** \brief Ordena un Array de Caracteres y Enteros por burbujeo de manera Descendente
 *
 * \param array recibe el array a ordenar con la cantidad de caracteres por elementos
 * \param arrayInt es el array de enteros por el cual se va a ordenar
 * \param limite recibe el tamaño del array
 * \return Devuelve 0 si pudo procesarle el ordenamiento exitosamente o -1 si hubo algun error.
 *
 */
int ordenarArraySwapStrIntDescByInt(char arrayChars[][QTY_CARACTERES],int arrayInt[],int limite)
{
	int i;
	int j;
	int retorno;;
	int flagSwap;
	char bufferChars[255];
	int bufferInt;
	if(	arrayChars != NULL &&
		arrayInt != NULL &&
		limite > 0)
	{
		retorno = EXIT_ERROR;
		do{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)// siempre el -1 al limite para que no compare con la nada misma
			{
				j = i+1;
				if(arrayInt[i]<arrayInt[j]) //strcmp=0.1=2/strcmp>0.2>1/strcmp<0.1>2
				{
					flagSwap = 1;
					strncpy(bufferChars, arrayChars[i],QTY_CARACTERES);
					strncpy(arrayChars[i],arrayChars[j],QTY_CARACTERES);
					strncpy(arrayChars[j],bufferChars,QTY_CARACTERES);
					bufferInt = arrayInt[i];
					arrayInt[i]=arrayInt[j];
					arrayInt[j] = bufferInt;
				}
			}

		}while(flagSwap);
		retorno = EXIT_SUCCESS;
	}
	return retorno;
}

/** \brief Obtiene y devuelve un caracter alfanumerico del ingreso del usuario
 *
 * \param resultado es la direccion de memoria donde almacenaremos el resultado de la funcion
 * \param mensaje es la consigna que recibira el usuario
 * \param mensajeError es el mensaje de error que recibira el usuario en caso de ingreso erroneo
 * \param minimo es el valor minimo aceptado por la funcion
 * \param maximo es el valor maximo aceptado por la funcion
 * \param reintentos es la cantidad de reintentos que tiene el usuario en caso de ingreso invalido
 * \return Devuelve 0 si se pudo recuperar un caracter o -1 si hubo algun error
 *
 */
char getChar(char *resultado,
			char *mensaje,
			char *mensajeError,
			char minimo,
			char maximo,
			int reintentos)
{
	int retorno = EXIT_ERROR;
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
				if(buffer == minimo || buffer == maximo)
				{
					retorno = EXIT_SUCCESS;
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


int isCharOrSpace(char buffer[])
{
    int retorno = EXIT_ERROR;
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
        retorno = EXIT_SUCCESS;
    }
    return retorno;
}

/*
int isFloat(float buffer)
{

}
*/
