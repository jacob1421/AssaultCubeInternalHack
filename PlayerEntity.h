#ifndef PLAYER_ENT
#define PLAYER_ENT

struct vector3 {
	float x;
	float y;
	float z;
};
struct vector2 {
	float yaw;
	float pitch;
};

class PlayerEntity{
	private:
		char pad_0000[4]; //0x0000
		vector3 position; //0x0004
		char pad_0010[48]; //0x0010
		vector2 view_angles; //0x0040
		char pad_0048[176]; //0x0048
		__int32 health; //0x00F8
		__int32 armor; //0x00FC
		char pad_0100[60]; //0x0100
		int pistolAmmo; //0x013C
		__int32 carbineAmmo; //0x0140
		__int32 shotgunAmmo; //0x0144
		__int32 subMachineGunAmmo; //0x0148
		__int32 sniperAmmo; //0x014C
		__int32 assualtAmmo; //0x0150
		char pad_0154[4]; //0x0154
		__int32 nades; //0x0158
		char pad_015C[160]; //0x015C
		__int32 kills; //0x01FC
		char pad_0200[4]; //0x0200
		__int32 deaths; //0x0204
		char pad_0208[29]; //0x0208
		char name[16]; //0x0224
		char pad_0234[247]; //0x0234
		__int32 team; //0x032C
		char pad_0330[72]; //0x0330
		class WeaponEntity * currWeapon; //0x0378
		char pad_037C[3296]; //0x037C


	public:
		vector3 getPosition();
		vector2 getViewAngles();
		int getHealth();
		int getArmor();
		int getNades();
		int getKills();
		int getDeaths();
		int getTeam();
		char* getName();
		void toString();
		WeaponEntity* getWeaponPtr();
		void updateWeaponPtr();
};

#endif