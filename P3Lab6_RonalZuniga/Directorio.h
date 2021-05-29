#ifndef DIRECTORIO_H
#define DIRECTORIO_H
#include <vector>
#include <string>
#include "FileSystemNode.h"
using namespace std;

class Directorio : public FileSystemNode{
	private:
		vector <FileSystemNode*> hijos;
	public:
		Directorio(string, string, FileSystemNode*);
		~Directorio();
		virtual string toString();
		void imprimirRecursivo(int);
		void agregarArchivo(FileSystemNode*);
		void agregarDirectorio(FileSystemNode*);
		void buscarPorNombre(string);
};

#endif