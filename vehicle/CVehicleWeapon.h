class CVehicleWeapon : public CVehicleGadget
{
    s32 m_weaponIndex;
    s32 m_handlingIndex;
};

// Gadget to handle multiple vehicle weapons fired sequentially
// e.g. a load of weapons on the front of a helicopter
class CVehicleWeaponBattery : public CVehicleWeapon
{
public:
#define MAX_NUM_VEHICLE_WEAPONS (6)
#define MAX_NUM_BATTERY_WEAPONS (38)
#define MAX_NUM_VEHICLE_TURRETS_PER_SLOT (4) // 1, 2, 3, 4
#define MAX_NUM_VEHICLE_TURRET_SLOTS (3)     // 1, A1, B1
#define MAX_NUM_VEHICLE_TURRETS (MAX_NUM_VEHICLE_TURRETS_PER_SLOT * MAX_NUM_VEHICLE_TURRET_SLOTS)

    enum eMissileFlapState
    {
        MFS_CLOSED,
        MFS_OPEN,
        MFS_CLOSING,
        MFS_OPENING
    };

    enum eMissileBatteryState
    {
        MBS_IDLE,
        MBS_RELOADING
    };

private:
    static float sm_fOppressor2MissileAlternateWaitTimeOverride;

    CVehicleWeapon *m_VehicleWeapons[MAX_NUM_BATTERY_WEAPONS];
    eMissileFlapState m_MissileFlapState[MAX_NUM_BATTERY_WEAPONS]; // Probably should live on vehicle weapon?
    eMissileBatteryState m_MissileBatteryState;
    s32 m_iLastFiredWeapon;

    s32 m_iNumVehicleWeapons;

    // Weapons are not fired in order
    s32 m_iCurrentWeaponCounter;

    u32 m_uNextLaunchTime; // 0x01F4
};

// Class to represent a single weapon mounted to a vehicle
// The weapon is fixed (always points along bone's forward vector)
class CFixedVehicleWeapon : public CVehicleWeapon
{
protected:
    CWeapon *m_pVehicleWeapon;
    eHierarchyId m_iWeaponBone;

    // Kickback vars
    u32 m_iTimeLastFired;

    // Fire vars need queuing so that weapon is only fired at the correct point in the frame
    RegdConstPed m_pFiringPed;
    RegdConstEnt m_pQueuedTargetEnt;
    Vector3 m_vQueuedTargetPos;
    Vector3 m_vQueuedFireDirection;
    Vector3 m_vOverrideWeaponDirection;
    Vector3 m_vTurretForwardLastUpdate;
    bool m_bFireIsQueued;
    bool m_bForceShotInWeaponDirection;
    bool m_bUseOverrideWeaponDirection;
    float m_fOverrideLaunchSpeed;

    // Required to cache off in post pre render
    Vector3 m_v3ReticlePosition;

    // Total dist used for frame by frame line probe
    f32 m_fProbeDist;

    // Number of radians still to rotate "ammo belt" through after firing a bullet.
    float m_fAmmoBeltAngToTurn;

    strRequest m_projectileRequester;
};
