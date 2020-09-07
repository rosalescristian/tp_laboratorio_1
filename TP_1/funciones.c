#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define EXIT_ERROR -1
#define EXIT_SUCCESS 0

/** \brief Imprime el menu de la calculadora
 * \return Devuelve -1 si no se pudo recorrer el menu, 0 si se pudo recorrer el menu correctamente.
 */
int funcionMenu(void)
{
    float operandoUno;
    int operandoUnoCargado;
    float operandoDos;
    int operandoDosCargado;
	float suma;
	float resta;
	float multiplicacion;
	float division;
	float factorialA;
	float factorialB;
	int retorno = EXIT_ERROR;
    int operacion;
    int operacionesCalculadas;

    operandoUnoCargado = 0;
    operandoDosCargado = 0;
    operacionesCalculadas = 0;

	do{
        printf("\n\t");
        if(operandoUnoCargado == 0)
        {
            printf("1- Ingrese 1er Operando (A=X)\n\t");
        }
        else
        {
            printf("1- Ingrese 1er Operando (A=%.2f)\n\t",operandoUno);
        }
        if(operandoDosCargado == 0)
        {
            printf("2- Ingrese 2do Operando (B=Y)\n\t");
        }
        else
        {
            printf("2- Ingrese 2do Operando (B=%.2f)\n\t",operandoDos);
        }
        printf("3- Calcular todas las operaciones\n\t");
        if(operandoUnoCargado == 0 || operandoDosCargado == 0)
        {
            printf("\ta)Calcular la Suma(A+B)\n\t");
            printf("\tb)Calcular la resta(A-B)\n\t");
            printf("\tc)Calcular la division(A/B)\n\t");
            printf("\td)Calcular la multiplicacion(A*B)\n\t");
            printf("\te)Calcular el factorial(A! - B!)\n\t");
        }
        else
        {
            printf("\ta)Calcular la Suma(%.2f+%.2f)\n\t",operandoUno,operandoDos);
            printf("\tb)Calcular la resta(%.2f-%.2f)\n\t",operandoUno,operandoDos);
            printf("\tc)Calcular la division(%.2f/%.2f)\n\t",operandoUno,operandoDos);
            printf("\td)Calcular la multiplicacion(%.2f*%.2f)\n\t",operandoUno,operandoDos);
            printf("\te)Calcular el factorial(%.2f! - %.2f!)\n\t",operandoUno,operandoDos);
        }
        printf("4- Informar Resultados \n\t");
        printf("5- Salir\n\n");
        getInt(&operacion,"Seleccione la opcion deseada\n","Ha ingresado una opcion invalida, reintente.\n\n",1,5,2);

        switch(operacion){
            case 1:
                system("cls");
                getFloat(&operandoUno,"Ingresar 1er Operando: \n","Ha ingresado un dato invalido. Reintente.\n",-100000,100000,3);
                operandoUnoCargado = 1;
                break;
            case 2:
                system("cls");
                getFloat(&operandoDos,"Ingresar 2do Operando: \n","Ha ingresado un dato invalido. Reintente.\n",-100000,100000,3);
                operandoDosCargado = 1;
                break;
            case 3:
                if(operandoUnoCargado == 1 && operandoDosCargado == 1)
                {
                    funcionSuma(&suma,&operandoUno,&operandoDos);
                    funcionResta(&resta,&operandoUno,&operandoDos);
                    if(operandoDos != 0)
                    {
                        funcionDivision(&division,&operandoUno,&operandoDos);
                    }
                    funcionMultiplicacion(&multiplicacion,&operandoUno,&operandoDos);
                    if(operandoUno >= 0)
                    {
                        funcionFactorial(&factorialA,&operandoUno);
                    }
                    if(operandoDos >= 0)
                    {
                        funcionFactorial(&factorialB,&operandoDos);
                    }
                    operacionesCalculadas = 1;
                    system("cls");
                }
                else
                {
                    printf("No se pueden calcular las operaciones ya que falta la carga de un operando.\n\n");
                }
                break;
            case 4:
                if(operacionesCalculadas == 1)
                {
                    printf("\t\ta) El resultado de %.2f + %.2f es: %.2f\n",operandoUno,operandoDos,suma);
                    printf("\t\tb) El resultado de %.2f - %.2f es: %.2f\n",operandoUno,operandoDos,resta);
                    if(operandoDos==0)
                    {
                        printf("\t\tc) No es posible dividir por cero\n");
                    }
                    else
                    {
                        printf("\t\tc) El resultado de %.2f / %.2f es: %.2f\n",operandoUno,operandoDos,division);
                    }
                    printf("\t\td) El resultado de %.2f * %.2f es: %.2f\n",operandoUno,operandoDos,multiplicacion);
                    if(operandoUno<0)
                    {
                        printf("\t\te) No es posible calcular el factorial de %.2f por ser un nro negativo\n",operandoUno);
                    }
                    else
                    {
                        printf("\t\te) El factorial de %.2f es : %.2f\n",operandoUno,factorialA);
                    }
                    if(operandoDos<0)
                    {
                        printf("\t\tf) No es posible calcular el factorial de %.2f por ser un nro negativo\n\n",operandoDos);
                    }
                    else
                    {
                        printf("\t\tf) El factorial de %.2f es : %.2f\n\n",operandoDos,factorialB);
                    }
                }
                else
                {
                        printf("No se pueden mostrar los resultados ya que no se calcularon las operaciones.\n\n");
                }
                break;
            }
        }while(operacion != 5);
    retorno = EXIT_SUCCESS;
    return retorno;
}

/** \brief : SUMA: Calcula la suma entre dos valores flotantes.
 *
 * \param *resultado float: Recibe la direccion de memoria donde se almacena el resultado de la operacion.
 * \param *operandoUno float: Recibe la direccion de memoria del primer operando.
 * \param *operandoDos float: Recibe la direccion de memoria del segundo operando.
 * \return int: Devuelve 0 o -1 dependiendo si se calculo el resultado de la operacion.
 *
 */
int funcionSuma(float *resultado,float *operandoUno,float *operandoDos)
 {
    int retorno;
    float buffer;
    retorno = EXIT_ERROR;

    if(resultado != NULL && operandoUno != NULL && operandoDos != NULL)
    {
        buffer=*operandoUno+*operandoDos;
        *resultado=buffer;
        retorno = EXIT_SUCCESS;
    }
    return retorno;
 }

/** \brief : RESTA: Calcula la resta entre dos valores flotantes.
 *
 * \param *resultado float: Recibe la direccion de memoria donde se almacena el resultado de la operacion.
 * \param *operandoUno float: Recibe la direccion de memoria del primer operando.
 * \param *operandoDos float: Recibe la direccion de memoria del segundo operando.
 * \return int: Devuelve 0 o -1 dependiendo si se calculo el resultado de la operacion.
 *
 */
int funcionResta(float *resultado,float *operandoUno,float *operandoDos)
 {
    int retorno;
    float buffer;
    retorno = EXIT_ERROR;

    if(resultado != NULL && operandoUno != NULL && operandoDos != NULL)
    {
        buffer=*operandoUno-*operandoDos;
        *resultado=buffer;
        retorno = EXIT_SUCCESS;
    }
    return retorno;
 }


/** \brief : DIVISION: Calcula la division entre dos valores flotantes.
 *
 * \param *resultado float: Recibe la direccion de memoria donde se almacena el resultado de la operacion.
 * \param *operandoUno float: Recibe la direccion de memoria del primer operando.
 * \param *operandoDos float: Recibe la direccion de memoria del segundo operando.
 * \return int: Devuelve 0 o -1 dependiendo si se calculo el resultado de la operacion.
 *
 */
int funcionDivision(float *resultado, float *operandoUno, float *operandoDos)
 {
    float buffer;
    int retorno;
    retorno = EXIT_SUCCESS;

    if (resultado != NULL && operandoUno != NULL && operandoDos != NULL)
    {
            if(*operandoDos==0)
            {
                retorno = EXIT_ERROR; //Muestra este mensaje si B == 0.
            }
        buffer = *operandoUno/ *operandoDos;
        *resultado = buffer;
    }
    return retorno;
}

/** \brief : Multiplicacion: Calcula la multiplicacion entre dos valores flotantes.
 *
 * \param *resultado float: Recibe la direccion de memoria donde se almacena el resultado de la operacion.
 * \param *operandoUno float: Recibe la direccion de memoria del primer operando.
 * \param *operandoDos float: Recibe la direccion de memoria del segundo operando.
 * \return int: Devuelve 0 o -1 dependiendo si se calculo el resultado de la operacion.
 *
 */
 int funcionMultiplicacion(float *resultado,float *operandoUno, float *operandoDos)
 {
    int retorno;
    float buffer;
    retorno = EXIT_ERROR;

    if(resultado != NULL && operandoUno != NULL && operandoDos != NULL)
    {
        buffer=(*operandoUno)*(*operandoDos);
        *resultado=buffer;
        retorno = EXIT_SUCCESS;
    }
    return retorno;
 }

/** \brief : FACTORIAL: Calcula el factorial de un valor flotante.
 *
 * \param *resultado float: Recibe la direccion de memoria donde se almacena el resultado de la operacion.
 * \param *a float: Recibe la direccion de memoria del operando.
 * \return int: Devuelve 0 o -1 dependiendo si se calculo el resultado de la operacion.
 *
 */
int funcionFactorial(float *resultado, float *a)
 {
    float i;
    float factorial;
    int retorno;
    retorno = EXIT_ERROR;
    factorial=1;

    if(resultado != NULL && a != NULL)
    {
        if(*a>=0)
        {
            for(i=1;i<=*a;i++)
            {
                factorial=factorial*i;
            }
            *resultado=factorial;
            retorno = EXIT_SUCCESS;
        }
    }
    return retorno;
 }


/** \brief : GETINT: Devuelve un valor entero validado como tal.
 *
 * \param *resultado int: Recibe la direccion de memoria donde se almacena el resultado de la operacion.
 * \param *mensaje char: Recibe la direccion de memoria del arryay con el mensaje ingresado por el usuario.
 * \param *mensajeError char: Recibe la direccion de memoria del array con el mensaje de error ingresado por el usuario.
 * \param minimo int: Recibe el limite minimo del rango definido desde el menu.
 * \param maximo int: Recibe el limite maximo del rango definido desde el menu.
 * \param reintentos int: Recibe el limite de reintentos definido desde el menu.
 * \return int: Devuelve 0 o -1 dependiendo si se calculo el resultado de la operacion.
 *
 */
int getInt(	int *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno = EXIT_ERROR;
	int buffer;
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
			if(scanf("%d",&buffer)==1)
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

/** \brief : GETFLOAT: Devuelve un valor flotante validado como tal.
 *
 * \param *resultado float: Recibe la direccion de memoria donde se almacena el resultado de la operacion.
 * \param *mensaje char: Recibe la direccion de memoria del array con el mensaje ingresado por el usuario.
 * \param *mensajeError char: Recibe la direccion de memoria del array con el mensaje de error ingresado por el usuario.
 * \param minimo float: Recibe el limite minimo del rango definido desde el menu.
 * \param maximo float: Recibe el limite maximo del rango definido desde el menu.
 * \param reintentos float: Recibe el limite de reintentos definido desde el menu.
 * \return int: Devuelve 0 o -1 dependiendo si se calculo el resultado de la operacion.
 *
 */
int getFloat(float *resultado,
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
