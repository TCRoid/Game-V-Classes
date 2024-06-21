class CPedInventory : public CWeaponObserver
{
public:
    char pad_0000[16]; //0x0000

    class CPed *m_pPed; //0x0010
    
    char pad_0018[96]; //0x0018

    //0x0078
    bool m_bUsingInfiniteAmmo : 1;
    bool m_bUsingInfiniteClips : 1;

    char pad_0079[39]; //0x0079
}; //Size: 0x00A0
