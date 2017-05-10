#include "App.h"
#include <cmath>

int ranN(int a) {
	return rand() % a;
}
int randomNumber(vector<blockStructure*> &vec) {

	int s = 0;
	for (int i = 0; i < vec.size(); i++) {
		s = rand() % vec.size();
		
		if (vec[s]->onScreen == false) {
			break;		
		}
	
	}
	return s;
}

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;

    begin = 0;
    end = 0;
	gBegin = 0;
	gEnd = 0;
	diffGTime = 0;

    inputRecordFile.open("record.txt");
	if(inputRecordFile.is_open()){
		inputRecordFile >> bestTime;
	} 
	cout << "bestTime: " << bestTime << endl;
	inputRecordFile.close();

	#if defined WIN32
    backg = loadTexture("..\\backg2.bmp"); //changed from wall
	#else
	backg = loadTexture("backg.bmp");
	#endif
	background = new TexRect(-1, 1, 2, 2);

	gameOver = false;
	gameStarted = false;	
	restartGame = false;
	vector<blockStructure > setOfBlocks; //this will be obstacles 

    mainPlayer.x = 0;
    mainPlayer.y = 0;

	if(gameStarted == false){	
		mainPlayer.resetGame();
	}

	

} //////

GLuint App::loadTexture(const char *filename) {
    GLuint texture_id;
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    RgbImage theTexMap( filename );
    
    // Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
    //    Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );
    
    glGenTextures( 1, &texture_id );
    glBindTexture( GL_TEXTURE_2D, texture_id );     
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData() );
    
    return texture_id;
}

void App::displayBestRecord()
{
	glColor3d(1.0, 1.0, 0.0);
	glRasterPos2f(0.30, -0.95); // center of screen. (-1,0) is center left.
	glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
	char buf[300];
	float a = abs(bestTime / 10);
	sprintf_s(buf, "Best Record: %4.3f ", a);
	const char * p = buf;
	do glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p); while (*(++p));
	glEnable(GL_DEPTH_TEST); // Turn depth testing back on

}

void App::displayGameOver() {
		glColor3d(1.0, 1.0, 0.0);
		glRasterPos2f( -0.5, -0.0 ) ; // center of screen. (-1,0) is center left.
		glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
		char buf[300];
		float a  = abs(diffTime);
		sprintf_s( buf, "Game Over!!! Your Record: %4.3f ", a ) ;
		const char * p = buf ;
		do glutBitmapCharacter(  GLUT_BITMAP_TIMES_ROMAN_24, *p ); while( *(++p) ) ;
		glEnable( GL_DEPTH_TEST ) ; // Turn depth testing back on
			
		//Replay message
	    glColor3d(1.0, 1.0, 0.0);
		glRasterPos2f( -0.4, -0.2 ) ; // center of screen. (-1,0) is center left.
		glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
		char buf2[300];
		sprintf( buf2, "Press Spacebar to Play Again" ) ;
		const char * p2 = buf2 ;
		do glutBitmapCharacter(  GLUT_BITMAP_TIMES_ROMAN_24, *p2 ); while( *(++p2) ) ;
		glEnable( GL_DEPTH_TEST ) ; // Turn depth testing back on

}

void App::updateDisplayTime() {
	//replace with the new record
	if (gameStarted)
		end = clock();
	else
		end = 0;

		diffTime = begin - end;
		diffTime = diffTime / CLOCKS_PER_SEC;
		glColor3d(1.0, 1.0, 0.0);
		glRasterPos2f(0.3f, 0.9f); // center of screen. (-1,0) is center left.
		glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
		char buf[300];
		float a = abs(diffTime);
		sprintf_s(buf, "Your time: %4.3f ", a);
		const char *p = buf;
		do glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p); while (*(++p));
		glEnable(GL_DEPTH_TEST); // Turn depth testing back on
}


void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
	//Dispaly record
	displayBestRecord();

	if(restartGame == true){
		mainPlayer.resetGame(); //reset player
		obstacles.resetGame(); //reset blocks to original location
		restartGame = false;
		gameStarted = false;	
	}

	mainPlayer.drawIt();
	obstacles.drawBlocks();	

	if(gameOver == true){
		displayGameOver();
	}

	updateDisplayTime();


	// For Texture....
	glColor3d(1.0, 1.0, 1.0);
    glBindTexture( GL_TEXTURE_2D, backg );
    background->draw();

	glDisable(GL_TEXTURE_2D);




    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;


    
    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
	if(key == 32){ //spacebar to restart
	//reset all values to restart the game
		gameStarted = true;
    	gameOver = false;
		restartGame = true;    	
		begin = 0;
		end = 0;
		gBegin = 0; //reset
		gBegin = clock();
		redraw();
    }
	if(key == 13){ 
		//enter to start the game
    	gameStarted = true;
		begin = 0;
		begin = clock();
		gBegin = 0; //reset
		gBegin = clock();
    	mainPlayer.getPlayerReady();    	
//    	redraw();
    }

	// Interaction with player
	//up-button (w or W) pressed
	if (key == 87 || key == 119) { 
		gBegin = 0; //reset
		gBegin = clock();
		mainPlayer.y += 0.019; // up up up
		redraw();
	}


}

void App::idle(){
	
	if(gameStarted == true){

		end = clock();

		// GRAVITY
		gEnd = clock();
		diffGTime = gBegin - gEnd;
		diffGTime = -1 * (diffGTime * 10) / CLOCKS_PER_SEC; // to seconds...
		float temp = diffGTime;
		mainPlayer.y -= 0.0001 * (pow(temp,2));
		/////////////////////////////////////////


		for (int i = 0; i < obstacles.topBlocks.size(); i++) {
			
			//if the block passes thru the left edge of the screen
			if (obstacles.topBlocks[i]->xCoord[1] < -1.0) {
				
				//first shift toward the beginning of display 
				for (int z = 0; z < 4; z++) {
					obstacles.topBlocks[i]->xCoord[z] += 2.2;
					obstacles.botBlocks[i]->xCoord[z] += 2.2;
				}

				//insert new block with the old one
				topORbot = rand() % 2; // 0 for top and 1 for bot; where next hole is
				nextBlock = rand() % 5; //from 0. distance from the character
				nextBlock /= 10; 
				float y = mainPlayer.y;
				float locationT = 0;
				float locationB = 0;
				float lenT, lenB = 0;

				if (topORbot == 0) {
					locationT = y + nextBlock;
					locationB = y;
				}
				else { //topORbot == 1 
					locationT = y;
					locationB = y - nextBlock;
				}

				if (topORbot == true) { //next block hole is above
					if (locationT > 1) {
						float len2 = 1 + locationT;
						obstacles.topBlocks[i]->setTopBlock(0); //x y a b
						obstacles.botBlocks[i]->setBotBlock(len2); //x y a b
					}
					else { //general case
						lenT = 1 - locationT;
						lenB = 2 - (lenT + 0.3);
						obstacles.topBlocks[i]->setTopBlock(lenT); //x y a b
						obstacles.botBlocks[i]->setBotBlock(lenB); //x y a b

					}
				}
				else { //bot
					if (locationB < -1) {
						float len2 = 1 + locationT - 0.3;
						obstacles.topBlocks[i]->setTopBlock(len2); //x y a b
						obstacles.botBlocks[i]->setBotBlock(0); //x y a b
					}
					else { //general case
						lenT = 1 - locationT;
						lenB = 2 - (lenT + 0.3);
						obstacles.topBlocks[i]->setTopBlock(lenT); //x y a b
						obstacles.botBlocks[i]->setBotBlock(lenB); //x y a b

					}
				}


			}

		}


		for (int i = 0; i < obstacles.botBlocks.size(); i++) {
			for (int j = 0; j < 4; j++) {
				obstacles.topBlocks[i]->xCoord[j] -= 0.0025;
				obstacles.botBlocks[i]->xCoord[j] -= 0.0025;

			}


		}

		//detect the collision
		//check if forContact[2] and forContact[3] interfere
		if (mainPlayer.y < -1 || mainPlayer.y > 1)
		{
			gameStarted = false; // game over
			gameOver = true;
			end = clock();
			
		}
		//Collisioon with topblock
		for(int i = 0; i < obstacles.topBlocks.size(); i++){
			if(mainPlayer.forContact[1]->x+mainPlayer.x > obstacles.topBlocks[i]->xCoord[0] 
				&& mainPlayer.forContact[1]->x +mainPlayer.x< obstacles.topBlocks[i]->xCoord[1]
				&& mainPlayer.forContact[1]->y+ mainPlayer.y < obstacles.topBlocks[i]->yCoord[0]
				&& mainPlayer.forContact[1]->y+mainPlayer.y > obstacles.topBlocks[i]->yCoord[3]){

				cout << "Collison!!!!!!" << endl;
				gameStarted = false; // game over
				gameOver = true;
				end = clock();

			}
		
		}
		for(int i = 0; i < obstacles.botBlocks.size(); i++){
			if(mainPlayer.forContact[1]->x+mainPlayer.x > obstacles.botBlocks[i]->xCoord[0] 
				&& mainPlayer.forContact[1]->x +mainPlayer.x< obstacles.botBlocks[i]->xCoord[1]
				&& mainPlayer.forContact[1]->y+ mainPlayer.y < obstacles.botBlocks[i]->yCoord[0]
				&& mainPlayer.forContact[1]->y+mainPlayer.y > obstacles.botBlocks[i]->yCoord[3]){

				cout << "Collison with BOT!!!!!!" << endl;
				gameStarted = false; // game over
				gameOver = true;
				end = clock();

			}
		
		}

	}

	if(gameOver == true){

		//replace with the new record
		float diffTime = begin - end;
		diffTime = -1*(diffTime*10)/CLOCKS_PER_SEC;		

		if(diffTime > bestTime){
			outputRecordFile.open("record.txt");
			outputRecordFile << diffTime;
			cout << "diffTime: " << diffTime << endl;
			bestTime = diffTime;
			gameOver = false;
			outputRecordFile.close();
		}

	}


	redraw();
}