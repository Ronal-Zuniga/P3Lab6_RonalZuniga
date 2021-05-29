#include <iostream>
#include <vector>
#include <string>
#include "Directorio.h"
#include "CPP.h"
#include "PPT.h"
#include "JPG.h"
using namespace std;

Directorio::Directorio(string _nombre, string _autor, FileSystemNode* _padre):
	FileSystemNode(_nombre, _autor, _padre) {
}

string Directorio::toString() {
	string result = this->nombre + "\n";
	for(int i = 0; i < this->hijos.size(); i++) {
		result += "      ";
		result += this->hijos[i]->getNombre();
		result += "\n";
	}
	return result;
}

Directorio::~Directorio() {
	for(int i = 0; i < this->hijos.size(); i++) {
		Directorio* d = dynamic_cast<Directorio*>(this->hijos[i]);
		delete d;
		this->hijos.erase(hijos.begin()+i);
	}
	this->hijos.clear();
}

void Directorio::agregarArchivo(FileSystemNode* archivo) {
	this->hijos.push_back(archivo);
}

void Directorio::agregarDirectorio(FileSystemNode* directorio) {
	this->hijos.push_back(directorio);
}

void Directorio::imprimirRecursivo(int espacio) {
	for(int i = 0; i < this->hijos.size(); i++) {
		for(int j = 0; j < espacio*6; j++) {
			cout << " ";
		}
		Directorio* dir;
		CPP* cpp;
		PPT* ppt;
		JPG* jpg;
		if(dynamic_cast<Directorio*>(this->hijos[i])) {
			dir = dynamic_cast<Directorio*>(this->hijos[i]);
			cout << dir->getNombre();
			imprimirRecursivo(espacio + 1);
		} else if(dynamic_cast<CPP*>(this->hijos[i])) {
			cpp = dynamic_cast<CPP*>(this->hijos[i]);
			cout << cpp->toString();
		} else if(dynamic_cast<PPT*>(this->hijos[i])) {
			ppt = dynamic_cast<PPT*>(this->hijos[i]);
			cout << ppt->toString();
		} else if(dynamic_cast<JPG*>(this->hijos[i])) {
			jpg = dynamic_cast<JPG*>(this->hijos[i]);
			cout << jpg->toString();
		}
	}
}

void Directorio::buscarPorNombre(string name){
	bool flag = false;
	for(int i = 0; i < this->hijos.size(); i++) {
		Directorio* dir;
		CPP* cpp;
		PPT* ppt;
		JPG* jpg;
		if(dynamic_cast<Directorio*>(this->hijos[i])) {
			dir = dynamic_cast<Directorio*>(this->hijos[i]);
			if(name == dir->getNombre()){
				flag = true;
				cout << "Se ha encontrado " << name << " en: " << endl;
				cout << dir->toString();
				cout << endl;
			}
		} else if(dynamic_cast<CPP*>(this->hijos[i])) {
			cpp = dynamic_cast<CPP*>(this->hijos[i]);
			if(name == cpp->getNombre()){
				flag = true;
				cout << "Se ha encontrado " << name << " en: " << endl;
				cout << cpp->toString();
				cout << endl;
			}
		} else if(dynamic_cast<PPT*>(this->hijos[i])) {
			ppt = dynamic_cast<PPT*>(this->hijos[i]);
			if(name == ppt->getNombre()){
				flag = true;
				cout << "Se ha encontrado " << name << " en: " << endl;
				cout << ppt->toString();
				cout << endl;
			}
		} else if(dynamic_cast<JPG*>(this->hijos[i])) {
			jpg = dynamic_cast<JPG*>(this->hijos[i]);
			if(name == jpg->getNombre()){
				flag = true;
				cout << "Se ha encontrado " << name << " en: " << endl;
				cout << jpg->toString();
				cout << endl;
			}
		}
		if(flag){
			break;
		}
	}
	if(!flag){
		cout << "No se ha encontrado ningun registro con el nombre " << name << endl;
	}
}