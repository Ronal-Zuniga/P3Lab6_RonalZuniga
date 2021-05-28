#include <iostream>
#include <vector>
#include <string>
#include "Directorio.h"
using namespace std;

Directorio::Directorio(string _nombre, string _autor, FileSystemNode* _padre):
FileSystemNode(_nombre, _autor, _padre){
}

string Directorio::toString(){
	return this->nombre;
}

Directorio::~Directorio(){
	for(int i = 0; i < this->hijos.size(); i++){
		Directorio* d = dynamic_cast<Directorio*>(this->hijos[i]);
		delete d;
		this->hijos.erase(hijos.begin()+i);
	}
	this->hijos.clear();
}