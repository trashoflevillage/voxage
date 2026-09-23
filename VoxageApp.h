#pragma once
#include "World.h"
class VoxageApp
{
public:
	Camera3D mCamera;
	World* mWorld;
	VoxageApp();
	void Draw();
};

