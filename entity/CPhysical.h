class CPhysicalFlags
{
public:
	uint32_t m_nPhysicalFlags_1; //0x0000
	uint32_t m_nPhysicalFlags_2; //0x0004
}; //Size: 0x0008

class CPhysical
{
public:
	char pad_0000[392]; //0x0000
	class CPhysicalFlags m_nPhysicalFlags; //0x0188
	uint32_t m_bDontResetDamageFlagsOnCleanupMissionState; //0x0190
	char pad_0194[236]; //0x0194
	float m_fHealth; //0x0280
	float m_fMaxHealth; //0x0284
	class WeaponDamageInfos (*m_pWeaponDamageInfos)[3]; //0x0288
	char pad_0290[72]; //0x0290
	class CEntity *m_canOnlyBeDamagedByEntity; //0x02D8
	class CEntity *m_cantBeDamagedByEntity; //0x02E0
	char pad_02E8[344]; //0x02E8
}; //Size: 0x0440
