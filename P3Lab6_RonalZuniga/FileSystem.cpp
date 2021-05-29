#include "FileSystem.h"

FileSystem::FileSystem(Directorio* _root){
	this->root = _root;
}

FileSystem::~FileSystem(){
	this->root->~Directorio();
	this->root = NULL;
}

Directorio* FileSystem::getRoot(){
	return this->root;
}