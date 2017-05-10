#ifndef App_hpp
#define App_hpp
#include <deque>
#include "GlutApp.h"
#include <vector>
#include <iostream>
#include <math.h>
#include "Blocks.h"

#include "RgbImage.h"
#include "TexRect.hpp"
#include "Player.h"
#include <fstream>
#include <time.h>

/*
    Character:
    To make the interaction between the character and the obstacle easier,
    -we can just wrap the character in invisible box that barely contains it, and use it to see if it crashes into the obstacle blocks.

    Block:
    -Don't let the block appear if one conflicts with lbx and rbx (or ltx and rtx). 
    -Unless, we can divide the random appearance of the block to 3 possible position. (top middle and bot)

    Texture/Background:
    -background will shift as the character move
    -Texture: If it's difficult, we can just make everything black color, and only apply the texture to the face.

*/

using namespace std;


class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;

public:

    ifstream inputRecordFile;
    ofstream outputRecordFile;
    float bestTime;
    float diffTime;

    playerChar mainPlayer;
    blockObstacles obstacles;
	
	//for gravity, as nothing is pressed, the ninja is gonna fall
	clock_t gBegin;
	clock_t gEnd;
	float diffGTime;

    clock_t begin;
    clock_t end;
	float nextBlock;
	int topORbot; // 0 for top and 1 for bot


    bool gameStarted;
    bool gameOver;
    bool restartGame;

    GLuint loadTexture(const char* filename);
    GLuint backg;    
    TexRect* background;


    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);

    void idle();
	void displayBestRecord();
	void displayGameOver();
	void updateDisplayTime();

};

#endif
