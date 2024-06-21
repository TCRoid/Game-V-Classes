class CNetGamePlayer : public netPlayer
{
public:
    char pad_0000[168]; //0x0000

    // The player info representing this player.
    class CPlayerInfo *m_PlayerInfo; //0x00A8

    char pad_00B0[16]; //0x00B0

    // Current active Clan/crew membership info
    class rlClanMembershipData m_clanMembershipInfo; //0x00C0

    char pad_0171[57]; //0x0171

    // multiplayer character rank
    uint16_t m_nCharacterRank; //0x01AA

    char pad_01AC[72]; //0x01AC
}; //Size: 0x01F4
