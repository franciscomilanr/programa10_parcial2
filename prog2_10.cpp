/*
Autor: Franciscomilan
Realizado: 07/04/22
Escuela: Universidad UVM
Materia: Programacion estructurada
Profesor: Armando Cruz
Ciclo: 01/2022
Descripcion: Programa 10 en C que utiliza el arreglo de la estrcutura Alumno y almacena los datos de 10 alumnos
Con las siguientes funciones
0 para Salir
1 para Agregar alumnos
2 para Imprimir
3 para Alumnos aprobados
4 para Alumnos reprobados
5 para Pormedio del grupo
6 para Porcentaje de alumnos aprobados 
para la materia programacion estructurada
*/

//Librerias
#include<stdio.h>
#include<stdlib.h>
//Libreria personalizada
#include"miLibreria.h"

//Declaraciones globales
#define MAX 10	
struct alumno {
	char nombre[30];
	float promedio;
	int faltas;
};	 
int n=0; 

//Prototipos de funcion
int menu();
void agregar(struct alumno x[]);
void imprimir(struct alumno x[], int tipo); 

//Funciones
int main () {
	//Declaracion variables locales
	int op;
	//Arreglo
	struct alumno grupo[MAX];	
	do {
		op=menu();
		switch(op) {
			case 0: printf(" - Adios - \n");
				break;
			case 1: agregar(grupo);
				break;
			case 2: imprimir(grupo,0);
				break;
			case 3: imprimir(grupo,1);
				break;
			case 4: imprimir(grupo,2);
				break;
		}
	}while(op!=0);
	return 0;
}

//Funcion menu
int menu() {

	int opcion;

	printf(" --------------- MENU ------------- ");
	printf(" 0. Salir \n");
	printf(" 1. Agregar alumnos \n");
	printf(" 2. Imprimir \n");
	printf(" 3. Alumnos aprobados\n");
	printf(" 4. Alumnos reprobados \n");
	printf(" 5. Promedio del grupo \n");
	printf(" 6. Porcentaje de alumno aprobados \n");
	opcion=leerd(" Seleccionar una opcion: ", 0,6);
	return opcion;
}

//Funcion agregar
void agregar (struct alumno x[]) {
	//Variables local
	int pregunta;
	//Proceso
	while (n<MAX) {
		leers("Nombre: ", x[n].nombre,30); 
		x[n].promedio=leerf("Promedio: ,0,10);
		x[n].faltas=leerd(" Faltas: ", 0, 32);
		n++;
		pregunta=leerd(" Agregar otro alumno? (1-Si, 0-No): ",0,1);
		if (pregunta==0) {
			break;
		}	
	}
	if (n==MAX) {
		printf(" Arreglo lleno ! \n");
		system("PAUSE");
	}
}

//Funcion imprimir
void imprimir(struct alumno x[], int tipo) {
	//Variables locales
	char mensaje[20];
	switch(tipo) {
		case 0: strcpy(mensaje,"Totales");
			break;
		case 1: strcpy(mensaje, "Aprobados");
			break;
		case 2: strcpy(mensaje,"Reprobados");
			break;
	}
	//Salida de datos
	printf("----------Alumnos %s---------------------\n");
	printf(" ------- DATOS DEL GRUPO ---------------\n");
	printf(" No.Alumno\t\t Nombre\t Faltas\t\t Promedio\n");
	printf("-----------------------------------------\n");
	//Proceso
	for (int i=0;i<n;i++) {
		switch(tipo) {
			case 0: printf("%2d \t %s30s \t %2d \t %4.1f \n",i+1,x[i].nombre, x[i].faltas,x[i].promedio);
				break;
			case 1: if (x[i].promedio>=7) {
					printf("%2d \t %s30s \t %2d \t %4.1f \n",i+1,x[i].nombre, x[i].faltas,x[i].promedio);
				}
				break;
			case 2: if (x[i].promedio<=7) {
					printf("%2d \t %s30s \t %2d \t %4.1f \n",i+1,x[i].nombre, x[i].faltas,x[i].promedio);
				}
				break;
			}
		}
	printf("----------------------------------------------------\n");
	system("PAUSE");
}

