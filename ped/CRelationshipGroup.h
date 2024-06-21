class CRelationshipGroup : public fwRefAwareBase
{
public:
    char pad_0000[16]; //0x0000

    enum eGroupOwnershipType
    {
        RT_Mission,
        RT_Random,
        RT_Invalid = -1
    };
    int32_t m_eType; //0x0010

    // relationship group hash
    int32_t m_name; //0x0014

    enum eRelationType
    {
        ACQUAINTANCE_TYPE_INVALID = 255,    
        ACQUAINTANCE_TYPE_PED_RESPECT = 0,
        ACQUAINTANCE_TYPE_PED_LIKE = 1,
        ACQUAINTANCE_TYPE_PED_IGNORE = 2,
        ACQUAINTANCE_TYPE_PED_DISLIKE = 3,
        ACQUAINTANCE_TYPE_PED_WANTED = 4,
        ACQUAINTANCE_TYPE_PED_HATE = 5,
        ACQUAINTANCE_TYPE_PED_DEAD = 6
    };
    uint8_t m_relations[300]; //0x0018

    uint8_t m_relationTypeRef[8]; //0x0144

    uint16_t m_index; //0x014C

    //0x014E
    uint8_t m_bCanBeCleanedUp : 1;      // Used for mission type relationship groups to see if they can be cleaned up post script cleanup
    uint8_t m_bAffectsWantedLevel : 1;  // Used to determine if a victim should be excluded from causing crimes to be reported
    uint8_t m_bBlipPeds : 1;            // Used to tell the mini map to blip all peds in this relationship group
}; //Size: 0x0150
