#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "GlutApp.h"
#include <math.h>
#include <fstream>

using namespace std;

class characterObject{
    public:
        float x;
        float y;

        characterObject(float a, float b){
            x = a;
            y = b;
        }
};


class playerChar{
    public:
        float x; //for the location of the object
        float y; 

        //modeling
        vector<characterObject* > face; // circle
        vector<characterObject* > body; // opal or just a square
        vector<characterObject* > leftArm; // square box
        vector<characterObject* > rightArm; // square box
        vector<characterObject* > leftFist; // circle (small)
        vector<characterObject* > rightFist; // circle (small)
        vector<characterObject* > leftLeg; // square
        vector<characterObject* > rightLeg; // square
        vector<characterObject* > leftShoe; // opal (small)
        vector<characterObject* > rightShoe; // opal (small)
        vector<characterObject* > forContact;

        //draw all face body arms etc...
        void drawIt();
        void getPlayerReady();
        void resetGame();

};

#endif