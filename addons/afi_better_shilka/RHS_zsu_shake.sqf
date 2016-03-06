// Exit if player not in vehicle
if (vehicle (call rhs_fnc_findPlayer) != (_this select 0)) exitWith {};

// Exit if 3rd person view
if (cameraView == "External") exitWith {};

// Shake camera on cannon fired
if ((_this select 1) == "RHS_weap_AZP23") then {
	enableCamShake true;
	addCamShake [1, 0.5, 20];
};