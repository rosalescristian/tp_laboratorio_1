#ifndef UTN_H_
#define UTN_H_

#define QTY_CLIENTS 100
#define QTY_PEDIDOS 1000
#define QTY_CARACTERES 56
#define QTY_CHAR_CUIT 13
#define EXIT_ERROR -1
#define EXIT_SUCCESS 0
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

int funcionMenu(void);
int funcionMenuInformes(void);

//Funciones con INT
int initArrayInt(int array[],int limite,int valor); // Iniciliaza el Array en 0s(SI NO ES NECESARIO NO USAR)
int imprimeArrayInt(int array[],int limite); // Imprime el array
int getArrayInt(int array[], int limite, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int maximoArrayInt(int array[],int limite,int *pResultado); // Busca el valor Maximo del Array
int getInt(int *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo, int reintentos);
int ordenarArrayInt(int array[],int limite); // primer burbujeo - Ordena Array INT
int ordenarArraySwapIntAsc(int array[] ,int limite); // burbujeo asc -- Ordena Array INT ASC
int ordenarArraySwapIntDes(int array[] ,int limite); // burbujeo desc -- Ordena Array INT DESC
int insertionSortArrayInt(int array[], int limite); //Ordena segun Insercion FUNCIONA OK

//Funciones con Array de Strings
int getString(char *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo, int reintentos);
int initArrayStr(char array[][QTY_CARACTERES],int limite,int valor); // Inicia un array de STRINGS(SI NO ES NECESARIO NO USAR)
int imprimeArrayStr(char array[][QTY_CARACTERES], int limite); // Imprime un Array de STRINGS
int getArrayStr(char array[][QTY_CARACTERES], int limite, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int ordenarArraySwapStrAsc(char array[][QTY_CARACTERES],int limite); // burbujeo asc -- Ordena Array STR ASC
int ordenarArraySwapStrDesc(char array[][QTY_CARACTERES],int limite); // burbujeo desc -- Ordena Array STR DESC

//Funciones con Array de Strings+Array INT
int ordenarArraySwapStrIntAscByInt(char arrayChars[][QTY_CARACTERES],int arrayInt[],int limite); // burbujeo asc -- Ordena Array STR+INT ASC segun INT
int ordenarArraySwapStrIntDescByInt(char arrayChars[][QTY_CARACTERES],int arrayInt[],int limite); // burbujeo desc -- Ordena Array STR+INT DESC segun INT
char getChar(char *resultado, char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos);
int esNumerico(char *buffer);
int esSoloChar(char *buffer);
int esAlfaNumerico (char *buffer);
int esCuit(char *buffer);
int isCharOrSpace(char buffer[]);
char getCharVarios(char *resultado,
			char *mensaje,
			char *mensajeError,
			char minimo,
			char maximo,
			int reintentos);
#endif /* UTN_H_ */

