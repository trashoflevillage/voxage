#pragma once
#include "Chunk.h"
#include "raylib.h"
#include <algorithm>

void Chunk::DrawChunk() {
	int x = -1, y = -1, z = -1;
	while (IterateVoxelPositions(x, y, z)) {
		if (mVoxelStates[x][y][z] != 0) {
			int worldX = x, worldY = y, worldZ = z;
			LocalPositionToWorldPosition(worldX, worldY, worldZ);
			Color color = Color(255, 0, 0, 255);
			if (mVoxelStates[x][y][z] == 2) color = Color(0, 0, 255, 255);
			DrawCube(Vector3(worldX, worldY, worldZ), 1, 1, 1, color);
		}
	}
}

/// <summary>
/// Iterates through all of the local voxel positions in a chunk.
/// Each parameter should be equal to -1 on the first call.
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
/// <returns></returns>
bool Chunk::IterateVoxelPositions(int& x, int& y, int& z) {
	y = std::max(0, y);
	z = std::max(0, z);
	x++;
	if (x == CHUNK_SIZE) {
		x = 0;
		z++;
		if (z == CHUNK_SIZE) {
			z = 0;
			y++;
			if (y == CHUNK_SIZE) {
				return false;
			}
		}
	}
	return true;
}

void Chunk::LocalPositionToWorldPosition(int& x, int& y, int& z) {
	x += CHUNK_SIZE * mChunkX;
	y += CHUNK_SIZE * mChunkY;
	z += CHUNK_SIZE * mChunkZ;
}

void Chunk::LocalPositionToWorldPosition(float& x, float& y, float& z) {
	x += CHUNK_SIZE * mChunkX;
	y += CHUNK_SIZE * mChunkY;
	z += CHUNK_SIZE * mChunkZ;
}