#pragma once
#include <raylib.h>
#include <vector>
#include "../Chunk.h"

class World
{
public:
	std::vector<Chunk> mLoadedChunks;
	World();
	void DrawWorld();
	Chunk LoadChunk(int chunkX, int chunkY, int chunkZ);
	void UnloadChunk(int chunkX, int chunkY, int chunkZ);
	void VoxelPosToChunkPos(int& x, int& y, int& z);
	void ChunkPosToVoxelPos(int& x, int& y, int& z);
};

