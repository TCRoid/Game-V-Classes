class CVehicleWeaponMgr
{
public:
	class CTurret *m_pTurrets[12]; //0x0000
	class CVehicleWeapon *m_pVehicleWeapons[6]; //0x0060

	int32_t m_WeaponSeatIndices[6]; //0x0090
	int32_t m_TurretSeatIndices[12]; //0x00A8
	int32_t m_TurretWeaponIndices[12]; //0x00D8
	
	int32_t m_iNumTurrets; //0x0108
	int32_t m_iNumVehicleWeapons; //0x010C
}; //Size: 0x0110
