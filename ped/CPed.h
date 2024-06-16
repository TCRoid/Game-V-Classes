// Created with ReClass.NET 1.2 by KN4CK3R

class CPedConfigFlags
{
public:
	uint32_t m_Flags; //0x0000
	float fClimbRateOverride; //0x0004
	uint32_t m_Flags_0; //0x0008
	uint32_t m_Flags_1; //0x000C
	uint32_t m_Flags_2; //0x0010
	uint32_t m_Flags_3; //0x0014
	uint32_t m_Flags_4; //0x0018
	uint32_t m_Flags_5; //0x001C
	uint32_t m_Flags_6; //0x0020
	uint32_t m_Flags_7; //0x0024
	uint32_t m_Flags_8; //0x0028
	uint32_t m_Flags_9; //0x002C
	uint32_t m_Flags_10; //0x0030
	uint32_t m_Flags_11; //0x0034
	uint32_t m_Flags_12; //0x0038
	uint32_t m_Flags_13; //0x003C
	uint32_t m_Flags_14; //0x0040
}; //Size: 0x0044

class CPedResetFlags
{
public:
	uint8_t m_nKnockedByDoor; //0x0000
	uint8_t m_nSetEntityZFromGround; //0x0001
	char pad_0002[2]; //0x0002
	uint32_t m_Flags; //0x0004
	float m_fAnimRotationModifier; //0x0008
	float m_fRootCorrectionModifer; //0x000C
	float m_fMoveAnimRate; //0x0010
	float m_fScriptedScaleBetweenSeatsDefaultDistance; //0x0014
	float m_fEntityZFromGroundZHeight; //0x0018
	float m_fEntityZFromGroundZThreshold; //0x001C
	char pad_0020[48]; //0x0020
}; //Size: 0x0050

class DeathInfo
{
public:
	class CEntity *m_Source; //0x0000
	uint32_t m_Weapon; //0x0008
	uint32_t m_Time; //0x000C
}; //Size: 0x0010

class CPed
{
public:
	char pad_0000[4256]; //0x0000
	class CPedIntelligence *m_pPedIntelligence; //0x10A0
	class CPlayerInfo *m_pPlayerInfo; //0x10A8
	class CPedInventory *m_inventory; //0x10B0
	class CPedWeaponManager *m_weaponManager; //0x10B8
	char pad_10C0[892]; //0x10C0
	class CPedConfigFlags m_PedConfigFlagBitSet; //0x143C
	class CPedResetFlags m_PedResetFlags; //0x1480
	char pad_14D0[48]; //0x14D0
	float m_nHealthLostScript; //0x1500
	float m_fMaxEndurance; //0x1504
	float m_fEndurance; //0x1508
	float m_nArmour; //0x150C
	float m_nArmourLost; //0x1510
	float m_fFatiguedHealthThreshold; //0x1514
	float m_fInjuredHealthThreshold; //0x1518
	float m_fDyingHealthThreshold; //0x151C
	float m_fHurtHealthThreshold; //0x1520
	float m_fNMAccumulate; //0x1524
	uint32_t m_cachedBoneSignature; //0x1528
	char pad_152C[4]; //0x152C
	class CVehicle *m_pMyVehicle; //0x1530
	char pad_1538[176]; //0x1538
	class CPedVfx *m_pPedVfx; //0x15E8
	uint8_t m_uRenderDelayFlags; //0x15F0
	char pad_15F1[3]; //0x15F1
	uint32_t m_uRenderFlagFrameCount; //0x15F4
	int32_t m_ShaveTimeInSeconds; //0x15F8
	uint32_t m_HurtEndTime; //0x15FC
	class DeathInfo m_DeathInfo; //0x1600
	float m_fAccumulatedFire; //0x1610
	uint32_t m_MoneyCarried; //0x1614
	uint16_t m_nInteriorFreeze_WasInsideCounter; //0x1618
	int16_t m_StreamedScriptBrainToLoad; //0x161A
	float m_fMaxTimeInWater; //0x161C
	float m_fMaxTimeUnderwater; //0x1620
	float m_OverrideMaxTimeInWater; //0x1624
	int32_t m_MinOnGroundTimeForStunGun; //0x1628
	int32_t m_lastSignificantShotBoneTag; //0x162C
	uint8_t m_iPedGroupIndex; //0x1630
	uint8_t m_InDangerTimer; //0x1631
	uint8_t m_OverhangConstraintCountdown; //0x1632
	uint8_t m_hiLodFadeValue; //0x1633
	char pad_1634[812]; //0x1634
	uint8_t m_uStickyCount; //0x1960
	uint8_t m_uStickToPedProjCount; //0x1961
	uint8_t m_uFlareGunProjCount; //0x1962
	int8_t m_iFailedQPedRagdollTests; //0x1963
	uint8_t m_modelLodIdx; //0x1964
	uint8_t m_uWeaponAnimationsIndex; //0x1965
	uint8_t m_iPhonePaletteIdx; //0x1966
	char pad_1967[13]; //0x1967
	uint8_t m_PedBitSet; //0x1974
	char pad_1975[79]; //0x1975
}; //Size: 0x19C4