class CPedIntelligence
{
public:
    char pad_0000[2864]; //0x0000
    class CCombatBehaviour m_combatBehaviour; //0x0B30
    class CFleeBehaviour m_fleeBehaviour; //0x0C18
    class CRelationshipGroup *m_pRelationshipGroupDefault; //0x0C20
    class CRelationshipGroup *m_pRelationshipGroup; //0x0C28
    class CPedPerception m_pedPerception; //0x0C30
    char pad_0C6C[192]; //0x0C6C
}; //Size: 0x0D2C


class CCombatBehaviour
{
public:
    // Defines how the AI can navigate and move during combat
    uint32_t m_CombatMovement; //0x0000

    // A set of flags that alters the way an AI behaves during combat
    uint32_t m_BehaviourFlags_0; //0x0004
    uint32_t m_BehaviourFlags_1; //0x0008
    uint32_t m_BehaviourFlags_2; //0x000C

    // How proficient this AI is during combat 0 to 1 the higher the more proficient
    uint32_t m_CombatAbility; //0x0010

    // Defines the perfect attack range for this ped
    uint32_t m_AttackRanges; //0x0014

    // Defines how a ped will react to losing the target
    uint32_t m_TargetLossResponse; //0x0018

    // Defines how a ped will react to an injured target, e.g. stop attacking or carry on
    uint32_t m_TargetInjuredReaction; //0x001C

    // If the forced injured on ground flag is set, this stores the required injured on ground duration
    int32_t m_InjuredOnGroundDuration; //0x0020

    // A modifier applied to the firing rate
    float m_fShootRateModifier; //0x0024

    // A single frame modifier applied to the firing rate
    float m_fShootRateModifierThisFrame; //0x0028

    // enum CombatFloats
    float m_aCombatFloats[31]; //0x002C

    // Determines the peds firing style
    class CFiringPattern m_FiringPattern; //0x00A8

    // This is the firing pattern we generall want to use in tasks
    int32_t m_FiringPatternHash; //0x00E0

    // Script guid for a peds preferred cover point list
    int32_t m_iPreferredCoverGuid; //0x00E4
}; //Size: 0x00E8


class CFleeBehaviour
{
public:
    enum BehaviourFlags
    {
        CanUseCover                            = BIT(0),
        CanUseVehicles                         = BIT(1),
        CanScream                              = BIT(2),
        PreferPavements                        = BIT(3),
        WanderAtEnd                            = BIT(4),
        LookForCrowds                          = BIT(5),
        WillReturnToOriginalPositionAfterFlee  = BIT(6), // Respond to new events
        DisableHandsUp                         = BIT(7),
        UpdateToNearestHatedPed                = BIT(8),
        NeverFlee                              = BIT(9),
        DisableCower                           = BIT(10),
        DisableExitVehicle                     = BIT(11),
        DisableReverseInVehicle                = BIT(12),
        DisableAccelerateInVehicle             = BIT(13),
        DisableFleeFromIndirectThreats         = BIT(14),
        CowerInsteadOfFlee                     = BIT(15),
        ForceExitVehicle                       = BIT(16),
        DisableHesitateInVehicle               = BIT(17),
        DisableAmbientClips                    = BIT(18),
    };
    uint32_t m_fleeBehaviourFlags; //0x0000

    int32_t m_sCowerHash; //0x0004
}; //Size: 0x0008


class CFiringPattern
{
public:
    int32_t m_uFiringPatternHash; //0x0000
    int32_t m_EquippedWeaponHash; //0x0004
    char pad_0008[48]; //0x0008
}; //Size: 0x0038


class CPedPerception
{
public:
    class CPed *m_pPed; //0x0000

    float m_fEncroachmentRange; //0x0008
    float m_fEncroachmentCloseRange; //0x000C

    float m_fHearingRange; //0x0010
    float m_fSeeingRange; //0x0014
    float m_fSeeingRangePeripheral; //0x0018

    // angles for perception are specified in degrees
    float m_fVisualFieldMinAzimuthAngle; //0x001C
    float m_fVisualFieldMaxAzimuthAngle; //0x0020
    float m_fVisualFieldMinElevationAngle; //0x0024
    float m_fVisualFieldMaxElevationAngle; //0x0028
    float m_fCentreOfGazeMaxAngle; //0x002C

    float m_fIdentificationRange; //0x0030

    // This essentially will give the ped a visual field azimuth value from -180 to 180 degrees and a peripheral seeing range equal to their standard seeing range
    bool m_bIsHighlyPerceptive; //0x0034

    // When scanning for ped encroachment events, this bool lets a ped always perceive the player if he is within the ped's personal space.
    bool m_bCanAlwaysSenseEncroachingPlayers; //0x0035

    // When scanning for ped encroachment events, force the check to be made in 3D not 2D space.
    bool m_bUse3DEncroachment; //0x0036

    char pad_0037[1]; //0x0037

    // Allows script to override rear view seeing range. Currently only set for cops with overridden perception params.
    float m_fRearViewSeeingRangeOverride; //0x0038
}; //Size: 0x003C

