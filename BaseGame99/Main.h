#include <stdio.h>
#include "iostream"
using namespace std;
#include "math.h";

#include "allegro5/allegro.h"
//use image addon for loading images, dialog boxes, and primitive shapes
#include <allegro5/allegro_image.h>
//use primitives addon to draw primitive shapes like line
#include <allegro5/allegro_primitives.h>
//use font addon for writing text
#include <allegro5/allegro_font.h> //fixed font
#include <allegro5/allegro_ttf.h> //truetype font

//Using Allegro
//1- create a Win32 Project (no Console)
//2- include "allegro5/allegro.h"
//3- add allegro-5.0.10-monolith-md-debug.lib to Additional Dependencies, in Properties/Linker/Input
//4- In Linker/System set the SubSystem to Not Set if you want to see text window
//http://alleg.sourceforge.net/a5docs/5.0.10/
//



#include "PlayerAttack.h"
#include "Player.h"
#include "GameObject.h"
#include "Game.h"

