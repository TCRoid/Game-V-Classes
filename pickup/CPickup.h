class CPickup : public CObject
{








    // used by portable pickups: this is the last accessible location on the map that the ped carrying a pickup was at. This is used when the ped dies and
	// drops a pickup in a location that other players cannot reach. In this case it is warped to the last accessible position
	Vector3 m_lastAccessibleLocation;

	Vector3 m_StartingLinearVelocity;
	Vector3 m_StartingAngularVelocity;

	// a ptr to the ped who dropped this pickup, if it was dropped
	RegdPed m_lastOwner;

	// The hash of the pickup
	u32 m_pickupHash;

	// Pointer to the data
	const CPickupData* m_pPickupData;

	// a ptr to the placement data that generated this pickup
	CPickupPlacement* m_pPlacement;

	// a variable amount used by some pickup types (eg money). This is used to get around the hard coded values specified in the Rave data. 
	u32 m_amount; 

	// amount collected by player after pickup.
	u32 m_amountCollected; 

	// pickup flags
	fwFlags<u64> m_flags; //0x0488

	// set when a pickup is trying to be collected but has to wait on approval from another machine (which owns the pickup)
	eCollectionType m_pendingCollectionType;

	// the ped trying to collect the pickup
	RegdPed m_pendingCollector;

	// the ped trying to carry the pickup
	RegdPed m_pendingCarrier;

	// the height the pickup needs to be placed above the ground to lie on it properly. Grabbed before the custom archetype is set up
	float m_heightOffGround;

	// the amount of time the pickup has existed (only used by pickups with no placements)
	u32 m_lifeTime;

	float m_glowOffset; //0x04B0

	u32 m_customWeaponHash;

	// only used by pickups collectable by boat
	float m_waterLevelNoWaves; //0x04B8
	
	// flags indicating which teams are allowed to collect this pickup
	TeamFlags m_teamPermits;

	// a timer used when the pickup is pending remote collection
	s16 m_pendingCollectionTimer;

	// the bound radius before adding the sphere bound
	float m_originalBoundRadius;
	
	// weapon streaming helper
	CWeaponItem* m_pWeaponItemForStreaming;

	bool m_includeProjectiles;

	bool m_allowNonScriptParticipantCollection; //0x04D1
}



enum PickupFlags
{
    // SYNCED SCRIPT FLAGS:
    PF_Portable	= 0,						// set if the pickup can be carried by a ped
    PF_TeamPermitsSet,						// team permits have been set
    PF_PlaceOnGround,						// force pickup onto the ground when created/detached
    PF_OrientToGround,						// orientate to ground when placed on ground 
    PF_UprightOnGround,						// place upright on ground when placed on ground 
    PF_LyingOnFixedObject,					// the pickup may be lying on a fixed object - if so include objects in the probes when placing on ground 
    PF_CollectionProhibited,				// used to prevent an individual pickup from being collected on all machines
    PF_OffsetGlow,							// offset glow position by half radius of model's bound.
    PF_DroppedInWater,						// lets us decide whether to force the pickup to be collideable or to be fixed
    PF_DroppedByPed,						// set when the pickup was dropped by a dead non-player ped
    PF_DebugCreated,						// this pickup was created for debug purposes
    PF_GlowInSameTeam,						// even if PF_TeamPermitsSet is set, still glow
    PF_AddArrowMarker,						// if set this pickup has an arrow marker above it
    PF_TransparentWhenUncollectable,		// if set this pickup is transparent when uncollectable by script
    PF_KeepPortablePickupAtDropoff,			
    PF_UnderwaterPickup,					// Set when the pickup was created underwater (for underwater missions), and therefore must subsequently be dropped underwater
    PF_ForceActivatePhysicsOnPickup,		// Forces portable pickup to turn on physics when dropped
    PF_ForceActivatePhysicsOnDropNearSubmarine, // Forces portable pickup to turn on physics when dropped if near a submarine
    PF_SuppressPickupAudio,					// if set on a pickup, we won't play a generic pickup sound when the pickup is collected (useful if eg. script wish to do something custom)
    PF_AllowCollectionInVehicle,			// if set, the pickup can be collected when in a vehicle(if collectable on foot)
    PF_ForceWaitForFullySyncedBeforeDestruction,
    PF_GlowOnProhibitCollection,
    PF_AllowArrowMarkerWhenUncollectable,	// 22 // Allows the AddArrowMarker flag to work when the pickup in uncollectable
    NUM_SYNCED_PICKUP_FLAGS,	

    // NON-SYNCED FLAGS:
    PF_Collected,							// set when the pickup is collected
    PF_HasCustomModel,						// set when the pickup has a custom model 
    PF_GotCustomArchetype,					// set when the pickup is given it's custom archetype
    PF_Initialised,							// set when the pickup has got its archetype and placed in the world properly
    PF_Destroyed,							// set when the pickup is destroyed. Used to sanity check that the pickup is being removed properly.
    PF_Inaccessible,						// set when a portable pickup may be in an inaccessible location
    PF_WarpToAccessibleLocation,			// set when a portable pickup has to be warped to an accessible location
    PF_SearchingForAccessibleLocation,		// set when we are waiting for the network respawn manager to find us an accessible location
    PF_CreateDefaultWeaponAttachments,		// create default weapon attachments
    PF_PlacedOnGround,						// set once the pickup has been placed on the ground
    PF_LocalPlayerCollision,				// set when ProcessPreComputeImpacts is called and the local player is colliding with the pickup
    PF_HelpTextDisplayed,					// set once the pickup has come into collectable range with the local player and the collection help text has been displayed 
    PF_LocalCollectionProhibited,			// prohibits the pickup being collected locally
    PF_DetachWhenLocal,						// flag the pickup to be detached when it becomes local
    PF_SleepThresholdsInitialized,			// special sleep thresholds for pickups
    PF_HideInPhotos,						// if set the pickup is not rendered when using the camera phone
    PF_DontGlow, 							// if set the pickup will not be glowing.
    PF_DontFadeOut, 						// if set the pickup will not fade out and be removed after a certain amount of time
    PF_DroppedFromLocalPlayer, 				// if set the pickup will not allow itself to be collected by the local player until he moves away and back again
    PF_DroppedInInterior,					// if set a portable pickup was dropped in an interior
    PF_DisabledCollision, 					// if set this pickup had its collision disabled when hidden
    PF_LastAccessiblePosHasValidGround, 	// set when a portable pickup being carried has last accessible location which is a valid navmesh location
    PF_PlayerGift,							// if set this pickup was dropped by a player for another player to collect
    PF_HideWhenDetached,					// if set this portable pickup is hidden when detached
    PF_UseExtendedScope, 					// if set this ambient pickup uses an extended scope range. Used for script created ambient pickups.
    PF_CollisionsWithPedDisabled, 			// set on the pickup when dropped from a dead ped, to prevent it subsequently colliding with it
    PF_CollisionsWithPedVehicleDisabled, 	// if set this pickup was dropped by a dead ped in a vehicle, and collisions disabled with that vehicle
    PF_HiddenByScript,						// if set this pickup has been forcibly hidden by script
    PF_LyingOnUnFixedObject,				// if set this portable pickup is attached to a ped standing or climbing on a non-fixed physical object
    PF_AutoEquipOnCollect,					// if set on a weapon pickup, it will auto equip the picked up weapon. It will ignore autoswap logic		
    PF_RequiresLineOfSight,					// if set on a pickup, the pickup can only be collected if we have line of sight to it
};


enum eCollectionType
{
    COLLECT_INVALID, 
    COLLECT_ONFOOT,
    COLLECT_INCAR,
    COLLECT_ONSHOT,
    COLLECT_REMOTE,
    COLLECT_TEAM_TRANSFER,
    COLLECT_CLONE,
    COLLECT_NUM_TYPES
};




