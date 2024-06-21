class CSeatManager
{
public:
    int8_t m_iNoSeats; //0x0000
    int8_t m_iDriverSeat; //0x0001
    uint8_t m_nNumPlayers; //0x0002

    //0x0003
    uint8_t m_nNumScheduledOccupants : 7; // 0~6
    uint8_t m_bHasEverHadOccupant : 1; // 7
    
    char pad_0005[4]; //0x0004
    
    class CPed *m_pSeatOccupiers[16]; //0x0008
    class CPed *m_pLastSeatOccupiers[16]; //0x0088
    class CPed *m_pLastDriverFromNetwork; //0x0108
}; //Size: 0x0110
