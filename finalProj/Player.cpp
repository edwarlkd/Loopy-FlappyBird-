#include "Player.h"

void playerChar::drawIt(){

	        // Set Color
            if(face.size() != 0){
                glColor3d(1.0, 1.0, 1.0);        
                glBegin(GL_LINE_LOOP);
                    for(int j =0; j <= face.size()-1; j++){
                        glVertex2d(face[j]->x + x, face[j]->y + y);
                    }
                glEnd();
            }

            if(body.size() != 0){
                glColor3d(1.0, 0.0, 0.0);        
                glBegin(GL_LINE_LOOP);
                    for(int j =0; j <= body.size()-1; j++)
                        glVertex2d(body[j]->x + x, body[j]->y + y);
                glEnd();
            }

            if(leftArm.size() != 0){
                glColor3d(1.0, 1.0, 1.0);
                glBegin(GL_LINE_LOOP);
                for(int j =0; j < leftArm.size(); j++)
                   glVertex2d(leftArm[j]->x + x, leftArm[j]->y + y);
                glEnd();
            }

            if(rightArm.size() != 0){
                glColor3d(1.0, 1.0, 1.0);
                glBegin(GL_LINE_LOOP);
                for(int j =0; j < rightArm.size(); j++)
                   glVertex2d(rightArm[j]->x + x, rightArm[j]->y + y);
                glEnd();
            }

            if(leftFist.size() != 0){
                glColor3d(1.0, 0.0, 0.0);        
                glBegin(GL_LINE_LOOP);
                    for(int j =0; j <= leftFist.size()-1; j++)
                        glVertex2d(leftFist[j]->x + x, leftFist[j]->y + y);
                glEnd();
            }

            if(rightFist.size() != 0){
                glColor3d(1.0, 0.0, 0.0);        
                glBegin(GL_LINE_LOOP);
                for(int j =0; j <= rightFist.size()-1; j++)
                    glVertex2d(rightFist[j]->x + x, rightFist[j]->y + y);
                glEnd();
            }

            if(leftLeg.size() != 0){
                glColor3d(0.0, 1.0, 1.0);
                glBegin(GL_LINE_LOOP);
                for(int j =0; j < leftLeg.size(); j++)
                    glVertex2d(leftLeg[j]->x + x, leftLeg[j]->y + y);
                glEnd();
            }

            if(rightLeg.size() != 0){
                glColor3d(0.0, 1.0, 1.0);
                glBegin(GL_LINE_LOOP);
                for(int j =0; j < rightLeg.size(); j++)
                    glVertex2d(rightLeg[j]->x + x, rightLeg[j]->y + y);
                glEnd();
            }
            
            if(leftShoe.size() != 0){
                glColor3d(0.0, 0.0, 1.0);
                glBegin(GL_LINE_LOOP);
                for(int j =0; j < leftShoe.size(); j++)
                    glVertex2d(leftShoe[j]->x + x, leftShoe[j]->y + y);
                glEnd();
            }

            if(rightShoe.size() != 0){
                glColor3d(0.0, 0.0, 1.0);
                glBegin(GL_LINE_LOOP);
                for(int j =0; j < rightShoe.size(); j++)
                    glVertex2d(rightShoe[j]->x + x, rightShoe[j]->y + y);
                glEnd();
            }

            if(forContact.size() != 0){
                glColor3d(0.0, 0.0, 0.0);
                glBegin(GL_LINE_LOOP);
                for(int j =0; j < forContact.size(); j++){
    //            	forContact[j]->x += x;
      //          	forContact[j]->y += y;
                    glVertex2d(forContact[j]->x + x, forContact[j]->y + y);
                }
                glEnd();
            }

}



void playerChar::getPlayerReady(){

	        face.clear();
            body.clear();
            leftArm.clear();
            rightArm.clear();
            leftFist.clear();
            rightFist.clear();
            leftLeg.clear();
            rightLeg.clear();
            leftShoe.clear();
            rightShoe.clear();
        
              //for head (circle)
            for(int i =0; i <= 300; i++){
                float angle = 2 * 3.1415 * i / 300;
                float x1 = cos(angle) /40;
                float y1 = sin(angle) /40;
                x1 -= 0.8;

                face.push_back(new characterObject(x1,y1));
            }   

            //body (opal) -> for opal, radius of x and y should be different 
            for(int i =0; i <= 300; i++){
                float angle = 2 * 3.1415 * i / 300;
                float x1 = cos(angle) /20;
                float y1 = sin(angle) /60;
                body.push_back(new characterObject(x1-0.86,y1-0.03));
            }   

            //leftarm... BUT USED as a FUCKING CAPE!!! once the game start
            leftArm.push_back(new characterObject(-0.89,0.014)); //left
            leftArm.push_back(new characterObject(-0.86,0.014));
            leftArm.push_back(new characterObject(-0.82,-0.01)); 
            leftArm.push_back(new characterObject(-0.84,-0.01));


            //body.push_back(new characterObject(x1-0.86,y1-0.03));
            
            rightArm.push_back(new characterObject(-0.81,-0.03));  //right
            rightArm.push_back(new characterObject(-0.75,-0.03));
            rightArm.push_back(new characterObject(-0.75,-0.05));
            rightArm.push_back(new characterObject(-0.81,-0.05));
            
            // leftFist 
            for(int i =0; i <= 300; i++){
                float angle = 2 * 3.1415 * i / 300;
                float x1 = cos(angle) / 100;
                float y1 = sin(angle) / 100;
                leftFist.push_back(new characterObject(x1-0.74,y1-0.04));
            }   

            //leg (rect)
            leftLeg.push_back(new characterObject(-0.98,-0.025)); //left
            leftLeg.push_back(new characterObject(-0.95,-0.025));
            leftLeg.push_back(new characterObject(-0.91,-0.041)); 
            leftLeg.push_back(new characterObject(-0.93,-0.041));
            
            //leftShoe (opal)
            for(int i =0; i <= 300; i++){
                float angle = 2 * 3.1415 * i / 300;
                float x1 = cos(angle) /100;
                float y1 = sin(angle) /80;
                leftShoe.push_back(new characterObject(x1-0.98,y1-0.027));
            }   

    //        forContact
            forContact.push_back(new characterObject(-0.96,0.03)); //left
            forContact.push_back(new characterObject(-0.75,0.03));
            forContact.push_back(new characterObject(-0.75,-0.05)); 
            forContact.push_back(new characterObject(-0.96,-0.05));

}


void playerChar::resetGame(){
	    face.clear();
        body.clear();
        leftArm.clear();
        rightArm.clear();
        leftFist.clear();
        rightFist.clear();
        leftLeg.clear();
        rightLeg.clear();
        leftShoe.clear();
        rightShoe.clear();
        forContact.clear();
            
        //for head (circle)
        for(int i =0; i <= 300; i++){
            float angle = 2 * 3.1415 * i / 300;
            float x1 = cos(angle) /40;
            float y1 = sin(angle) /40;
            x1 -= 0.8;
            face.push_back(new characterObject(x1,y1));
        }   

        //body (opal) -> for opal, radius of x and y should be different 
        for(int i =0; i <= 300; i++){
            float angle = 2 * 3.1415 * i / 300;
            float x1 = cos(angle) /40;
            float y1 = sin(angle) /20;
            body.push_back(new characterObject(x1-0.8,y1-0.08));
        }   

        //arm (square) both left and right
        leftArm.push_back(new characterObject(-0.84,-0.03)); //left
        leftArm.push_back(new characterObject(-0.82,-0.03));
        leftArm.push_back(new characterObject(-0.82, -0.09));
        leftArm.push_back(new characterObject(-0.84,-0.09));
        
        rightArm.push_back(new characterObject(-0.78,-0.03));  //right
        rightArm.push_back(new characterObject(-0.76,-0.03));
        rightArm.push_back(new characterObject(-0.76,-0.09));
        rightArm.push_back(new characterObject(-0.78,-0.09));
        
        //leftFist (circle)
        for(int i =0; i <= 300; i++){
            float angle = 2 * 3.1415 * i / 300;
            float x1 = cos(angle) / 70;
            float y1 = sin(angle) / 70;
            leftFist.push_back(new characterObject(x1-0.83,y1-0.1));
        }   

        //rightFist (circle)
        for(int i =0; i <= 300; i++){
            float angle = 2 * 3.1415 * i / 300;
            float x1 = cos(angle) / 70;
            float y1 = sin(angle) / 70;
            rightFist.push_back(new characterObject(x1-0.77,y1-0.1));
        }   
        //leg (rect)
        
        leftLeg.push_back(new characterObject(-0.82,-0.13)); //left
        leftLeg.push_back(new characterObject(-0.81,-0.13));
        leftLeg.push_back(new characterObject(-0.81, -0.21));
        leftLeg.push_back(new characterObject(-0.82,-0.21));
        
        rightLeg.push_back(new characterObject(-0.79,-0.13));  //right
        rightLeg.push_back(new characterObject(-0.78,-0.13));
        rightLeg.push_back(new characterObject(-0.78,-0.21));
        rightLeg.push_back(new characterObject(-0.79,-0.21));


        //leftShoe (opal)
        for(int i =0; i <= 300; i++){
            float angle = 2 * 3.1415 * i / 300;
            float x1 = cos(angle) /80;
            float y1 = sin(angle) /100;
            leftShoe.push_back(new characterObject(x1-0.83,y1-0.21));
        }   

        //rightShoe (opal)
        for(int i =0; i <= 300; i++){
            float angle = 2 * 3.1415 * i / 300;
            float x1 = cos(angle) /80;
            float y1 = sin(angle) /100;
            rightShoe.push_back(new characterObject(x1-0.77,y1-0.21));
        }   
}


