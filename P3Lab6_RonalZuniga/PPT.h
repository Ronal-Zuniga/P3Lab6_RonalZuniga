#ifndef PPT_H
#define PPT_H
#include "Archivo.h"
#include <string>

class PPT : public Archivo{
	private:
		string titulo;
		int slides;
		int plantilla;
		bool animaciones;
	public:
		PPT(string, int, int, bool, string, string, FileSystemNode*);
		virtual string toString();
};

#endif