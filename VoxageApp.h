#pragma once
#include "World.h"
#include "Player.h"
class VoxageApp
{
public:
	Camera3D mCamera;
	World* mWorld;
	Player mPlayer;
	VoxageApp();
	void Draw();
	void UpdateApp();
};

