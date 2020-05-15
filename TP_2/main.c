/*
 ============================================================================
 Name        : TP Nº 2
 Author      : Cristian Rosales
 Version     : 20200430
 Copyright   : Your copyright notice
 Description : Trabajo Practico Nº2 - Catedra: Laboratorio de Prog. 1G
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleados.h"


int main(void)
{
    int retorno;

    retorno = EXIT_ERROR;
    if(funcionMenu()==EXIT_SUCCESS)
    {
        retorno = EXIT_SUCCESS;
    }
	return retorno;
}
