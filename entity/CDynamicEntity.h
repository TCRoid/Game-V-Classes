class CDynamicEntity : public CEntity
{
public:
    char pad_0000[208]; // 0x0000

    class netObject *m_pObject; // 0x00D0

    CDynamicEntityFlags m_nDEflags; // 0x00D8

    char pad_00DC[164]; // 0x00DC
}; // Size: 0x0180


struct CDynamicEntityFlags
{
    // 0x00D8
    uint16_t nStatus : 3;                     // 0~2    // control status
    uint16_t bFrozenByInterior : 1;           // 3      // flag to say if an entity has been frozen by an interior
    uint16_t bFrozen : 1;                     // 4      // Flag to say if the entity update has been frozen this frame (could be due to an interior, or a physical fixed flag)
    uint16_t bCheckedForDead : 1;             // 5      // The dead/alive state of this entity has been checked in the script code this frame
    uint16_t bIsGolfBall : 1;                 // 6      // the object is marked as a golf ball and will run some alternate or extra physics to deal with the small scale (Particularly for rolling)
    uint16_t bForcePrePhysicsAnimUpdate : 1;  // 7      // Set to true if the entity should always update its animation pre physics regardless of if it's on screen
    uint16_t bIsBreakableGlass : 1;           // 8
    uint16_t bIsOutOfMap : 1;                 // 9
    uint16_t bOverridePhysicsBounds : 1;      // 10
    uint16_t bHasMovedSinceLastPreRender : 1; // 11
    uint16_t bUseExtendedBoundingBox : 1;     // 12
    uint16_t bIsStraddlingPortal : 1;         // 13

    // 0x00DA
    uint16_t nPopType : 4;               // 0~3
    uint16_t nPopTypePrev : 4;           // 4~7
    uint16_t bReplayWarpedThisFrame : 1; // 8
};


enum eStatus
{
    STATUS_PLAYER = 0,
    STATUS_PHYSICS = 1,
    STATUS_ABANDONED = 2,
    STATUS_WRECKED = 3,
    STATUS_PLAYER_DISABLED = 4,
    STATUS_OUT_OF_CONTROL = 5
};


enum ePopType
{
    POPTYPE_UNKNOWN = 0,

    // World simulation related population types.
    POPTYPE_RANDOM_PERMANENT = 1, // Trains, singularly Placed Helis, etc.
    POPTYPE_RANDOM_PARKED = 2,    // Parked Vehs and boats, etc. (generated semi- randomly on car-generators)
    POPTYPE_RANDOM_PATROL = 3,    // Peds and vehs generated on patrol paths (around banks, castles, etc).
    POPTYPE_RANDOM_SCENARIO = 4,  // Random pairs of Peds talking in the street, etc. placed at scenario points.
    POPTYPE_RANDOM_AMBIENT = 5,   // Random wandering Peds and Vehs (generated on road paths or the navmesh)

    // Game-play and playback related population types.
    POPTYPE_PERMANENT = 6, // The player and player groups.
    POPTYPE_MISSION = 7,   // Scripted chars, vehs, etc.
    POPTYPE_REPLAY = 8,    // For game replays.

    POPTYPE_CACHE = 9, // Vehicle is a part of the vehicle cache

    // Debugging and tool only population types.
    POPTYPE_TOOL = 10 // For debug tools.
};
