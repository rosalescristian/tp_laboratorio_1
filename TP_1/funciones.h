/**< Prototipos */


int funcionMenu(void);
int getInt(	int *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos);
int getFloat(float *resultado,
			  char *mensaje,
			  char *mensajeError,
			  float minimo,
			  float maximo,
			  float reintentos);
int funcionSuma(float *suma, float *a,float *b);
int funcionResta(float *resta, float *a,float *b);
int funcionDivision(float *division,float *a, float *b);
int funcionMultiplicacion(float *resultado,float *a, float *b);
int funcionFactorial(float *resultado, float *a);


