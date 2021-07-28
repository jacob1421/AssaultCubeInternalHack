#include "pch.h"
#include "PlayerEntity.h"
#include <stdio.h>

int PlayerEntity::getHealth() {
	return this->health;
}
int PlayerEntity::getArmor() {
	return this->armor;
}
int PlayerEntity::getNades() {
	return this->nades;
}
int PlayerEntity::getKills() {
	return this->kills;
}
int PlayerEntity::getDeaths() {
	return this->deaths;
}
int PlayerEntity::getTeam() {
	return this->team;
}
char* PlayerEntity::getName() {
	return this->name;
}
vector3 PlayerEntity::getPosition() {
	return this->position;
}
vector2 PlayerEntity::getViewAngles() {
	return this->view_angles;
}
WeaponEntity* PlayerEntity::getWeaponPtr() {
	return this->currWeapon;
}

void PlayerEntity::toString() {
	printf("\nName: %s\nHealth: %i\nArmor:%i\nKills: %i\nDeaths: %i\nTeam: %i\nWeaponPointer: %p\n", this->name, this->health, this->armor, this->kills, this->deaths, this->team, ((DWORD*)this->currWeapon + 0xC));
	printf("Position = X: %.2f Y: %.2f Z: %.2f\n", this->position.x, this->position.y, this->position.z);
	printf("View Angles = Pitch: %.2f Yaw: %.2f", this->view_angles.pitch, this->view_angles.yaw);
}