/*
 * utn.h
 *
 * Created on: 30 Apr. 2020
 * Author: Cristian Rosales
 */

#ifndef UTN_H_
#define UTN_H_

#define QTY_EMPLEADOS 1000
#define QTY_CARACTERES 51
#define EXIT_ERROR -1
#define EXIT_SUCCESS 0
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

int funcionMenu(void);
/* Funciones con INT */
int initArrayInt(int array[],int limite,int valor);
int imprimeArrayInt(int array[],int limite);
int getArrayInt(	int array[],
					int limite,
					char *mensaje,
					char *mensajeError,
					int minimo,
					int maximo,
					int reintentos);
int maximoArrayInt(int array[],int limite,int *pResultado);
int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos);
int ordenarArrayInt(int array[],int limite);
int ordenarArraySwapIntAsc(int array[] ,int limite);
int ordenarArraySwapIntDes(int array[] ,int limite);
int insertionSortArrayInt(int array[], int limite);

/* Funciones con Array de Strings */
int getString(char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos);
int initArrayStr(char array[][QTY_CARACTERES],int limite,int valor);
int imprimeArrayStr(char array[][QTY_CARACTERES], int limite);
int getArrayStr(	char array[][QTY_CARACTERES],
					int limite,
					char *mensaje,
					char *mensajeError,
					int minimo,
					int maximo,
					int reintentos);
int ordenarArraySwapStrAsc(char array[][QTY_CARACTERES],int limite);
int ordenarArraySwapStrDesc(char array[][QTY_CARACTERES],int limite);

/*Funciones con Array de Strings+Array INT*/
int ordenarArraySwapStrIntAscByInt(char arrayChars[][QTY_CARACTERES],int arrayInt[],int limite);
int ordenarArraySwapStrIntDescByInt(char arrayChars[][QTY_CARACTERES],int arrayInt[],int limite);
char getChar(char *resultado,
			char *mensaje,
			char *mensajeError,
			char minimo,
			char maximo,
			int reintentos);
int isCharOrSpace(char buffer[]);
#endif /* UTN_H_ */
