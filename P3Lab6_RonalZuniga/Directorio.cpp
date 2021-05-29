#include <iostream>
#include <vector>
#include <string>
#include "Directorio.h"
using namespace std;

Directorio::Directorio(string _nombre, string _autor, FileSystemNode* _padre):
FileSystemNode(_nombre, _autor, _padre){
}

string Directorio::toString(){
	string result = this->nombre + "\n";
	for(int i = 0; i < this->hijos.size(); i++){
		result += "      ";
		result += this->hijos[i]->getNombre();
		result += "\n";
	}
	return result;
}

Directorio::~Directorio(){
	for(int i = 0; i < this->hijos.size(); i++){
		Directorio* d = dynamic_cast<Directorio*>(this->hijos[i]);
		delete d;
		this->hijos.erase(hijos.begin()+i);
	}
	this->hijos.clear();
}

void Directorio::agregarArchivo(FileSystemNode* archivo){
	this->hijos.push_back(archivo);
}

void Directorio::agregarDirectorio(FileSystemNode* directorio){
	this->hijos.push_back(directorio);
}