#pragma once
#include "constants.h"
// Defining a pointer doesnt need an include
// If I later try to use World methods, it will break without this include, uncomment it
// if World is an undefined type in Chunk!!!
// #include "World.h"

class World;

class Chunk
{
public:
	int mVoxelStates[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
	int mChunkX;
	int mChunkY;
	int mChunkZ;
	World* mWorld;
	void DrawChunk();
	bool IterateVoxelPositions(int& x, int& y, int& z);
	void LocalPositionToWorldPosition(int& x, int& y, int& z);
	void LocalPositionToWorldPosition(float& x, float& y, float& z);
};