class rlClanDesc
{
public:
	int64_t m_Id; //0x0000
	uint32_t m_clanColor; //0x0008
	int32_t m_MemberCount; //0x000C
	int32_t m_CreatedTimePosix; //0x0010
	bool m_IsSystemClan; //0x0014
	bool m_IsOpenClan; //0x0015
	char m_ClanName[25][1]; //0x0016
	char m_ClanTag[5][1]; //0x002F
	char m_ClanMotto[65][1]; //0x0034
}; //Size: 0x0075

class rlClanRank
{
public:
	int64_t m_Id; //0x0000
	char m_RankName[25][1]; //0x0008
	char pad_0021[3]; //0x0021
	int32_t m_RankOrder; //0x0024
	uint64_t m_SystemFlags; //0x0028
}; //Size: 0x0030

class rlClanMembershipData
{
public:
	int64_t rlClanMemberId; //0x0000
	class rlClanDesc m_Clan; //0x0008
	char pad_007D[3]; //0x007D
	class rlClanRank m_Rank; //0x0080
	bool m_IsPrimary; //0x00B0
}; //Size: 0x00B1
