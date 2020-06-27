#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
void employee_delete();

int employee_setId(Employee* this,char* id);
int employee_getId(Employee* this,int id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadasStr);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int isValidNombre(Employee* this, char* nombreStr);
int isValidId(Employee* this, char* id);
int isValidHsTrabajadas(Employee* this, char* horasTrabajadasStr);
int isValidSueldo(Employee* this, char* sueldo);

int getIdStr(char *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
int getNombreStr(char *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
int getHsTrabajadasStr(char *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
int getSueldoStr(char *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);

int employee_sortByName(void* dato1,void* dato2);
int findPushEmployeeByName(LinkedList* this);
int controller_pushEmployee(LinkedList* pArrayListEmployee,int auxId, Employee* replaceEmployee);
int findDeleteEmployeeByName(LinkedList* this);

#endif // EMPLOYEE_H_INCLUDED
