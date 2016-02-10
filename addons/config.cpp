class CfgPatches {
	class afi_better_shilka {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"rhs_c_heavyweapons","rhs_c_a2port_armor"};
	};
};

class CfgAmmo {
	class B_35mm_AA;
	class RHS_ammo_23mm_AA: B_35mm_AA {
		hit = 10;
		indirectHit = 10;
		indirectHitRange = 2;
		airLock = 2;
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
		magazineReloadTime = 30;
		class manual: CannonCore {
			dispersion = 0.008;
			reloadTime = 0.03;
			burst = 4;
			multiplier= 2;
		};
	};
};

class CfgVehicles {
	class LandVehicle;
	class Tank: LandVehicle {
		class NewTurret;
	};
	class Tank_F: Tank {
		class Turrets {
			class MainTurret: NewTurret {
				class Turrets;
			};
		};
	};
	class APC_Tracked_02_base_F: Tank_F{};
	class rhs_zsutank_base: APC_Tracked_02_base_F {
		radarType = 4;
		lockDetectionSystem = 0;
		incomingMissileDetectionSystem = 0;
		class Turrets: Turrets {
			class MainTurret: MainTurret {
				magazines[] = {
					"RHS_mag_AZP23_250"
				};
				maxHorizontalRotSpeed = 2;
				maxVerticalRotSpeed = 2;
				discreteDistance[] = {100,800,1200,1600,2000,2400};
				discreteDistanceInitIndex = 0;
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