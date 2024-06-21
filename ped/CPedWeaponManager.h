class CPedWeaponManager : public CInventoryListener
{
public:
    char pad_0000[16]; //0x0000

    // Owner ped
    class CPed *m_pPed; //0x0010

    // Input handler - manages pad input and weapon selection
    class CPedWeaponSelector m_selector; //0x0018

    // Equipped weapon
    class CPedEquippedWeapon m_equippedWeapon; //0x0058

    // Last equipped weapon
    class CWeaponInfo *m_pLastEquippedWeaponInfo; //0x0158

    // Ped Accuracy
    class CPedAccuracy m_accuracy; //0x0160

    // Equipped vehicle weapon
    // Vehicle weapons and ped weapons are mutually exclusive
    int32_t m_iEquippedVehicleWeaponIndex; //0x016C

    // Equipped gadgets
    char m_equippedGadgets[2][8]; //0x0170

    // Backed up equipped weapon hash - stored when in vehicles, so it can be restored
    uint32_t m_uEquippedWeaponHashBackup; //0x0180

    // Chance of firing blanks
    float m_fChanceToFireBlanksMin; //0x0184
    float m_fChanceToFireBlanksMax; //0x0188

    // Handle to any active constraint from SwitchToRagdoll
    uint16_t m_RagdollConstraintHandle_index; //0x018C
    uint16_t m_phConstraintHandle_generation; //0x018E //?

    // The time when we equipped or fired our weapon
    uint32_t m_uLastEquipOrFireTime; //0x0190

    bool m_bForceReloadOnEquip; //0x0194
    char pad_0195[11]; //0x0195

    // The position we are aiming our weapon at
    Vector3 m_vWeaponAimPosition; //0x01A0
    char pad_01AC[4]; //0x01AC

    // The last position we hit with our weapon
    Vector3 m_vImpactPosition; //0x01B0
    char pad_01BC[4]; //0x01BC

    // The time the impact position was recorded
    int32_t m_iImpactTime; //0x01C0

    enum Flags
    {
        Flag_CreateWeaponWhenLoaded     = BIT(0),
        Flag_DetonatorDeactivated       = BIT(1),
        Flag_SyncAmmo                   = BIT(2),
        Flag_DelayedWeaponInLeftHand    = BIT(3)
    };
    uint32_t m_flags; //0x01C4

    enum eWeaponInstruction
    {
        WI_None,
        WI_AmbientTaskDestroyWeapon,
        WI_AmbientTaskDestroyWeapon2ndAttempt,
        WI_RevertToStoredWeapon,
        WI_AmbientTaskDropAndRevertToStored,
        WI_AmbientTaskDropAndRevertToStored2ndAttempt
    };
    uint32_t m_nInstruction; //0x01C8
}; //Size: 0x01CC


class CPedWeaponSelector
{
public:
    // The current selected weapon
    int32_t m_uSelectedWeaponHash; //0x0000

    char pad_0004[4]; //0x0004

    // The current selected weapon info
    class CWeaponInfo *m_pSelectedWeaponInfo; //0x0008

    // The current selected vehicle weapon
    int32_t m_iSelectedVehicleWeaponIndex; //0x0010

    // Time weapon was selected
    uint32_t m_uWeaponSelectTime; //0x0014

    // Next time to consider switching weapon
    uint32_t m_uNextConsiderSwitchTimeMS; //0x0018

    char pad_001C[36]; //0x001C
}; //Size: 0x0040


class CPedEquippedWeapon
{
public:
    // Owner ped
    class CPed *m_pPed; //0x0000

    // Flag to avoid the AI from requesting the animations multiple times
    bool m_bWeaponAnimsRequested; //0x0008
    bool m_bWeaponAnimsStreamed; //0x0009

    char pad_000A[6]; //0x000A

    // The equipped weapon info
    class CWeaponInfo *m_pEquippedWeaponInfo; //0x0010

    // The vehicle weapon info, if we are in a vehicle
    class CWeaponInfo *m_pEquippedVehicleWeaponInfo; //0x0018

    // Pointer to instantiated object
    class CObject *m_pObject; //0x0020
    class CObject *m_pSecondObject; //0x0028
    class CWeapon *m_pUnarmedWeapon; //0x0030
    class CWeapon *m_pUnarmedKungFuWeapon; //0x0038
    class CWeapon *m_pWeaponNoModel; //0x0040

    char pad_0048[184]; //0x0048
}; //Size: 0x0100


class CPedAccuracy : public CPedAccuracyResetVariables
{
public:
    // Recoil firing time
    float m_fNormalisedTimeFiring; //0x0008
}; //Size: 0x000C

