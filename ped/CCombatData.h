
enum CCombatData_Movement
{
    CM_Stationary = 0,  // Stands totally still during combat
    CM_Defensive = 1,   // Seeks a defensive position
    CM_WillAdvance = 2, // Will advance forward in combat
    CM_WillRetreat = 3  // Will retreat if the enemy gets too close
};

enum CCombatData_Ability
{
    CA_Poor = 0,        // Ped has low combat ability
    CA_Average = 1,     // Ped has average combat ability
    CA_Professional = 2 // Ped has high combat ability
};

enum CCombatData_Range
{
    CR_Near = 0,   // keeps within 5-15m
    CR_Medium = 1, // keeps within 7-30m
    CR_Far = 2,    // keeps within 15-40m
    CR_VeryFar = 3 // keeps within 22-45m
};

enum CCombatData_TargetLossResponse
{
    TLR_ExitTask = 0,        // Exit the current task
    TLR_NeverLoseTarget = 1, // Never lose the target
    TLR_SearchForTarget = 2  // Search for the target
};

enum CCombatData_TargetInjuredReaction
{
    TIR_TreatAsDead = 0,  // Ped will ignore as a target and continue as if the ped is dead
    TIR_TreatAsAlive = 1, // Ped will see the target as a threat and continue combat as normal
    TIR_Execute = 2       // Ped will approach the ped and shoot at close range
};

enum CCombatData_BehaviourFlags
{
    BF_CanUseCover = BIT(0),                                        // AI can use cover
    BF_CanUseVehicles = BIT(1),                                     // AI can use vehicles
    BF_CanDoDrivebys = BIT(2),                                      // AI can perform drivebys
    BF_CanLeaveVehicle = BIT(3),                                    // AI can leave the vehicle
    BF_CanUseDynamicStrafeDecisions = BIT(4),                       // AI can make dynamic strafe decisions
    BF_AlwaysFight = BIT(5),                                        // AI will always fight
    BF_FleeWhilstInVehicle = BIT(6),                                // AI will flee while in a vehicle
    BF_JustFollowInVehicle = BIT(7),                                // AI will just follow in a vehicle
    BF_Unused_3 = BIT(8),                                           // Unused flag
    BF_WillScanForDeadPeds = BIT(9),                                // AI will scan for dead peds
    BF_Unused_1 = BIT(10),                                          // Unused flag
    BF_JustSeekCover = BIT(11),                                     // AI will just seek cover
    BF_BlindFireWhenInCover = BIT(12),                              // AI can blind fire when in cover
    BF_Aggressive = BIT(13),                                        // AI is aggressive
    BF_CanInvestigate = BIT(14),                                    // AI can investigate
    BF_HasRadio = BIT(15),                                          // AI has a radio
    BF_Unused_2 = BIT(16),                                          // Unused flag
    BF_AlwaysFlee = BIT(17),                                        // AI will always flee
    BF_ForceInjuredOnGround = BIT(18),                              // AI will be forced injured on ground
    BF_DisableInjuredOnGround = BIT(19),                            // AI will disable injured on ground
    BF_CanTauntInVehicle = BIT(20),                                 // AI can taunt in vehicle
    BF_CanChaseTargetOnFoot = BIT(21),                              // AI can chase target on foot
    BF_WillDragInjuredPedsToSafety = BIT(22),                       // AI will drag injured peds to safety
    BF_RequiresLosToShoot = BIT(23),                                // AI requires line of sight to shoot
    BF_UseProximityFiringRate = BIT(24),                            // AI uses proximity firing rate
    BF_DisableSecondaryTarget = BIT(25),                            // AI disables secondary target
    BF_DisableEntryReactions = BIT(26),                             // AI disables entry reactions
    BF_PerfectAccuracy = BIT(27),                                   // AI has perfect accuracy
    BF_CanUseFrustratedAdvance = BIT(28),                           // AI can use frustrated advance
    BF_MoveToLocationBeforeCoverSearch = BIT(29),                   // AI moves to location before cover search
    BF_CanShootWithoutLOS = BIT(30),                                // AI can shoot without line of sight
    BF_MaintainMinDistanceToTarget = BIT(31),                       // AI maintains minimum distance to target
    BF_IgnoreHatedPedsInFastMovingVehicles = BIT(32),               // AI ignores hated peds in fast-moving vehicles
    BF_UseProximityAccuracy = BIT(33),                              // AI uses proximity accuracy
    BF_CanUsePeekingVariations = BIT(34),                           // AI can use peeking variations
    BF_DisablePinnedDown = BIT(35),                                 // AI disables pinned down behavior
    BF_DisablePinDownOthers = BIT(36),                              // AI disables pinning down others
    BF_ClearAreaSetDefensiveIfDefensiveAreaReached = BIT(37),       // AI clears area and sets defensive if defensive area reached
    BF_DisableBulletReactions = BIT(38),                            // AI disables bullet reactions
    BF_CanBust = BIT(39),                                           // AI can bust
    BF_IgnoredByOtherPedsWhenWanted = BIT(40),                      // AI is ignored by other peds when wanted
    BF_CanCommandeerVehicles = BIT(41),                             // AI can commandeer vehicles
    BF_CanFlank = BIT(42),                                          // AI can flank
    BF_SwitchToAdvanceIfCantFindCover = BIT(43),                    // AI switches to advance if can't find cover
    BF_SwitchToDefensiveIfInCover = BIT(44),                        // AI switches to defensive if in cover
    BF_ClearPrimaryDefensiveAreaWhenReached = BIT(45),              // AI clears primary defensive area when reached
    BF_CanFightArmedPedsWhenNotArmed = BIT(46),                     // AI can fight armed peds when not armed
    BF_EnableTacticalPointsWhenDefensive = BIT(47),                 // AI enables tactical points when defensive
    BF_DisableCoverArcAdjustments = BIT(48),                        // AI disables cover arc adjustments
    BF_UseEnemyAccuracyScaling = BIT(49),                           // AI uses enemy accuracy scaling
    BF_CanCharge = BIT(50),                                         // AI can charge
    BF_ClearAreaSetAdvanceIfDefensiveAreaReached = BIT(51),         // AI clears area and sets advance if defensive area reached
    BF_UseVehicleAttack = BIT(52),                                  // AI uses vehicle attack
    BF_UseVehicleAttackIfVehicleHasMountedGuns = BIT(53),           // AI uses vehicle attack if vehicle has mounted guns
    BF_AlwaysEquipBestWeapon = BIT(54),                             // AI always equips best weapon
    BF_CanSeeUnderwaterPeds = BIT(55),                              // AI can see underwater peds
    BF_DisableAimAtAITargetsInHelis = BIT(56),                      // AI disables aim at AI targets in helis
    BF_DisableSeekDueToLineOfSight = BIT(57),                       // AI disables seek due to line of sight
    BF_DisableFleeFromCombat = BIT(58),                             // AI disables flee from combat
    BF_DisableTargetChangesDuringVehiclePursuit = BIT(59),          // AI disables target changes during vehicle pursuit
    BF_CanThrowSmokeGrenade = BIT(60),                              // AI can throw smoke grenade
    BF_NonMissionPedsFleeFromThisPedUnlessArmed = BIT(61),          // Non-mission peds flee from this ped unless armed
    BF_ClearAreaSetDefensiveIfDefensiveCannotBeReached = BIT(62),   // AI clears area and sets defensive if defensive cannot be reached
    BF_FleesFromInvincibleOpponents = BIT(63),                      // AI flees from invincible opponents
    BF_DisableBlockFromPursueDuringVehicleChase = BIT(64),          // AI disables block from pursue during vehicle chase
    BF_DisableSpinOutDuringVehicleChase = BIT(65),                  // AI disables spin out during vehicle chase
    BF_DisableCruiseInFrontDuringBlockDuringVehicleChase = BIT(66), // AI disables cruise in front during block during vehicle chase
    BF_CanIgnoreBlockedLosWeighting = BIT(67),                      // AI can ignore blocked line of sight weighting
    BF_DisableReactToBuddyShot = BIT(68),                           // AI disables react to buddy shot
    BF_PreferNavmeshDuringVehicleChase = BIT(69),                   // AI prefers navmesh during vehicle chase
    BF_AllowedToAvoidOffroadDuringVehicleChase = BIT(70),           // AI is allowed to avoid offroad during vehicle chase
    BF_PermitChargeBeyondDefensiveArea = BIT(71),                   // AI permits charge beyond defensive area
    BF_UseRocketsAgainstVehiclesOnly = BIT(72),                     // AI uses rockets against vehicles only
    BF_DisableTacticalPointsWithoutClearLos = BIT(73),              // AI disables tactical points without clear line of sight
    BF_DisablePullAlongsideDuringVehicleChase = BIT(74),            // AI disables pull alongside during vehicle chase
    BF_DisableShoutTargetPosition = BIT(75),                        // AI disables shout target position
    BF_SetDisableShoutTargetPositionOnCombatStart = BIT(76),        // AI disables shout target position on combat start
    BF_DisableRespondedToThreatBroadcast = BIT(77),                 // AI disables responded to threat broadcast
    BF_DisableAllRandomsFlee = BIT(78),                             // AI disables all randoms flee
    BF_WillGenerateDeadPedSeenScriptEvents = BIT(79),               // AI will generate dead ped seen script events
    BF_UseMaxSenseRangeWhenReceivingEvents = BIT(80),               // AI uses max sense range when receiving events
    BF_RestrictInVehicleAimingToCurrentSide = BIT(81),              // AI restricts in-vehicle aiming to current side
    BF_UseDefaultBlockedLosPositionAndDirection = BIT(82),          // AI uses default blocked line of sight position and direction
    BF_RequiresLosToAim = BIT(83),                                  // AI requires line of sight to aim
    BF_CruiseAndBlockInVehicle = BIT(84),                           // AI can cruise and block in vehicle
    BF_PreferAirCombatWhenInAircraft = BIT(85),                     // AI prefers air combat when in aircraft
    BF_AllowDogFighting = BIT(86),                                  // AI allows dog fighting
    BF_PreferNonAircraftTargets = BIT(87),                          // AI prefers non-aircraft targets
    BF_PreferKnownTargetsWhenCombatClosestTarget = BIT(88),         // AI prefers known targets when combat closest target
    BF_ForceCheckAttackAngleForMountedGuns = BIT(89),               // AI forces check attack angle for mounted guns
    BF_BlockFireForVehiclePassengerMountedGuns = BIT(90)            // AI blocks fire for vehicle passenger mounted guns
};

enum CombatFloats
{
    CCF_BlindFireChance = 0,                               // Chance to blind fire from cover, range is 0.0-1.0 (default is 0.05 for civilians, law doesn't blind fire)
    CCF_BurstDurationInCover = 1,                          // How long each burst from cover should last (default is 2.0)
    CCF_MaxShootingDistance = 2,                           // The maximum distance the ped will try to shoot from (will override weapon range if set to anything > 0.0, default is -1.0)
    CCF_TimeBetweenBurstsInCover = 3,                      // How long to wait, in cover, between firing bursts (< 0.0 will disable firing, unless cover fire is requested, default is 1.25)
    CCF_TimeBetweenPeeks = 4,                              // How long to wait before attempting to peek again (default is 10.0)
    CCF_StrafeWhenMovingChance = 5,                        // A chance to strafe to cover, range is 0.0-1.0 (0.0 will force them to run, 1.0 will force strafe and shoot, default is 1.0)
    CCF_WeaponAccuracy = 6,                                // default is 0.4
    CCF_FightProficiency = 7,                              // How well an opponent can melee fight, range is 0.0-1.0 (default is 0.5)
    CCF_WalkWhenStrafingChance = 8,                        // The possibility of a ped walking while strafing rather than jog/run, range is 0.0-1.0 (default is 0.0)
    CCF_HeliSpeedModifier = 9,                             // The speed modifier when driving a heli in combat
    CCF_HeliSensesRange = 10,                              // The range of the ped's senses (sight, identification, hearing) when in a heli
    CCF_AttackWindowDistanceForCover = 11,                 // The distance we'll use for cover based behaviour in attack windows Default is -1.0 (disabled), range is -1.0 to 150.0
    CCF_TimeToInvalidateInjuredTarget = 12,                // How long to stop combat an injured target if there is no other valid target, if target is player in singleplayer this will happen indefinitely unless explicitly disabled by setting to 0.0, default = 10.0 range = 0-50
    CCF_MinDistanceToTarget = 13,                          // Min distance the ped will use if CA_MAINTAIN_MIN_DISTANCE_TO_TARGET is set, default 5.0 (currently only for cover search + usage)
    CCF_BulletImpactDetectionRange = 14,                   // The range at which the ped will detect the bullet impact event
    CCF_AimTurnThreshold = 15,                             // The threshold at which the ped will perform an aim turn
    CCF_OptimalCoverDistance = 16,                         //
    CCF_AutomobileSpeedModifier = 17,                      // The speed modifier when driving an automobile in combat
    CCF_SpeedToFleeInVehicle = 18,                         //
    CCF_TriggerChargeTimeNear = 19,                        // How long to wait before charging a close target hiding in cover
    CCF_TriggerChargeTimeFar = 20,                         // How long to wait before charging a distant target hiding in cover
    CCF_MaxDistanceToHearEvents = 21,                      // Max distance peds can hear an event from, even if the sound is louder
    CCF_MaxDistanceToHearEventsUsingLOS = 22,              // Max distance peds can hear an event from, even if the sound is louder if the ped is using LOS to hear events (CPED_CONFIG_FLAG_CheckLoSForSoundEvents)
    CCF_HomingRocketBreakLockAngle = 23,                   // Angle between the rocket and target where lock-on will stop, range is 0.0-1.0, (default is 0.2), the bigger the number the easier to break lock
    CCF_HomingRocketBreakLockAngleClose = 24,              // Angle between the rocket and target where lock-on will stop, when rocket is within CCF_HomingRocketBreakLockCloseDistance, range is 0.0-1.0, (default is 0.6), the bigger the number the easier to break lock
    CCF_HomingRocketBreakLockCloseDistance = 25,           // Distance at which we check CCF_HomingRocketBreakLockAngleClose rather than CCF_HomingRocketBreakLockAngle
    CCF_HomingRocketTurnRateModifier = 26,                 // Alters homing characteristics defined for the weapon (1.0 is default, <1.0 slow turn rates, >1.0 speed them up
    CCF_TimeBetweenAggressiveMovesDuringVehicleChase = 27, // Sets the time delay between aggressive moves during vehicle chases. -1.0 means use random values, 0.0 means never
    CCF_MaxVehicleTurretFiringRange = 28,                  // Max firing range for a ped in vehicle turret seat
    CCF_WeaponDamageModifier = 29                          // Multiplies the weapon damage dealt by the ped, range is 0.0-10.0 (default is 1.0)
};
