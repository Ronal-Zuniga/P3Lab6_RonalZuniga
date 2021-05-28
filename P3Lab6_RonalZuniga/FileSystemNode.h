#ifndef FILESYSTEMNODE_H
#define FILESYSTEMNODE_H
#include <string>
using namespace std;

class FileSystemNode{
	protected:
		string nombre;
		string autor;
		FileSystemNode* padre;
	public:
		virtual string toString() = 0;
		FileSystemNode(string, string, FileSystemNode*);
};

#endif