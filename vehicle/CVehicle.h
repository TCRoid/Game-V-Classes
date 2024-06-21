class CVehicle : public CPhysical
{
public:
	char pad_0000[760]; //0x0000

	// Boost state flag
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

	// Place on road probe heights
	float m_fOverridenPlaceOnRoadHeight; //0x0334

	// Flags whether the vehicle weapons can lock on to script flagged objects
	bool m_bHomingCanLockOnToObjects; //0x0338
	char pad_0339[3]; //0x0339

	uint32_t m_ParachuteModelHash; //0x033C
	char pad_0340[68]; //0x0340


	enum ECarJumpState
	{
		NOT_JUMPING,
		JUMPING,
		IN_AIR_STABILISATION,
		HOVER_CAR_END
	};
	// Tracks the current state of the jump
	uint32_t m_carJumpState; //0x0384

	// Flag accessible to the world to start/cancel jump
	bool m_bDoingJump; //0x0388
	char pad_0389[3]; //0x0389

	// Timer used for transitioning between jump states
	float m_fCarJumpTimer; //0x038C

	// Ground normal for measuring angles to stabilise vehicle mid-jump
	Vector3 m_vCarJumpGroundNormal; //0x0390
	char pad_039C[4]; //0x039C

	// Jump recharge timer
	float m_fJumpRechargeTimer; //0x03A0

	// Extra jump strength, to be set by script and used on missions
	bool m_bDoHigherJump; //0x03A4

	char pad_03A5[1115]; //0x03A5

	// ====== CVehicleDamage START ======

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

	// ====== CVehicleDamage END ======

	class CTransmission m_Transmission; //0x0880

	class CHandlingData *pHandling; //0x0960
	
	class CVehicleFlags m_nVehicleFlags; //0x0968

	char pad_098C[144]; //0x098C

	// rendering / effects
	enum eSwankness // 0 = crap, 5 = super nice
	{
		SWANKNESS_0 = 0,
		SWANKNESS_1,
		SWANKNESS_2,
		SWANKNESS_3,
		SWANKNESS_4,
		SWANKNESS_5
	};
	int32_t m_Swankness; //0x0A1C
	// Dirt level of vehicle body texture: 0.0f=fully clean, 15.0f=maximum dirt visible, it may be altered at any time while vehicle's cycle of lige
	float m_fBodyDirtLevel; //0x0A20
	uint32_t m_bodyDirtColor; //0x0A24

	// lights
	class CVehicleLightSwitch m_VehicleLightSwitch; //0x0A28
	uint32_t m_FlashHeadLights; //0x0A30
	uint32_t m_TimeFullBeamSwitchedOn; //0x0A34
	uint32_t m_KeepLightsOnForWeatherTime; //0x0A38
	float m_HeadlightMultiplier; //0x0A3C

	//0x0A40
	uint8_t m_OverrideLights : 3;			// 0~2	// uses enum NO_CAR_LIGHT_OVERRIDE, FORCE_CAR_LIGHTS_OFF, FORCE_CAR_LIGHTS_ON, SET_CAR_LIGHTS_OFF, SET_CAR_LIGHTS_ON
	uint8_t m_HeadlightShadows : 2;			// 3~4	// uses bit flags HEADLIGHTS_CAST_DYNAMIC_SHADOWS, HEADLIGHTS_CAST_STATIC_SHADOWS, HEADLIGHTS_CAST_FULL_SHADOWS
	uint8_t m_AmbientScaleOverriden : 1;	// 5
	uint8_t m_bInteriorLightForceOn : 1;	// 6	// Force interior lights to be on (like m_nVehicleFlags.bInteriorLightOn, but ignores day/night fade)
	uint8_t m_padding : 1;					// 7

	enum eOverrideLights {
		NO_CAR_LIGHT_OVERRIDE = 0,
		FORCE_CAR_LIGHTS_OFF = 1,
		FORCE_CAR_LIGHTS_ON = 2,
		SET_CAR_LIGHTS_ON = 3,
		SET_CAR_LIGHTS_OFF = 4
	};
	enum eHeadlightShadows {
		NO_HEADLIGHT_SHADOWS			= 0x0,
		HEADLIGHTS_CAST_DYNAMIC_SHADOWS = 0x1,
		HEADLIGHTS_CAST_STATIC_SHADOWS  = 0x2,
		HEADLIGHTS_CAST_FULL_SHADOWS    = 0x3,
	};

	bool m_usePlayerLightSettings; //0x0A41
	uint8_t m_prevNaturalAmbientScale; //0x0A42
	uint8_t m_prevArtificialAmbientScale; //0x0A43

	uint32_t m_nFixedWaitingForCollisionCheckTimer; //0x0A44

	enum eHomingLockOnState {
		HLOnS_NONE,
		HLOnS_ACQUIRING,
		HLOnS_ACQUIRED,
	};
	// Is this vehicle locked onto a target?  - Value gets reset every frame and set by other systems
	uint32_t m_eHomingLockOnState; //0x0A48
	// Is something locked onto this vehicle? - Value gets reset every frame and set by other systems
	uint32_t m_eHomingLockedOntoState; //0x0A4C

	// The los targeting checks for lock on pass within this distance
	float m_fTargetableDistance; //0x0A50

	// The distance to the closest homing projectile
	float m_fHomingProjectileDistance; //0x0A54

	int8_t m_nHomingLockOnStateResetFrame; //0x0A58
	int8_t m_nHomingLockedOntoStateResetFrame; //0x0A59
	int8_t m_nHomingProjectileDistanceResetFrame; //0x0A5A

	uint8_t m_AirResistanceState; //0x0A5B
	uint32_t m_uLastTimeHomedAt; //0x0A5C

	// The object being targetted
	class CPhysical *m_pLockOnTarget; //0x0A60

	// Ground physical used when wheels aren't touching the ground (i.e. when vehicle is flipped)
	class CPhysical *m_pGroundPhysical; //0x0A68

	uint32_t m_uGroundPhysicalTime; //0x0A70
	uint32_t m_iFullThrottleRecoveryTime; //0x0A74
	bool m_bFullThrottleActive; //0x0A78
	char pad_0A79[7]; //0x0A79

	// If set, only these peds can drive this vehicle.
	class CPed *m_pExclusiveDriverPeds[3]; //0x0A80

	uint32_t m_wheelBrokenIndex; //0x0A98
	float m_fFrictionOverride; //0x0A9C
	float m_fDragCoeff; //0x0AA0

	// Between ambient temperature and 100 degrees. Affects engine starting.
	float m_EngineTemperature; //0x0AA4
	// This is in place until the audio scripts take over the responsibility of switching on the engine
	uint32_t m_EngineSwitchedOnTime; //0x0AA8

	// bit masks for the different extra rules setups
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

	// Air defence flag/explosion timer
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


class CVehicleLightSwitch
{
public:
	class CVehicle *m_pParentVehicle; //0x0000
}; //Size: 0x0008

