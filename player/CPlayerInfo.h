class sPortablePickupInfo
{
public:
	int32_t modelIndex; //0x0000
	uint16_t maxPermitted; //0x0004
	uint16_t numCarried; //0x0006
}; //Size: 0x0008

class CPlayerHealthRecharge
{
public:
	float m_fRechargeScriptMultiplier; //0x0000
	float m_fMaxHealthToRechargeAsPercentage; //0x0004
	uint32_t m_uLastTimeHealthDamageTaken; //0x0008
}; //Size: 0x000C

class sNearVehicle
{
public:
	class CVehicle *veh; //0x0000
	uint32_t time; //0x0008
}; //Size: 0x000C

class CPlayerInfo
{
public:
	char pad_0000[32]; //0x0000
	class rlGamerInfo m_GamerInfo; //0x0020
	int32_t m_FriendStatus; //0x0110
	int32_t Team; //0x0114
	int32_t CollectablesPickedUp; //0x0118
	int32_t TotalNumCollectables; //0x011C
	class sPortablePickupInfo PortablePickupsInfo[20]; //0x0120
	uint32_t m_LastTimeHeliWasDestroyed; //0x01C0
	float m_fForceAirDragMult; //0x01C4
	float m_fSwimSpeedMultiplier; //0x01C8
	uint32_t LastTimeEnergyLost; //0x01CC
	uint32_t LastTimeArmourLost; //0x01D0
	uint32_t TimeSinceSwitch; //0x01D4
	int32_t HavocCaused; //0x01D8
	float m_fLastPlayerNearbyTimer; //0x01DC
	float m_fPutPedDirectlyIntoCoverNetworkBlendInDuration; //0x01E0
	float StealthRate; //0x01E4
	uint16_t CarDensityForCurrentZone; //0x01E8
	uint16_t m_nLastBustMessageNumber; //0x01EA
	uint16_t MaxHealth; //0x01EC
	uint16_t MaxArmour; //0x01EE
	uint32_t DetonateDownTime; //0x01F0
	bool bExplodedTriggeredProjectilesWithThisButtonPress; //0x01F4
	char pad_01F5[3]; //0x01F5
	int32_t m_sFireProofTimer; //0x01F8
	uint16_t JackSpeed; //0x01FC
	int8_t m_maxPortablePickupsCarried; //0x01FE
	int8_t m_numPortablePickupsCarried; //0x01FF
	uint32_t m_uLastTimeStopAiming; //0x0200
	uint32_t m_nearMissedDriverQueueIndex; //0x0204
	class CVehicle *m_lastNearMissedVehicles[5]; //0x0208
	int32_t m_PlayerState; //0x0230
	uint32_t m_TimeOfPlayerStateChange; //0x0234
	uint32_t m_TimeOfPlayerLastRespawn; //0x0238
	char pad_023C[4]; //0x023C
	class CPed *m_pPlayerPed; //0x0240
	class CVehicle *m_pLastTargetVehicle; //0x0248
	class CVehicle *m_pOnlyEnterThisVehicle; //0x0250
	class CVehicle *m_pPreferRearSeatsVehicle; //0x0258
	class CVehicle *m_pPreferFrontPassengerSeatVehicle; //0x0260
	class CPed *m_pSpotterOfStolenVehicle; //0x0268
	class CPlayerResetFlags m_PlayerResetFlags; //0x0270
	char pad_0278[52]; //0x0278
	uint32_t m_iNumEnemiesInCombat; //0x02AC
	uint32_t m_iNumEnemiesShootingInCombat; //0x02B0
	char pad_02B4[2700]; //0x02B4
	float m_fRunSprintSpeedMultiplier; //0x0D40
	float m_fSprintEnergy; //0x0D44
	float m_fMaxSprintEnergy; //0x0D48
	float m_fSprintControlCounter; //0x0D4C
	float m_fCachedSprintMultThisFrame; //0x0D50
	uint32_t m_uTimeBikeSprintPressed; //0x0D54
	uint32_t m_nLastChangeWeaponFrame; //0x0D58
	float m_fWeaponDamageModifier; //0x0D5C
	float m_fWeaponDefenseModifier; //0x0D60
	float m_fWeaponMinigunDefenseModifier; //0x0D64
	float m_fMeleeWeaponDamageModifier; //0x0D68
	float m_fMeleeUnarmedDamageModifier; //0x0D6C
	float m_fMeleeWeaponDefenseModifier; //0x0D70
	float m_fMeleeWeaponForceModifier; //0x0D74
	float m_fVehicleDamageModifier; //0x0D78
	float m_fVehicleDefenseModifier; //0x0D7C
	int32_t m_PlayerGroup; //0x0D80
	float m_fMaxExplosiveDamage; //0x0D84
	float m_fExplosiveDamageModifier; //0x0D88
	float m_fWeaponTakedownDefenseModifier; //0x0D8C
	uint32_t m_ParachuteSmokeTrailColor; //0x0D90
	uint32_t m_LastTimePlayerHitCar; //0x0D94
	uint32_t m_LastTimePlayerHitPed; //0x0D98
	uint32_t m_LastTimePlayerHitBuilding; //0x0D9C
	uint32_t m_LastTimePlayerHitObject; //0x0DA0
	uint32_t m_LastTimePlayerDroveOnPavement; //0x0DA4
	uint32_t m_LastTimePlayerRanLight; //0x0DA8
	uint32_t m_LastTimePlayerDroveAgainstTraffic; //0x0DAC
	uint32_t m_uTimeToEnableAgitation; //0x0DB0
	class CPlayerHealthRecharge m_healthRecharge; //0x0DB4
	char pad_0DC0[208]; //0x0DC0
	float m_StealthNoise; //0x0E90
	float m_fNormalStealthMultiplier; //0x0E94
	float m_fSneakingStealthMultiplier; //0x0E98
	float m_fDampenRootWeight; //0x0E9C
	float m_fDampenRootTargetWeight; //0x0EA0
	float m_fDampenRootTargetHeight; //0x0EA4
	uint32_t m_uLastTimePedMadeMobileCommentOnWeirdPlayer; //0x0EA8
	uint32_t m_uLastTimeDamagedLocalPlayer; //0x0EAC
	float m_fSimulateGaitMoveBlendRatio; //0x0EB0
	float m_fSimulateGaitHeading; //0x0EB4
	float m_fSimulateGaitDuration; //0x0EB8
	float m_fSimulateGaitTimerCount; //0x0EBC
	float m_fSimulateGaitStartHeading; //0x0EC0
	float m_fLaggedYawControl; //0x0EC4
	float m_fLaggedPitchControl; //0x0EC8
	float m_fLaggedRollControl; //0x0ECC
	float m_fLaggedSteerControl; //0x0ED0
	float m_fTimeBetweenRandomControlInputs; //0x0ED4
	float m_fRandomControlYaw; //0x0ED8
	float m_fRandomControlPitch; //0x0EDC
	float m_fRandomControlRoll; //0x0EE0
	float m_fRandomControlThrottle; //0x0EE4
	float m_fRandomControlSteerModifier; //0x0EE8
	float m_fControlSettledTime; //0x0EEC
	float m_fPreviousSteerValue; //0x0EF0
	float m_fTimeSinceApplyingRandomControl; //0x0EF4
	float m_fTimeSinceLastDrivingAtSpeed; //0x0EF8
	char pad_0EFC[20]; //0x0EFC
	float m_fStealthPerceptionModifier; //0x0F10
	uint32_t m_uTimeExitVehicleTaskFinished; //0x0F14
	class sNearVehicle m_nearVehicles[8]; //0x0F18
	char pad_0F78[100]; //0x0F78
	uint32_t m_SwitchedToOrFromFirstPersonCount; //0x0FDC
	uint32_t m_SwitchedToFirstPersonCount; //0x0FE0
	uint32_t m_SwitchedToFirstPersonFromThirdPersonCoverCount; //0x0FE4
	float m_fFallHeightOverride; //0x0FE8
	int32_t m_eSpecialAbilitiesMP[2]; //0x0FEC
	char pad_0FF4[104]; //0x0FF4
}; //Size: 0x105C