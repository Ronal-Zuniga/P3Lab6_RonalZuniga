#ifndef CPP_H
#define CPP_H
#include "Archivo.h"
#include <string>
using namespace std;

class CPP : public Archivo{
	private:
		int lineasCodigo;
		int numErrores;
	public:
		CPP(int, int, string, string, FileSystemNode*);
		string toString();	
};

#endif