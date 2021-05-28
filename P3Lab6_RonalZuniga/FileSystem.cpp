#include "FileSystem.h"

FileSystem::FileSystem(Directorio* _root){
	this->root = _root;
}

FileSystem::~FileSystem(){
	this->root->~Directorio();
	delete this->root;
	this->root = NULL;
}