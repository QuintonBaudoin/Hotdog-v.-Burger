#include "Assets.h"
/* Total number of sprites*/
Assets::Assets()
{
	for (int i = 0; i < g_maxSprites; ++i)
	{
		sprites[i] = nullptr;
		if (i < eSize) assoc[i] = nullptr;
	}

	nSprites = 0;

	
}


unsigned Assets::Get(eSpriteFlag s) { return *assoc[s]; }

/*Loads sprites using the variables called.*/

unsigned Assets::LoadSprite(char *path, int w, int h, eSpriteFlag s, bool center)
{
	if (nSprites < 64)
	{
		unsigned *t = new unsigned(CreateSprite(path, w, h, center));

		sprites[nSprites++] = t; 
		if (s != eNone)
			assoc[s] = t;			

		return *t;
	}
	return 0;
}
/*Destructor for sprites*/
Assets::~Assets()
{
	for (int i = 0; i < g_maxSprites; ++i)
		if (sprites[i])
		{
			DestroySprite(*sprites[i]);
								

			delete sprites[i];
		}
}