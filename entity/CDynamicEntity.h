class CDynamicEntity
{
public:
	char pad_0000[208]; //0x0000
	class netObject *m_pObject; //0x00D0
	uint16_t m_nDEflags_1; //0x00D8
	uint16_t m_nDEflags_2; //0x00DA
	char pad_00DC[164]; //0x00DC
}; //Size: 0x0180
