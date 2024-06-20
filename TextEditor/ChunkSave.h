#pragma once
#include "Command.h"

class ChunkSave
{
public:
	ChunkSave(char* filename);
	~ChunkSave();

	bool SaveChunk(char* chunk);

private:
		char* filename;
		char* chunk;
};

