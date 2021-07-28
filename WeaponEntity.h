#ifndef WEAPON_ENT
#define WEAPON_ENT
class WeaponEntity{
	private:
		char gun_name[8]; //0x0000
		char pad_0008[78]; //0x0008
	public:
		char* getGunName();
};
#endif