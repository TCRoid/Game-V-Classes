
class CObject
{
public:
	char pad_0000[760]; //0x0000
	uint32_t m_nObjectFlags_1; //0x02F8
	uint32_t m_nObjectFlags_2; //0x02FC
	uint16_t m_procObjInfoIdx; //0x0300
	int16_t StreamedScriptBrainToLoad; //0x0302
	uint32_t m_nEndOfLifeTimer; //0x0304
	char pad_0308[238]; //0x0308
	uint32_t m_damageScanCode; //0x03F6
	uint32_t m_eLastCoverOrientation; //0x03FA
	uint32_t m_nPhysicsTimeSliceToAvoidCollision; //0x03FE
	int32_t m_firstMovedTimer; //0x0402
	float m_fTargetableDistance; //0x0406
	uint16_t m_iPathServerDynObjId; //0x040A
	uint8_t m_vehModSlot; //0x040C
	uint8_t m_speedBoost; //0x040D
	uint8_t m_speedBoostDuration; //0x040E
	uint8_t m_jointToDriveIndex; //0x040F
	uint8_t m_ObjectBitSet_0; //0x0410
	uint8_t m_ObjectBitSet_1; //0x0411
	uint8_t m_ObjectBitSet_2; //0x0412
	uint8_t m_ObjectBitSet_3; //0x0413
	char pad_0414[174]; //0x0414
}; //Size: 0x04C2
