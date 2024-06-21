class CPhysical : public CDynamicEntity
{
public:
    char pad_0000[392]; // 0x0000

    class CPhysicalFlags m_nPhysicalFlags; // 0x0188
    uint32_t m_bDontResetDamageFlagsOnCleanupMissionState; // 0x0190

    char pad_0194[236]; // 0x0194

    float m_fHealth; // 0x0280
    float m_fMaxHealth; // 0x0284

    class WeaponDamageInfos (*m_pWeaponDamageInfos)[3]; // 0x0288

    char pad_0290[72]; // 0x0290

    class CEntity *m_canOnlyBeDamagedByEntity; // 0x02D8
    class CEntity *m_cantBeDamagedByEntity; // 0x02E0

    char pad_02E8[344]; // 0x02E8
}; // Size: 0x0440


class CPhysicalFlags
{
public:
    // 0x0000
    uint32_t bIsInWater : 1;                            // 0    // If this is set then the guy is floating in water
    uint32_t bWasInWater : 1;                           // 1    // Was floating in water last frame
    uint32_t bDontLoadCollision : 1;                    // 2    // Doesn't try to load collision for this physical
    uint32_t bAllowFreezeIfNoCollision : 1;             // 3    // Should this object be allowed to deactivate from the physics sim if collision isn't loaded around it?
    uint32_t bNotDamagedByBullets : 1;                  // 4    // This guy is bullet proof
    uint32_t bNotDamagedByFlames : 1;                   // 5    // This guy is flame proof
    uint32_t bNotDamagedByCollisions : 1;               // 6    // This guy is collision proof
    uint32_t bNotDamagedByMelee : 1;                    // 7    // This guy is melee weapon proof
    uint32_t bNotDamagedByAnything : 1;                 // 8    // This guy can't be damaged by anything
    uint32_t bNotDamagedByAnythingButHasReactions : 1;  // 9    // This guy won't take any damage but will react to any impact/explosion etc.
    uint32_t bOnlyDamagedByPlayer : 1;                  // 10   // This guy can only be damaged by the player
    uint32_t bIgnoresExplosions : 1;                    // 11   // does entity get affected by explosions
    uint32_t bOnlyDamagedByRelGroup : 1;                // 12   // This guy can only be damaged by m_specificRelationshipGroup
    uint32_t bNotDamagedByRelGroup : 1;                 // 13   // This guy can not be damaged by m_specificRelationshipGroup
    uint32_t bOnlyDamagedWhenRunningScript : 1;         // 14   // This guy can only be damaged when we're running the script he belongs to
    uint32_t bNotDamagedBySteam : 1;                    // 15   // This guy is steam proof
    uint32_t bNotDamagedBySmoke : 1;                    // 16   // This guy is smoke proof
    uint32_t bExplodeInstantlyWhenChecked : 1;          // 17   // This vehicle will explode instantly when a check to explode a vehicle is done
    uint32_t bFlyer : 1;                                // 18   // Is a flying object (plane, heli)
    uint32_t bRenderScorched : 1;                       // 19   // this guy is fucked and should be rendered black
    uint32_t bCarriedByRope : 1;                        // 20   // We are attached to a rope (crane) at the moment
    uint32_t bMoved : 1;                                // 21   // Set when physical is moved for the first time after a collision
    uint32_t bPossiblyTouchesWaterIsUpToDate : 1;       // 22
    uint32_t bModifiedBounds : 1;                       // 23   // set when the collision archetype is modified (eg pickups)
    uint32_t bIsNotBuoyant : 1;                         // 24   // Set true to disable the buoyancy calculation (eg: for fish while swimming under water)
    uint32_t bNotToBeNetworked : 1;                     // 25   // Set in MP when an entity is deliberately created without a network object
    uint32_t bUseKinematicPhysics : 1;                  // 26   // Set if this entity wants to use the kinematic physics mode (can't be pushed out of the way by other objects)
    uint32_t bPreserveVelocityFromKinematicPhysics : 1; // 27   // Set if this entity wants to preserve the velocity when switching out of kinematic physics
    uint32_t bIsRootOfOtherAttachmentTree : 1;          // 28   // Is this instance the root of a tree of attachments not known by CPhysical?
    uint32_t bAutoVaultDisabled : 1;                    // 29   // This entity can't be auto-vaulted.
    uint32_t bClimbingDisabled : 1;                     // 30   // This entity can't be climbed.
    uint32_t bPickUpByCargobobDisabled : 1;             // 31   // Have disabled being able to be picked up by the cargobob

    // 0x0004
    uint32_t bIsUsingKinematicPhysics : 1; // 0 // Is the entity currently in the kinematic physics mode (so we can tell when to activate / deactivate it)
    uint32_t bCreatedBlip : 1;             // 1 // optimization for cleanup - is there a blip associated with this
    uint32_t bCoverBoundsRemoved : 1;      // 2 // Have we already turned off collision for the extra cover collision bound if this is a frag?
}; // Size: 0x0008
