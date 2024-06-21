class CPickup : public CObject
{
public:
    char pad_0000[1072]; //0x0000

    // used by portable pickups: this is the last accessible location on the map that the ped carrying a pickup was at. This is used when the ped dies and
    // drops a pickup in a location that other players cannot reach. In this case it is warped to the last accessible position
    Vector3 m_lastAccessibleLocation; //0x0430
    char pad_043C[4]; //0x043C

    Vector3 m_StartingLinearVelocity; //0x0440
    char pad_044C[4]; //0x044C

    Vector3 m_StartingAngularVelocity; //0x0450
    char pad_045C[4]; //0x045C

    // a ptr to the ped who dropped this pickup, if it was dropped
    class CPed *m_lastOwner; //0x0460

    // The hash of the pickup
    uint32_t m_pickupHash; //0x0468

    char pad_046C[4]; //0x046C

    class CPickupData *m_pPickupData; //0x0470
    class CPickupPlacement *m_pPlacement; //0x0478

    // a variable amount used by some pickup types (eg money). This is used to get around the hard coded values specified in the Rave data.
    uint32_t m_amount; //0x0480

    // amount collected by player after pickup.
    uint32_t m_amountCollected; //0x0484

    // pickup flags
    uint64_t m_flags; //0x0488

    // set when a pickup is trying to be collected but has to wait on approval from another machine (which owns the pickup)
    uint32_t m_pendingCollectionType; //0x0490

    char pad_0494[4]; //0x0494

    // the ped trying to collect the pickup
    class CPed *m_pendingCollector; //0x0498

    // the ped trying to carry the pickup
    class CPed *m_pendingCarrier; //0x04A0

    // the height the pickup needs to be placed above the ground to lie on it properly. Grabbed before the custom archetype is set up
    float m_heightOffGround; //0x04A8

    // the amount of time the pickup has existed (only used by pickups with no placements)
    uint32_t m_lifeTime; //0x04AC

    float m_glowOffset; //0x04B0
    uint32_t m_customWeaponHash; //0x04B4

    // only used by pickups collectable by boat
    float m_waterLevelNoWaves; //0x04B8

    // flags indicating which teams are allowed to collect this pickup
    uint16_t m_teamPermits; //0x04BC

    // a timer used when the pickup is pending remote collection
    int16_t m_pendingCollectionTimer; //0x04BE

    // the bound radius before adding the sphere bound
    float m_originalBoundRadius; //0x04C0

    char pad_04C4[4]; //0x04C4

    // weapon streaming helper
    class CWeaponItem *m_pWeaponItemForStreaming; //0x04C8

    bool m_includeProjectiles; //0x04D0

    bool m_allowNonScriptParticipantCollection; //0x04D1

    char pad_04D2[94]; //0x04D2
}; // Size: 0x0530


enum PickupFlags
{
    // SYNCED SCRIPT FLAGS:
    PF_Portable = 0,                      // set if the pickup can be carried by a ped
    PF_TeamPermitsSet = 1,                // team permits have been set
    PF_PlaceOnGround = 2,                 // force pickup onto the ground when created/detached
    PF_OrientToGround = 3,                // orientate to ground when placed on ground
    PF_UprightOnGround = 4,               // place upright on ground when placed on ground
    PF_LyingOnFixedObject = 5,            // the pickup may be lying on a fixed object - if so include objects in the probes when placing on ground
    PF_CollectionProhibited = 6,          // used to prevent an individual pickup from being collected on all machines
    PF_OffsetGlow = 7,                    // offset glow position by half radius of model's bound.
    PF_DroppedInWater = 8,                // lets us decide whether to force the pickup to be collideable or to be fixed
    PF_DroppedByPed = 9,                  // set when the pickup was dropped by a dead non-player ped
    PF_DebugCreated = 10,                 // this pickup was created for debug purposes
    PF_GlowInSameTeam = 11,               // even if PF_TeamPermitsSet is set, still glow
    PF_AddArrowMarker = 12,               // if set this pickup has an arrow marker above it
    PF_TransparentWhenUncollectable = 13, // if set this pickup is transparent when uncollectable by script
    PF_KeepPortablePickupAtDropoff = 14,
    PF_UnderwaterPickup = 15,                        // Set when the pickup was created underwater (for underwater missions), and therefore must subsequently be dropped underwater
    PF_ForceActivatePhysicsOnPickup = 16,            // Forces portable pickup to turn on physics when dropped
    PF_ForceActivatePhysicsOnDropNearSubmarine = 17, // Forces portable pickup to turn on physics when dropped if near a submarine
    PF_SuppressPickupAudio = 18,                     // if set on a pickup, we won't play a generic pickup sound when the pickup is collected (useful if eg. script wish to do something custom)
    PF_AllowCollectionInVehicle = 19,                // if set, the pickup can be collected when in a vehicle(if collectable on foot)
    PF_ForceWaitForFullySyncedBeforeDestruction = 20,
    PF_GlowOnProhibitCollection = 21,
    PF_AllowArrowMarkerWhenUncollectable = 22, // Allows the AddArrowMarker flag to work when the pickup in uncollectable
    NUM_SYNCED_PICKUP_FLAGS,

    // NON-SYNCED FLAGS:
    PF_Collected,                        // set when the pickup is collected
    PF_HasCustomModel,                   // set when the pickup has a custom model
    PF_GotCustomArchetype,               // set when the pickup is given it's custom archetype
    PF_Initialised,                      // set when the pickup has got its archetype and placed in the world properly
    PF_Destroyed,                        // set when the pickup is destroyed. Used to sanity check that the pickup is being removed properly.
    PF_Inaccessible,                     // set when a portable pickup may be in an inaccessible location
    PF_WarpToAccessibleLocation,         // set when a portable pickup has to be warped to an accessible location
    PF_SearchingForAccessibleLocation,   // set when we are waiting for the network respawn manager to find us an accessible location
    PF_CreateDefaultWeaponAttachments,   // create default weapon attachments
    PF_PlacedOnGround,                   // set once the pickup has been placed on the ground
    PF_LocalPlayerCollision,             // set when ProcessPreComputeImpacts is called and the local player is colliding with the pickup
    PF_HelpTextDisplayed,                // set once the pickup has come into collectable range with the local player and the collection help text has been displayed
    PF_LocalCollectionProhibited,        // prohibits the pickup being collected locally
    PF_DetachWhenLocal,                  // flag the pickup to be detached when it becomes local
    PF_SleepThresholdsInitialized,       // special sleep thresholds for pickups
    PF_HideInPhotos,                     // if set the pickup is not rendered when using the camera phone
    PF_DontGlow,                         // if set the pickup will not be glowing.
    PF_DontFadeOut,                      // if set the pickup will not fade out and be removed after a certain amount of time
    PF_DroppedFromLocalPlayer,           // if set the pickup will not allow itself to be collected by the local player until he moves away and back again
    PF_DroppedInInterior,                // if set a portable pickup was dropped in an interior
    PF_DisabledCollision,                // if set this pickup had its collision disabled when hidden
    PF_LastAccessiblePosHasValidGround,  // set when a portable pickup being carried has last accessible location which is a valid navmesh location
    PF_PlayerGift,                       // if set this pickup was dropped by a player for another player to collect
    PF_HideWhenDetached,                 // if set this portable pickup is hidden when detached
    PF_UseExtendedScope,                 // if set this ambient pickup uses an extended scope range. Used for script created ambient pickups.
    PF_CollisionsWithPedDisabled,        // set on the pickup when dropped from a dead ped, to prevent it subsequently colliding with it
    PF_CollisionsWithPedVehicleDisabled, // if set this pickup was dropped by a dead ped in a vehicle, and collisions disabled with that vehicle
    PF_HiddenByScript,                   // if set this pickup has been forcibly hidden by script
    PF_LyingOnUnFixedObject,             // if set this portable pickup is attached to a ped standing or climbing on a non-fixed physical object
    PF_AutoEquipOnCollect,               // if set on a weapon pickup, it will auto equip the picked up weapon. It will ignore autoswap logic
    PF_RequiresLineOfSight,              // if set on a pickup, the pickup can only be collected if we have line of sight to it
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
