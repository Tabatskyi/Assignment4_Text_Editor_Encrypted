#include "ChunkSave.h"

ChunkSave::ChunkSave(char* filename)
{
	this->filename = filename;
	file = fopen(filename, "w");
}

ChunkSave::~ChunkSave()
{
	fclose(file);
}

bool ChunkSave::SaveChunk(char* text)
{
	size_t size = strlen(text);
	if (file == NULL)
	{
		return false;
	}

	fwrite(text, sizeof(char), size, file);
	//fprintf(file, "%s", chunk);

	return true;
}
