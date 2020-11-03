#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	pFile = fopen(path,"r");
	if(pFile != NULL)
	{
		parser_EmployeeFromText(pFile,pArrayListEmployee);
	}
	fclose(pFile);
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

    FILE* pArchivo;
    int retorno = -1;
    pArchivo = fopen(path, "rb");
    if(pArchivo != NULL)
    {
        parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
        retorno = 0;
    }
    fclose(pArchivo);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int maxLen;
	int maxId;
	int i;
	int bIdPointer;
	char bId[8];
	char bNombre[128];
	char bHorasTrabajadas[8];
	char bSueldo[8];
	char bufferId[8];
	char bufferNombre[128];
	char bufferHorasTrabajadas[8];
	char bufferSueldo[8];
	Employee* aEmployee;

	if(pArrayListEmployee != NULL)
	{
		maxLen = ll_len(pArrayListEmployee);
		maxId = 0;
		for(i=0;i<maxLen;i++)
		{
			aEmployee = ll_get(pArrayListEmployee,i);
			employee_getId(aEmployee,&bIdPointer);
			if(bIdPointer > maxId)
			{
				maxId = bIdPointer;
			}
		}
			maxId++;
			sprintf(bId,"%d",maxId);
            strcpy(bufferId,bId);
		if(getNombreStr(bNombre, "Ingrese el nombre del Empleado: \n", "Ha ingresado un nombre invalido. Reintente\n",2,sizeof(bNombre),3)==0)
        {
            strcpy(bufferNombre,bNombre);
            if(getHsTrabajadasStr(bHorasTrabajadas, "Ingrese las nuevas horas trabajadas del empleado: \n","Ha ingresado un valor invalido, reingrese.\n",0,5,0,8760,3)==0)
            {
                strcpy(bufferHorasTrabajadas,bHorasTrabajadas);
                if(getSueldoStr(bSueldo, "Ingrese el nuevo sueldo del empleado: \n","Ha ingresado un valor invalido, reingrese.\n",1,sizeof(bSueldo),0,999999,3)==0)
                {
                    strcpy(bufferSueldo,bSueldo);
                    aEmployee = employee_newParametros(bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
                    ll_add(pArrayListEmployee, aEmployee);
                    printf("\nSe ingreso el nuevo empleado exitosamente.\n");
                }
            }
        }
		else
		{
			printf("No se pudo completar la carga del empleado, reintente.\n");
		}
	}
	return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int maxLen;
	int idEditar;
	int bIdStruct;
	char bId[8];
	char respuesta;
	char respuestaDos;
	char bNombre[128];
	char bSueldo[8];
	char bHorasTrabajadas[5];
	Employee* aEmployee;

	if(pArrayListEmployee != NULL)
	{
	    retorno = -1;
		respuesta = 'n';
		maxLen = ll_len(pArrayListEmployee);
		system("cls");
		printf("\n\n\t\t*** EDICION DE EMPLEADOS ***\n\n");
		controller_ListEmployee(pArrayListEmployee);
		if(getIdStr(bId,"\nIngrese el ID el Empleado a modificar: \n","Ha ingresado un ID invalido. Reintente\n",0,maxLen,3)==0)
		{
			system("cls");
			idEditar=atoi(bId);
			for(int i=0; i<maxLen;i++)
            {
                aEmployee = ll_get(pArrayListEmployee,i);
                employee_getId(aEmployee,&bIdStruct);
                if(idEditar==bIdStruct)
                {
                    aEmployee=ll_get(pArrayListEmployee,i);
                    break;
                }
            }
			printf("\nVa a editar el siguiente empleado:\n\n");
			controller_PrintEmployee(aEmployee);
            getChar(&respuesta, "Desea proceder? (s/n)\n\n", "La respuesta es invalida, reintente.\n",'n','s',3);
            if(respuesta == 's')
            {
                printf("\nQue campo desea editar?\n");
                printf("\tA- Nombre\n");
                printf("\tB- Hs Trabajadas\n");
                printf("\tC- Sueldo\n");

                if(getCharVarios(&respuestaDos,"Ingrese la opcion deseada.\n","Ha ingresesado una opcion invalida. Reintente.\n",'A','C',3)==0)
                {
                    switch(respuestaDos)
                    {
                        case 'A':
                                getNombreStr(bNombre, "Ingrese el nuevo nombre del Empleado: \n", "Ha ingresado un nombre invalido. Reintente\n",2,sizeof(bNombre),3);
                                employee_setNombre(aEmployee, bNombre);
                                break;
                        case 'B':
                                getHsTrabajadasStr(bHorasTrabajadas, "Ingrese las nuevas horas trabajadas del empleado: \n","Ha ingresado un valor invalido, reingrese.\n",2,sizeof(bHorasTrabajadas),1,8760,3);
                                employee_setHorasTrabajadas(aEmployee, bHorasTrabajadas);
                                break;
                        case 'C':
                                getSueldoStr(bSueldo, "Ingrese el nuevo sueldo del empleado: \n","Ha ingresado un valor invalido, reingrese.\n",1,sizeof(bSueldo),0,999999,3);
                                employee_setSueldo(aEmployee,bSueldo);
                                break;
                    }
                        retorno = 0;
                        printf("\nSe realizo la modificacion solicitada.\n\n");
                }

            }
            retorno = -1;
		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno;
	int maxLen;
	int idEditar;
	int bIdStruct;
	int bIdPointer;
    int maxId;
	char bId[12];
	char respuesta;
    int deleteId;

	Employee* aEmployee;
    retorno = -1;
    deleteId = -1;
    system("cls");
    printf("\n\n\t\t*** ELIMINAR EMPLEADOS ***\n\n");
	if(pArrayListEmployee != NULL)
	{
		respuesta = 'n';
		maxLen = ll_len(pArrayListEmployee);
		controller_ListEmployee(pArrayListEmployee);
		if(maxLen > 1)
        {
            for(int i=0;i<maxLen;i++)
            {
                aEmployee = ll_get(pArrayListEmployee,i);
                employee_getId(aEmployee,&bIdPointer);
                if(bIdPointer > maxId)
                {
                    maxId = bIdPointer;
                }
            }
            getIdStr(bId,"\n\n Ingrese el ID el Empleado a Eliminar: \t","Ha ingresado un ID invalido. Reintente\n",0,maxId,3);
			idEditar=atoi(bId);
			for(int i=0; i<maxLen;i++)
            {
                aEmployee = ll_get(pArrayListEmployee,i);
                employee_getId(aEmployee,&bIdStruct);
                if(idEditar==bIdStruct)
                {
                    aEmployee=ll_get(pArrayListEmployee,i);
                    deleteId = i;
                    break;
                }
            }
            printf("\nVa a borrar el siguiente empleado:\n");
            controller_PrintEmployee(aEmployee);
            getChar(&respuesta, "\nDesea proceder? (s/n)\t", "La respuesta es invalida, reintente.\n",'n','s',3);
            if(respuesta != 'n')
            {
                ll_remove(pArrayListEmployee,deleteId);
                printf("Se elimino el empleado solicitado.\n\n");
                retorno = 0;
            }
        }
        else if(maxLen == 1)
		{
		    aEmployee = ll_get(pArrayListEmployee,0);
			printf("\nVa a borrar el siguiente empleado:\n");
            controller_PrintEmployee(aEmployee);
            getChar(&respuesta, "\nDesea proceder? (s/n)\t", "La respuesta es invalida, reintente.\n",'n','s',3);
            if(respuesta != 'n')
            {
                ll_remove(pArrayListEmployee,0);
                printf("Se elimino el empleado solicitado. La lista se encuentra vacia.\n\n");
                retorno = 0;
            }
        }
        else
        {
            printf("\t\tNo hay empleados para eliminar.\n\n");
        }
            retorno = -1;
    }
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	int maxLen;
	Employee* aEmployee;

	if(pArrayListEmployee != NULL)
	{
		maxLen = ll_len(pArrayListEmployee);
		for(i=0;i<maxLen;i++)
		{
			aEmployee = ll_get(pArrayListEmployee,i);
			controller_PrintEmployee(aEmployee);
		}
	}
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee, employee_sortByName, 1);
        printf("\n\t\tSe ordenaron los empleados por nombre de manera ascendente exitosamente.\n\n");
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* aEmployee;

    int retorno = -1;
    int i;
    int idAux;
    char nombreAux[128];
    int sueldoAux;
    int horasAux;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        pArchivo = fopen(path, "w");
        if(pArchivo != NULL)
        {
            fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");
            for(i=0; i< ll_len(pArrayListEmployee); i++)
            {
                aEmployee = ll_get(pArrayListEmployee,i);
                employee_getId(aEmployee,&idAux);
                employee_getNombre(aEmployee,nombreAux);
                employee_getHorasTrabajadas(aEmployee,&horasAux);
                employee_getSueldo(aEmployee,&sueldoAux);
                fprintf(pArchivo,"%d,%s,%d,%d\n",idAux,nombreAux,sueldoAux,horasAux);
            }
            fclose(pArchivo);
            retorno = 0;
        }
        else
        {
            printf("\t\tNo se puede escribir el archivo.\n");
        }
    }
    return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* aEmployee;

    int retorno = -1;
    int i = 0;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        pArchivo = fopen(path,"wb");

        for(i=0; i< ll_len(pArrayListEmployee); i++)
        {
            aEmployee = (Employee*)ll_get(pArrayListEmployee,i);
            fwrite(aEmployee, sizeof(Employee),1,pArchivo);
        }
        fclose(pArchivo);
        retorno = 0;
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
void controller_PrintEmployee(void* this)
{
	int idStruct;
    char nombreStruct[128];
    int horasTrabajadasStruct;
    int sueldoStruct;

	if(this != NULL)
	{
		employee_getId(this, &idStruct);
		employee_getNombre(this, nombreStruct);
		employee_getHorasTrabajadas(this, &horasTrabajadasStruct);
		employee_getSueldo(this, &sueldoStruct);
		printf("ID: %6d - Nombre: %-20s - Horas Trabajadas: %6d - Sueldo: %9d\n",idStruct,nombreStruct,horasTrabajadasStruct,sueldoStruct);
    }
}
