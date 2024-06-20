#include "ChunkSave.h"

ChunkSave::ChunkSave(char* filename)
{
	this->filename = filename;
}

ChunkSave::~ChunkSave()
{
	delete[] chunk;
}

bool ChunkSave::SaveChunk(char* chunk)
{
	unsigned int size = strlen(chunk);
	FILE* file = fopen(filename, "wt");
	if (file == NULL)
	{
		return false;
	}

	fwrite(chunk, sizeof(char), size, file);
	fclose(file);

	return true;
}
