#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new(); // OK
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo); //OK
void employee_delete(); // OK

int employee_setId(Employee* this,char* id); // OK
int employee_getId(Employee* this,int id); // OK

int employee_setNombre(Employee* this,char* nombre); // OK
int employee_getNombre(Employee* this,char* nombre); // OK

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadasStr); //OK
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas); //OK

int employee_setSueldo(Employee* this,char* sueldo); //OK
int employee_getSueldo(Employee* this,int* sueldo); //OK

int isValidNombre(Employee* this, char* nombreStr); //OK
int isValidId(Employee* this, char* id); //OK
int isValidHsTrabajadas(Employee* this, char* horasTrabajadasStr); //OK
int isValidSueldo(Employee* this, char* sueldo); //OK

int getIdStr(char *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos); // OK
int getNombreStr(char *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos); //OK
int getHsTrabajadasStr(char *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos); //OK
int getSueldoStr(char *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos); //OK

int employee_sortByName(void* dato1,void* dato2); // OK

#endif // EMPLOYEE_H_INCLUDED
