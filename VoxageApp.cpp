#pragma once
#include "VoxageApp.h"

VoxageApp::VoxageApp() {
	mCamera = Camera3D();
	mCamera.position = Vector3(-5, 1, 0); // Position the camera at -5 1 0
	mCamera.target = Vector3(0, 0, 0); // Face 0 0 0
	mCamera.up = Vector3(0, 1, 0); // Make the camera's up direction on the Y axis
	mCamera.fovy = 90; // Set the camera's FOV to 90
	mCamera.projection = CAMERA_PERSPECTIVE; // I honestly have yet to figure out what this means.

	mPlayer = Player();
	mPlayer.mX = -5;
	mPlayer.mY = 1;
	mPlayer.mZ = 0;
}

void VoxageApp::Draw() {
	BeginMode3D(mCamera);
	mWorld->DrawWorld();
	EndMode3D();
}

void VoxageApp::UpdateApp() {
	mCamera.position.x = mPlayer.mX;
	mCamera.position.y = mPlayer.mY;
	mCamera.position.z = mPlayer.mZ;
	mCamera.target.x = mPlayer.mX + 1;
	mCamera.target.y = mPlayer.mY;
	mCamera.target.z = mPlayer.mZ;
	mPlayer.UpdatePlayer();
}