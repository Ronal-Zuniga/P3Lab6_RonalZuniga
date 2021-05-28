#include <iostream>
using namespace std;
int menu();

int main() {
	int opcion;
	while((opcion = menu()) != 5) {
		switch(opcion) {
			case 1:{
				break;
			}

			case 2:{
				break;
			}

			case 3:{
				break;
			}
			
			case 4:{
				break;
			}
		}//fin del switch
	}//fin del while
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
	cout << endl;
	while(opcion <= 0 || opcion > 5) {
		cout << "Seleccione una opcion dentro del rango" << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcion;
		cout << endl;
	}
	return opcion;
}