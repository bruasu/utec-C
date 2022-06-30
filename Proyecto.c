#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
// Estructuras
typedef struct Estudiante{
		char nombre[20];
		char apellido[20];
		int edad;
		int cedula;
		char direccion[30];
		float notas;
} Estudiante;

//Variables Globales
Estudiante Estudiantes[10];
int CantidadRegistros = 0;


void ingreso(){	
	DibujaTituloCuadro();
	
	gotoxy(2,6); printf("Ingrese el Nombre:");
	scanf("%[^\n]",&Estudiantes[CantidadRegistros].nombre);		
	fflush(stdin);
	
	gotoxy(2,8); printf("Ingrese el Apellido:");
	scanf("%[^\n]",&Estudiantes[CantidadRegistros].apellido);	
	fflush(stdin);
	
	gotoxy(2,10); printf("Ingrese el Edad:");
	scanf("%d",&Estudiantes[CantidadRegistros].edad);
	fflush(stdin);	
	
	gotoxy(2,12); printf("Ingrese el Cedula:");
	scanf("%d",&Estudiantes[CantidadRegistros].cedula);	
	fflush(stdin);
	
	gotoxy(2,14); printf("Ingrese el Direccion:");
	scanf("%[^\n]",&Estudiantes[CantidadRegistros].direccion);
	fflush(stdin);	
	
	CantidadRegistros ++;	
	
	menu();
}

void VisualizarEstudiantes(Estudiante datos){
	DibujaTituloCuadro();
	
	if(CantidadRegistros == 0){
		VisualizarEst(datos, 1);
	}
	
	if(CantidadRegistros>0){
		int i = 0;
		for(i=0;i<CantidadRegistros;i++){
			VisualizarEst(Estudiantes[i],i+1);
		}
	}
	gotoxy(20,4);printf("Cantidad Total de Registros: %d",CantidadRegistros);
	
	gotoxy (2,23); system("pause");
	menu();
}

void VisualizarEst(Estudiante datos, int posicion){
	if(posicion == 1){
		gotoxy(2,5);printf("----------------------------");
		gotoxy(2,6);printf("-- Numero de Registro : %d--",CantidadRegistros);
		gotoxy(2,7);printf("----------------------------");
		gotoxy(2,8);printf("Nombre: %s",datos.nombre);
		gotoxy(2,9);printf("Apellido: %s",datos.apellido);
		gotoxy(2,10);printf("Edad: %d",datos.edad);
		gotoxy(2,11);printf("Cedula: %d",datos.cedula);
		gotoxy(2,12);printf("Direccion: %s",datos.direccion);
		gotoxy(2,13);printf("----------------------------");
	}
	else if(posicion == 2){
		gotoxy(2,14);printf("----------------------------");
		gotoxy(2,15);printf("-- Numero de Registro : %d--",CantidadRegistros);
		gotoxy(2,16);printf("----------------------------");
		gotoxy(2,17);printf("Nombre: %s",datos.nombre);
		gotoxy(2,18);printf("Apellido: %s",datos.apellido);
		gotoxy(2,19);printf("Edad: %d",datos.edad);
		gotoxy(2,20);printf("Cedula: %d",datos.cedula);
		gotoxy(2,21);printf("Direccion: %s",datos.direccion);
		gotoxy(2,22);printf("----------------------------");		
	}
	else if(posicion == 3){
		gotoxy(35,5);printf("----------------------------");
		gotoxy(35,6);printf("-- Numero de Registro : %d--",CantidadRegistros);
		gotoxy(35,7);printf("----------------------------");
		gotoxy(35,8);printf("Nombre: %s",datos.nombre);
		gotoxy(35,9);printf("Apellido: %s",datos.apellido);
		gotoxy(35,10);printf("Edad: %d",datos.edad);
		gotoxy(35,11);printf("Cedula: %d",datos.cedula);
		gotoxy(35,12);printf("Direccion: %s",datos.direccion);
		gotoxy(35,13);printf("----------------------------");	
	}
	else if(posicion == 4){
		gotoxy(35,14);printf("----------------------------");
		gotoxy(35,15);printf("-- Numero de Registro : %d--",CantidadRegistros);
		gotoxy(35,16);printf("----------------------------");
		gotoxy(35,17);printf("Nombre: %s",datos.nombre);
		gotoxy(35,18);printf("Apellido: %s",datos.apellido);
		gotoxy(35,19);printf("Edad: %d",datos.edad);
		gotoxy(35,20);printf("Cedula: %d",datos.cedula);
		gotoxy(35,21);printf("Direccion: %s",datos.direccion);
		gotoxy(35,22);printf("----------------------------");	
	}
	
}

void GuardarEstudiante(){
	FILE* fichero;
    fichero = fopen("Parcial.txt", "wt");
    fprintf(fichero,"Nombre: %s \n",Estudiantes[0].nombre);
    fprintf(fichero,"Apellido: %s \n",Estudiantes[0].apellido);
    fprintf(fichero,"Edad: %d \n",Estudiantes[0].edad);
    fprintf(fichero,"Cedula: %d \n",Estudiantes[0].cedula);
    fprintf(fichero,"Direccion: %s \n",Estudiantes[0].direccion);
    fclose(fichero);
    
	gotoxy (2,15);printf("Proceso completado");
    gotoxy (2,23); system("pause");
    menu();
}

void menu(){
	int op;
	
	DibujaTituloCuadro();
		
	gotoxy (2,5);printf("1. Registrar Estudiante");
	gotoxy (2,6);printf("2. Ver Datos Estudiantes");
	gotoxy (2,7);printf("3. Guardar Datos de un Estudiante");
	gotoxy (2,8);printf("4. Ingresar Materias");
	gotoxy (2,9);printf("5. Ver Materias");
	gotoxy (2,10);printf("6. Salir del Programa");
	gotoxy (2,12);printf("Ingrese una opcion: ");
	scanf("%i",&op);	
	fflush(stdin);
	
	switch(op){
		case 1:
			ingreso();
			break;
		
		case 2:
			VisualizarEstudiantes(Estudiantes[0]);
			break;
		
		case 3:
			GuardarEstudiante();
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		
		case 6:
			exit(0);
			break;
	}
	
}
main(){	
	system("mode con: cols=80 lines=25");
	system("COLOR B0");
		
	menu();
	
	gotoxy (2,23); system("pause");
}

void DibujaTituloCuadro(){	
	system("cls");
	dibujarCuadro(0,0,78,24);
	dibujarCuadro(1,1,77,3);
	gotoxy(30,2); printf("DATOS DE LOS ESTUDIANTES");
}

//FUNCION GOTOXY
void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
 
 //FUNCION QUE DIBUJA EL CUADRO
void dibujarCuadro(int x1,int y1,int x2,int y2){
	int i;

    for (i=x1;i<x2;i++){
		gotoxy(i,y1); printf("\304"); //linea horizontal superior
		gotoxy(i,y2); printf("\304"); //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); printf("\263"); //linea vertical izquierda
		gotoxy(x2,i); printf("\263"); //linea vertical derecha
	}

    gotoxy(x1,y1); printf("\332");
    gotoxy(x1,y2); printf("\300");
    gotoxy(x2,y1); printf("\277");
    gotoxy(x2,y2); printf("\331");
}
