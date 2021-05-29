#include <iostream>
#include <string>
#include "FileSystem.h"
#include "FileSystemNode.h"
#include "Archivo.h"
#include "CPP.h"
#include "PPT.h"
#include "JPG.h"
using namespace std;
int menu();
int submenu();

int main() {
	FileSystem* root = new FileSystem(new Directorio("Root", "Ronal Z", NULL));
	Directorio* dir1 = new Directorio("Documents", "Ronal Z", root->getRoot());
	dir1->agregarArchivo(new CPP(259, 3, "Examen1.cpp", "Ronal Z", dir1));
	dir1->agregarArchivo(new JPG(true, "1080x720", 17.5, 12.3, "Paisaje", "Ronal Z", dir1));
	dir1->agregarArchivo(new PPT("Reino animal", 13, 6, true, "Tarea1", "Ronal Z", dir1));
	
	Directorio* dir2 = new Directorio("Archivos Clase", "Ronal Z", dir1);
	dir2->agregarArchivo(new CPP(512, 7, "Lab4.cpp", "Ronal Z", dir2));
	dir2->agregarArchivo(new JPG(true, "720x720", 19.5, 12, "Logo", "Ronal Z", dir2));
	dir2->agregarArchivo(new PPT("Sistema Oseo", 10, 2, true, "Exposicion", "Ronal Z", dir2));
	
	Directorio* dir3 = new Directorio("Personal", "Ronal Z", dir2);
	dir3->agregarArchivo(new CPP(1500, 2, "Juego.cpp", "Ronal Z", dir3));
	dir3->agregarArchivo(new JPG(true, "1080x720", 22.3, 15.2, "Wallpaper", "Ronal Z", dir3));
	dir3->agregarArchivo(new PPT("Musica Favorita", 22, 9, true, "Musica", "Ronal Z", dir3));
	
	dir1->agregarDirectorio(dir2);
	dir2->agregarDirectorio(dir3);
	int opcion;
	while((opcion = menu()) != 5) {
		switch(opcion) {
			case 1: {
				break;
			}

			case 2: {
				Directorio* d;
				cout << endl;
				cout << "Agregar directorio" << endl;
				string nombre, autor;
				cout << "Ingrese el nombre del directorio: ";
				getline(cin, nombre);
				cout << "Ingrese el autor del directorio: ";
				getline(cin, autor);
				d = new Directorio(nombre, autor, root->getRoot());
				root->getRoot()->agregarDirectorio(d);
				cout << "Directorio agregado correctamente" << endl;
				cout << endl;
				delete d;
				break;
			}

			case 3: {
				cout << endl;
				int opcionAdd = 0;
				while((opcionAdd = submenu()) != 4) {
					switch(opcionAdd) {
						case 1: {
							CPP* cpp;
							cout << "Agregar archivo cpp" << endl;
							string nombre1, autor1;
							int lineas, errores;
							cout << "Ingrese el nombre del archivo: ";
							getline(cin, nombre1);
							cout << "Ingrese el autor del archivo: ";
							getline(cin, autor1);
							cout << "Ingrese el numero de Lineas: ";
							cin >> lineas;
							cin.ignore();
							cout << "Ingrese el numero de Errores: ";
							cin >> errores;
							cin.ignore();
							cpp = new CPP(lineas, errores, nombre1, autor1, root->getRoot());
							root->getRoot()->agregarArchivo(cpp);
							cout << "Archivo agregado correctamente" << endl;
							cout << endl;
							delete cpp;
							break;
						}

						case 2: {
							PPT* ppt;
							cout << "Agregar archivo ppt" << endl;
							string nombre1, autor1, titulo;
							int slides, plantilla, aux;
							bool animaciones;
							cout << "Ingrese el nombre del archivo: ";
							getline(cin, nombre1);
							cout << "Ingrese el autor del archivo: ";
							getline(cin, autor1);
							cout << "Ingrese el titulo del archivo: ";
							getline(cin, titulo);
							cout << "Ingrese el numero de Slides: ";
							cin >> slides;
							cin.ignore();
							cout << "Ingrese el numero de Plantilla: ";
							cin >> plantilla;
							cin.ignore();
							cout << "Ingrese 1(si tiene animaciones) o 0(si no tiene): ";
							cin >> aux;
							cin.ignore();
							if(aux == 1) {
								animaciones = true;
							} else {
								animaciones = false;
							}
							ppt = new PPT(titulo, slides, plantilla, animaciones, nombre1, autor1, root->getRoot());
							root->getRoot()->agregarArchivo(ppt);
							cout << "Archivo agregado correctamente" << endl;
							cout << endl;
							delete ppt;
							break;
						}

						case 3: {
							JPG* jpg;
							cout << "Agregar archivo JPG" << endl;
							string resolucion, nombre1, autor1;
							double largo, ancho;
							int aux;
							bool flash;
							cout << "Ingrese el nombre del archivo: ";
							getline(cin, nombre1);
							cout << "Ingrese el autor del archivo: ";
							getline(cin, autor1);
							cout << "Ingrese la resolucion de la foto: ";
							getline(cin, resolucion);
							cout << "Ingrese el largo: ";
							cin >> largo;
							cin.ignore();
							cout << "Ingrese el ancho: ";
							cin >> ancho;
							cin.ignore();
							cout << "Ingrese 1(si fue tomada con flash) o 0(si no): ";
							cin >> aux;
							cin.ignore();
							if(aux == 1) {
								flash = true;
							} else {
								flash = false;
							}
							jpg = new JPG(flash, resolucion, largo, ancho, nombre1, autor1, root->getRoot());
							root->getRoot()->agregarArchivo(jpg);
							cout << "Archivo agregado correctamente" << endl;
							cout << endl;
							delete jpg;
							break;
						}
					}//fin del switch
				}//fin del while submenu
				cout << endl;
				break;
			}

			case 4: {
				break;
			}
		}//fin del switch
	}//fin del while
	delete dir1;
	delete dir2;
	delete dir3;
	root->~FileSystem();
	delete root;
	return 0;
}

int menu() {
	int opcion;
	cout << "----MENU----" << endl;
	cout << "1. Imprimir FileSystem" << endl;
	cout << "2. Agregar Directorios" << endl;
	cout << "3. Agregar Archivos" << endl;
	cout << "4. Buscar por nombre" << endl;
	cout << "5. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	cin.ignore();
	cout << endl;
	while(opcion <= 0 || opcion > 5) {
		cout << "Seleccione una opcion dentro del rango" << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcion;
		cin.ignore();
		cout << endl;
	}
	return opcion;
}

int submenu() {
	int opcion;
	cout << "Agregar Archivo" << endl;
	cout << "1. Agregar cpp" << endl;
	cout << "2. Agregar ppt" << endl;
	cout << "3. Agregar jpg" << endl;
	cout << "4. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	cin.ignore();
	cout << endl;
	while(opcion <= 0 || opcion > 4) {
		cout << "Seleccione una opcion dentro del rango" << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcion;
		cin.ignore();
		cout << endl;
	}
	return opcion;
}