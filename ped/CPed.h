class CPed : public CPhysical
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

    // VFX data
    class CPedVfx *m_pPedVfx; //0x15E8

    uint8_t m_uRenderDelayFlags; //0x15F0
    char pad_15F1[3]; //0x15F1
    uint32_t m_uRenderFlagFrameCount; //0x15F4

    // time that last had a shave
    int32_t m_ShaveTimeInSeconds; //0x15F8

    uint32_t m_HurtEndTime; //0x15FC

    class DeathInfo m_DeathInfo; //0x1600

    // store the amount of fire a ped has accumulated fire-resistant peds take a little while to catch on fire
    float m_fAccumulatedFire; //0x1610

    // The amount of money this ped carries around
    uint32_t m_MoneyCarried; //0x1614

    // stops peds getting frozen immediately after coming out of an interior
    uint16_t m_nInteriorFreeze_WasInsideCounter; //0x1618
    // the following variable is used by peds created by ped generators so that they aren't deleted as soon as they are created
    int16_t m_StreamedScriptBrainToLoad; //0x161A

    // Times before ped starts taking damage in water. Longer for player
    float m_fMaxTimeInWater; //0x161C
    float m_fMaxTimeUnderwater; //0x1620
    float m_OverrideMaxTimeInWater; //0x1624

    // The minimum time the ped should spend on the ground when hit with a stun gun (in milliseconds) -1 to use the weapon's default value.
    int32_t m_MinOnGroundTimeForStunGun; //0x1628

    int32_t m_lastSignificantShotBoneTag; //0x162C

    // Which group this ped is in
    uint8_t m_iPedGroupIndex; //0x1630

    uint8_t m_InDangerTimer; //0x1631
    uint8_t m_OverhangConstraintCountdown; //0x1632
    uint8_t m_hiLodFadeValue; //0x1633

    char pad_1634[812]; //0x1634

    // how many sticky bombs this ped has deployed
    uint8_t m_uStickyCount; //0x1960

    // how many stick-to-ped projectiles (ie harpoon projectiles) has this ped shot
    uint8_t m_uStickToPedProjCount; //0x1961

    // how many flare gun projectiles has this ped shot 
    uint8_t m_uFlareGunProjCount; //0x1962

    // Countdown to ragdoll falling for quadrupeds
    int8_t m_iFailedQPedRagdollTests; //0x1963
    
    uint8_t m_modelLodIdx; //0x1964
    uint8_t m_uWeaponAnimationsIndex; //0x1965
    uint8_t m_iPhonePaletteIdx; //0x1966
    char pad_1967[1]; //0x1967

    class crFrame *m_pIndependentMoverFrame; //0x1968
    uint32_t m_WeaponBlockingDelay; //0x1970

    //0x1974
    bool m_forcePedHasNoMassInImpacts : 1;
    bool m_disableHighFallInstantDeath : 1;

    char pad_1975[79]; //0x1975
}; //Size: 0x19C4


class CPedConfigFlags
{
public:
    //0x0000
    uint32_t nCantBeKnockedOffVehicle : 2;          // 0 = Default(harder for mission peds), 1 = Never, 2 = Easy, 3 = Hard
    uint32_t nPedLegIkMode : 2;                     // Enable the leg ik on a non player
    uint32_t nPedGestureMode : 2;                   // What is the gesture mode normal, obey "allow" or "blocking" tags in anims
    uint32_t m_iPassengerIndexToUseInAGroup : 5;    // If this ped is in a group, this is the seat they will use when entering vehicles

    float fClimbRateOverride; //0x0004

    // ePedConfigFlagsBitSet
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
    // if ped is getting pushed out of the way by the player pushing a door 
    uint8_t m_nKnockedByDoor; //0x0000

    // use the ground position to snap the height of the ped to the correct distance above the ground (don't want to do this all the time)
    uint8_t m_nSetEntityZFromGround; //0x0001

    char pad_0002[2]; //0x0002

    //0x0004
    uint32_t m_nDontAcceptIKLookAts : 2;
    uint32_t m_nDontAcceptCodeIKLookAts : 2;
    uint32_t m_nHasJustLeftVehicle : 4;
    uint32_t m_nIsInCover : 2;

    // rotation modifier, used to allow tasks to override the amount of rotation applied from anims, reset each frame to 1
    float m_fAnimRotationModifier; //0x0008

    // root correction modifier, how much of the root correction is applied to the ped, reset to 1 each frame
    float m_fRootCorrectionModifer; //0x000C

    // Overall control of speed at which movement anims play, default is 1.0f
    float m_fMoveAnimRate; //0x0010

    // Modifier set each frame by script, sets a distance a ped should be between seats to be applied when in a vehicle
    float m_fScriptedScaleBetweenSeatsDefaultDistance; //0x0014

    //EntityZ ground height. Used to prevent snapping z unless we are close to this height.
    float m_fEntityZFromGroundZHeight; //0x0018
    float m_fEntityZFromGroundZThreshold; //0x001C

    // ePedResetFlagsBitSet uint32_t
    char pad_0020[48]; //0x0020
}; //Size: 0x0050


class DeathInfo
{
public:
    class CEntity *m_Source; //0x0000
    uint32_t m_Weapon; //0x0008
    uint32_t m_Time; //0x000C
}; //Size: 0x0010

