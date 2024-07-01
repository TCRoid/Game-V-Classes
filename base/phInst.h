class phInst : public pgBase
{
public:
    char pad_0000[16]; // 0x0000

    class phArchetype *m_Archetype; // 0x0010

    uint16_t m_LevelIndex; // 0x0018

    // The instance flags are eInstFlags and they are used for controlling ways in which the object collides.
    uint16_t m_Flags; // 0x001A

    char pad_001C[4]; // 0x001C

    // orientation (3x3 part) and position (d-vector) for the physics instance
    Matrix4x4 m_Matrix; // 0x0020

    char pad_0060[40]; // 0x0060
}; // Size: 0x0088


enum
{
    INVALID_INDEX = 0xFFFF
}; // magic number indicating not in a level


enum eInstFlags
{
    FLAG_OPTIONAL_ITERATIONS = (1 << 0),     // optional force solver iterations reqested by game
    FLAG_DONT_WAKE_DUE_TO_ISLAND = (1 << 1), // Don't wake up if your sleep island wakes up
    FLAG_HIGH_PRIORITY = (1 << 2),           // manifolds are allocated with "high priority"
    FLAG_NEVER_ACTIVATE = (1 << 3),          // this inst should never activate (return NULL from PrepareForActivation)
    FLAG_NO_GRAVITY = (1 << 4),
    FLAG_NO_GRAVITY_ON_ROOT_LINK = (1 << 5),    // don't apply gravity to the root link of articulated collider (gta specific)
    FLAG_QUERY_EXTERN_VEL = (1 << 6),           // A derived class of this inst overrides one of the GetExternallyControlled_xxx_Velocity() functions and wants it to be used by the impulse solver. This can be changed at runtime if an inst goes to or from active/inactive.
    FLAG_INTERNAL_USE_ONLY_LAST_MTX = (1 << 7), // Has a last matrix when in the level. Only to be set by the level.
    FLAG_SLEEPS_ALONE = (1 << 8),               // Doesn't go to sleep using islands
    FLAG_USER_0 = (1 << 9)                      // first user defined flag bit
};
