#pragma once
#include "World.h"
#include "raylib.h"

World::World() {
	LoadChunk(0, 0, 0);
}

void World::DrawWorld() {
	DrawGrid(20, 1.0f);
	for (Chunk c : mLoadedChunks) {
		c.DrawChunk();
	}
}

/// <summary>
/// Loads a chunk at the provided chunk position.
/// </summary>
/// <param name="chunkX"></param>
/// <param name="chunkY"></param>
/// <param name="chunkZ"></param>
/// <returns></returns>
Chunk World::LoadChunk(int chunkX, int chunkY, int chunkZ) {
	Chunk chunk = Chunk();
	for (int x = 0; x < CHUNK_SIZE; x++) {
		for (int y = 0; y < CHUNK_SIZE; y++) {
			for (int z = 0; z < CHUNK_SIZE; z++) {
				if (y < CHUNK_SIZE / 2) 
				{
					if (((float)rand() / RAND_MAX) < 0.5f) chunk.mVoxelStates[x][y][z] = 2;
					else chunk.mVoxelStates[x][y][z] = 1;
				}
				else chunk.mVoxelStates[x][y][z] = 0;
			}
		}
	}
	mLoadedChunks.push_back(chunk);
	chunk.mChunkX = chunkX;
	chunk.mChunkY = chunkY;
	chunk.mChunkZ = chunkZ;
	chunk.mWorld = this;
	return chunk;
}

/// <summary>
/// Unloads a chunk at the provided chunk position.
/// </summary>
/// <param name="chunkX"></param>
/// <param name="chunkY"></param>
/// <param name="chunkZ"></param>
void World::UnloadChunk(int chunkX, int chunkY, int chunkZ) {
	for (int i = 0; i < mLoadedChunks.size(); i++) {
		Chunk c = mLoadedChunks.at(i);
		if (c.mChunkX == chunkX && c.mChunkY == chunkY && c.mChunkZ == chunkZ) {
			mLoadedChunks.erase(mLoadedChunks.begin() + i);
		}
	}
}

/// <summary>
/// Converts a voxel position to a chunk position.
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
void World::VoxelPosToChunkPos(int& x, int& y, int& z) {
	float newX = (float)x / CHUNK_SIZE;
	float newY = (float)y / CHUNK_SIZE;
	float newZ = (float)z / CHUNK_SIZE;
	x = floor(newX);
	y = floor(newY);
	z = floor(newZ);
}

/// <summary>
/// Converts a chunk position to a voxel position.
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
void World::ChunkPosToVoxelPos(int& x, int& y, int& z) {
	x *= CHUNK_SIZE;
	y *= CHUNK_SIZE;
	z *= CHUNK_SIZE;
}