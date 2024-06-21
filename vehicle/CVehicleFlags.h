class CVehicleFlags
{
public:
    // 0x0000
    uint8_t bDisplayHighDetail : 1;           // 0 // want to display the high detail model associated with this model (not the actual model)
    uint8_t bCreatedByFactory : 1;            // 1 // Set true if car has been created using a vehicle factory
    uint8_t bNeverUseSmallerRemovalRange : 1; // 2 // Some vehicles (like planes) we don't want to remove just behind the camera.
    uint8_t bCreatedUsingCheat : 1;           // 3 // Player has created this vehicle using a cheat. (Should be tidied away next time cheat is used)
    uint8_t bGangVeh : 1;                     // 4 // This is a gang car and gang member should be created inside (gangPopGroup obtained from CVehicleModelInfo)
    uint8_t bMercVeh : 1;                     // 5 // This is a vehicle belonging to a mercanary
    uint8_t bIsVan : 1;                       // 6 // Is this vehicle a van (doors at back of vehicle)
    uint8_t bIsBus : 1;                       // 7 // Is this vehicle a bus

    // 0x0001
    uint8_t bIsBig : 1;                   // 0 // Is this vehicle big
    uint8_t bLowVehicle : 1;              // 1 // Need this for sporty type cars to use low getting-in/out anims
    uint8_t bHasDummyBound : 1;           // 2 // Does this vehicle have a dummy bound
    uint8_t bWasCreatedByDispatch : 1;    // 3 // Tells us if this vehicle was created by a dispatch system
    uint8_t bIsLawEnforcementVehicle : 1; // 4 // Same result as old IsLawEnforcementVehicle() function but faster.
    uint8_t bIsLawEnforcementCar : 1;     // 5 // Same result as old IsLawEnforcementCar() function but faster.
    uint8_t bReportCrimeIfStandingOn : 1; // 6 // Crime reporting for standing on
    uint8_t bIsThisAParkedCar : 1;        // 7 // Same result as old IsThisAParkedCar() function but faster.

    // 0x0002
    uint8_t bIsThisAStationaryCar : 1;                    // 0 // Same result as old IsThisAStationaryCar() function but faster. Note: NOT an accurate indicator of the vehicle's velocity (moving vehicles CAN have this flag set to true in certain situations)
    uint8_t bIsThisADriveableCar : 1;                     // 1 // Same result as old GetVehicleDamage()->GetIsDriveable() function but faster.
    uint8_t bForceOtherVehiclesToStopForThisVehicle : 1;  // 2 // Makes sure normal traffic always stops rather than trying to steer round (reset every frame)
    uint8_t bForceOtherVehiclesToOvertakeThisVehicle : 1; // 3 // Makes sure normal traffic always tries to overtake this car rather than wait behind
    uint8_t bBecomeStationaryQuicker : 1;                 // 4 // Become stationary more quickly after losing the driver.
    uint8_t bHasDynamicNavMesh : 1;                       // 5 // If this vehicle has its own navmesh
    uint8_t bMadDriver : 1;                               // 6 // This vehicle is driving like a lunatic
    uint8_t bSlowChillinDriver : 1;                       // 7 // This vehicle is driving slow, windows down, music up

    // 0x0003
    uint8_t bHasGlowingBrakes : 1;      // 0
    uint8_t bHasSiren : 1;              // 1 // Vehicle has a siren.
    uint8_t bUseDeformation : 1;        // 2 // turn deformation off for certain vehicle types (bikes for example)
    uint8_t bFreebies : 1;              // 3 // Any freebies left in this vehicle ?
    uint8_t bTakeLessDamage : 1;        // 4 // This vehicle is stronger (takes about 1/4 of damage)
    uint8_t bTyresDontBurst : 1;        // 5 // If this is set the tyres are invincible
    uint8_t bWheelsDontBreak : 1;       // 6 // If set the wheels cannot be broken off
    uint8_t bVehicleCanBeTargetted : 1; // 7 // The ped driving this vehicle can be targetted, (for Torenos plane mission).  If no ped then the vehicle is targeted

    // 0x0004
    uint8_t bIsATargetPriority : 1;             // 0 // If set to targetable then this vehicle is higher priority target than normal
    uint8_t bTargettableWithNoLos : 1;          // 1 // If set to targetable then this vehicle can be targeted with no line of sight
    uint8_t bDoesProvideCover : 1;              // 2 // If this is false this particular vehicle can not be used to take cover behind.
    uint8_t bConsideredByPlayer : 1;            // 3 // This vehicle is considered by the player to enter
    uint8_t bCanBeVisiblyDamaged : 1;           // 4
    uint8_t bMissionVehToughAxles : 1;          // 5 // tougher axles for mission vehicles so they don't skew / jam so easily
    uint8_t bShouldNotChangeColour : 1;         // 6 // Some scripted cars shouldn't change colour in respray shop
    uint8_t bExplodesOnHighExplosionDamage : 1; // 7 // Script can stop cars exploding instantly when hit by explosion

    // 0x0005
    uint8_t bExplodesOnNextImpact : 1;    // 0 // Script can set vehicles to explode on the next impact
    uint8_t bPlaneResistToExplosion : 1;  // 1 // (MP Only) Script can set a plane to survive from 2 to 3 explosion impacts
    uint8_t bDisableExplodeOnContact : 1; // 2 // Script can set this to override the CVehicleModelInfoFlags::FLAG_EXPLODE_ON_CONTACT flag
    uint8_t bCanEngineMissFire : 1;       // 3 // Script can enable engines to missfire when damaged
    uint8_t bCanLeakPetrol : 1;           // 4 // script can enable cars to leak petrol from damaged petrol tanks
    uint8_t bCanLeakOil : 1;              // 5 // script can enable cars to leak oil from damaged engines
    uint8_t bCanPlayerCarLeakPetrol : 1;  // 6 // script can enable player cars to leak petrol from damaged petrol tanks
    uint8_t bCanPlayerCarLeakOil : 1;     // 7 // script can enable player cars to leak oil from damaged engines

    // 0x0006
    uint8_t bDisablePetrolTankFires : 1;                     // 0 // script can disable petrol tank fires from starting
    uint8_t bDisablePetrolTankDamage : 1;                    // 1 // script can disable petrol tank damage
    uint8_t bDisableEngineFires : 1;                         // 2 // script can disable engine fires from starting
    uint8_t bLimitSpeedWhenPlayerInactive : 1;               // 3 // script can disable the limiting of speed when the player driver is inactive
    uint8_t bStopInstantlyWhenPlayerInactive : 1;            // 4 // script can allow vehicle stop naturally when the player driver is inactive
    uint8_t bUnfreezeWhenCleaningUp : 1;                     // 5 // decides whether to call SetFixedPhysics(false) in CPhysical::CleanupMissionState
    uint8_t bDontTryToEnterThisVehicleIfLockedForPlayer : 1; // 6 // (MP Only) Player won't even attempt to enter this vehicle if its locked for the player, also displays help text
    uint8_t bDisablePretendOccupants : 1;                    // 7 // script can disable the vehicle attempting to add pretend occupants to the vehicle.

    // 0x0007
    uint8_t bUnbreakableLights : 1;              // 0 // nothing will break the lights, unless they actually get detached from the vehicle.
    uint8_t bRespectLocksWhenHasDriver : 1;      // 1 // vehicle locks are ignored for vehicles with drivers by default - this flag ensures locks are always checked
    uint8_t bForceEngineDamageByBullet : 1;      // 2 // Apply engine damage when vehicle gets hit by bullet at any position
    uint8_t bGeneratesEngineShockingEvents : 1;  // 3 // Script can disable whether this vehicle generates shocking events tied to the engine like CEventShockingPlaneFlyBy
    uint8_t bCanEngineDegrade : 1;               // 4 // Script can enable/disable engine degrading
    uint8_t bCanPlayerAircraftEngineDegrade : 1; // 5 // Script can enable/disable engine degrading for aircraft that's driven by player
    uint8_t bCanDeformWheels : 1;                // 6 // Script can enable/disable the wheel deformation
    uint8_t bCanBreakOffWheelsWhenBlowUp : 1;    // 7 // Script can enable/disable breaking off wheels when car blows up

    // 0x0008
    uint8_t bIsStolen : 1;                              // 0 // mark the vehicle as stolen
    uint8_t bForceEnemyPedsFalloff : 1;                 // 1 // force peds that are standing on this vehicle to fall off regardless of how slow the vehicle is moving
    uint8_t bBlowUpWhenMissingAllWheels : 1;            // 2 // force this vehicle to blow up when it is missing all of its wheels.
    uint8_t bRearDoorsHaveBeenBlownOffByStickybomb : 1; // 3 // True if vehicle rear doors have been blown off by stickybomb
    uint8_t bDisableSuperDummy : 1;                     // 4 // Prevent a vehicle from switching to superdummy mode.
    uint8_t bInfluenceWantedLevel : 1;                  // 5 // Does this vehicle affect the wanted level if it's considered the "victim" of a crime?
    uint8_t bLightsOn : 1;                              // 6 // Are the lights switched on ?
    uint8_t bHeadlightsFullBeamOn : 1;                  // 7 // Are the extra brights headlights active

    // 0x0009
    uint8_t bLeftIndicator : 1;        // 0 // If true the left indicator light should be on.
    uint8_t bRightIndicator : 1;       // 1 // If true the right indicator light should be on.
    uint8_t bHazardLights : 1;         // 2 // Hazard lights make all indicators flash.
    uint8_t bIndicatorLights : 1;      // 3 // Turn indicator forced on/off
    uint8_t bForceBrakeLightOn : 1;    // 4 // If this is true the brake light is rendered 'on' regardless of the actual braking applied.
    uint8_t bSuppressBrakeLight : 1;   // 5 // If this is true the brake light is rendered 'off' regardless of the actual braking applied.
    uint8_t bInteriorLightOn : 1;      // 6 // Force interior lights to be on.
    uint8_t bLightsButtonHeldDown : 1; // 7 // Is the headlights button held down?

    // 0x000A
    uint8_t bLightsAllowFullBeamSwitch : 1;         // 0 // If swapping between dipped/full beam, don't allow another swap until bLightsButtonHeldDown becomes false
    uint8_t bRepairWhenSafe : 1;                    // 1 // Calls Fix() on the vehicle during ProcessControl(). This is set when we can't immediately fix the vehicle, usually during the physics update.
    uint8_t bPlayerHasTurnedOffLowBeamsAtNight : 1; // 2 // If the player toggles lights twice, cycle through off-low-high
    uint8_t bRoofLowered : 1;                       // 3 // If the car is a convertible and has it's roof lowered
    uint8_t bEngineOn : 1;                          // 4 // Cars can only drive when their engine is on.
    uint8_t bEngineStarting : 1;                    // 5 // Before the engine is actually on the engine will be starting first. Depending on the temperature of the engine this may take longer.
    uint8_t bEngineWontStart : 1;                   // 6 // Is the engine going to fail to start this time?
    uint8_t bSkipEngineStartup : 1;                 // 7 // should skip audible ignition sequence

    // 0x000B
    uint8_t bBlipThrottleRandomly : 1; // 0 // script can set this
    uint8_t bHasCoolingFan : 1;        // 1
    uint8_t bIsCoolingFanOn : 1;       // 2
    uint8_t bAudioBackfired : 1;       // 3 // this flag is set when the audio thread plays a backfire sound - we need to trigger an fx but can't from this thread
    uint8_t bAudioBackfiredBanger : 1; // 4 // this flag is set when the audio thread plays a banger backfire sound - we need to trigger an fx but can't from this thread
    uint8_t bHornOnNetwork : 1;        // 5
    uint8_t bIsAmbulanceOnDuty : 1;    // 6 // Ambulance trying to get to an accident
    uint8_t bIsFireTruckOnDuty : 1;    // 7 // Firetruck trying to get to a fire

    // 0x000C
    uint8_t bCannotRemoveFromWorld : 1;         // 0 // Is this guy locked by the script (cannot be removed)
    uint8_t bHasBeenOwnedByPlayer : 1;          // 1 // To work out whether stealing it is a crime
    uint8_t bCarNeedsToBeHotwired : 1;          // 2 // To work out whether stealing it is a crime
    uint8_t bCountAsParkedCarForPopulation : 1; // 3 // For population purposes this car is counted as a parked car (So it won't come out of the budget for moving cars)
    uint8_t bDontStoreAsPersistent : 1;         // 4 // Some vehicles (like mission vehicles) should not be stored as persistent.
    uint8_t bScheduledForCreation : 1;          // 5 // This vehicle is scheduled for creation
    uint8_t bAlertWhenEntered : 1;              // 6 // This car will send a shocking event for being stolen when the player enters it.
    uint8_t bIsParkedAtPetrolStation : 1;       // 7 // This car is parked in a petrol stations and is waiting for a scenario to be applied to it.

    // 0x000D
    uint8_t bCantTrafficJam : 1;                // 0 // This car will not be considered part of a traffic jam (for population control purposes).
    uint8_t bVehicleIsOnscreen : 1;             // 1 // If this car can be seen on screen.
    uint8_t bCreatingAsInactive : 1;            // 2 // The vehicle is being created in inactive state (i.e. super-dummy with physics "disabled")
    uint8_t bTryToRemoveAggressively : 1;       // 3 // If set, try to delete this vehicle when the player isn't looking. Used for scenario vehicles within blocking areas.
    uint8_t bCanBeDeletedWithAlivePedsInIt : 1; // 4
    uint8_t bIsInCluster : 1;                   // 5 // Was this created at a clustered scenario point
    uint8_t bIsInClusterBeingSpawned : 1;       // 6 // True while we are in the process of spawning as a part of a scenario cluster
    uint8_t bCanBeUsedByFleeingPeds : 1;        // 7 // This vehicle can be used by fleeing peds

    // 0x000E
    uint8_t bCreatedByLowPrioCargen : 1;               // 0 // A low prio cargen has created this vehicle
    uint8_t bRemoveWithEmptyCopOrWreckedVehs : 1;      // 1
    uint8_t bCreatedByCarGen : 1;                      // 2 // Vehicle was created on a cargen
    uint8_t bHasBeenDriven : 1;                        // 3 // Vehicle has been driven
    uint8_t bApproachingJunctionWithSiren : 1;         // 4 // This car has its siren on and is within a certain distance of a junction
    uint8_t bPreviousApproachingJunctionWithSiren : 1; // 5 // Same as above but for previous frame. (Can be used to find out whether we have just approached junction)
    uint8_t bIsParkedParallelly : 1;                   // 6 // This car has parked itself in a parallel parking spot
    uint8_t bIsParkedPerpendicularly : 1;              // 7 // This car has parked itself in a perpendicular parking spot

    // 0x000F
    uint8_t bShouldBeRemovedByAmbientPed : 1; // 0 // This car is a nuisance and should be removed by an ambient ped
    uint8_t bPoliceFocusWillTrackCar : 1;     // 1 // If this is set the vehicle will always have the police focus circle locked onto it.
    uint8_t bShouldBeBeepedAt : 1;            // 2 // This car is badly driven by player and should be beeped at
    uint8_t bPlayerDrivingAgainstTraffic : 1; // 3
    uint8_t bDisableTowing : 1;               // 4 // Don't allow this vehicle to tow another (set on the tow truck)
    uint8_t bIsWaitingToTurnLeft : 1;         // 5 // This car is waiting to turn left at a junction
    uint8_t bIsRacing : 1;                    // 6 // This vehicle is racing and should use different params for avoidance/etc
    uint8_t bHasGeneratedCover : 1;           // 7 // Whether the vehicle has generated cover

    // 0x0010
    uint8_t bIsInRecording : 1;                      // 0 // Is the vehicle being controlled by a vehicle recording
    uint8_t bIsCargoVehicle : 1;                     // 1
    uint8_t bHasWheelOnPavement : 1;                 // 2
    uint8_t bWillTurnLeftAgainstOncomingTraffic : 1; // 3 // we think we will set bIsWaitingToTurnLeft when we get to the middle of a junction
    uint8_t bTurningLeftAtJunction : 1;              // 4 // Are we in the middle of a left turn?
    uint8_t bToldToGetOutOfTheWay : 1;               // 5 // Another vehicle has hurried us
    uint8_t bIsInRoadBlock : 1;                      // 6 // This car is in a road block
    uint8_t bShouldLerpFromAiToFullRecording : 1;    // 7 // This car is flagged to use bLerpToFullRecording when switching from an AI recording to a full recording

    // 0x0011
    uint8_t bIsDoingHandBrakeTurn : 1;         // 0
    uint8_t bDisableAvoidanceProjection : 1;   // 1
    uint8_t bForceEntityScansAtHighSpeeds : 1; // 2
    uint8_t bIsRacingConservatively : 1;       // 3
    uint8_t bMoveAwayFromPlayer : 1;           // 4 // Used to tell helis to fly away. (When wanted level has dropped)
    uint8_t bCanMakeIntoDummyVehicle : 1;      // 5
    uint8_t bUsingPretendOccupants : 1;        // 6
    uint8_t bSuperDummyProcessed : 1;          // 7 // Was the super-dummy update processed this frame

    // 0x0012
    uint8_t bLodFarFromPopCenter : 1;                       // 0 // Is this vehicle far from the pop center this frame? (LOD info independent of dummy state.  Useful for LODing features that have small visual impact.)
    uint8_t bLodSuperDummyWheelCompressionSet : 1;          // 1 // Have the wheel compressions been set since this vehicle became a super-dummy?
    uint8_t bLodCanUseTimeslicing : 1;                      // 2 // This is meant to get set to true by vehicle tasks that support timeslicing
    uint8_t bLodCanUseTimeslicingAfterVisibilityChecks : 1; // 3 // Set by the LOD manager based on bLodCanUseTimeslicing.
    uint8_t bLodCanUseTimeslicingIfTooManyUpdates : 1;      // 4 // Set by the LOD manager based on bLodCanUseTimeslicing.
    uint8_t bLodShouldUseTimeslicing : 1;                   // 5 // Like bLodCanUseTimeslicing, but more aggressive, bypassing checks for superdummy and visibility.
    uint8_t bLodShouldSkipUpdatesInTimeslicedLod : 1;       // 6
    uint8_t bLodForceUpdateThisTimeslice : 1;               // 7 // Used for AI timeslicing to force an immediate update on the first frame in timeslicing LOD.

    // 0x0013
    uint8_t bLodForceUpdateUntilNextAiUpdate : 1;    // 0 // Similar to bLodForceUpdateThisTimeslice, but ensures that we get an actual AI update before the flag gets reset.
    uint8_t bLodStrictRoadProximityTest : 1;         // 1 // If a vehicle is coming from navigation other than using road nodes, then be more strict when testing to see if it can convert to dummy
    uint8_t bIsDeactivatedByPlayback : 1;            // 2 // If a vehicle physics gets deactivated by the playback, either forcibly or as an optimization
    uint8_t bMayBecomeParkedSuperDummy : 1;          // 3 // If this vehicle is parked, should we possibly allow it to become a superdummy?
    uint8_t bMoreAccurateVirtualRoadProbes : 1;      // 4 // If set, do some extra calculations to see if we might want to use virtual road probes on all wheels when in superdummy, due to an uneven surface.
    uint8_t bWasOffroadWithConstraint : 1;           // 5
    uint8_t bCheckForMisalignmentOnDeactivation : 1; // 6 // True if we should check for misalignment with the road on the next OnDeactivate() call
    uint8_t bWheelsDisabled : 1;                     // 7

    // 0x0014
    uint8_t bWheelsDisabledOnDeactivation : 1; // 0 // Wheels were disabled when this vehicle was deactivated.
    uint8_t bIsDrowning : 1;                   // 1 // is vehicle occupants taking damage in water (i.e. vehicle is dead in water)
    uint8_t bDisableParticles : 1;             // 2 // Disable particles from this car. Used in garage.
    uint8_t bWanted : 1;                       // 3 // If true this car is wanted by the police, if a player is in a wanted car he is easier to see.
    uint8_t bInSlownessZone : 1;               // 4 // This is true if this vehicle is in an artists specified slowness zone and needs to have extra air friction applied.
    uint8_t bWheelShapetest : 1;               // 5 // Is wheel shapetest enabled (more expensive wheel processing)
    uint8_t bPlaceOnRoadQueued : 1;            // 6 // Waiting for collision to load to place on road properly
    uint8_t bAutomaticallyAttaches : 1;        // 7 // Indicates whether tow trucks or trucks automatically attach to this vehicle

    // 0x0015
    uint8_t bScansWithNonPlayerDriver : 1;        // 0 // Indicates whether trucks without player drivers search and attach to trailers
    uint8_t bCarAgainstCarSideCollision : 1;      // 1 // Indicates whether a car has run into the side of this car
    uint8_t bCarHitByHeavyVehicle : 1;            // 2 // Indicates whether a car has been hit by a heavy vehicle
    uint8_t bCarHitWhileInRoadBlock : 1;          // 3 // Indicates whether a car has been hit side on while part of a road block
    uint8_t bCarBrushAgainstCarSideCollision : 1; // 4 // Indicates whether a car side has brushing against another car side in high speed
    uint8_t bCarHitBySuperHeavyVehicle : 1;       // 5 // Indicates whether a car has been hit by a super heavy vehicle
    uint8_t bCarCrushingBike : 1;                 // 6 // Indicates whether a car is sitting on top of a bike
    uint8_t bShouldFixIfNoCollision : 1;          // 7 // Fixes the car if no collision is around it

    // 0x0016
    uint8_t bPetrolTankEmpty : 1;             // 0 // True if the petrol tank is empty (set by vehicledamage code)
    uint8_t bDrivingOnVehicle : 1;            // 1 // True it the vehicle is driving on another vehicle
    uint8_t bProducingSlipStream : 1;         // 2 // This vehicle is producing slip stream for another vehicle, i.e. another vehicle is behind this vehicle and speeding up because of it.
    uint8_t bUpdateProducingSlipStream : 1;   // 3 // The vehicle was producing slip stream
    uint8_t bSlipStreamDisabledByTimeOut : 1; // 4 // After being in slip stream for a certain amount of time we deactivate slipstream for a bit.
    uint8_t bDisableHeightMapAvoidance : 1;   // 5 // Setting this to true will disable height map avoidance on planes and helicopters
    uint8_t bDrivenDangerouslyThisUpdate : 1; // 6
    uint8_t bDrivenDangerouslyExtreme : 1;    // 7

    // 0x0017
    uint8_t bIsInPopulationCache : 1;      // 0
    uint8_t bPartsBrokenOff : 1;           // 1
    uint8_t bHasBeenRepainted : 1;         // 2
    uint8_t bForceHd : 1;                  // 3
    uint8_t bScriptForceHd : 1;            // 4
    uint8_t bIsBeingTowed : 1;             // 5
    uint8_t bCanSaveInGarage : 1;          // 6
    uint8_t bRestoreVelAfterCollLoads : 1; // 7 // Setting to true will restore velocity on vehicles that was set before they were fixed waiting for collision

    // 0x0018
    uint8_t bRestorePlaybackVelAfterCollLoads : 1; // 0 // Setting to true will restore velocity on vehicles that was set by a recording after they are un-fixed from waiting for collision
    uint8_t bMayHavePedDrivingDoorFlagSet : 1;     // 1 // Set if PED_DRIVING_DOOR is currently set on any of the doors
    uint8_t bIsAsleep : 1;                         // 2
    uint8_t bCanBeStolen : 1;                      // 3 // if false it won't be flagged as stolen when player enters
    uint8_t bVehicleInaccesible : 1;               // 4 // Used to identify when a ped can't enter a vehicle, e.g. a bike gets stuck under something low.
    uint8_t bAllowBoundsToBeRaised : 1;            // 5 // This vehicle can have its bounds raised and lowered to allow vehicles to go over high curbs without disturbance from collision.
    uint8_t bTowedVehBoundsCanBeRaised : 1;        // 6 // This towed vehicle can have its bounds raised and lowered to allow vehicles to go over high curbs without disturbance from collision.
    uint8_t bIsNitrousBoostActive : 1;             // 7 // Set when the engine is being given a boost due to nitrous

    // 0x0019
    uint8_t bIsKERSBoostActive : 1;              // 0 // Set when the engine is being given a boost due to KERS
    uint8_t bAICanUseExclusiveSeats : 1;         // 1 // AI are allowed to use driver seats marked as exclusive
    uint8_t bAreHydraulicsAllRaised : 1;         // 2 // Set when the hydraulics are set to their top position.
    uint8_t bPlayerModifiedHydraulics : 1;       // 3 // Set when hydraulics are being modified by the player. Synced across network.
    uint8_t bIsUnderMagnetControl : 1;           // 4 // Set when a vehicle is being pulled in by a magnet gadget. Prevents the owner of the magnet from losing control of the vehicle in network games.
    uint8_t bDisableRoadExtentsForAvoidance : 1; // 5 // Set to disable road extent calculation for vehicle avoidance
    uint8_t bHasBeenResprayed : 1;               // 6 // Has been resprayed in a respray garage. Reset after it has been checked.
    uint8_t bHideInCutscene : 1;                 // 7 // all (mission) vehicles are hidden in cutscene as default

    // 0x001A
    uint8_t bNotDriveable : 1;                        // 0 // Script can prevent us from being able to start the engine (can still get in though)
    uint8_t bUseAlternateHandling : 1;                // 1 // Signifies whether the car uses alternate handling or not.
    uint8_t bStealable : 1;                           // 2 // Disables a vehicle from being stealable by ambient peds.
    uint8_t bLockDoorsOnCleanup : 1;                  // 3 // Locks all doors when the vehicle converts from a script vehicle to an ambient one
    uint8_t bForceInactiveDuringPlayback : 1;         // 4 // Force the vehicle staying inactive during the playback recording.
    uint8_t bForceActiveDuringPlayback : 1;           // 5 // Force the vehicle staying active during the playback recording.
    uint8_t bAllowKnockOffVehicleForLargeVertVel : 1; // 6
    uint8_t bScriptSetHandbrake : 1;                  // 7 // Script is forcing the handbrake on

    // 0x001B
    uint8_t bUsedForPilotSchool : 1;        // 0 // Is used for pilot school
    uint8_t bActiveForPedNavigation : 1;    // 1 // Peds will consider this vehicle when navigation
    uint8_t bKeepEngineOnWhenAbandoned : 1; // 2 // The engine will remain on after driver exit vehicle
    uint8_t bUsesLargeRearRamp : 1;         // 3 // Script can force aircraft doors to use the VEH_BOOT tunings for other doors (used for Cargoplane)
    uint8_t bForceAfterburnerVFX : 1;       // 4 // Script can force vehicles after burner on. This is a fix for GTAV B*1739284
    uint8_t bAllowHomingMissleLockon : 1;   // 5 // Special case where scripters can disable homing missiles from targeting individual vehicles;
    uint8_t bAllowNoPassengersLockOn : 1;   // 6 // Allow lock on, no occupants.
    uint8_t bAnimateWheels : 1;             // 7

    // 0x001C
    uint8_t bAnimatePropellers : 1;                        // 0
    uint8_t bForcePostCameraAiSecondaryTaskUpdate : 1;     // 1
    uint8_t bForcePostCameraAnimUpdate : 1;                // 2
    uint8_t bForcePostCameraAnimUpdateUseZeroTimeStep : 1; // 3
    uint8_t bDriveMusclesToAnim : 1;                       // 4
    uint8_t bAnimateJoints : 1;                            // 5 // Don't sync the skeleton when joints are being animated
    uint8_t bUseCutsceneWheelCompression : 1;              // 6
    uint8_t bCountsTowardsAmbientPopulation : 1;           // 7

    // 0x001D
    uint8_t bIsFarDrawEnabled : 1;     // 0 // vehicle has it's fade dist extended
    uint8_t bRequestDrawHD : 1;        // 1 // issues necessary requests and draw this vehicle as HD
    uint8_t bRefreshVisibility : 1;    // 2
    uint8_t bDamageTrackingLocked : 1; // 3 // When this is set the vehicle is locked for future damage tracking.
    uint8_t bSyncPopTypeOnMigrate : 1; // 4
    uint8_t bBlownUp : 1;              // 5

    // 0x001E
    uint8_t bSiren : 1;                 // 0 // Set to TRUE if siren active, else FALSE
    uint8_t bRandomlyDelaySiren : 1;    // 1 // Set to TRUE if siren active, else FALSE
    uint8_t bSirenUsesEarlyFade : 1;    // 2 // Set to TRUE to reduce sirens fade in distance.
    uint8_t bSirenUseNoSpec : 1;        // 3 // Set to TRUE to force no specular on siren lights.
    uint8_t bSirenUseNoLights : 1;      // 4 // Set to TRUE to force sirens to use no lights.
    uint8_t bSirenUsesDayNightFade : 1; // 5 // Set to TRUE to use Daylight fade on sirens.
    uint8_t bSirenMutedByScript : 1;    // 6 // Set to TRUE if the siren is muted (still flashing), else FALSE
    uint8_t bSirenMutedByCode : 1;      // 7

    // ====== reset state ======

    // 0x001F
    uint8_t bWarnedPeds : 1;                                      // 0 // Has scan and warn peds of danger been processed?
    uint8_t bVehicleColProcessed : 1;                             // 1 // Has ProcessEntityCollision been processed for this car?
    uint8_t bWakeUpNextUpdate : 1;                                // 2 //
    uint8_t bRestingOnPhysical : 1;                               // 3 // Don't go static cause car is sitting on a physical object that might get removed
    uint8_t bDontSleepOnThisPhysical : 1;                         // 4
    uint8_t bPreventBeingDummyThisFrame : 1;                      // 5 // Disallow this vehicle from becoming a dummy this frame
    uint8_t bPreventBeingSuperDummyThisFrame : 1;                 // 6 // Disallow SuperDummy updates but allow Dummy
    uint8_t bPreventBeingDummyUnlessCollisionLoadedThisFrame : 1; // 7

    // 0x0020
    uint8_t bTasksAllowDummying : 1;              // 0 // The tasks set this flag then they permit the vehicle to become a dummy
    uint8_t bNoDummyPathAvailable : 1;            // 1 // This vehicle does not have a path that could be used to become a dummy.
    uint8_t bDummyWheelImpactsSampled : 1;        // 2 // Whether the dummy/superdummy virtual wheel impacts have already been sampled this frame
    uint8_t bDoorRatioHasChanged : 1;             // 3 // Doors have opened/closed, navigation bounds may need updating
    uint8_t bActAsIfHighSpeedForFragSmashing : 1; // 4 // When processing collisions with frags, pretend we have a really high speed in order to smash stuff
    uint8_t bMayHaveWheelGroundForcesToApply : 1; // 5 // The wheels are touching something movable
    uint8_t bHasParentVehicle : 1;                // 6 // Is this a trailer attached to a cab, or a car on the back of a trailer?
    uint8_t bHasProcessedAIThisFrame : 1;         // 7

    // 0x0021
    uint8_t uAllowedDummyConversion : 3;                       // 0~2 // If we do a GetCanMakeIntoDummy check, store what dummy mode we're allowed (seee VehicleDummyMode) so we don't have to do it again
    uint8_t bIsOvertakingStationaryCar : 1;                    // 3
    uint8_t bOtherCarsShouldCheckTrajectoryBeforeSpawning : 1; // 4
    uint8_t bAvoidanceDirtyFlag : 1;                           // 5
    uint8_t bInMotionFromExplosion : 1;                        // 6 // Set while we're in motion due to an explosion
    uint8_t bActAsIfHasSirenOn : 1;                            // 7 // Allow non-sirened cars to get other vehs to act as if they do

    // 0x0022
    uint8_t bUnbreakableLandingGear : 1;       // 0 // Make landing gear invincible for one frame
    uint8_t bIsInTunnel : 1;                   // 1
    uint8_t bSwitchToAiRecordingThisFrame : 1; // 2
    uint8_t bLerpToFullRecording : 1;          // 3
    uint8_t bTellOthersToHurry : 1;            // 4
    uint8_t bDisableVehicleMapCollision : 1;   // 5 // Reset flag. Used by synced scenes and scripted animations.
    uint8_t bUseScriptedCeilingHeight : 1;     // 6 // Reset flag. Vehicle uses the ceiling height that's set from script
    uint8_t bWasStoppedForDoor : 1;            // 7

    // 0x0023
    uint8_t bIsHesitating : 1; // 0
}; // Size: 0x0024
