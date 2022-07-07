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
Estudiante Estudiantes[10] = {"Bruno","Asuncion",32,1212,"asdasd",0,"Marcos","Farias",32,1212,"asdasd",0,"Pedro","Antunes",32,1212,"asdasd",0,"Juan","Pablo",32,1212,"asdasd",0,"Pepe","Freitas",20,1212,"asdasd",0};
int CantidadRegistros = 5;


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

//La variable datos se utiliza si solamente tenemos 1 estudiante registrado
//La variable retorno ingresa como valor 1 o 2, 1 es para retornar al menu principal y 2 para el menu Guardar
//La variable posicion es para determinar cuales son los estudiantes que se estan mostrando. por ejemplo cuanto tiene el valor 1 quiere decir que esta mostrando los primero 4 estudiantes.
void VisualizarEstudiantes(Estudiante datos, int retorno, int posicion){
	DibujaTituloCuadro();
	
	// si no tenemos ningun registro de estudiantes
	if(CantidadRegistros == 0){
		VisualizarEst(datos, 1, 1);
	}
	
	//si tenemos 1 asta 4 estudiantes. mostraria solo una pantalla
	if(CantidadRegistros>0 && CantidadRegistros <=4){
		int i = 0;
		for(i=0;i<4;i++){
			VisualizarEst(Estudiantes[i],i+1,i+1);
		}
	}
	else if(posicion == 1){
		int i = 0;
		for(i=0;i<4;i++){
			VisualizarEst(Estudiantes[i],i+1,i+1);
		}
	}
	// calculamos que pocición del vector vamos a mostrar si son mas de una pantalla, del 5 estudiante en adelante
	if(CantidadRegistros>4 && posicion > 1){
		int i = 0;
		int contador = 1;
		int inicio = 0;
		int fin = 0;
		int cantidadCuadros = 0;
		
		if(CantidadRegistros % 4 == 0){
			cantidadCuadros = CantidadRegistros / 4;
		}
		else if(CantidadRegistros % 4 > 0){
			cantidadCuadros = (CantidadRegistros / 4)+1;
		}
	
		if(posicion <= cantidadCuadros ){
			inicio = (posicion * 4) - 4;
			fin = CantidadRegistros-1;
		}
		//gotoxy(2,6);printf("Testing %d - %d",inicio,fin);
		for(i=inicio;i<=fin;i++){
			//gotoxy(2,6);printf("Testing %d - %d",inicio,fin);
			VisualizarEst(Estudiantes[i],contador,i+1);
			contador++;
		}
	}	

	gotoxy(20,4);printf("Cantidad Total de Registros: %d",CantidadRegistros);
	
	
	if(CantidadRegistros <= 4 && posicion>1){
		gotoxy (2,23);system("pause");
	}
	else if(CantidadRegistros <= 4 && posicion == 1){
		gotoxy (2,23);system("pause");
	}
	else if(posicion == 1){
		gotoxy (2,23);printf("Proxima Pagina  -  ");system("pause");
		VisualizarEstudiantes(datos, 1,posicion+1);
	}
	else if(posicion > 1){		
		int inicio, fin;
		
		inicio = (posicion * 4) - 3;
		fin = posicion*4;
		
		if(CantidadRegistros>= inicio && CantidadRegistros <=fin){
			gotoxy (2,23);system("pause");
		}else{
			gotoxy (2,23); printf("Proxima Pagina");system("pause");
			VisualizarEstudiantes(datos, 1,posicion+1);	
		}
	}
	
	//la segunda variable que recibe la funcion se utiliza aqui y define para donde va retornar despues de visualizar los estudiantes, dependiendo de donde se este utilizando esta funcion
	if(retorno == 1){
		menu();
	}else if(retorno == 2){
		SeleccionGuardar();
	}
	
}
//1 Parametro - Recibimos los datos del estudiante
//2 Parametro - Recibimos la posicion en la que queremos que se imprima los datos en la pantalla que Son 4
//3 Parametro - El numero de Registro
void VisualizarEst(Estudiante datos, int posicion, int NumeroRegistro){
	if(posicion == 1){
		gotoxy(2,5);printf("----------------------------");
		gotoxy(2,6);printf("-- Numero de Registro : %d",NumeroRegistro);
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
		gotoxy(2,15);printf("-- Numero de Registro : %d",NumeroRegistro);
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
		gotoxy(35,6);printf("-- Numero de Registro : %d",NumeroRegistro);
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
		gotoxy(35,15);printf("-- Numero de Registro : %d",NumeroRegistro);
		gotoxy(35,16);printf("----------------------------");
		gotoxy(35,17);printf("Nombre: %s",datos.nombre);
		gotoxy(35,18);printf("Apellido: %s",datos.apellido);
		gotoxy(35,19);printf("Edad: %d",datos.edad);
		gotoxy(35,20);printf("Cedula: %d",datos.cedula);
		gotoxy(35,21);printf("Direccion: %s",datos.direccion);
		gotoxy(35,22);printf("----------------------------");	
	}
	
}

void GuardarEstudiante(int posicion){
	FILE* fichero;
    fichero = fopen("Parcial.txt", "a+");
    fprintf(fichero,"Nombre: %s \n",Estudiantes[posicion].nombre);
    fprintf(fichero,"Apellido: %s \n",Estudiantes[posicion].apellido);
    fprintf(fichero,"Edad: %d \n",Estudiantes[posicion].edad);
    fprintf(fichero,"Cedula: %d \n",Estudiantes[posicion].cedula);
    fprintf(fichero,"Direccion: %s \n",Estudiantes[posicion].direccion);
    fprintf(fichero,"\n----------------\n");
    fclose(fichero);
    
	gotoxy (2,15);printf("Proceso completado");
    gotoxy (2,23); system("pause");
    SeleccionGuardar();
}

void SeleccionGuardar(){
		int valor = 0;
		DibujaTituloCuadro();
		gotoxy(2,5);printf("-------------------------------------------");
		gotoxy(2,6);printf("-- Cantidad de Estudiantes Registrados : %d",CantidadRegistros);
		gotoxy(2,7);printf("-------------------------------------------");
		gotoxy(2,8);printf("Elige una Opcion:");	
		gotoxy (2,10);printf("1. Ver Datos Estudiantes: ");
		gotoxy (2,11);printf("2. Elige un numero de Registro: ");
		gotoxy (2,12);printf("3. Volver al Menu: ");
		fflush(stdin);
		gotoxy (2,13);scanf("%d",&valor);
		
		
		if(valor == 1){
			VisualizarEstudiantes(Estudiantes[0],2,1);
		}
		else if(valor == 2){
			MenuGuardarEstudiante();
		}
		else if(valor == 3){
			menu();
		}
}
void MenuGuardarEstudiante(){
	int numero = 0;
		DibujaTituloCuadro();
		gotoxy(2,5);printf("-----------------------------------------------------");
		gotoxy(2,6);printf("-- Selecione el numero de Registro que Desea Guardar: ");
		gotoxy(2,7);printf("-----------------------------------------------------");
		gotoxy(2,8);printf("-- Para volver al Menu Guardar Digite -1 --");
		fflush(stdin);
		gotoxy(2,10);scanf("%d",&numero);
		fflush(stdin);
		
		if(numero >= 0){
			GuardarEstudiante(numero-1);
		}
		else if(numero == -1){
			SeleccionGuardar();
		}
		
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
			VisualizarEstudiantes(Estudiantes[0],1,1);
			break;
		
		case 3:
			SeleccionGuardar();
			break;
		case 4:
			EnConstrucion();
			break;
		case 5:
			EnConstrucion();
			break;
		
		case 6:
			exit(0);
			break;
	}
	
}
void EnConstrucion(){
		DibujaTituloCuadro();
		gotoxy (30,6);printf("EN CONSTRUCION");
		gotoxy (2,23); system("pause");
		menu();
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
