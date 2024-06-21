class CObject : public CPhysical
{
public:
	char pad_0000[760]; // 0x0000

	CObjectFlags m_nObjectFlags; // 0x02F8

	uint16_t m_procObjInfoIdx;		   // 0x0300
	int16_t StreamedScriptBrainToLoad; // 0x0302

	uint32_t m_nEndOfLifeTimer; // 0x0304

	char pad_0308[238]; // 0x0308

	uint32_t m_damageScanCode;					  // 0x03F6
	uint32_t m_eLastCoverOrientation;			  // 0x03FA
	uint32_t m_nPhysicsTimeSliceToAvoidCollision; // 0x03FE
	int32_t m_firstMovedTimer;					  // 0x0402
	float m_fTargetableDistance;				  // 0x0406

	uint16_t m_iPathServerDynObjId; // 0x040A
	uint8_t m_vehModSlot;			// 0x040C
	uint8_t m_speedBoost;			// 0x040D
	uint8_t m_speedBoostDuration;	// 0x040E
	uint8_t m_jointToDriveIndex;	// 0x040F


	// 0x0410
	bool m_bShootThroughWhenEquipped : 1;				  // 0	// if this object can be shot through by bullets when a ped is holding it.
	bool m_bForcePostCameraAiUpdate : 1;				  // 1	// should the object force a post camera ai task update this frame (resets in processpostcamera)
	bool m_bForcePostCameraAnimUpdate : 1;				  // 2	// Should the object force a post camera anim update this frame (resets in processpostcamera)
	bool m_bForcePostCameraAnimUpdateUseZeroTimeStep : 1; // 3	// Should we use a zero timestep when frocing the update
	bool m_bFixedByScriptOrCode : 1;					  // 4	// Distinguish that this object's fixed state is not the same as its default state
	bool m_bForceVehiclesToAvoid : 1;					  // 5	// Set by script. Force vehicles to avoid this even if it's small
	bool m_bHasNetworkedFrags : 1;						  // 6	// Used in MP
	bool m_bDisableObjectMapCollision : 1;				  // 7	// Reset flag. Used by synced scenes and scripted animation.

	// 0x0411
	bool m_bIsAttachedToHandler : 1;					// 0	// Should a player ped should ragdoll when hit by the big container model used with the handler?
	bool m_bTakesDamageFromCollisionsWithBuildings : 1; // 1	// the object takes collision damage when hitting buildings.
	bool m_bIsParachute : 1;							// 2
	bool m_bIsCarParachute : 1;							// 3	// Is this a parachute for a car? (Ruiner gadget car)
	bool m_bDisableCarCollisionsWithCarParachute : 1;	// 4
	bool m_bRegisteredInNetworkGame : 1;				// 5
	bool m_bIntentionallyLeakedObject : 1;				// 6
	bool m_bUseLightOverride : 1;						// 7	// Applies a light override.

	// 0x0412
	bool m_bProjectilesExplodeOnImpact : 1;		// 0
	bool m_bDriveToMaxAngle : 1;				// 1
	bool m_bDriveToMinAngle : 1;				// 2
	bool m_bIsPressurePlate : 1;				// 3
	bool m_bWeaponImpactsApplyGreaterForce : 1; // 4
	bool m_bIsArticulatedProp : 1;				// 5
	bool m_bIsBall : 1;							// 6
	bool m_bBallShunted : 1;					// 7

	// 0x0413
	bool m_bExtraBounceApplied : 1; // 0
	bool m_bIsAlbedoAlpha : 1;		// 1


	char pad_0414[174]; // 0x0414
}; // Size: 0x04C2


struct CObjectFlags
{
	// 0x02F8
	uint32_t bIsPickUp								: 1; // 0
	uint32_t bIsDoor								: 1; // 1
	uint32_t bHasBeenUprooted						: 1; // 2
	uint32_t bCanBeTargettedByPlayer				: 1; // 3	// true if this object can be locked on by the player
	uint32_t bIsATargetPriority						: 1; // 4	// If set to targetable then this object is higher priority target than normal
	uint32_t bTargettableWithNoLos					: 1; // 5	// If set to targetable then this object can be targeted with no line of sight
	uint32_t bIsStealable							: 1; // 6	// objects stealable in the procedural interior code
	uint32_t bVehiclePart							: 1; // 7	// this object is a bit that broke of a vehicle - it requires the vehicle to still exist to render
	uint32_t bPedProp								: 1; // 8	// this object is a ped prop that needs to be destroyed when the ped is removed
	uint32_t bFadeOut								: 1; // 9
	uint32_t bRemoveFromWorldWhenNotVisible			: 1; // 10
	uint32_t bMovedInNetworkGame					: 1; // 11
	uint32_t bBoundsNeedRecalculatingForNavigation	: 1; // 12	// Set on an object when it fragments, so that its navigation bounds can be recalculated
	uint32_t bFloater								: 1; // 13	// object is created on the water, so always floats and stays active when ever the player is near
	uint32_t bWeaponWillFireOnImpact				: 1; // 14
	uint32_t bAmbientProp							: 1; // 15	// if this object is an ambient prop
	uint32_t bDetachedPedProp						: 1; // 16	// is a prop object which has been detached from a ped
	uint32_t bFixedForSmallCollisions				: 1; // 17	// if this object uses fixed physics until it collides with high mass objects and vehicles
	uint32_t bSkipTempObjectRemovalChecks			: 1; // 18	// allows temp object to be deleted when near/onscreen
	uint32_t ScriptBrainStatus						: 3; // 19~21
	uint32_t bWeWantOwnership						: 1; // 22	// Used in network game
	uint32_t bActivatePhysicsAsSoonAsUnfrozen		: 1; // 23	// Set by script so that objects placed on slopes will drop to correct position as soon as possible
	uint32_t bCarWheel								: 1; // 24	// need to identify wheels that fall off cars so they render correctly
	uint32_t bCanBePickedUp							: 1; // 25	// certain objects can't be picked up
	uint32_t bIsHelmet								: 1; // 26	// object is a helmet
	uint32_t bIsRageEnvCloth						: 1; // 27	// object is a rage environment cloth attached to moving entity
	uint32_t bOnlyCleanUpWhenOutOfRange				: 1; // 28	// clean up when out of range only
	uint32_t bPopTires								: 1; // 29	// causes tires to pop when collided with
	uint32_t bHasInitPhysics						: 1; // 30	// the object has initialized physics
	uint32_t bHasAddedPhysics						: 1; // 31	// the object has added physics

	// 0x02FC
	uint32_t bIsVehicleGadgetPart					: 1; // 0	// The object is part of a vehicle gadget. Used by network to ensure the owner of the vehicle and the owner of the vehicle gadget parts are consistent.
	uint32_t bIsNetworkedFragment					: 1; // 1	// The object is a fragment that is being networked
};


enum eScriptBrainStatus
{
	OBJECT_DOESNT_USE_SCRIPT_BRAIN = 0, 
	OBJECT_WAITING_TILL_IN_BRAIN_RANGE = 1,		// used to be called OBJECT_SCRIPT_BRAIN_NOT_LOADED, 
	OBJECT_WAITING_FOR_SCRIPT_BRAIN_TO_LOAD = 2, 
	OBJECT_WAITING_TILL_OUT_OF_BRAIN_RANGE = 3,
	OBJECT_RUNNING_SCRIPT_BRAIN = 4
};

