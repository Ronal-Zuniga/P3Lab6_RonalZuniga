#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include "Directorio.h"

class FileSystem{
	private:
		Directorio* root;
	public:
		FileSystem(Directorio*);
		~FileSystem();
};

#endif