#pragma once
#include <iostream>

class ChunkLoad
{
public:
	ChunkLoad(char* filename, unsigned int size);
	~ChunkLoad();

	char* LoadChunk();
private:
	char* chunk;
	unsigned int size;
	char* filename;
};

