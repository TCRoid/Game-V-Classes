class CPedWeaponManager
{
public:
	char pad_0000[16]; //0x0000
	class CPed *m_pPed; //0x0010
	class CPedWeaponSelector m_selector; //0x0018
	class CPedEquippedWeapon m_equippedWeapon; //0x0058
	class CWeaponInfo *m_pLastEquippedWeaponInfo; //0x0158
	class CPedAccuracy m_accuracy; //0x0160
	int32_t m_iEquippedVehicleWeaponIndex; //0x016C
	char m_equippedGadgets[2][8]; //0x0170
	uint32_t m_uEquippedWeaponHashBackup; //0x0180
	float m_fChanceToFireBlanksMin; //0x0184
	float m_fChanceToFireBlanksMax; //0x0188
	uint16_t m_RagdollConstraintHandle_index; //0x018C
	uint16_t m_phConstraintHandle_generation; //0x018E
	uint32_t m_uLastEquipOrFireTime; //0x0190
	bool m_bForceReloadOnEquip; //0x0194
	char pad_0195[11]; //0x0195
	Vector3 m_vWeaponAimPosition; //0x01A0
	char pad_01AC[4]; //0x01AC
	Vector3 m_vImpactPosition; //0x01B0
	char pad_01BC[4]; //0x01BC
	int32_t m_iImpactTime; //0x01C0
	uint32_t m_flags; //0x01C4
	uint32_t m_nInstruction; //0x01C8
}; //Size: 0x01CC


class CPedWeaponSelector
{
public:
	int32_t m_uSelectedWeaponHash; //0x0000
	char pad_0004[4]; //0x0004
	class CWeaponInfo *m_pSelectedWeaponInfo; //0x0008
	int32_t m_iSelectedVehicleWeaponIndex; //0x0010
	uint32_t m_uWeaponSelectTime; //0x0014
	uint32_t m_uNextConsiderSwitchTimeMS; //0x0018
	char pad_001C[36]; //0x001C
}; //Size: 0x0040


class CPedEquippedWeapon
{
public:
	class CPed *m_pPed; //0x0000
	bool m_bWeaponAnimsRequested; //0x0008
	bool m_bWeaponAnimsStreamed; //0x0009
	char pad_000A[6]; //0x000A
	class CWeaponInfo *m_pEquippedWeaponInfo; //0x0010
	class CWeaponInfo *m_pEquippedVehicleWeaponInfo; //0x0018
	class CObject *m_pObject; //0x0020
	class CObject *m_pSecondObject; //0x0028
	class CWeapon *m_pUnarmedWeapon; //0x0030
	class CWeapon *m_pUnarmedKungFuWeapon; //0x0038
	class CWeapon *m_pWeaponNoModel; //0x0040
	char pad_0048[184]; //0x0048
}; //Size: 0x0100


class CPedAccuracy : public CPedAccuracyResetVariables
{
public:
	float m_fNormalisedTimeFiring; //0x0008
}; //Size: 0x000C

