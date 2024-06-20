#include "ChunkSave.h"

ChunkSave::ChunkSave(char* filename)
{
	this->filename = filename;
	char* chunk = nullptr;
}

ChunkSave::~ChunkSave()
{
	delete[] chunk;
}

bool ChunkSave::SaveChunk(char* chunk)
{
	unsigned int size = strlen(chunk);
	file = fopen(filename, "w");
	if (file == NULL)
	{
		return false;
	}

	//fwrite(chunk, sizeof(char), size, file);
	fprintf(file, "%s", chunk);
	fclose(file);

	return true;
}
