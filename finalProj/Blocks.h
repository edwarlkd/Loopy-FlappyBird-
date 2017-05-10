
#ifndef BLOCKS_H
#define BLOCKS_H

#include "GlutApp.h"
#include <iostream>
#include <vector>
using namespace std;

class blockStructure{ //where the block will be configured (each will be just a long vertical rectangle)   

    public:
        float width;
        float length; //hopefully this comes in handy to configure the bottom

        float x; //for location of the block
        float y;

        float xCoord[4];
        float yCoord[4];

		bool onScreen;

    blockStructure(int set, float x, float y, float a, float b){
		onScreen = false; //ready to be insert back.

		if(set == 0){ 
           // Rectangle blocks
            xCoord[0] = x;
            xCoord[1] = x+a;
            xCoord[2] = x+a;
            xCoord[3] = x;

            yCoord[0] = y;
            yCoord[1] = y;
            yCoord[2] = y-b;
            yCoord[3] = y-b;
        }
        else if(set == 1){
        	xCoord[0] = x;
            xCoord[1] = x+a;
            xCoord[2] = x+a;
            xCoord[3] = x;

            yCoord[0] = y;
            yCoord[1] = y;
            yCoord[2] = y-b;
            yCoord[3] = y-b;
        }
        else if(set == 2){
            xCoord[0] = x;
            xCoord[1] = x+a;
            xCoord[2] = x+a;
            xCoord[3] = x;

            yCoord[0] = y+b;
            yCoord[1] = y+b;
            yCoord[2] = y;
            yCoord[3] = y;

        }

    }////

	void setTopBlock(float b) {
		//max of b is 2
		yCoord[0] = 1;
		yCoord[1] = 1;
		yCoord[2] = 1 - b;
		yCoord[3] = 1 - b;
	
	}

	void setBotBlock(float b) {

		// Rectangle blocks
		yCoord[0] = -1 + b;
		yCoord[1] = -1 + b;
		yCoord[2] = -1;
		yCoord[3] = -1;

	}

};

//instead of vector, use either 'list' or 'deck' --> CHOOSE ONE that makes it efficient to push front and end.
class blockObstacles{

    public:
        //let it possible for top and bot blocks appear together
        vector<blockStructure*> topBlocks;
        vector<blockStructure*> botBlocks;
        //vector<blockStructure*> midBlocks;

        blockObstacles(){
            resetGame();
        }


        void defaultBlocks(int a, float x, float y, float width, float height);
        void resetGame();
        void drawBlocks();

};

#endif