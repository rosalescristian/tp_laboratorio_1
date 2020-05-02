/*
 * empleado.h
 *
 *  Created on: 30 Apr. 2020
 *  Author: Cristian Rosales
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

#define QTY_EMPLEADOS 1000
#define QTY_CARACTERES 51
#define EXIT_ERROR -1
#define EXIT_SUCCESS 0

struct sEmployee
{
	int id;
	char name[QTY_CARACTERES];
	char lastName[QTY_CARACTERES];
	float salary;
	int sector;
	int isEmpty;
};

int sueldosSobrePromedio(struct sEmployee *aEmpleado,int limite,int *pResultado, float promedioSalario);
int promedioArrayStruct(struct sEmployee *aEmpleado,int limite,float *pResultado, float *sueldoTotal);
int imprimirArrayEmpleados(struct sEmployee *aEmpleado, int cantidad);
int ordenarStructEmpleadosByNameOrLastName(struct sEmployee *aEmpleado, int cantidad);
int initLugarLibreEmpleado(struct sEmployee *aEmpleado, int cantidad);
int buscarLugarLibreEmpleado(struct sEmployee *aEmpleado, int cantidad);
int buscarEmpleadosPorId(struct sEmployee *aEmpleado, int cantidad, int id);
int altaEmpleadosPorId(struct sEmployee *aEmpleado, int cantidad, struct sEmployee empleado);
int modificarEmpleadosPorId(struct sEmployee *aEmpleado, int cantidad, struct sEmployee empleado);
int bajaEmpleadosPorId(struct sEmployee *aEmpleado, int cantidad);
int altaForzadaEmpleados(struct sEmployee *aEmpleado, int cantidad);
int getEmpleadoStr( struct sEmployee *aEmpleado,
                    struct sEmployee bEmpleado,
					int limite,
					int reintentos,
					int id);
int getNameEmpleado(char *pResultado,
                    char *pMensaje,
                    char *pMensajeError,
                    int minimo,
                    int maximo,
                    int reintentos);
int getLastNameEmpleado(char *pResultado,
                        char *pMensaje,
                        char *pMensajeError,
                        int minimo,
                        int maximo,
                        int reintentos);
int getSalary(float *resultado,
			  char *mensaje,
			  char *mensajeError,
			  float minimo,
			  float maximo,
			  float reintentos);
int getSector(  int *pResultado,
                char *pMensaje,
                char *pMensajeError,
                int minimo,
                int maximo,
                int reintentos);
#endif /* EMPLEADO_H_ */
