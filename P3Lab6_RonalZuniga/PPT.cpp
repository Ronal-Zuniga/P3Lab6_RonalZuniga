#include "PPT.h"

PPT::PPT(string _titulo, int _slides, int _plantilla, bool _animaciones,
string _nombre, string _autor, FileSystemNode* _padre) : Archivo(_nombre, _autor, _padre){
	this->titulo = _titulo;
	this->slides = _slides;
	this->plantilla = _plantilla;
	this->animaciones = _animaciones;
}

string PPT::toString(){
	return this->nombre + "\n" + "      " + "Titulo: " + this->titulo + "\n" + "      " + "Numero de Slides: " +
	to_string(this->slides) + "\n" + "      " + "Numero de Plantilla: " + to_string(this->plantilla)
	+ "\n" + "      " + "Animaciones: " + (this->animaciones ? "Si" : "No");
}