/*********************************************************************
 * File  : PerceptronMulticapa.cpp
 * Date  : 2017
 *********************************************************************/

#include "PerceptronMulticapa.h"
#include "util.h"


#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <string>
#include <cstdlib>  // Para establecer la semilla srand() y generar números aleatorios rand()
#include <limits>
#include <math.h>


using namespace imc;
using namespace std;
using namespace util;

// ------------------------------
// CONSTRUCTOR: Dar valor por defecto a todos los parámetros
PerceptronMulticapa::PerceptronMulticapa(){

}

// ------------------------------
// Reservar memoria para las estructuras de datos
int PerceptronMulticapa::inicializar(int nl, int npl[]) {
	return 1;
}


// ------------------------------
// DESTRUCTOR: liberar memoria
PerceptronMulticapa::~PerceptronMulticapa() {
	liberarMemoria();

}


// ------------------------------
// Liberar memoria para las estructuras de datos
void PerceptronMulticapa::liberarMemoria() {

}

// ------------------------------
// Rellenar todos los pesos (w) aleatoriamente entre -1 y 1
void PerceptronMulticapa::pesosAleatorios() {

}

// ------------------------------
// Alimentar las neuronas de entrada de la red con un patrón pasado como argumento
void PerceptronMulticapa::alimentarEntradas(vector <double> entrada) {

}

// ------------------------------
// Recoger los valores predichos por la red (out de la capa de salida) y almacenarlos en el vector pasado como argumento
void PerceptronMulticapa::recogerSalidas(vector <double> salida)
{

}

// ------------------------------
// Hacer una copia de todos los pesos (copiar w en copiaW)
void PerceptronMulticapa::copiarPesos() {

}

// ------------------------------
// Restaurar una copia de todos los pesos (copiar copiaW en w)
void PerceptronMulticapa::restaurarPesos() {

}

// ------------------------------
// Calcular y propagar las salidas de las neuronas, desde la primera capa hasta la última
void PerceptronMulticapa::propagarEntradas() {
	
}

// ------------------------------
// Calcular el error de salida (MSE) del out de la capa de salida con respecto a un vector objetivo y devolverlo
double PerceptronMulticapa::calcularErrorSalida(vector <double> target) {
	return -1;
}


// ------------------------------
// Retropropagar el error de salida con respecto a un vector pasado como argumento, desde la última capa hasta la primera
void PerceptronMulticapa::retropropagarError(vector <double> objetivo) {
	
}

// ------------------------------
// Acumular los cambios producidos por un patrón en deltaW
void PerceptronMulticapa::acumularCambio() {

}

// ------------------------------
// Actualizar los pesos de la red, desde la primera capa hasta la última
void PerceptronMulticapa::ajustarPesos() {

}

// ------------------------------
// Imprimir la red, es decir, todas las matrices de pesos
void PerceptronMulticapa::imprimirRed() {

}

// ------------------------------
// Simular la red: propagar las entradas hacia delante, retropropagar el error y ajustar los pesos
// entrada es el vector de entradas del patrón y objetivo es el vector de salidas deseadas del patrón
void PerceptronMulticapa::simularRedOnline(vector <double> entrada, vector <double> objetivo) {

}

// ------------------------------
// Leer una matriz de datos a partir de un nombre de fichero y devolverla
Datos* PerceptronMulticapa::leerDatos(const string archivo) {

	Datos *p = new Datos;
	ifstream file;

	string filename = "../basesDatosPr1IMC/dat/test_forest.dat";
	file.open(filename);
	if (! file.is_open())
		return 0;	// Meter aqui una funcion de error


	file >> p->nNumEntradas >> p->nNumSalidas >> p->nNumPatrones;
	cout << "nEntradas: " << p->nNumEntradas << " nSalidas: " << p->nNumSalidas << " nPatrones: " << p->nNumPatrones << endl; 

	string line;
	string token;

	vector < vector <double> > auxEntradas(p->nNumPatrones, vector<double>(p->nNumEntradas, 0));
	vector < vector <double> > auxSalidas(p->nNumPatrones, vector<double>(p->nNumSalidas, 0));

	int i = 0;
	while(getline(file, line)){

		stringstream ss(line);

		for(int j = 0; j < p->nNumEntradas; j++){

			ss >> token;
			auxEntradas[i][j] = atof(token.c_str());
		}

		for(int j = 0; j < p->nNumSalidas; j++){

			ss >> token;
			auxSalidas[i][j] = atof(token.c_str());
		}

		i++;
	}

/*
	for(int i = 0; i < p->nNumPatrones; i++){

		cout << endl << "Entradas[" << i << "]: " << endl;
		for(int j = 0; j < p->nNumEntradas; j++){

			file >> token;
			cout << token  << " "; 
			auxEntradas[i][j] = stod(token);
		}

		cout << "Salidas[" << i << "]: " << endl;
		for(int j = 0; j < p->nNumSalidas; j++){

			file >> token;
			cout << token  << " ";
			auxSalidas[i][j] = stod(token);
		}
	}
*/
	for(int i = 0; i < p->nNumPatrones; i++){

		for(int j = 0; j < p->nNumEntradas; j++){

			cout << p->entradas[i][j] << " ";
		}
		cout << endl;
	}
	cin >> token;

	file.close();

	return p;
}

// ------------------------------
// Entrenar la red on-line para un determinado fichero de datos
void PerceptronMulticapa::entrenarOnline(Datos* pDatosTrain) {
	int i;
	for(i=0; i<pDatosTrain->nNumPatrones; i++){
		simularRedOnline(pDatosTrain->entradas[i], pDatosTrain->salidas[i]);
	}
}

// ------------------------------
// Probar la red con un conjunto de datos y devolver el error MSE cometido
double PerceptronMulticapa::test(Datos* pDatosTest) {
	return -1.0;
}

// ------------------------------
// Ejecutar el algoritmo de entrenamiento durante un número de iteraciones, utilizando pDatosTrain
// Una vez terminado, probar como funciona la red en pDatosTest
// Tanto el error MSE de entrenamiento como el error MSE de test debe calcularse y almacenarse en errorTrain y errorTest
void PerceptronMulticapa::ejecutarAlgoritmoOnline(Datos * pDatosTrain, Datos * pDatosTest, int maxiter, double *errorTrain, double *errorTest)
{
	int countTrain = 0;

	// Inicialización de pesos
	pesosAleatorios();

	double minTrainError = 0;
	int numSinMejorar;
	double testError = 0;

	double validationError = 0;

	// Generar datos de validación
	if(dValidacion > 0 && dValidacion < 1){
		// .......
	}


	// Aprendizaje del algoritmo
	do {

		entrenarOnline(pDatosTrain);
		double trainError = test(pDatosTrain);
		if(countTrain==0 || fabs(trainError - minTrainError) > 0.00001){
			minTrainError = trainError;
			copiarPesos();
			numSinMejorar = 0;
		}
		else{
			numSinMejorar++;
		}

		if(numSinMejorar==50){
			restaurarPesos();
			countTrain = maxiter;
		}

		countTrain++;

		// Comprobar condiciones de parada de validación y forzar

		cout << "Iteración " << countTrain << "\t Error de entrenamiento: " << trainError << "\t Error de validación: " << validationError << endl;

	} while ( countTrain<maxiter );

	cout << "PESOS DE LA RED" << endl;
	cout << "===============" << endl;
	imprimirRed();

	cout << "Salida Esperada Vs Salida Obtenida (test)" << endl;
	cout << "=========================================" << endl;
	for(int i=0; i<pDatosTest->nNumPatrones; i++){
		vector <double> prediccion(pDatosTest->nNumSalidas);

		// Cargamos las entradas y propagamos el valor
		alimentarEntradas(pDatosTest->entradas[i]);
		propagarEntradas();
		recogerSalidas(prediccion);
		for(int j=0; j<pDatosTest->nNumSalidas; j++)
			cout << pDatosTest->salidas[i][j] << " -- " << prediccion[j] << " ";
		cout << endl;
		prediccion.clear();

	}

	testError = test(pDatosTest);
	*errorTest=testError;
	*errorTrain=minTrainError;

}
