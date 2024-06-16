class netObject
{
public:
	char pad_0000[72]; //0x0000
	uint8_t m_syncDataChangeTimer; //0x0048
	uint8_t m_PlayerIndex; //0x0049
	uint8_t m_PendingPlayerIndex; //0x004A
	bool m_IsClone; //0x004B
	uint16_t m_LocalFlags; //0x004C
	uint16_t m_GlobalFlags; //0x004E
	void *m_GameObject; //0x0050
	class netBlender *m_NetBlender; //0x0058
	uint8_t m_SyncTreeUpdateLevel; //0x0060
	uint8_t m_SyncTreeUpdateBatch; //0x0061
	uint8_t m_NumPossibleUpdateBatches; //0x0062
	uint8_t m_StartIndexForPlayerBatch; //0x0063
	char pad_0064[30]; //0x0064
	uint8_t m_ClonedState; //0x0082
	uint8_t m_PendingCloningState; //0x0083
	uint8_t m_PendingRemovalState; //0x0084
	uint8_t m_InScopeState; //0x0085
	uint8_t m_ClonedPlayersThatLeft; //0x0086
	uint8_t m_LastPlayersSyncUpdated; //0x0087
	uint32_t m_ownershipToken; //0x0088
	char pad_008C[392]; //0x008C
}; //Size: 0x0214
