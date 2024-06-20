#include "ChunkLoad.h"


ChunkLoad::ChunkLoad(char* filename, unsigned int size)
{
	this->filename = filename;
	this->size = size;
}

ChunkLoad::~ChunkLoad()
{
	delete[] chunk;
}

char* ChunkLoad::LoadChunk()
{
	file = fopen(filename, "r");
	if (file == NULL)
	{
		return NULL;
	}

	chunk = new char[size];
	fread(chunk, sizeof(char), size, file);
	fclose(file);

	return chunk;
}

