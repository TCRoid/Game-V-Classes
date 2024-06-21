// fwEntity is the base class for all entities in the world.  
class fwEntity : public fwExtensibleBase
{
public:
    char pad_0000[32]; //0x0000

    class fwArchetype *m_pArchetype; //0x0020
    uint8_t m_type; //0x0028

    uint8_t m_protectedFlags; //0x0029

    uint16_t m_RenderFlags; //0x002A

    uint32_t m_baseFlags; //0x002C

    void *m_CurrentPhysicsInst; //0x0030

    uint16_t m_phaseVisibilityMask; //0x0038
    uint16_t m_visibilityType; //0x003A

    char pad_003C[12]; //0x003C

    class fwDrawData *m_pDrawHandler; //0x0048
    class fwDynamicEntityComponent *m_DynamicEntityComponent; //0x0050

    float N00000CFC; //0x0058
    float N00000DE7; //0x005C

    Matrix4x4 m_Matrix; //0x0060

    char pad_00A0[112]; //0x00A0
    Vector3 m_Position; //0x0110
    char pad_011C[4]; //0x011C
    Vector3 m_Position; //0x0120
    char pad_012C[60]; //0x012C
}; //Size: 0x0168


enum eEntityType
{
    ENTITY_TYPE_NOTHING = 0,
    ENTITY_TYPE_BUILDING = 1,               // CBuilding                             : CEntity
    ENTITY_TYPE_ANIMATED_BUILDING = 2,      // CAnimatedBuilding    : CDynamicEntity : CEntity
    ENTITY_TYPE_VEHICLE = 3,                // CVehicle : CPhysical : CDynamicEntity : CEntity
    ENTITY_TYPE_PED = 4,                    // CPed     : CPhysical : CDynamicEntity : CEntity
    ENTITY_TYPE_OBJECT = 5,                 // CObject  : CPhysical : CDynamicEntity : CEntity
    ENTITY_TYPE_DUMMY_OBJECT = 6,           // CDummyObject                          : CEntity
    ENTITY_TYPE_PORTAL = 7,                 // CPortalInst   : CBuilding : CEntity
    ENTITY_TYPE_MLO = 8,                    // CInteriorInst : CBuilding : CEntity
    ENTITY_TYPE_NOTINPOOLS = 9,             // Only used to trigger audio
    ENTITY_TYPE_PARTICLESYSTEM = 10,        // CPtFxSortedEntity : CEntity
    ENTITY_TYPE_LIGHT = 11,                 // CLightEntity : CEntity
    ENTITY_TYPE_COMPOSITE = 12,             // CCompEntity  : CEntity
    ENTITY_TYPE_INSTANCE_LIST = 13,         // CEntityBatch : CEntityBatchBase : CEntity
    ENTITY_TYPE_GRASS_INSTANCE_LIST = 14,   // CGrassBatch : CEntityBatchBase : CEntity
    ENTITY_TYPE_VEHICLEGLASSCOMPONENT = 15  // CVehicleGlassComponentEntity : CEntity
};


enum protectedFlags
{
    IS_FIXED_UNTIL_COLLISION = BIT(0),    // this is used by script created entities - they are static until the collision is loaded below them
    USES_COLLISION           = BIT(1),    // DO NOT SET THIS DIRECTLY! You can query it, but use CEntity::EnableCollision() and CEntity::DisableCollision().
    HAS_SLOD_REF             = BIT(2),
    HAS_FPV                  = BIT(3),    // Is this a first person view object?
};


enum baseFlags
{
    IS_VISIBLE                           = BIT(0),      // if set this entity will be ignored in visibility
    IS_SEARCHABLE                        = BIT(1),      // if set this entity will be ignored in world searches

    HAS_OPAQUE                           = BIT(2),      // draw object in opaque pass
    HAS_ALPHA                            = BIT(3),      // draw object in alpha pass
    HAS_DECAL                            = BIT(4),      // draw object in decal phase
    HAS_CUTOUT                           = BIT(5),      // draw object in cutout phase
    HAS_WATER                            = BIT(6),      // draw object in water phase
    HAS_DISPL_ALPHA                      = BIT(7),      // draw object in displacement alpha pass
    HAS_PRERENDER                        = BIT(8),      // Object has a pre-render effects attached to it
    IS_LIGHT                             = BIT(9),      // this is a light entity

    USE_SCREENDOOR                       = BIT(10),     // this includes MLO objects and small debris (leaves, cans etc)
    SUPPRESS_ALPHA                       = BIT(11),     // used for Skipping any alpha in the entity
    FORCE_ALPHA                          = BIT(12),     // Force Alpha
    RENDER_SMALL_SHADOW                  = BIT(13),     // don't cull shadow caster based on screen size
    OK_TO_PRERENDER                      = BIT(14),     // modify to suppress prerender later

    HAS_NON_WATER_REFLECTION_PROXY_CHILD = BIT(15),     // has a LOD child which renders in water reflection but is not a proxy
    HAS_HYBRID_ALPHA                     = BIT(15),     // SHARED(15) - has a solid part inside an alpha object
    IS_DYNAMIC                           = BIT(16),     // this is a dynamic entity (i.e. it can move in space)
    IS_FIXED                             = BIT(17),     // physics is fixed in position
    IS_FIXED_BY_NETWORK                  = BIT(18),     // this is used during a network game to stop clones having their physics updated between sync updates
    SPAWN_PHYS_ACTIVE                    = BIT(19),     // when adding to world, ensure that this object has activated physics

    IS_TIMED_ENTITY                      = BIT(20),     // If true, this is uses a model that's a timed entity

    DONT_STREAM                          = BIT(21),     // tell the streaming not to stream me
    LOW_PRIORITY_STREAM                  = BIT(22),     // set that this object is unimportant, if streaming is having problems

    HAS_PHYSICS_DICT                     = BIT(23),
    REMOVE_FROM_WORLD                    = BIT(24),     // remove this entity next time it should be processed

    FORCED_ZERO_ALPHA                    = BIT(25),     // this entity has forced alpha=0 (e.g. by the script)

    DRAW_LAST                            = BIT(26),     // entity is always pushed back in draw order as late as possible
    DRAW_FIRST_SORTED                    = BIT(27),     // entity is drawn first (only in sorted drawlists, i.e. SORT_ASCENDING or SORT_DESCENDING)

    NO_INSTANCED_PHYS                    = BIT(28),
    HAS_HD_TEX_DIST                      = BIT(29),     // entity has a texture dictionary that supports streaming in HD top mip

    PROTECT_ARCHETYPE                    = BIT(30),     // this entity has protected it's archetype with a ref & needs handled correctly on destruction
    HAS_ALPHA_SHADOW                     = BIT(31)
};


enum RenderFlags
{
    RenderFlag_USE_CUSTOMSHADOWS    = BIT(10),
    RenderFlag_IS_DYNAMIC           = BIT(11),
    RenderFlag_IS_PED               = BIT(12),
    RenderFlag_IS_GROUND            = BIT(13),
    RenderFlag_IS_BUILDING          = BIT(14),
    RenderFlag_IS_SKINNED           = BIT(15),
};
