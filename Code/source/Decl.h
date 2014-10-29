#pragma once

#include "Aie.h"

/*
	Declares the classes, viables, and enums for global use.
*/


const int g_w	= 1000;
const int g_h	= 700;


const int gv_gScreenMid		= g_w / 2;
const int gv_gScreenLeft	= gv_gScreenMid - (gv_gScreenMid * .50);
const int gv_gScreenRight   = gv_gScreenMid + (gv_gScreenMid * .50);

const int gv_pScreenTop		= 200;
const int gv_pScreenBot		= 50;



const int g_maxSprites = 64;
const int g_maxBullets = 64;

//Used fore game controll for player creation and using.

enum eSpriteFlag { eNone, ePlayer, eShot, eSize, eHotDog, eInter, eExit};
// Used for "Menu"
enum State {ePlay, eMenu, eRecords, eClose};

extern int g_State;
extern int g_Last;



class Assets;
class GameState;
class Player;
class Bullet;
class Enemy;
