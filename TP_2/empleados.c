/*
 * empleado.c
 *
 *  Created on: 30 Apr. 2020
 *  Author: Cristian Rosales
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleados.h"

#define QTY_EMPLEADOS 1000
#define QTY_CARACTERES 51
#define EXIT_ERROR -1
#define EXIT_SUCCESS 0

/** \brief Cargo datos en una estructura de manera masiva
 *
 * \param aArray recibo la estructura a cargar
 * \param cantidad recibe la cantidad de datos a cargar
 * \return Devuelve 0 si la carga fue exitosa, -1 si hubo algun error.
 *
 */
int altaForzadaEmpleados(struct sEmployee *aArray, int cantidad)
{
	int i;
	int id[] ={1,5,6,7,8};
	char name[][QTY_CARACTERES] = {"Juan","Pedro","Cristian","Eva","Jose"};
	char lastName[][QTY_CARACTERES] = {"Gomez","Gonzalez","Ruiz","Sanchez","Perez"};
    float salary[] = {25000,35000,45000,15000,5000};
	int sector[] = {1,10,5,55,99};
	int retorno;

    retorno = EXIT_ERROR;
	for(i=0;i<5;i++)
	{
		aArray[i].isEmpty = 0;
		aArray[i].id = id[i];
		strncpy(aArray[i].name,name[i],QTY_CARACTERES);
		strncpy(aArray[i].lastName,lastName[i],QTY_CARACTERES);
		aArray[i].salary = salary[i];
		aArray[i].sector = sector[i];
	}
	retorno = EXIT_SUCCESS;
	return retorno;
}

/** \brief Imprimo la estructura de Empleados
 *
 * \param aEmpleados recibe la direccion de memoria donde se almaceno la estructura a imprimir
 * \param cantidad recibe la cantidad de elementos en la estructura a imprimir
 * \return Devuelve 0 si pudo mostrar los elementos por pantalla, -1 si hubo algun error
 *
 */
int imprimirArrayEmpleados(struct sEmployee *aEmpleados, int cantidad)
{
	int i;
	int retorno = -1;
	if(aEmpleados != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			if(aEmpleados[i].isEmpty == 0)
			{
				printf("Id: %d - Nombre: %s - Apellido: %s - Salario: %.2f - Sector: %d\n", aEmpleados[i].id,aEmpleados[i].name,aEmpleados[i].lastName,aEmpleados[i].salary,aEmpleados[i].sector);
			}

		}
	}
	return retorno;
}

/** \brief Imprime un array de caracteres
 *
 * \param aNombres recibe el array a imprimir
 * \param cantidad recibe la cantidad de elementos en el array
 * \return Devuelve 0 si pudo imprimir los valores, -1 si hubo algun error
 *
 */
int imprimirArrayString(char aNombres[][QTY_CARACTERES], int cantidad){
	int i;
	int retorno = -1;
	if(aNombres != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			printf("Nombre: %s \n",aNombres[i]);
		}
	}
	return retorno;
}

/** \brief Ordena los elementos de la estructura por Nombre o Apellido
 *
 * \param aEmpleado recibe la estructura a ordenar
 * \param cantidad recibe la cantidad de elementos en la estructura
 * \return Devuelve 0 si pudo ordenar la estructura o -1 si hubo algun error
 *
 */
int ordenarStructEmpleadosByNameOrLastName(struct sEmployee *aEmpleado, int cantidad)
{
	int i;
	int j;
	int retorno = EXIT_ERROR;
	struct sEmployee bEmpleado;
	int fSwap;
	if(aEmpleado != NULL && cantidad>0)
	{
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				j = i+1;
				if(strncmp(aEmpleado[i].lastName,aEmpleado[j].lastName,QTY_CARACTERES)>0)
				{
					fSwap = 1;
					bEmpleado = aEmpleado[i];
					aEmpleado[i]=aEmpleado[j];
					aEmpleado[j]=bEmpleado;
				}
				else if(strncmp(aEmpleado[i].lastName,aEmpleado[j].lastName,QTY_CARACTERES)==0)
				{
					if(aEmpleado[i].sector > aEmpleado[j].sector)
					{
						fSwap = 1;
						bEmpleado = aEmpleado[i];
						aEmpleado[i]=aEmpleado[j];
						aEmpleado[j]=bEmpleado;
					}
				}
			}
			retorno = EXIT_SUCCESS;
		}while(fSwap);
	}
	return retorno;
}

/** \brief Inicializa la estructura, setea todos los elementos como Empty
 *
 * \param aEmpleado recibe la direccion de memoria donde se encuentra la estructura a inicializar
 * \param cantidad recibe la cantidad de elementos de la estructura
 * \return Devuelve 0 si pudo iniciarlizarse, -1 si hubo algun error
 *
 */
int initLugarLibreEmpleado(struct sEmployee *aEmpleado, int cantidad)
{
	int retorno;
	int i;
	if(aEmpleado != NULL && cantidad >0)
	{
		retorno = EXIT_ERROR;
		for(i=0;i<cantidad;i++)
		{
			aEmpleado[i].isEmpty=1;
		}
		retorno = EXIT_SUCCESS;
	}

	return retorno;

}

/** \brief Recorre el array de estructura y recupera el lugar libre
 *
 * \param aArray recibe el array de estructura a recorrer
 * \param cantidad recibe la cantidad de elementos maximos en el array
 * \return Devuelve la posicion libre en el array o -1 si hubo algun error
 *
 */
int buscarLugarLibreEmpleado(struct sEmployee *aArray, int cantidad)
{
	int index;
	int i;
	int retorno;

	if(aArray != NULL && cantidad > 0)
	{
		index = EXIT_ERROR;
		retorno=EXIT_ERROR;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].isEmpty == 1)
			{
				index=i;
				break;
			}
		}
		retorno = index;
	}
	return retorno;
}

/** \brief Da de alta un nuevo elemento en el array de estructura
 *
 * \param aArray recibe el array de estructura donde se ingresara el valor nuevo
 * \param cantidad recibe el valor de elementos del array
 * \param empleado recibe el nuevo elemento a ingresar en el array
 * \return Devuelve 0 si pudo ingresar el nuevo elemento, -1 si hubo algun error
 *
 */
int altaEmpleadosPorId(struct sEmployee *aArray, int cantidad, struct sEmployee empleado)
{
	int retorno;
	int bLugarLibre;

	if(aArray != NULL && cantidad > 0)
	{
		retorno = EXIT_ERROR;
		bLugarLibre = buscarLugarLibreEmpleado(aArray, QTY_EMPLEADOS);
		if(bLugarLibre != -1)
			{
				aArray[bLugarLibre]=empleado;
				retorno = EXIT_SUCCESS;
			}
	}
	return retorno;
}

/** \brief Recorre el array de estructura y devuelve el valor de determinada posicion
 *
 * \param aArray recibe la direccion de memoria del array a recorrer
 * \param cantidad recibe el tamaño del array a recorrer
 * \param id recibe el id a buscar en el array
 * \return Devuelve el id buscado si lo pudo encontrar o -1 si hubo algun error
 *
 */
int buscarEmpleadosPorId(struct sEmployee *aArray, int cantidad, int id)
{
	int i;
	int retorno;
	if(aArray != NULL && cantidad>0 && id > 0)
	{
		retorno  = EXIT_ERROR;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].id == id)
			{
				retorno = id;
				break;
			}

		}
	}
	return retorno;
}

/** \brief Da de beja un elemento en el array de estructura
 *
 * \param aArray recibe la direccion de memoria donde se encuentra el array de estructura
 * \param cantidad recibe el tamaño del array a recorrer
 * \return Devuelve 0 si se pudo procesar la baja o -1 si hubo algun error.
 *
 */
int bajaEmpleadosPorId(struct sEmployee *aArray, int cantidad)
{
	int i;
	int retorno;
	int idEditable;
	char seguir;

	if(aArray != NULL && cantidad>0)
	{
	    system("cls");
        imprimirArrayEmpleados(aArray, cantidad);
        retorno = EXIT_ERROR;
        seguir = 'N';
		if(getInt(&idEditable,"\nIngrese el id a dar de baja: \n","Ha seleccionado un id no valida. Reintente\n",0,cantidad-1,3)==0)
        {
            for(i=0;i<cantidad;i++)
            {
                if(aArray[i].id == idEditable)
                {
                    system("cls");
                    printf("Va a eliminar el siguiente empleado:\n\tId: %d - Nombre: %s - Apellido: %s - Salario: %.2f - Sector: %d\n", aArray[i].id,aArray[i].name,aArray[i].lastName,aArray[i].salary,aArray[i].sector);
                    getChar(&seguir, "Desea proceder(S/N): \n", "La respuesta es invalida, reintente.\n",'N','S',3);
                    if(seguir == 'S')
                    {
                        aArray[i].isEmpty=1;
                        retorno = EXIT_SUCCESS;
                        break;
                    }

                }
            }
        }

	}
	return retorno;
}

/** \brief Modifica los datos de un elemento del array de estructura
 *
 * \param aEmpleado recibe la direccion de memoria donde se encuentra almacenado el elemento a modificar
 * \param cantidad recibe el tamaño del array
 * \param recibe los datos a ingresar
 * \return Devuelve 0 si pudo hacer la modificacion o -1 si hubo algun error
 *
 */
int modificarEmpleadosPorId(struct sEmployee *aEmpleado, int cantidad, struct sEmployee empleado)
{
	char bNombre[QTY_CARACTERES];
	char bLastName[QTY_CARACTERES];
	char seguir;
	float bSalary;
	int bSector;
    int retorno;
    int idEditable;
    int campoEditable;

do{
    system("cls");
    imprimirArrayEmpleados(aEmpleado, QTY_EMPLEADOS);
    retorno = EXIT_ERROR;
    seguir = 'N';

    if(getInt(&idEditable,"\nIngrese el id a editar: \n\n","Ha seleccionado una opcion no valida. Reintente\n\n",0,QTY_EMPLEADOS-1,3)==0)
    {
        empleado=aEmpleado[idEditable];
        printf("1.Nombre: %s\t 2.Apellido: %s\t 3.Salario: %.2f\t 4.Sector: %d\t\n",empleado.name,empleado.lastName,empleado.salary,empleado.sector);
        if(getInt(&campoEditable,"Ingrese el campo a editar (1/4)\n\n","Ha elegido un campo invalido, reintente.\n",1,4,3)==0)
        {
            switch(campoEditable)
            {
                case 1:
                    printf("Va a editar el Nombre: %s\n", empleado.name);
                    if(getNameEmpleado(bNombre,"Ingrese el nuevo Nombre: \n", "Ha ingresado un nombre Invalido. Reintente\n",2,sizeof(bNombre),3)==0)
                    {
                        strncpy(empleado.name,bNombre,QTY_CARACTERES);
                        printf("El nuevo Nombre es: %s\n", empleado.name);
                        getChar(&seguir, "Desea modificar algun otro empleado?(S/N)", "La respuesta es invalida, reintente.",'N','S',3);

                    }
                    break;
                case 2:
                    printf("Va a editar el Apellido: %s\n", empleado.lastName);
                    if(getLastNameEmpleado(bLastName,"Ingrese el nuevo Apellido: \n", "Ha ingresado un apellido Invalido. Reintente\n",2,QTY_CARACTERES,3)==0)
                    {
                        strncpy(empleado.lastName,bLastName,QTY_CARACTERES);
                        printf("El nuevo Apellido es: %s\n", empleado.lastName);
                        getChar(&seguir, "Desea modificar algun otro empleado?(S/N)", "La respuesta es invalida, reintente.",'N','S',3);

                    }
                    break;
                case 3:
                    printf("Va a editar el Salario: %.2f\n", empleado.salary);
                    if(getSalary(&bSalary,"Ingrese el nuevo Salario: \n", "Ha ingresado un salario Invalido. Reintente\n",0,999999999,3)==0)
                    {
                        empleado.salary=bSalary;
                        printf("El nuevo Salario es: %.2f\n", empleado.salary);
                        getChar(&seguir, "Desea modificar algun otro empleado?(S/N)", "La respuesta es invalida, reintente.",'N','S',3);

                    }
                    break;
                case 4:
                    printf("Va a editar el Sector: %d\n", empleado.sector);
                    if(getSector(&bSector,"Ingrese el nuevo Sector: \n", "Ha ingresado un sector Invalido. Reintente\n",1,999999999,3)==0)
                    {
                        empleado.sector=bSector;
                        printf("El nuevo Sector es: %d\n", empleado.sector);
                        getChar(&seguir, "Desea modificar algun otro empleado?(S/N)", "La respuesta es invalida, reintente.",'N','S',3);

                    }
                    break;
            }

        }

    }
    aEmpleado[idEditable]=empleado;
}while(seguir == 'S');
    retorno = EXIT_SUCCESS;
return retorno;
}

/** \brief Recupero los valores de cadena de caracteres para almacenar en la estructura
 *
 * \param aEmpleado recibe la direccion de memoria donde se encuentra almacenada la estructura
 * \param bEmpledao recibe un item dentro de la estructura
 * \param limite recibe el valor maximo de elementos de la estructura
 * \param reintentos es la cantidad de intentos que tendra el usuario en caso de cometer algun errot
 * \param id es la posicion de la estructura donde ingresaremos los valores que recuperemos
 * \return Devuelve 0 si pudo tomar un valor o -1 si hubo algun error
 *
 */
int getEmpleadoStr(	struct sEmployee *aEmpleado,
                   struct sEmployee bEmpleado,
					int limite,
					int reintentos,
					int id)
{
	int retorno;
	char bNombre[QTY_CARACTERES];
	char bLastName[QTY_CARACTERES];
	float bSalary;
	int bSector;
	int cEmpleado;

	if(		aEmpleado != NULL &&
            limite > 0 &&
			reintentos > 0 &&
			id != -1)
	{
		do
		{
		    retorno = EXIT_ERROR;
		    cEmpleado = -1;

		    if(getNameEmpleado(bNombre, "\nIngrese el nombre del empleado: ", "Ha ingresado un nombre invalido, reintente.", 2, sizeof(bNombre),3)==0)
            {
                strncpy(bEmpleado.name,bNombre,QTY_CARACTERES);
            }
            if(getLastNameEmpleado(bLastName, "\nIngrese el apellido del empleado: ", "Ha ingresado un apellido invalido, reintente.", 2, sizeof(bLastName),3)==0)
            {
                strncpy(bEmpleado.lastName,bLastName,QTY_CARACTERES);
            }
            if(getSalary(&bSalary, "\nIngrese el sueldo del empleado:", "Ha ingresado un valor invalido, reintente.",0,99999999999,3)==0)
            {
                bEmpleado.salary=bSalary;
            }
            if(getSector(&bSector, "\nIngrese el sector del empleado: ", "Ha ingresado un sector invalido, reintente", 0,100,3)==0)
            {
                bEmpleado.sector=bSector;
            }
            bEmpleado.id=id;
            bEmpleado.isEmpty=0;
            cEmpleado = 0;
        }while(cEmpleado != 0);

        altaEmpleadosPorId(aEmpleado,QTY_EMPLEADOS,bEmpleado);

		retorno = EXIT_SUCCESS;
	}
	return retorno;
}

/** \brief Capturo del usuario el campo nombre del elemento Empleado dentro de la estructura
 *
 * \param bName es la direccion de memoria donde almacenaremos el resultado de la consulta
 * \param pMensaje es la consigna que le brindaremos al usuario
 * \param pMensajeError es el mensaje de error que se le dara al usuario en caso de un ingreso erroneo
 * \param minimo es el valor minimo aceptado por la funcion
 * \param maximo es el valor maximo aceptado por la funcion
 * \param reintentos es la cantidad de reintentos que tendra el usuario en caso de un ingreso erroneo
 * \return Devuelve 0 si pudo capturar el dato o -1 si hubo algun error
 *
 */
int getNameEmpleado(    char *bName,
                        char *pMensaje,
                        char *pMensajeError,
                        int minimo,
                        int maximo,
                        int reintentos)
{
	int retorno = EXIT_ERROR;
	char buffer[255];

	if(		bName != NULL &&
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
				strncpy(bName,buffer,maximo+1);
				retorno = EXIT_SUCCESS;
				break;
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/** \brief Capturo del usuario el campo apellido del elemento Empleado dentro de la estructura
 *
 * \param bLastName es la direccion de memoria donde almacenaremos el resultado de la consulta
 * \param pMensaje es la consigna que le brindaremos al usuario
 * \param pMensajeError es el mensaje de error que se le dara al usuario en caso de un ingreso erroneo
 * \param minimo es el valor minimo aceptado por la funcion
 * \param maximo es el valor maximo aceptado por la funcion
 * \param reintentos es la cantidad de reintentos que tendra el usuario en caso de un ingreso erroneo
 * \return Devuelve 0 si pudo capturar el dato o -1 si hubo algun error
 *
 */
int getLastNameEmpleado(char *bLastName,
                        char *pMensaje,
                        char *pMensajeError,
                        int minimo,
                        int maximo,
                        int reintentos)
{
	int retorno = EXIT_ERROR;
	char buffer[255];

	if(		bLastName != NULL &&
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
				strncpy(bLastName,buffer,maximo+1);
				retorno = EXIT_SUCCESS;
				break;
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/** \brief Capturo del usuario el campo salario del elemento Empleado dentro de la estructura
 *
 * \param resultado es la direccion de memoria donde almacenaremos el resultado de la consulta
 * \param mensaje es la consigna que le brindaremos al usuario
 * \param mensajeError es el mensaje de error que se le dara al usuario en caso de un ingreso erroneo
 * \param minimo es el valor minimo aceptado por la funcion
 * \param maximo es el valor maximo aceptado por la funcion
 * \param reintentos es la cantidad de reintentos que tendra el usuario en caso de un ingreso erroneo
 * \return Devuelve 0 si pudo capturar el dato o -1 si hubo algun error
 *
 */
int getSalary(float *resultado,
			  char *mensaje,
			  char *mensajeError,
			  float minimo,
			  float maximo,
			  float reintentos)
{
int retorno = EXIT_ERROR;
float buffer;
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
		if(scanf("%f",&buffer)==1)
		{
			if(buffer >= minimo && buffer <= maximo)
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

/** \brief Capturo del usuario el campo sector del elemento Empleado dentro de la estructura
 *
 * \param pResultado es la direccion de memoria donde almacenaremos el resultado de la consulta
 * \param pMensaje es la consigna que le brindaremos al usuario
 * \param pMensajeError es el mensaje de error que se le dara al usuario en caso de un ingreso erroneo
 * \param minimo es el valor minimo aceptado por la funcion
 * \param maximo es el valor maximo aceptado por la funcion
 * \param reintentos es la cantidad de reintentos que tendra el usuario en caso de un ingreso erroneo
 * \return Devuelve 0 si pudo capturar el dato o -1 si hubo algun error
 *
 */
int getSector(  int *pResultado, // Recupera un valor Int
                char *pMensaje,
                char *pMensajeError,
                int minimo,
                int maximo,
                int reintentos)
{
	int retorno = EXIT_ERROR;
	int buffer;
	if(	pResultado != NULL &&
		pMensaje	!= NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",pMensaje);
            fflush(stdin);
			if(scanf("%d",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/** \brief Calcula el promedio de Salarios de la estructura
 *
 * \param aEmpleado recibe la direccion de memoria donde se almacena la estructura
 * \param limite recibe el valor de elementos dentro de la estructura
 * \param pResultado es la direccion de memoria donde almacenaremos el resultado de la funcion
 * \param sueldoTotal es la direccion de memoria donde almacenaremos la suma de salarios
 * \return Devuelve 0 si pudo calcular el promedio, -1 si hubo algun error
 *
 */
int promedioArrayStruct(struct sEmployee *aEmpleado,int limite,float *pResultado, float *sueldoTotal)
{
    int i;
    int retorno;
    int contador;
    float acumulador;
    float promedio;
    if( aEmpleado != NULL &&
        limite > 0)
    {
        retorno = EXIT_ERROR;
        contador = 0;
        acumulador = 0;

        for(i=0;i<limite;i++)
        {
            if(aEmpleado[i].isEmpty != 1)
            {
                contador++;
                acumulador = aEmpleado[i].salary+acumulador;
            }
        }
        promedio = acumulador/contador;
        *pResultado = promedio;
        *sueldoTotal = acumulador;
        retorno = EXIT_SUCCESS;
    }
    return retorno;
}

/** \brief Cuenta cuantos empleados tienen un sueldo por encima del promedio
 *
 * \param aEmpleado recibe la direccion de memoria de la estructura
 * \param limite recibe la cantidad de elementos maximos dentro de la estructura
 * \param pResultado es la direccion de memoria donde almacenaremos el calculo de la funcion
 * \param promedioSalario es el valor donde recibimos cual es el promedio contra el que vamos a comparar
 * \return Devuelve 0 si pudo hacer el calculo, -1 si hubo algun error
 *
 */
int sueldosSobrePromedio(struct sEmployee *aEmpleado,int limite,int *pResultado, float promedioSalario)
{
    int i;
    int retorno;
    int contador;

    if(aEmpleado != NULL &&
       limite > 0 &&
       pResultado != NULL)
    {
        retorno = EXIT_ERROR;
        contador = 0;
        for(i=0;i<limite;i++)
        {
            if(aEmpleado[i].isEmpty != 1 && aEmpleado[i].salary > promedioSalario)
            {
                contador++;
            }
        }
        *pResultado = contador;
        retorno = EXIT_SUCCESS;


    }
    return retorno;
}
