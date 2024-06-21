class CPickupPlacement : public netGameObjectBase, public CGameScriptHandlerObject
{
public:
    char pad_0000[104]; //0x0000

    // the key of the room this placement is in
    uint32_t m_roomHashkey; //0x0068

    // weapon hash
    uint32_t m_customWeaponHash; //0x006C

    // position of the pickup object when generated
    Vector3 m_pickupPosition; //0x0070
    char pad_007C[4]; //0x007C

    // euler angle orientation of the pickup object when generated
    Vector3 m_pickupOrientation; //0x0080
    char pad_008C[4]; //0x008C

    // ptr to the pickup object which this placement has generated
    class CPickup *m_pPickup; //0x0090

    // a pointer to the pickup data
    class CPickupData *m_pPickupData; //0x0098

    // the script handler that this placement is registered with
    class scriptHandler *m_pHandler; //0x00A0

    // some placements can set additional custom data
    class CPickupPlacementCustomScriptData *m_pCustomScriptData; //0x00A8

    // placement flags
    uint32_t m_flags; //0x00B0

    // a custom regeneration time in seconds, specific only to this placement. Overrides the value set in the pickup data.
    uint16_t m_customRegenTime; //0x00B4

    // a variable amount used by some pickup types (eg money). This is used to get around the hard coded values specified in the Rave data.
    uint16_t m_amount; //0x00B6

    // the amount that is actually picked up when we consume this pickup placement.
    uint16_t m_amountCollected; //0x00B8

    char pad_00BA[6]; //0x00BA
}; //Size: 0x00C03


enum PlacementFlags
{
    // global (broadcast over network):
    PLACEMENT_CREATION_FLAG_MAP                     = BIT(0),   // map placements are treated as a special case due to their large number. These are the placements scattered around the map in a deathmatch, etc.
    PLACEMENT_CREATION_FLAG_FIXED                   = BIT(1),   // if set the spawned pickup will not activate its physics
    PLACEMENT_CREATION_FLAG_REGENERATES             = BIT(2),   // if set the placement will regenerate the pickup after it has been collected
    PLACEMENT_CREATION_FLAG_SNAP_TO_GROUND          = BIT(3),   // if set the placement will snap to the ground (within a range of 2.0 meters up/down)
    PLACEMENT_CREATION_FLAG_ORIENT_TO_GROUND        = BIT(4),   // if set the placement will orient to the ground normal (if ground is found)
    PLACEMENT_CREATION_FLAG_LOCAL_ONLY              = BIT(5),   // if set the placement will not be cloned on other machines
    PLACEMENT_CREATION_FLAG_BLIPPED_SIMPLE          = BIT(6),   // if set the placement has a simple blip
    PLACEMENT_CREATION_FLAG_BLIPPED_COMPLEX         = BIT(7),   // if set the placement has a complex blip
    PLACEMENT_CREATION_FLAG_UPRIGHT                 = BIT(8),   // if set the spawned pickup upright
    PLACEMENT_CREATION_FLAG_ROTATE                  = BIT(9),   // if set the spawned pickup will rotate
    PLACEMENT_CREATION_FLAG_FACEPLAYER              = BIT(10),  // if set the spawned pickup will always face the player
    PLACEMENT_CREATION_FLAG_HIDE_IN_PHOTOS          = BIT(11),  // if set the spawned pickup will not be rendered when the player is using the phone camera
    PLACEMENT_CREATION_FLAG_PLAYER_GIFT             = BIT(12),  // if set the pickup is being dropped as a gift to another player
    PLACEMENT_CREATION_FLAG_ON_OBJECT               = BIT(13),  // if set the pickup may be lying on an object - if so include objects in the probes when placing on ground
    PLACEMENT_CREATION_FLAG_GLOW_IN_TEAM            = BIT(14),
    PLACEMENT_CREATION_FLAG_AUTO_EQUIP              = BIT(15),
    PLACEMENT_CREATION_FLAG_COLLECTABLE_IN_VEHICLE  = BIT(16),  // if set the pickup can be collected by a ped in a vehicle
    PLACEMENT_CREATION_FLAG_DISABLE_WEAPON_HD_MODEL = BIT(17),  // if set the weapon pickup will render SD model only (HD<->SD model switch will be disabled)
    PLACEMENT_CREATION_FLAG_FORCE_DEFERRED_MODEL    = BIT(18),  // if set the pickup will render as deferred model (no transparency/alpha blending in this render mode)
};
