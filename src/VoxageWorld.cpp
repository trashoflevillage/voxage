#include "VoxageWorld.h"
#include "raylib.h"

VoxageWorld::VoxageWorld() {
	mCamera = Camera3D();
	mCamera.position = Vector3(-5, 1, 0);
	mCamera.target = Vector3(0, 0, 0);
	mCamera.up = Vector3(0, 1, 0);
	mCamera.fovy = 90;
	mCamera.projection = CAMERA_PERSPECTIVE;
}

void VoxageWorld::DrawWorld() {
	BeginMode3D(mCamera);
	DrawGrid(20, 1.0f);
	DrawCube(Vector3(0, 0, 0), 1, 1, 1, Color(255, 0, 0, 255));
	EndMode3D();
}