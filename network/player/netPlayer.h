class netPlayer
{
public:
	char pad_0000[8]; //0x0000
	uint32_t m_PlayerType; //0x0008
	char pad_000C[4]; //0x000C
	class nonPhysicalPlayerDataBase *m_NonPhysicalPlayerData; //0x0010
	int32_t m_CxnId; //0x0018
	int32_t m_EndpointId; //0x001C
	uint8_t m_ActivePlayerIndex; //0x0020
	uint8_t m_PhysicalPlayerIndex; //0x0021
	char pad_0022[2]; //0x0022
	uint32_t m_NatType; //0x0024
	uint32_t m_PeerPlayerIndex; //0x0028
	uint32_t m_TimeAdded; //0x002C
	int32_t m_Team; //0x0030
	char pad_0034[84]; //0x0034
	int32_t m_VoiceChannel; //0x0088
	uint32_t m_sizeOfNetArrayData; //0x008C
	uint8_t m_PlayerBitset; //0x0090
	char pad_0091[23]; //0x0091
}; //Size: 0x00A8
