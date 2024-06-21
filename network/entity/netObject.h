class netObject : public netSyncTreeTargetObject
{
public:
    char pad_0000[72]; //0x0000

    // Timer used to avoid thrashing of the creation/deletion of sync data - keeps
    // track of the number of frames before a change is allowed rather than storing
    // a time in order to save memory
    uint8_t m_syncDataChangeTimer; //0x0048

    // The physical player in control of this network object
    uint8_t m_PlayerIndex; //0x0049

    // The next physical player in the process of being given control
    uint8_t m_PendingPlayerIndex; //0x004A

    // Is this object a network clone?
    bool m_IsClone; //0x004B

    // Local flags used by this object
    uint16_t m_LocalFlags; //0x004C

    // Global flags used by this object (flags broadcast to other machines)
    uint16_t m_GlobalFlags; //0x004E

    // The game object associated with this network object
    void *m_GameObject; //0x0050

    // Pointer to a blender used to interpolate between sync messages
    class netBlender *m_NetBlender; //0x0058

    // The update level the network object is registered with the sync tree
    uint8_t m_SyncTreeUpdateLevel; //0x0060

    // The update batch the network object is registered with the sync tree
    uint8_t m_SyncTreeUpdateBatch; //0x0061

    // Stores how many possible update batches this object could be in (1 means updated every frame, 2 every other frame etc...)
    uint8_t m_NumPossibleUpdateBatches; //0x0062

    // The physical player index of the player to start with when performing operations that are batched
    // by groups of players (for example some expensive processes may be applied to only one player per frame)
    uint8_t m_StartIndexForPlayerBatch; //0x0063

    char pad_0064[30]; //0x0064

    // flags indicating which player machines this object is cloned on
    uint8_t m_ClonedState; //0x0082

    // flags indicating which player machines this object is pending cloning on
    uint8_t m_PendingCloningState; //0x0083

    // flags indicating which player machines this object is pending removal on
    uint8_t m_PendingRemovalState; //0x0084

    // flags indicating which player machines this object is in scope on
    uint8_t m_InScopeState; //0x0085

    // flags indicating which players left while the object was cloned on their machine when local
    uint8_t m_ClonedPlayersThatLeft; //0x0086

    // flags indicating which players this object was updated on (used for batching sends by players)
    uint8_t m_LastPlayersSyncUpdated; //0x0087

    // the ownership token for this network object
    uint32_t m_ownershipToken; //0x0088

    char pad_008C[392]; //0x008C
}; //Size: 0x0214


class CNetObjGame : public netObject
{
public:
    // LocalFlags
    static const unsigned int LOCALFLAG_UNREGISTERING               = BIT(0);   // if set this object has been unregistered and is cleaning itself up
    static const unsigned int LOCALFLAG_NOCLONE                     = BIT(1);   // if set this object is not cloned on other machines
    static const unsigned int LOCALFLAG_BEINGREASSIGNED             = BIT(2);   // set when an object is ownerless and on the reassign list
    static const unsigned int LOCALFLAG_NOREASSIGN                  = BIT(3);   // if set this object will not be reassigned when a player leaves
    static const unsigned int LOCALFLAG_NOLONGERNEEDED              = BIT(4);   // set if this object is a script object and is no longer needed by the script
    static const unsigned int LOCALFLAG_SHOWINCUTSCENE              = BIT(5);   // this object has to remain locally visible in a MP cutscene
    static const unsigned int LOCALFLAG_RESPAWNPED                  = BIT(6);   // set if this object will be used for player ped swap, we cant accept ownership while this is set. After the change is done this FLAG is RESET
    static const unsigned int LOCALFLAG_FORCE_SYNCHRONISE           = BIT(7);   // set if the object should be forced to have sync data
    static const unsigned int LOCALFLAG_TELEPORT                    = BIT(8);   // set if the object is being teleported and ownership can not change
    static const unsigned int LOCALFLAG_DISABLE_BLENDING            = BIT(9);   // set if the object is has been flagged for disabling network blending
    static const unsigned int LOCALFLAG_REMOVE_POST_TUTORIAL_CHANGE = BIT(10);  // set if the object has been flagged for removal once a tutorial session state change has finished
    static const unsigned int LOCALFLAG_OWNERSHIP_CONFLICT          = BIT(11);  // set if the object is being unregistered due to an ownership conflict
    static const unsigned int LOCALFLAG_ENTITY_FIXED                = BIT(12);  // set if the object is being fixed so that it must be moved Straight to target.
    static const unsigned int LOCALFLAG_HAS_MIGRATED                = BIT(13);  // set if the object has migrated locally
    static const unsigned int LOCALFLAG_COUNTED_BY_RESERVATIONS     = BIT(14);  // set if the object has been accounted for by the script reservation system
    static const unsigned int LOCALFLAG_DISABLE_PROXIMITY_MIGRATION = BIT(15);  // set if the object cannot migrate by proximity

    // GlobalFlags
    static const unsigned int GLOBALFLAG_PERSISTENTOWNER    = BIT(0);   // disallows proximity or other common ownership changes to this object - ownership can only be altered via explicit means (usually script commands)
    static const unsigned int GLOBALFLAG_CLONEALWAYS        = BIT(1);   // forces cloning of this object on all players
    static const unsigned int GLOBALFLAG_SCRIPTOBJECT       = BIT(2);   // set if this object is a script object - these objects require extra sync information
    static const unsigned int GLOBALFLAG_CLONEALWAYS_SCRIPT = BIT(3);   // set if this object is always cloned on machines running the same script that created the object
    static const unsigned int GLOBALFLAG_CLONEONLY_SCRIPT   = BIT(4);   // set if this object is only cloned on machines running the same script that created the object
    static const unsigned int GLOBALFLAG_SCRIPT_MIGRATION   = BIT(5);   // set if this object is only to migrate to machines running the same script that created the object
    static const unsigned int GLOBALFLAG_WAS_SCRIPTOBJECT   = BIT(6);   // set if this object used to be a script object
    static const unsigned int GLOBALFLAG_RESERVEDOBJECT     = BIT(7);   // set if this object was created as part of an external population reservation
};
