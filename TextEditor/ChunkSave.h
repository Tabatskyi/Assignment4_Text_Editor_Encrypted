#pragma once
#include "Command.h"

class ChunkSave
{
public:
	ChunkSave(char* filename);
	~ChunkSave();

	bool SaveChunk(char* chunk);

private:
		char* chunk;
		unsigned int size;
		char* filename;
};

