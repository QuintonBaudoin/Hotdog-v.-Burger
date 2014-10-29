#pragma once
#include "Decl.h"

/*declares assets*/
class Assets
{
	unsigned *sprites[g_maxSprites];
	unsigned *assoc[eSize];
	int nSprites;

public:

	Assets();
	unsigned Get(eSpriteFlag s);

	unsigned LoadSprite(char *path, int w, int h, eSpriteFlag s = eNone, bool center = true);

	~Assets();
};