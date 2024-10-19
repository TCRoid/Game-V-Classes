// PURPOSE
//   A ROS client manages the login state of a local gamer.
//   With rare exceptions, it automatically manages getting and
//   refreshing ROS credentials in a TRC-compliant way.
// NOTE
//   This class should never be accessed by users directly.
class rlRosClient
{
public:
    // PURPOSE
    //  Local gamer index this client represents.
    int GetLocalGamerIndex() const { return m_LocalGamerIndex; }

    // PURPOSE
    //   Returns the client's current login status.
    rlRosLoginStatus GetLoginStatus() const;

    // PURPOSE
    //   Returns the time until the next login attempt.  This will only be valid
    //   when GetLoginStatus() == RLROS_LOGIN_STATUS_COUNTING_DOWN.  In all other
    //   states, -1 will be returned.
    int GetMsUntilNextLoginAttempt() const;

    // PURPOSE
    //   Returns clients current credentials.  Callers should check
    //   the credentials' IsValid() to determine if they are usable.
    //   If the client is not online, the credentials are guaranteed
    //   to be invalid.
    const rlRosCredentials &GetCredentials() const;

    // PURPOSE
    //   Directly sets the credentials used by a client.
    //   The only valid time to call this is when you receive a new
    //   ticket by creating or linking to an SC account.
    //   Outside of those cases, you should let ROS handle fetching
    //   and refreshing credentials, since it will do it in a
    //   TCR-compliant way.
    bool SetCredentials(const rlRosCredentials *cred);

    // PURPOSE
    //   Forces a ROS ticket refresh
    void RenewCredentials();


private:
    friend class rlRos;

    bool Init(const int localGamerIndex);
    void Update(const unsigned timeStep);
    void Shutdown();

    void Retry();
    static unsigned GetFailDelaySeconds();

    int m_LocalGamerIndex;

    enum eState
    {
        STATE_COUNTDOWN,
        STATE_REFRESH_PENDING
    };
    eState m_State;

    rlRosPlatformCredentials m_PlatformCred;
    rlRosCredentials m_RosCred;
    netRetryTimer m_CreateTicketTimer;
    unsigned m_NumRetries;

    class RefreshCredTask : public rlTaskBase
    {
        friend class rlRosClient;

    public:
        RL_TASK_USE_CHANNEL(rline_ros);
        RL_TASK_DECL(RefreshCredTask);

        RefreshCredTask();
        virtual ~RefreshCredTask();

        bool Configure(const int localGamerIndex, rlRosPlatformCredentials *platformCred);

        virtual void DoCancel();

        virtual void Update(const unsigned timeStep);
        virtual bool IsCancelable() const { return true; }
        const char *GetXmlResponse() const { return (const char *)m_ResponseBuf.GetBuffer(); }

    private:
        void Reset();

        rlRosCredentials m_RosCred;
        datGrowBuffer m_ResponseBuf;
        netStatus m_MyStatus;
    };

    RefreshCredTask m_RefreshCredTask;
    netStatus m_RefreshCredStatus;

    bool m_Initialized : 1;
};


// PURPOSE
//   Container for platform-specific credentials necessary to obtain
//   a ROS ticket.  This is only used internally by ROS.
class rlRosPlatformCredentials
{
public:
    char m_Email[101];       // 0x0000
    char m_ScAuthToken[256]; // 0x0065
}; // Size: 0x0165
