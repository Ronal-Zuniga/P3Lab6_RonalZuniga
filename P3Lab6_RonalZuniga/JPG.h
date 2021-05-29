#ifndef JPG_H
#define JPG_H
#include "Archivo.h"
#include <string>

class JPG : public Archivo{
	private:
		bool conFlash;
		string resolucion;
		double largo;
		double ancho;
	public:
		JPG(bool, string, double, double, string, string, FileSystemNode*);
		virtual string toString();
};

#endif