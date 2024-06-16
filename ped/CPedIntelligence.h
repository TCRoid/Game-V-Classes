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
	uint32_t m_CombatMovement; //0x0000
	uint32_t m_BehaviourFlags_0; //0x0004
	uint32_t m_BehaviourFlags_1; //0x0008
	uint32_t m_BehaviourFlags_2; //0x000C
	uint32_t m_CombatAbility; //0x0010
	uint32_t m_AttackRanges; //0x0014
	uint32_t m_TargetLossResponse; //0x0018
	uint32_t m_TargetInjuredReaction; //0x001C
	int32_t m_InjuredOnGroundDuration; //0x0020
	float m_fShootRateModifier; //0x0024
	float m_fShootRateModifierThisFrame; //0x0028
	float m_aCombatFloats[31]; //0x002C
	class CFiringPattern m_FiringPattern; //0x00A8
	int32_t m_FiringPatternHash; //0x00E0
	int32_t m_iPreferredCoverGuid; //0x00E4
}; //Size: 0x00E8


class CFleeBehaviour
{
public:
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
	float m_fVisualFieldMinAzimuthAngle; //0x001C
	float m_fVisualFieldMaxAzimuthAngle; //0x0020
	float m_fVisualFieldMinElevationAngle; //0x0024
	float m_fVisualFieldMaxElevationAngle; //0x0028
	float m_fCentreOfGazeMaxAngle; //0x002C
	float m_fIdentificationRange; //0x0030
	bool m_bIsHighlyPerceptive; //0x0034
	bool m_bCanAlwaysSenseEncroachingPlayers; //0x0035
	bool m_bUse3DEncroachment; //0x0036
	char pad_0037[1]; //0x0037
	float m_fRearViewSeeingRangeOverride; //0x0038
}; //Size: 0x003C

