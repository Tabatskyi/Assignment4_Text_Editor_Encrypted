#pragma once
class ChunkSave
{
public:
	ChunkSave(char* chunk, char* filename);
	~ChunkSave();

	void SaveChunk();

private:
		char* chunk;
		unsigned int size;
		char* filename;
};

