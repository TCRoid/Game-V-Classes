class fwEntity
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
