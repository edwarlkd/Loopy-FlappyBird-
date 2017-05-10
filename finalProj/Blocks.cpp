#include "Blocks.h"


void blockObstacles::defaultBlocks(int a, float x, float y, float width, float height){

        if (a == 0){
            topBlocks.push_back(new blockStructure(a, x, y, width, height));

        }
        else if (a == 1){
//            midBlocks.push_back(new blockStructure(a, x, y, width, height));
        }
        else if (a == 2){
            botBlocks.push_back(new blockStructure(a, x, y, width, height));
        }

    }
    
void blockObstacles::resetGame(){
        topBlocks.clear();
        //midBlocks.clear();
        botBlocks.clear();

        topBlocks.push_back(new blockStructure(0, 0.0, 1.0, 0.05, 0.7));
//        topBlocks.push_back(new blockStructure(0, 0.4, 1.0, 0.05, 0.4));
        topBlocks.push_back(new blockStructure(0, 0.8, 1.0, 0.05, 0.6));
		topBlocks.push_back(new blockStructure(0, 1.5, 1.0, 0.05, 0.3));



        botBlocks.push_back(new blockStructure(2, 0.0, -1.0, 0.05, 0.4));
  //      botBlocks.push_back(new blockStructure(2, 0.4, -1.0, 0.05, 0.9));
		botBlocks.push_back(new blockStructure(2, 0.8, -1.0, 0.05, 1.1));
		botBlocks.push_back(new blockStructure(2, 1.5, -1.0, 0.05, 1.4));

		
		
}

void blockObstacles::drawBlocks(){

	if(topBlocks.size() != 0){
        for(int i = 0; i < topBlocks.size(); i++){
            glColor3d(1.0, 1.0, 1.0);
            glBegin(GL_LINE_LOOP);
			                
            for(int j = 0; j < 4; j++){
					glVertex2d(topBlocks[i]->xCoord[j], topBlocks[i]->yCoord[j]);          
            }
            glEnd();                    
        }
    }

	if(botBlocks.size() != 0){
        for(int i = 0; i < botBlocks.size(); i++){
            glColor3d(1.0, 1.0, 1.0);
            glBegin(GL_LINE_LOOP);                    
            for(int j = 0; j < 4; j++){
					glVertex2d(botBlocks[i]->xCoord[j], botBlocks[i]->yCoord[j]);          
            }
            glEnd();                    
        }
    }

}

