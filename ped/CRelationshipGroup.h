class CRelationshipGroup
{
public:
	char pad_0000[16]; //0x0000
	int32_t m_eType; //0x0010
	int32_t m_name; //0x0014
	uint8_t m_relations[300]; //0x0018
	uint8_t m_relationTypeRef[7]; //0x0144
	uint16_t m_index; //0x014B
	uint8_t m_bCanBeCleanedUp; //0x014D
	uint8_t m_bAffectsWantedLevel; //0x014E
	uint8_t m_bBlipPeds; //0x014F
}; //Size: 0x0150
