class CPlayerInfo : public fwExtensibleBase
{
public:
    char pad_0000[32]; //0x0000

    class rlGamerInfo m_GamerInfo; //0x0020

    enum
    {
        FRIEND_UNKNOWN = 0,
        FRIEND_NOTFRIEND = 1,
        FRIEND_ISFRIEND = 2,
    };
    int32_t m_FriendStatus; //0x0110

    // The player's team (in network game)
    int32_t Team; //0x0114

    // How many bags of sugar do we have
    int32_t CollectablesPickedUp; //0x0118
    // How many bags of sugar are there to be had in the game
    int32_t TotalNumCollectables; //0x011C
    // used to limit the maxium number of a portable pickup type carried
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

    // Time for fire proof after recovering from being set on fire 
    int32_t m_sFireProofTimer; //0x01F8

    // NETWORK_PLAYER_DEFAULT_JACK_SPEED = 90
    uint16_t JackSpeed; //0x01FC

    // the maximum number of portable pickups of any type the player can carry
    int8_t m_maxPortablePickupsCarried; //0x01FE
    // the current number of portable pickups being carried
    int8_t m_numPortablePickupsCarried; //0x01FF

    uint32_t m_uLastTimeStopAiming; //0x0200

    uint32_t m_nearMissedDriverQueueIndex; //0x0204
    class CVehicle *m_lastNearMissedVehicles[5]; //0x0208

    enum ePlayerState
    {
        PLAYERSTATE_INVALID = -1,
        PLAYERSTATE_PLAYING = 0,
        PLAYERSTATE_HASDIED = 1,
        PLAYERSTATE_HASBEENARRESTED = 2,
        PLAYERSTATE_FAILEDMISSION = 3,
        PLAYERSTATE_LEFTGAME = 4,
        PLAYERSTATE_RESPAWN = 5,
        PLAYERSTATE_IN_MP_CUTSCENE = 6
    };
    int32_t m_PlayerState; //0x0230

    // Time of the player state change
    uint32_t m_TimeOfPlayerStateChange; //0x0234
    // Time this player last went from respawn to a new state
    uint32_t m_TimeOfPlayerLastRespawn; //0x0238
    char pad_023C[4]; //0x023C

    // Pointer to the player ped
    class CPed *m_pPlayerPed; //0x0240

    // Last vehicle player tried to enter.
    class CVehicle *m_pLastTargetVehicle; //0x0248

    // Restrict the player to only being able to enter this vehicle (script-controlled)
    class CVehicle *m_pOnlyEnterThisVehicle; //0x0250

    // Script can prefer the player to enter the rear seats for this vehicle
    class CVehicle *m_pPreferRearSeatsVehicle; //0x0258

    // Script can prefer the player to enter the frotn passenger seat for this vehicle
    class CVehicle *m_pPreferFrontPassengerSeatVehicle; //0x0260

    class CPed *m_pSpotterOfStolenVehicle; //0x0268

    // flags on the player that get reset every frame
    class CPlayerResetFlags m_PlayerResetFlags; //0x0270

    char pad_0278[52]; //0x0278

    // A count of the number of enemy peds in combat targetting this player.
    uint32_t m_iNumEnemiesInCombat; //0x02AC
    // A count of the number of enemy peds shooting at this player.
    uint32_t m_iNumEnemiesShootingInCombat; //0x02B0
    char pad_02B4[2700]; //0x02B4

    // Sprint variables
    float m_fRunSprintSpeedMultiplier; //0x0D40
    float m_fSprintEnergy; //0x0D44
    float m_fMaxSprintEnergy; //0x0D48
    float m_fSprintControlCounter; //0x0D4C
    float m_fCachedSprintMultThisFrame; //0x0D50
    uint32_t m_uTimeBikeSprintPressed; //0x0D54

    // Weapon/damage info
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

    // These variables keep track of reckless driving. The script can work out whether the player should be pulled over.
    uint32_t m_LastTimePlayerHitCar; //0x0D94
    uint32_t m_LastTimePlayerHitPed; //0x0D98
    uint32_t m_LastTimePlayerHitBuilding; //0x0D9C
    uint32_t m_LastTimePlayerHitObject; //0x0DA0
    uint32_t m_LastTimePlayerDroveOnPavement; //0x0DA4
    uint32_t m_LastTimePlayerRanLight; //0x0DA8
    uint32_t m_LastTimePlayerDroveAgainstTraffic; //0x0DAC

    uint32_t m_uTimeToEnableAgitation; //0x0DB0

    // Class managing player health recharge
    class CPlayerHealthRecharge m_healthRecharge; //0x0DB4

    char pad_0DC0[208]; //0x0DC0

    // Keeps track of noise indications in MP. This is basically the size of a sonar blip on the stealth radar, decaying over time.
    float m_StealthNoise; //0x0E90

    // allows scripts to tweak how noisy a player is while walking normally.
    float m_fNormalStealthMultiplier; //0x0E94

    // allows scripts to tweak how noisy a player is while sneaking.
    float m_fSneakingStealthMultiplier; //0x0E98

    float m_fDampenRootWeight; //0x0E9C
    float m_fDampenRootTargetWeight; //0x0EA0
    float m_fDampenRootTargetHeight; //0x0EA4

    // Stores information for the talking system.
    uint32_t m_uLastTimePedMadeMobileCommentOnWeirdPlayer; //0x0EA8
    // Stores damage information for local player. E.g. used to bump target threat if a friendly ped fires on local player.
    uint32_t m_uLastTimeDamagedLocalPlayer; //0x0EAC

    // Simulate player gait input variables    
    float m_fSimulateGaitMoveBlendRatio; //0x0EB0
    float m_fSimulateGaitHeading; //0x0EB4
    float m_fSimulateGaitDuration; //0x0EB8
    float m_fSimulateGaitTimerCount; //0x0EBC
    float m_fSimulateGaitStartHeading; //0x0EC0

    // Vehicle control variables
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

    // Modify the ability for peds to see you when in stealth
    float m_fStealthPerceptionModifier; //0x0F10

    uint32_t m_uTimeExitVehicleTaskFinished; //0x0F14

    class sNearVehicle m_nearVehicles[8]; //0x0F18

    char pad_0F78[100]; //0x0F78

    uint32_t m_SwitchedToOrFromFirstPersonCount; //0x0FDC
    uint32_t m_SwitchedToFirstPersonCount; //0x0FE0
    uint32_t m_SwitchedToFirstPersonFromThirdPersonCoverCount; //0x0FE4

    float m_fFallHeightOverride; //0x0FE8

    int32_t m_eSpecialAbilitiesMP[2]; //0x0FEC

    char pad_0FF4[76]; //0x0FF4

    int16_t m_iPlayerRoadLinkLocalIndex; //0x1040
    uint8_t m_nearVehiclePut; //0x1042
    uint8_t m_uNumAiAttemptingArrestOnPlayer; //0x1043

    // 0x1044
    bool m_bMayFollowTargetGroupMembers : 1;     // 0
    bool m_bEnableMeleeClipSetReleaseTimer : 1;  // 1
    bool m_bEnableBlueToothHeadset : 1;          // 2
    bool m_bSimulateGaitNoInputInterruption : 1; // 3 // don't break out on input changes, it just times out.
    bool PortablePickupPending : 1;              // 4 // Set when we are trying to carry a portable pickup
    bool bDoesNotGetTired : 1;                   // 5
    bool bFastReload : 1;                        // 6
    bool bFireProof : 1;                         // 7

    // 0x1045
    bool bCanDoDriveBy : 1;                     // 0
    bool bCanBeHassledByGangs : 1;              // 1
    bool bCanUseCover : 1;                      // 2
    bool bEnableControlOnDeath : 1;             // 3
    bool bHasDamagedAtLeastOnePed : 1;          // 4 // including the animal type
    bool bHasDamagedAtLeastOneNonAnimalPed : 1; // 5 // Excluding the animal type
    bool bHasDamagedAtLeastOneVehicle : 1;      // 6
    bool bSpecifyInitialCoverDirection : 1;     // 7

    // 0x1046
    bool bInitialCoverDirectionFaceLeft : 1;   // 0
    bool m_bIsShelteredAbove : 1;              // 1 // Whether the player is sheltered above (occasional linetest)
    bool m_bCanMoveLeft : 1;                   // 2
    bool m_bCanMoveRight : 1;                  // 3
    bool m_bInsideCorner : 1;                  // 4
    bool m_bCoverGeneratedByDynamicEntity : 1; // 5
    bool m_bIsRoundCover : 1;                  // 6
    bool m_bHitPed : 1;                        // 7

    // 0x1047
    bool m_bPlayerSprintDisabled : 1;          // 0
    bool m_bDisplayMobilePhone : 1;            // 1
    bool m_bStopNearbyVehicles : 1;            // 2
    bool m_bCanLeaveParachuteSmokeTrail : 1;   // 3
    bool m_bIsInsideMovingTrain : 1;           // 4
    bool m_bAllowControlInsideMovingTrain : 1; // 5

    class CVehicle *m_pTrainPedIsInside; //0x1048

    // 0x1050
    bool m_bSimulateGaitInput : 1;                // 0 // if the simulated gait is on.
    bool m_bSimulateGaitUseRelativeHeading : 1;   // 1 // the heading is local to the ped.
    bool m_bAutoGiveParachuteWhenEnterPlane : 1;  // 2 // if give player a parachute automatically when he gets into a plane or helicopter.
    bool m_bAutoGiveScubaGearWhenExitVehicle : 1; // 3
    bool m_bHasWorldExtentsSpawnedAShark : 1;     // 4
    bool m_bSprintReplenishing : 1;               // 5 // sprint energy is replenishing, needs to be above zero to re-start sprinting
    bool m_bFreeAiming : 1;                       // 6
    bool m_bCanBeDamaged : 1;                     // 7

    // 0x1051
    bool m_DamageAllowedFromSetPlayerControl : 1; // 0
    bool m_bHasControlOfRagdoll : 1;              // 1 // player can apply forces to the ragdoll, to move around
    bool m_bAllowedToPickUpNonMissionObjects : 1; // 2 // script will set this to false when it needs to use LB button for something else like launching the internet script
    bool m_bCanCollectMoneyPickups : 1;           // 3 // if false, the player is not allowed to collect dropped money pickups (used for cops in cops 'n' crooks)
    bool m_bAmbientMeleeMoveDisabled : 1;         // 4 // if true, the player cannot perform the ambient melee move
    bool m_bPlayerOnHighway : 1;                  // 5 // Player is on highway. Ped population can be reduced.
    bool m_bPlayerOnWideRoad : 1;                 // 6 // If player is on a wide road and goes fast. Ped population can be reduced.
    bool m_bNodesNearbyInZ : 1;                   // 7 // Are there nodes present nearby the player at a similar height (+/- 10 meters). If not height requirement should be dropped when creating cars.

    // 0x1052
    bool m_bCanUseSearchLight : 1;           // 0 // Player is allow to use vehicle searchlights
    bool m_bDisableAgitation : 1;            // 1
    bool m_bWasAiming : 1;                   // 2
    bool m_bWasLightAttackPressed : 1;       // 3
    bool m_bWasAlternateAttackPressed : 1;   // 4
    bool m_bUseHighFiringAttackBoundary : 1; // 5

    char pad_1053[80]; //0x1053
}; //Size: 0x105C


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
