class CfgPatches {
	class afi_better_shilka {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"rhs_c_a2port_armor","rhs_c_heavyweapons"};
	};
};

class CfgAmmo {
	class B_35mm_AA;
	class RHS_ammo_23mm_AA: B_35mm_AA {
		hit = 20;
		indirectHit = 10;
		indirectHitRange = 2;
		airLock = 2;
	};
};

class CfgWeapons {
	class CannonCore;
	class RHS_weap_AZP23: CannonCore {
		ballisticscomputer = 1;
		weaponLockSystem = 8;
		magazineReloadTime = 3;
		class manual: CannonCore {
			dispersion = 0.008;
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
				maxHorizontalRotSpeed = 2;
				maxVerticalRotSpeed = 2;
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