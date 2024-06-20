#pragma once
#include "Command.h"

class ChunkLoad
{
public:
	ChunkLoad(char* filename, unsigned int size);
	~ChunkLoad();

	char* LoadChunk();
private:
	char* chunk;
	size_t size;
	char* filename;
	FILE* file;
};

