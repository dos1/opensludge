#ifndef SPRITE_H
#define SPRITE_H

#if !defined(HAVE_GLES2)
#include <GL/glew.h>
#else
#include <GLES2/gl2.h>
#endif

struct onScreenPerson;

struct sprite {
	int width, height, xhot, yhot;
	int tex_x;
	int texNum;
	//unsigned char * data;
};

class spritePalette {
public:
	unsigned short int * pal;
	unsigned char * r;
	unsigned char * g;
	unsigned char * b;
	GLuint * tex_names;
	GLuint * burnTex_names;
	int * tex_w, * tex_h;
	int numTextures;
	unsigned char originalRed, originalGreen, originalBlue, total;
	
	spritePalette(): pal(0), r(0), g(0), b(0), tex_names(0), burnTex_names(0)
	, tex_w(0), tex_h(0), numTextures(0)
	, total(0) {}
	
	~spritePalette() {
		delete [] pal;
		delete [] r;
		delete [] g;
		delete [] b;
		delete [] tex_names;
		delete [] burnTex_names;
		delete [] tex_w;
		delete [] tex_h;
	}
};

struct spriteBank {
	int total;
	int type;
	sprite * sprites;
	spritePalette myPalette;
	bool isFont;
};

void forgetSpriteBank (spriteBank & forgetme);
bool loadSpriteBank (char * filename, spriteBank & loadhere);
bool loadSpriteBank (int fileNum, spriteBank & loadhere, bool isFont);

void fontSprite		(int x1, int y1, sprite & single, const spritePalette & fontPal);
void flipFontSprite	(int x1, int y1, sprite & single, const spritePalette & fontPal);

bool scaleSprite (sprite & single, const spritePalette & fontPal, onScreenPerson * thisPerson, bool mirror);
void pasteSpriteToBackDrop (int x1, int y1, sprite & single, const spritePalette & fontPal);
bool reserveSpritePal (spritePalette & sP, int n);
void fixScaleSprite (int x1, int y1, sprite & single, const spritePalette & fontPal, onScreenPerson * thisPerson, const int camX, const int camY, bool);
void burnSpriteToBackDrop (int x1, int y1, sprite & single, const spritePalette & fontPal);

#endif
