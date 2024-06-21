class netPlayer
{
public:
	char pad_0000[8]; //0x0000

	// The type of player
	uint32_t m_PlayerType; //0x0008

	char pad_000C[4]; //0x000C

	// The non physical player data for this class
	class nonPhysicalPlayerDataBase *m_NonPhysicalPlayerData; //0x0010

	// The connection id of the remote machine the player exists on
	int32_t m_CxnId; //0x0018

	// The endpoint id of the remote machine the player exists on
	int32_t m_EndpointId; //0x001C

	// The index of this network player in the player manager's player pile.
	uint8_t m_ActivePlayerIndex; //0x0020

	// The index of this network player in the player manager's physical player array.
	uint8_t m_PhysicalPlayerIndex; //0x0021

	char pad_0022[2]; //0x0022

	// The NAT type this player is using
	uint32_t m_NatType; //0x0024

	// The index of this network player on the machine that is in control of it
	uint32_t m_PeerPlayerIndex; //0x0028

	// The time the player was added (the synced network time)
	uint32_t m_TimeAdded; //0x002C

	// the player's team
	int32_t m_Team; //0x0030

	char pad_0034[84]; //0x0034

	// The voice channel for this player. -1 for no channel
	int32_t m_VoiceChannel; //0x0088

	// the total size of all net array handler data arbitrated by this player
	uint32_t m_sizeOfNetArrayData; //0x008C

	//0x0090
    bool m_Local : 1;			// Flag indicating whether the player is local
    bool m_Active : 1;			// Flag indicating whether the player is active (updated once per frame)
    bool m_VoiceFlagsDirty : 1;	// Flag indicating whether the voice flags are dirty
	bool m_Leaving : 1;			// set when the player is leaving the session

	char pad_0091[23]; //0x0091
}; //Size: 0x00A8
