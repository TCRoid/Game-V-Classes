// PURPOSE
//   Container for information obtained during authentication.
class rlRosCredentials
{
public:
    // PURPOSE
    //   Returns true if the ticket is valid, and hasn't expired.
    //   On nonsecure platforms, this will return false if we don't have a session key.
    bool IsValid() const;

    // PURPOSE
    //   Returns true if the credentials contain a valid rockstar ID.
    bool IsScMember() const;

    // PURPOSE
    //   Returns milliseconds until the ticket expires.
    int GetMsUntilExpiration() const;

    // PURPOSE
    //   Returns true if we have a valid (non NULL) ticket but we have expired
    bool HasExpired() const;

    // PURPOSE
    //   Returns region ID, determined by ROS from this client's public IP.
    int GetRegion() const;

    // PURPOSE
    //   Returns player account ID.  This should never be zero, as the player
    //   account (which is essentially a shadow account of the platform account)
    //   is automatically created when obtaining credentials.
    PlayerAccountId GetPlayerAccountId() const;

    // PURPOSE
    //   Returns Social Club ID of user.  This will be zero if the player
    //   account is not linked to a Rockstar account.
    RockstarId GetRockstarId() const;

    // PURPOSE
    //   Returns RockstarAccount linked to this local gamer.  If the player is
    //   not linked, the RockstarId on the account will be zero.
    const rlScAccountInfo &GetRockstarAccount() const;

    // PURPOSE
    //   Returns the ID for this session.  Session IDs are unique per player, but not globally unique.
    //   They are used to identify all the calls made within a boot of the game.
    s64 GetSessionId() const;

    // PURPOSE
    //   Returns the base64 ROS ticket, or NULL if no ticket available.
    const char *GetTicket() const;

    // PURPOSE
    //	Sets the base64 ROS ticket
    void SetTicket(const char *ticket);

    // PURPOSE
    //   Returns the base64 ROS session ticket, or NULL if no ticket available.
    const char *GetSessionTicket() const;

    // PURPOSE
    //   Returns the plaintext session key for encryption
    const SessionKey &GetSessionKey() const;

    // PURPOSE
    //   Returns the plaintext cloud key for encryption of cloud files
    const CloudKey &GetCloudKey() const;

    // PURPOSE
    //   Returns true if user has specified privilege.
    bool HasPrivilege(const rlRosPrivilegeId privilegeId) const;

private:
    friend class rlRosClient;

    // Ticket blob, encrypted with a private key known only to ROS backend.
    char m_Ticket[512]; // 0x0000

    // Session ticket blob, encrypted with private key known only to ROS backend.
    // This is basically our way of privately telling the server our m_SessionKey
    char m_SessionTicket[128]; // 0x0200

    uint32_t m_ValidMs;        // 0x0280
    int32_t m_Region;          // 0x0284
    int32_t m_PlayerAccountId; // 0x0288
    int64_t m_SessionId;       // 0x028C

    char pad_0294[4]; // 0x0294

    class rlScAccountInfo m_RockstarAcct; // 0x0298

    // char pad_042A[542]; // 0x042A

    atFixedBitSet<RLROS_NUM_PRIVILEGEID> m_Privileges;

    // Privilege infos for any privileges that aren't the default
    PrivilegeInfo m_PrivilegeInfos[RLROS_NUM_PRIVILEGEID];

    // Our plaintext session key used for encryption/decryption,
    // as chosen by the server.
    uint8_t m_SessionKey[32];    // 0x0648
    uint32_t m_SessionKeyLength; // 0x0668

    // Our plaintext cloud key
    uint8_t m_CloudKey[32];    // 0x066C
    uint32_t m_CloudKeyLength; // 0x068C
};


// PURPOSE
//   Structure that describes a Social Club account.
class rlScAccountInfo
{
public:
    int32_t m_Age;           // 0x0000
    char m_AvatarUrl[160];   // 0x0004
    char m_CountryCode[3];   // 0x00A4
    char m_Dob[32];          // 0x00A7
    char m_Email[101];       // 0x00C7
    bool m_IsApproxDob;      // 0x012C
    char m_LanguageCode[10]; // 0x012D
    char m_Nickname[51];     // 0x0137
    char m_Phone[16];        // 0x016A
    char pad_017A[6];        // 0x017A
    int64_t m_RockstarId;    // 0x0180
    char m_ZipCode[10];      // 0x0188
}; // Size: 0x0192
