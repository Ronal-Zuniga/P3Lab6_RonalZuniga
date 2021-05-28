#include "CPP.h"

CPP::CPP(int _lineasCodigo, int _numErrores, string _nombre, 
string _autor, FileSystemNode* _padre) : Archivo(_nombre, _autor, _padre){
	this->lineasCodigo = _lineasCodigo;
	this->numErrores = _numErrores;
}

string CPP::toString(){
	return this->nombre + "/n" + "      " + "Lineas de codigo: " + to_string(this->lineasCodigo)
	+ "/n" + "      " + "Numero de errores: " + to_string(this->numErrores);
}