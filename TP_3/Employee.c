#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Crea un nuevo elemento Empleado
 *
 * \param
 * \param
 * \return Devuelve el puntero al nuevo elemento
 *
 */
Employee* employee_new()
{
	return malloc(sizeof(Employee));
}

/** \brief Configura el nuevo empleado con los valores de las variables
 *
 * \param idStr recibe el id del empleado en formatos tring
 * \param nombreStr recibe el nombre del empleado en formatos tring
 * \param horasTrabajadasStr recibe las horas trabajadas del empleado en formatos tring
 * \param sueldo recibe el sueldo del empleado en formatos tring
 * \return Devuelve la direccion de memoria al elemento configurado en la LinkedList
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
    Employee* retorno;
	retorno = NULL;
	Employee* this;
	this = employee_new();
	if(this != NULL)
	{
		if(		employee_setId(this, idStr) == 0 &&
                employee_setNombre(this,nombreStr) == 0 &&
				employee_setHorasTrabajadas(this,horasTrabajadasStr) == 0 &&
                employee_setSueldo(this,sueldo) == 0)
            {
                retorno = this;
            }
            else
            {
                employee_delete(this);
            }
	}
	return retorno;
}

/** \brief Libera el espacio en memoria de un empleado
 *
 * \param this es la direccion de memoria del empleado a borrar
 * \return void
 *
 */
void employee_delete(Employee* this)
{
	free(this);
}

/** \brief Configura el id de un empleado
 *
 * \param this es la direccion de memoria de un empleado
 * \param id es el id que se configurara al empleado recibido
 * \return
 *
 */
int employee_setId(Employee* this,char* id)
{
    int retorno;
	int bId;
	retorno = -1;
	if(this!=NULL && isValidId(this,id))
	{
		bId=atoi(id);
		this->id = bId;
		retorno = 0;
	}
	return retorno;
}

/** \brief Recupera el id de un empleado en la lista
 *
 * \param this es la direccion de memoria del elemento
 * \param id es el campo donde se almacenara el dato recuperado
 * \return -1 si hubo algun error, 0 si fue exitoso
 *
 */
int employee_getId(Employee* this,int id)
{
	int retorno;
	retorno = -1;
	if(this != NULL)
	{
	    id=this->id;
        retorno = 0;
    }
	return retorno;
}

/** \brief Configura el nombre de un empleado
 *
 * \param this es la direccion de memoria de un empleado
 * \param nombre es el nombre que se configurara al empleado recibido
 * \return
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno;
	retorno = -1;
	if(this!=NULL && isValidNombre(this,nombre))
	{
		strncpy(this->nombre,nombre,sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}

/** \brief Recupero el nombre de un elemento existente
 *
 * \param this es la direccion de memoria del elemento
 * \param nombre donde almaceno el valor que busco
 * \return -1 si hubo un error, 0 si fue exitoso
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno;
	retorno = -1;
	if(this != NULL && nombre != NULL)
	{
	    strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
	return retorno;
}

/** \brief Configura las hs trabajadas de un empleado
 *
 * \param this es la direccion de memoria de un empleado
 * \param horasTrabajadasStr es el valor que se configurara al empleado recibido
 * \return
 *
 */
int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadasStr)
{
	int retorno;
	int bHsTrabajadas;
	retorno = -1;
	if(this != NULL && isValidHsTrabajadas(this,horasTrabajadasStr))
	{
        bHsTrabajadas=atoi(horasTrabajadasStr);
		this->horasTrabajadas = bHsTrabajadas;
		retorno = 0;
	}
	return retorno;
}

/** \brief Recupero el valor de Hs trabajadas de un elemento existente
 *
 * \param this es la direccion de memoria del elemento
 * \param horasTrabajadas donde almaceno el valor que busco
 * \return -1 si hubo un error, 0 si fue exitoso
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno;
	retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
        horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
	return retorno;
}

/** \brief Configura el sueldo de un empleado
 *
 * \param this es la direccion de memoria de un empleado
 * \param sueldo es el valor que se configurara al empleado recibido
 * \return
 *
 */
int employee_setSueldo(Employee* this,char* sueldo)
{
	int retorno;
	int bSueldo;
	retorno = -1;
	if(this != NULL && isValidSueldo(this,sueldo))
	{
        bSueldo=atoi(sueldo);
		this->sueldo = bSueldo;
		retorno = 0;
	}
	return retorno;
}

/** \brief Recupero el sueldo de un elemento existente
 *
 * \param this es la direccion de memoria del elemento
 * \param sueldo donde almaceno el valor que busco
 * \return -1 si hubo un error, 0 si fue exitoso
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno;
	retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
        sueldo = this->sueldo;
        retorno = 0;
    }
	return retorno;
}

/** \brief Valida que el valor recibido es un nombre valido
 *
 * \param this es la direccion de memoria de un empleado
 * \param nombreStr es el valor a analizar
 * \return
 *
 */
int isValidNombre(Employee* this, char* nombreStr)
{
    int retorno;
	if(this != NULL && nombreStr != NULL)
	{
		retorno = -1;
        if(esAlfaNumerico(nombreStr))
        {
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Valida que el valor recibido es un ID valido
 *
 * \param this es la direccion de memoria de un empleado
 * \param id es el valor a analizar
 * \return
 *
 */
int isValidId(Employee* this, char* id)
{
    int retorno;
	if(this != NULL && id != NULL)
	{
		retorno = -1;
        if(esNumerico(id))
        {
            retorno = 0;
        }
    }
	return retorno;
}

/** \brief Valida que el valor recibido son horas validas
 *
 * \param this es la direccion de memoria de un empleado
 * \param horasTrabajadasStr es el valor a analizar
 * \return
 *
 */
int isValidHsTrabajadas(Employee* this, char* horasTrabajadasStr)
{
    int retorno;
	if(this != NULL && horasTrabajadasStr != NULL)
	{
		retorno = -1;
        if(esNumerico(horasTrabajadasStr))
        {
            retorno = 0;
        }
	}
    return retorno;
}

/** \brief Valida que el valor recibido es un sueldo valido
 *
 * \param this es la direccion de memoria de un empleado
 * \param sueldo es el valor a analizar
 * \return
 *
 */
int isValidSueldo(Employee* this, char* sueldo)
{
    int retorno;
	if(this != NULL && sueldo != NULL)
	{
		retorno = -1;
        if(esNumerico(sueldo))
        {
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Capturo del usuario el campo ID del elemento Empleado dentro de la estructura
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
int getIdStr(char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer[6];

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
                if((esNumerico(buffer)==0) && (atoi(buffer)>= minimo) && (atoi(buffer)<=maximo))
                {
                    strncpy(pResultado,buffer,strlen(buffer));
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
int getNombreStr(char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer[120];

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

				if(isCharOrSpace(buffer)==0)
                {
                    strncpy(pResultado,buffer,maximo+1);
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

/** \brief Capturo del usuario el campo horas trabajadas del elemento Empleado dentro de la estructura
 *
 * \param bNombre es la direccion de memoria donde almacenaremos el resultado de la consulta
 * \param pMensaje es la consigna que le brindaremos al usuario
 * \param pMensajeError es el mensaje de error que se le dara al usuario en caso de un ingreso erroneo
 * \param minimo es el valor minimo aceptado por la funcion
 * \param maximo es el valor maximo aceptado por la funcion
 * \param reintentos es la cantidad de reintentos que tendra el usuario en caso de un ingreso erroneo
 * \return Devuelve 0 si pudo capturar el dato o -1 si hubo algun error
 *
 */
int getHsTrabajadasStr(char *bNombre,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer[7];

	if(		bNombre != NULL &&
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
                if((esNumerico(buffer)==0) && (atoi(buffer)>= minimo) && (atoi(buffer)<=maximo))
                {
                    strncpy(bNombre,buffer,strlen(buffer));
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

/** \brief Capturo del usuario el campo sueldo del elemento Empleado dentro de la estructura
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
int getSueldoStr(char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer[7];

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
                if((esNumerico(buffer)==0) && (atoi(buffer)>= minimo) && (atoi(buffer)<=maximo))
                {
                    strcpy(pResultado,buffer);
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

/** \brief Ordena los empleados por Nombre de Manera Ascendente
 *
 * \param dato1 es el puntero a un elemento de la LinkedList
 * \param dato1 es el puntero a un elemento de la LinkedList
 * \return Devuelve 0 si los nombres son iguales, 1 si Nombre A > Nombre B o -1 si Nombre A < Nombre B; -2 si hubo un error
 *
 */
int employee_sortByName(void* dato1,void* dato2)
{

    Employee* a = (Employee*) dato1;
    Employee* b = (Employee*) dato2;
    int retorno = -2;

    if(strcmp(a->nombre, b->nombre) == 0)
    {
        retorno = 0;
    }
    else if(strcmp(a->nombre, b->nombre) > 0)
    {
        retorno = 1;
    }
    else
    {
        retorno = -1;
    }
    return retorno;
}
