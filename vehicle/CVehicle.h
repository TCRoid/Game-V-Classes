// Created with ReClass.NET 1.2 by KN4CK3R

class ScriptOverridesNitrous
{
public:
	bool isOverrideActive; //0x0000
	char pad_0001[3]; //0x0001
	float durationModifier; //0x0004
	float powerModifier; //0x0008
	float rechargeRateModifier; //0x000C
	bool disableDefaultSound; //0x0010
	char pad_0011[19]; //0x0011
}; //Size: 0x0024

class CTransmission
{
public:
	int16_t m_nGear; //0x0000
	int16_t m_nPrevGear; //0x0002
	int16_t m_nFlags; //0x0004
	uint8_t m_nDriveGears; //0x0006
	char pad_0007[1]; //0x0007
	bool m_bKERSAllowed; //0x0008
	char pad_0009[3]; //0x0009
	float m_aGearRatios[11]; //0x000C
	char pad_0038[52]; //0x0038
	float m_fThrottleBlipAmount; //0x006C
	float m_fThrottleBlipTimer; //0x0070
	uint32_t m_fThrottleBlipStartTime; //0x0074
	uint32_t m_fThrottleBlipDuration; //0x0078
	float m_fManifoldPressure; //0x007C
	uint32_t m_nGearChangeTime; //0x0080
	uint32_t m_UnderLoadChangeUpDelay; //0x0084
	float m_fMissFireTime; //0x0088
	float m_fOverrideMissFireTime; //0x008C
	float m_fEngineHealth; //0x0090
	float m_fEngineHealthDamageScale; //0x0094
	float m_fFireEvo; //0x0098
	char pad_009C[4]; //0x009C
	class CEntity *m_pEntityThatSetUsOnFire; //0x00A0
	float m_fForceThrottle; //0x00A8
	float m_fRemainingNitrousDuration; //0x00AC
	float m_fRemainingKERS; //0x00B0
	char pad_00B4[12]; //0x00B4
	float m_fPlaneDamageThresholdOverride; //0x00C0
	float m_fBoatDriveForce; //0x00C4
	float m_fLastCalculatedDriveForce; //0x00C8
	char pad_00CC[20]; //0x00CC
}; //Size: 0x00E0

class CVehicleFlags
{
public:
	uint32_t m_nVehicleFlags_0; //0x0000
	uint32_t m_nVehicleFlags_1; //0x0004
	uint32_t m_nVehicleFlags_2; //0x0008
	uint32_t m_nVehicleFlags_3; //0x000C
	uint32_t m_nVehicleFlags_4; //0x0010
	uint32_t m_nVehicleFlags_5; //0x0014
	uint32_t m_nVehicleFlags_6; //0x0018
	uint32_t m_nVehicleFlags_7; //0x001C
	uint32_t m_nVehicleFlags_8; //0x0020
}; //Size: 0x0024

class CVehicleLightSwitch
{
public:
	class CVehicle *m_pParentVehicle; //0x0000
}; //Size: 0x0008

class CSeatManager
{
public:
	int8_t m_iNoSeats; //0x0000
	int8_t m_iDriverSeat; //0x0001
	uint8_t m_nNumPlayers; //0x0002
	uint8_t m_nNumScheduledOccupants; //0x0003
	uint8_t m_bHasEverHadOccupant; //0x0004
	char pad_0005[3]; //0x0005
	class CPed *m_pSeatOccupiers[16]; //0x0008
	class CPed *m_pLastSeatOccupiers[16]; //0x0088
	class CPed *m_pLastDriverFromNetwork; //0x0108
}; //Size: 0x0110

class CVehicle
{
public:
	char pad_0000[760]; //0x0000
	bool m_bIsRocketBoosting; //0x02F8
	bool m_bRocketBoostedFromNetwork; //0x02F9
	bool m_bRocketBoostedStoppedFromNetwork; //0x02FA
	bool m_bCanRechargeRocketBoost; //0x02FB
	bool m_bTriggerRefillBoostEffect; //0x02FC
	bool m_bHasRocketBoostFXStarted; //0x02FD
	char pad_02FE[2]; //0x02FE
	float m_fRocketBoostRemaining; //0x0300
	float m_fRocketBoostRechargeRate; //0x0304
	uint32_t m_boostToggledTime; //0x0308
	bool m_nitrousActive; //0x030C
	char pad_030D[3]; //0x030D
	class ScriptOverridesNitrous m_scriptOverridesNitrous; //0x0310
	float m_fOverridenPlaceOnRoadHeight; //0x0334
	bool m_bHomingCanLockOnToObjects; //0x0338
	char pad_0339[3]; //0x0339
	uint32_t m_ParachuteModelHash; //0x033C
	char pad_0340[68]; //0x0340
	uint32_t m_carJumpState; //0x0384
	bool m_bDoingJump; //0x0388
	char pad_0389[3]; //0x0389
	float m_fCarJumpTimer; //0x038C
	Vector3 m_vCarJumpGroundNormal; //0x0390
	char pad_039C[4]; //0x039C
	float m_fJumpRechargeTimer; //0x03A0
	bool m_bDoHigherJump; //0x03A4
	char pad_03A5[1115]; //0x03A5
	Vector3 m_vecLastStuckPos; //0x0800
	char pad_080C[4]; //0x080C
	Vector3 m_vecLastStuckJammedPos; //0x0810
	char pad_081C[4]; //0x081C
	uint16_t m_nStuckCounterOnRoof; //0x0820
	uint16_t m_nStuckCounterOnSide; //0x0822
	uint16_t m_nStuckCounterHungUp; //0x0824
	uint16_t m_nStuckCounterJammed; //0x0826
	class CVehicle *m_pParent; //0x0828
	float m_fBodyHealth; //0x0830
	float m_fPetrolTankHealth; //0x0834
	float m_fBodyDamageScale; //0x0838
	float m_fPetrolTankDamageScale; //0x083C
	float m_fCollisionWithMapDamageScale; //0x0840
	float m_fPetrolTankLevel; //0x0844
	float m_fOilLevel; //0x0848
	char pad_084C[4]; //0x084C
	void *m_pEntityThatSetUsOnFire; //0x0850
	float m_fCountDownToTimeAnotherPartCanBreakOff; //0x0858
	char pad_085C[8]; //0x085C
	bool m_UpdateLightBones; //0x0864
	bool m_UpdateSirenBones; //0x0865
	bool m_bHasHandBrake; //0x0866
	bool m_bDisableDamageWithPickedUpEntity; //0x0867
	float m_fPadShakeIntensity; //0x0868
	uint8_t m_uPadShakeDuration; //0x086C
	char pad_086D[3]; //0x086D
	float m_fDynamicSpoilerDamage; //0x0870
	float m_fScriptDamageScale; //0x0874
	float m_fScriptWeaponDamageScale; //0x0878
	char pad_087C[4]; //0x087C
	class CTransmission m_Transmission; //0x0880
	class CHandlingData *pHandling; //0x0960
	class CVehicleFlags m_nVehicleFlags; //0x0968
	char pad_098C[144]; //0x098C
	int32_t m_Swankness; //0x0A1C
	float m_fBodyDirtLevel; //0x0A20
	uint32_t m_bodyDirtColor; //0x0A24
	class CVehicleLightSwitch m_VehicleLightSwitch; //0x0A28
	uint32_t m_FlashHeadLights; //0x0A30
	uint32_t m_TimeFullBeamSwitchedOn; //0x0A34
	uint32_t m_KeepLightsOnForWeatherTime; //0x0A38
	float m_HeadlightMultiplier; //0x0A3C
	uint8_t LightsBitset; //0x0A40
	bool m_usePlayerLightSettings; //0x0A41
	uint8_t m_prevNaturalAmbientScale; //0x0A42
	uint8_t m_prevArtificialAmbientScale; //0x0A43
	uint32_t m_nFixedWaitingForCollisionCheckTimer; //0x0A44
	uint32_t m_eHomingLockOnState; //0x0A48
	uint32_t m_eHomingLockedOntoState; //0x0A4C
	float m_fTargetableDistance; //0x0A50
	float m_fHomingProjectileDistance; //0x0A54
	int8_t m_nHomingLockOnStateResetFrame; //0x0A58
	int8_t m_nHomingLockedOntoStateResetFrame; //0x0A59
	int8_t m_nHomingProjectileDistanceResetFrame; //0x0A5A
	uint8_t m_AirResistanceState; //0x0A5B
	uint32_t m_uLastTimeHomedAt; //0x0A5C
	class CPhysical *m_pLockOnTarget; //0x0A60
	class CPhysical *m_pGroundPhysical; //0x0A68
	uint32_t m_uGroundPhysicalTime; //0x0A70
	uint32_t m_iFullThrottleRecoveryTime; //0x0A74
	bool m_bFullThrottleActive; //0x0A78
	char pad_0A79[7]; //0x0A79
	class CPed *m_pExclusiveDriverPeds[3]; //0x0A80
	uint32_t m_wheelBrokenIndex; //0x0A98
	float m_fFrictionOverride; //0x0A9C
	float m_fDragCoeff; //0x0AA0
	float m_EngineTemperature; //0x0AA4
	uint32_t m_EngineSwitchedOnTime; //0x0AA8
	uint32_t m_nDisableExtras; //0x0AAC
	uint32_t m_iLastActivationTime; //0x0AB0
	uint32_t m_iNextValidHornTime; //0x0AB4
	bool m_bProducingSlipStreamForOther; //0x0AB8
	char pad_0AB9[3]; //0x0AB9
	float m_fTimeInSlipStream; //0x0ABC
	float m_fTimeProducingSlipStream; //0x0AC0
	float m_fSlipStreamRechargeAndDechargeTimer; //0x0AC4
	float m_fTimeInAir; //0x0AC8
	float m_fTimeInAirCrash; //0x0ACC
	float m_fTimeTouchingPavement; //0x0AD0
	float m_fSpeedToRestoreAfterFix; //0x0AD4
	float m_fPreviousSpeedForDash; //0x0AD8
	uint32_t m_dialsRequestFrame; //0x0ADC
	uint16_t CarAlarmState; //0x0AE0
	uint8_t m_failedEngineStartAttempts; //0x0AE2
	bool m_failNextEngineStartAttempt; //0x0AE3
	bool m_bInAirCrash; //0x0AE4
	bool m_bAllowRemoteDamageOnCreation; //0x0AE5
	bool m_bNoDamageFromExplosionsOwnedByDriver; //0x0AE6
	bool m_pedRemoteUsingDoor; //0x0AE7
	bool m_remoteDriverDoorClosing; //0x0AE8
	bool m_forceLightsOnAtNightRandomisationTime; //0x0AE9
	bool m_forceLightsOffAtMorningRandomisationTime; //0x0AEA
	bool m_bSuppressNeons; //0x0AEB
	bool m_bVehicleOccupantsTakeExplosiveDamage; //0x0AEC
	bool m_bCanEjectPassengersIfLocked; //0x0AED
	bool m_bAllowHomingMissleLockOnSynced; //0x0AEE
	bool m_bSpecialEnterExit; //0x0AEF
	bool m_bDontProcessVehicleGlass; //0x0AF0
	bool m_bTyresDontBurstToRim; //0x0AF1
	bool m_bDriftTyres; //0x0AF2
	bool m_bUseDesiredZCruiseSpeedForLanding; //0x0AF3
	bool m_bDontResetTurretHeadingInScriptedCamera; //0x0AF4
	bool m_bDontOpenRearDoorsOnExplosion; //0x0AF5
	bool m_bOnlyStartVehicleEngineOnThrottle; //0x0AF6
	bool m_bClearWaitingOnCollisionOnPlayerEnter; //0x0AF7
	bool m_bUseMPDamageMultiplierForPlayerVehicle; //0x0AF8
	bool m_bShouldVehicleExplodesOnExplosionDamageAtZeroBodyHealth; //0x0AF9
	bool m_bBlockDueToEnterExit; //0x0AFA
	bool m_bDisablePlayerCanStandOnTop; //0x0AFB
	bool m_bSubmarineCarTransformPrevented; //0x0AFC
	bool m_bDisableWantedConesResponse; //0x0AFD
	bool m_bHasDeformationBeenApplied; //0x0AFE
	char pad_0AFF[13]; //0x0AFF
	bool m_bAirDefenceExplosionTriggered; //0x0B0C
	char pad_0B0D[7]; //0x0B0D
	int32_t m_uTimeAirDefenceExplosionTriggered; //0x0B14
	float m_VehicleTopSpeedPercent; //0x0B18
	float m_fOverrideArriveDistForVehPersuitAttack; //0x0B1C
	int32_t m_LaunchedInAirTimer; //0x0B20
	int32_t m_ForcedMaximumUpdateRateTimer; //0x0B24
	uint32_t m_kersToggledTime; //0x0B28
	char pad_0B2C[268]; //0x0B2C
	class CCarDoor *m_pDoors; //0x0C38
	int32_t m_nNumDoors; //0x0C40
	bool m_bWindowsRolledDown[7]; //0x0C44
	char pad_0C4B[1]; //0x0C4B
	int32_t m_iWindowComponent[9]; //0x0C4C
	class CVehicleWeaponMgr *m_pVehicleWeaponMgr; //0x0C70
	class CVehicleGadget *m_pVehicleGadgets; //0x0C78
	char pad_0C80[8]; //0x0C80
	float m_fVerticalVelocityToKnockOffThisBike; //0x0C88
	float m_fGravityForWheelIntegrator; //0x0C8C
	class CSeatManager m_SeatManager; //0x0C90
	char pad_0DA0[1324]; //0x0DA0
	int32_t m_iRestrictedAmmoCount[6]; //0x12CC
	int32_t m_iBombAmmoCount; //0x12E4
	int32_t m_iCountermeasureAmmoCount; //0x12E8
	char pad_12EC[120]; //0x12EC
}; //Size: 0x1364