#include "Player.h"
#include "raylib.h"

Player::Player() {
}

void Player::UpdatePlayer() {
	if (IsKeyDown(KEY_W)) mX += 0.1;
	if (IsKeyDown(KEY_S)) mX -= 0.1;
	if (IsKeyDown(KEY_A)) mZ -= 0.1;
	if (IsKeyDown(KEY_D)) mZ += 0.1;
}