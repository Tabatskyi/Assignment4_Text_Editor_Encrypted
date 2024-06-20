#include "ChunkLoad.h"


ChunkLoad::ChunkLoad(char* filename, unsigned int size)
{
	this->filename = filename;
	this->size = size;
	file = fopen(filename, "r");
}

ChunkLoad::~ChunkLoad()
{
	delete[] chunk;
	fclose(file);
}

char* ChunkLoad::LoadChunk()
{
	if (file == NULL)
	{
		return NULL;
	}

	chunk = new char[size];
	fread(chunk, sizeof(char), size, file);

	return chunk;
}

