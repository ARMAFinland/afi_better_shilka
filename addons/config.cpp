class CfgPatches {
	class afi_better_shilka {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"rhs_c_heavyweapons","rhs_c_a2port_armor","A3_Sounds_F"};
	};
};

class CfgAmmo {
	class B_35mm_AA;
	class RHS_ammo_23mm_AA: B_35mm_AA {
		hit = 10;
		indirectHit = 10;
		indirectHitRange = 2;
		visibleFire = 32;
		audibleFire = 32;
		visibleFireTime = 5;
		explosive = 0.8;
		airLock = 2;
		cost = 15;
		model = "\A3\Weapons_f\Data\bullettracer\shell_tracer_red";
		tracerScale = 0.8;
		tracerStartTime = 0.1;
		tracerEndTime = 5;
		airFriction = -0.000824;
		caliber = 1.11;
		simulation = "shotShell";
	};
};

class CfgMagazines {
	class VehicleMagazine;
	class rhs_mag_AZP23_250: VehicleMagazine {
		scope = 2;
		displayName = "$STR_RHS_AZP23_NAME";
		ammo = "RHS_ammo_23mm_AA";
		count = 2000;
		initSpeed = 980;
		maxLeadSpeed = 600;
		nameSound = "cannon";
		tracersEvery = 1;
	};
};

class CfgWeapons {
	class CannonCore;
	class RHS_weap_AZP23: CannonCore {
		ballisticscomputer = 1;
		weaponLockSystem = 8;
		weaponLockDelay = 1;
		magazineReloadTime = 30;
		autoReload = 0;
		backgroundReload = 0;
		flash = "gunfire";
		flashSize = 1;
		modes[] = {"manual","close","short","medium","far"};
		class manual: CannonCore {
			reloadTime = 0.06;
			dispersion = 0.005;
			multiplier = 4;
			burst = 1;
			aiRateOfFire = 1;
			aiRateOfFireDistance = 1000;
			aiRateOfFireDispersion = 1;
			minRange = 0;
			minRangeProbab = 1;
			midRange = 500;
			midRangeProbab = 0.9;
			maxRange = 1000;
			maxRangeProbab = 0.8;
		};
		class close: manual {
			showToPlayer = 0;
			soundBurst = 0;
			burst = 4;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 1500;
			aiRateOfFireDispersion = 2;
			minRange = 0;
			minRangeProbab = 0.01;
			midRange = 1000;
			midRangeProbab = 0.8;
			maxRange = 1500;
			maxRangeProbab = 0.7;
		};
		class short: close {
			burst = 8;
			aiRateOfFire = 3;
			aiRateOfFireDistance = 2000;
			aiRateOfFireDispersion = 3;
			minRange = 1000;
			minRangeProbab = 0.8;
			midRange = 1500;
			midRangeProbab = 0.7;
			maxRange = 2000;
			maxRangeProbab = 0.6;
		};
		class medium: close {
			burst = 12;
			aiRateOfFire = 4;
			aiRateOfFireDistance = 3000;
			aiRateOfFireDispersion = 4;
			minRange = 1500;
			minRangeProbab = 0.7;
			midRange = 2000;
			midRangeProbab = 0.6;
			maxRange = 3000;
			maxRangeProbab = 0.5;
		};
		class far: close {
			burst = 16;
			aiRateOfFire = 5;
			aiRateOfFireDistance = 4000;
			aiRateOfFireDispersion = 5;
			minRange = 1000;
			minRangeProbab = 0.6;
			midRange = 2000;
			midRangeProbab = 0.5;
			maxRange = 4000;
			maxRangeProbab = 0.4;
		};
	};
};

class CfgVehicles {
	class LandVehicle;
	class Tank: LandVehicle {
		class NewTurret;
	};
	class Tank_F: Tank {
		class CommanderOptics;
		class Turrets {
			class MainTurret: NewTurret {
				class Turrets {
					class CommanderOptics;
				};
			};
		};
	};
	class APC_Tracked_02_base_F: Tank_F{};
	class rhs_zsutank_base: APC_Tracked_02_base_F {
		showAllTargets = 0;
		radarType = 4 + 8;
		lockDetectionSystem = 0;
		incomingMissileDetectionSystem = 0;
		gunnerCanSee = 4 + 8 + 16;
		driverCanSee = 2 + 8 + 16;
		class Turrets: Turrets {
			class MainTurret: MainTurret {
				stabilizedInAxes = 0;
				weapons[] = {"RHS_weap_AZP23"};
				magazines[] = {"RHS_mag_AZP23_250"};
				maxHorizontalRotSpeed = 2;
				maxVerticalRotSpeed = 2;
				turretInfoType = "RscWeaponRangeZeroing";
				discreteDistance[] = {100,800,1200,1600,2000,2400};
				discreteDistanceInitIndex = 0;
				gunnerOutOpticsShowCursor = 0;
				gunnerOpticsShowCursor = 0;
				showaimcursorinternal = 0;
				soundServo[] = {"A3\Sounds_F\vehicles\armor\noises\servo_tank_turret_06","db-10",1,50};
				class CommanderOptics: CommanderOptics {
					outGunnerMayFire = 1;
				};
			};
		};
	};
};

class CfgFunctions {
	class RHS {
		tag = "RHS";
		class functions {
			class zsu_shake {
				file = "\afi_better_shilka\RHS_zsu_shake.sqf";
				description = "Camera shake for ZSU cannon fire";
			};
		};
	};
};

class cfgMods {
	author = "Johnson";
	authorUrl = "www.armafinland.fi";
};