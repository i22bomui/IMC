//============================================================================
// Introducción a los Modelos Computacionales
// Name        : practica1.cpp
// Author      : Pedro A. Gutiérrez
// Version     :
// Copyright   : Universidad de Córdoba
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <ctime>    // Para cojer la hora time()
#include <cstdlib>  // Para establecer la semilla srand() y generar números aleatorios rand()
#include <string.h>
#include <math.h>
#include <vector>
#include "imc/PerceptronMulticapa.h"


using namespace imc;
using namespace std;

int main(int argc, char **argv) {
	// Procesar los argumentos de la línea de comandos

	// Objeto perceptrón multicapa
	PerceptronMulticapa mlp;

	// Parámetros del mlp. Por ejemplo, mlp.dEta = valorQueSea;

	// Lectura de datos de entrenamiento y test: llamar a mlp.leerDatos(...)

	// Inicializar vector topología
	//int *topologia = new int[capas+2];
	//topologia[0] = pDatosTrain->nNumEntradas;
	//for(int i=1; i<(capas+2-1); i++)
	//	topologia[i] = neuronas;
	//topologia[capas+2-1] = pDatosTrain->nNumSalidas;

	// Inicializar red con vector de topología
	//mlp.inicializar(capas+2,topologia);


    // Semilla de los números aleatorios
    int semillas[] = {10,20,30,40,50};
    double *erroresTest = new double[5];
    double *erroresTrain = new double[5];
    for(int i=0; i<5; i++){
    	cout << "**********" << endl;
    	cout << "SEMILLA " << semillas[i] << endl;
    	cout << "**********" << endl;
		srand(semillas[i]);
		mlp.ejecutarAlgoritmoOnline(pDatosTrain,pDatosTest,iteraciones,&(erroresTrain[i]),&(erroresTest[i]));
		cout << "Finalizamos => Error de test final: " << erroresTest[i] << endl;
	}

    cout << "HEMOS TERMINADO TODAS LAS SEMILLAS" << endl;

    double mediaErrorTest = 0, desviacionTipicaErrorTest = 0;
    double mediaErrorTrain = 0, desviacionTipicaErrorTrain = 0;
    
    // Calcular medias y desviaciones típicas de entrenamiento y test

    cout << "INFORME FINAL" << endl;
    cout << "*************" << endl;
    cout << "Error de entrenamiento (Media +- DT): " << mediaErrorTrain << " +- " << desviacionTipicaErrorTrain << endl;
    cout << "Error de test (Media +- DT):          " << mediaErrorTest << " +- " << desviacionTipicaErrorTest << endl;
    return EXIT_SUCCESS;
}

