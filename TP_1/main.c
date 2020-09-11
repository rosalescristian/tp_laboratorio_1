/*******************************************************************
*Programa: Calculadora - TP 1 - Laboratorio Programacion 1
*
*Objetivo: Desarrollar una calculadora con sus funciones en una biblioteca aparte.
*
*Version: 1.0 - 20200912
*Autor: Cristian Rosales
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define EXIT_ERROR -1
#define EXIT_SUCCESS 0

int main()
{
    int retorno = EXIT_FAILURE;
    if(funcionMenu()==EXIT_SUCCESS)
    {
        retorno = EXIT_SUCCESS;
    }
    return retorno;
}
