#include "JPG.h"

JPG::JPG(bool _conFlash, string _resolucion, double _largo, double _ancho, 
string _nombre, string _autor, FileSystemNode* _padre) : Archivo(_nombre, _autor, _padre){
	this->conFlash = _conFlash;
	this->resolucion = _resolucion;
	this->largo = _largo;
	this->ancho = _ancho;
}

string JPG::toString(){
	return this->nombre + "\n" + "      " + "Con Flash: " + (this->conFlash ? "Si" : "No") 
	+ "\n" + "      " + "Resolucion: " + this->resolucion + "\n" + "      " + "Largo: " + to_string(this->largo)
	+ "\n" + "      " + "Ancho: " + to_string(this->ancho);
}