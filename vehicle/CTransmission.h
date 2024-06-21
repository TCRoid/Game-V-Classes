class CTransmission
{
public:
    int16_t m_nGear; //0x0000
    int16_t m_nPrevGear; //0x0002

    // misc flags for tracking engine behaviour
    enum eTransFlags
    {
        CHANGE_UP_TIME          = BIT(0),
        CHANGE_DOWN_TIME        = BIT(1),
        THROTTLE_HELD           = BIT(2),
        SELECT_GEAR_FOR_SPEED   = BIT(3),  // Used to select an appropriate gear just after a car recording has stopped. Reset after one call to process gears
        SELECTING_REVERSE       = BIT(4),  // Used for bicycles to stop them selecting reverse too quickly
        AUDIO_SUGGEST_CHANGE_UP = BIT(5),  // Suggest a slightly earlier up-shift if it would sound better (eg. audio revs have maxed out)
        ENGINE_UNDER_LOAD       = BIT(6)   // Makes the shift up later and therefore rev higher for longer
    };
    int16_t m_nFlags; //0x0004

    uint8_t m_nDriveGears; //0x0006
    char pad_0007[1]; //0x0007

    bool m_bKERSAllowed; //0x0008
    char pad_0009[3]; //0x0009
    float m_aGearRatios[11]; //0x000C
    char pad_0038[52]; //0x0038

    float m_fThrottleBlipAmount; //0x006C
    float m_fThrottleBlipTimer; //0x0070
    uint32_t m_fThrottleBlipStartTime; //0x0074
    uint32_t m_fThrottleBlipDuration; //0x0078

    // amount of vacuum or boost on the engine
    float m_fManifoldPressure; //0x007C

    uint32_t m_nGearChangeTime; //0x0080
    uint32_t m_UnderLoadChangeUpDelay; //0x0084

    // When a car is running out of petrol make it miss fire
    float m_fMissFireTime; //0x0088
    // Time after miss fire that the car runs fine
    float m_fOverrideMissFireTime; //0x008C

    float m_fEngineHealth; //0x0090
    float m_fEngineHealthDamageScale; //0x0094

    float m_fFireEvo; //0x0098
    char pad_009C[4]; //0x009C
    class CEntity *m_pEntityThatSetUsOnFire; //0x00A0
    float m_fForceThrottle; //0x00A8
    float m_fRemainingNitrousDuration; //0x00AC
    float m_fRemainingKERS; //0x00B0

    char pad_00B4[12]; //0x00B4

    float m_fPlaneDamageThresholdOverride; //0x00C0
    float m_fBoatDriveForce; //0x00C4
    float m_fLastCalculatedDriveForce; //0x00C8

    char pad_00CC[20]; //0x00CC
}; //Size: 0x00E0
