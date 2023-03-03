#include "gameWorld.h"
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>
#include <iostream>
const int RIGHT = 0;
const int UP = 1;
const int LEFT = 2;
const int DOWN = 3;
gameWorld::gameWorld(): gridLength(21) {
	setUpInitialState();
};

void gameWorld::setUpInitialState() {
	pacmanpos = sf::Vector2i(9, 11);
	gr.inputAdjacencyList();
	gr.setcoordinates();
	setUpGhostPos();
	setUpTiles();
}

void gameWorld::setUpGhostPos() {
	ghostpos.clear();
	ghostpos.push_back(sf::Vector2i(15, 15));
	ghostpos.push_back(sf::Vector2i(1, 11));
}


void gameWorld::setUpTiles() {
	tiles.clear();
	vector<gameTile*> firstRow;

	firstRow.push_back(new gameTile(filnamehl, 0, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 40, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 80, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 120, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 160, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 200, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 240, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 280, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 320, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 360, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 400, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 440, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 480, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 520, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 560, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 600, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 640, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 680, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 720, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 760, 40, true));
	firstRow.push_back(new gameTile(filnamehl, 800, 40, true));

	tiles.push_back(firstRow);
	vector<gameTile*> secondRow;

	secondRow.push_back(new gameTile(filnamevll, 0, 80, true));
	secondRow.push_back(new gameTile(filnamefood, 40, 80, false));
	secondRow.push_back(new gameTile(filnamefood, 80, 80, false));
	secondRow.push_back(new gameTile(filnamefood, 120, 80, false));
	secondRow.push_back(new gameTile(filnamefood, 160, 80, false));
	secondRow.push_back(new gameTile(filnamefood, 200, 80, false));
	secondRow.push_back(new gameTile(filnamefood, 240, 80, false));
	secondRow.push_back(new gameTile(filnamefood, 280, 80, false));
	secondRow.push_back(new gameTile(filnamefood, 320, 80, false));
	secondRow.push_back(new gameTile(filnamefood, 360, 80, false));
	secondRow.push_back(new gameTile(filnamefood, 400, 80, false));
	secondRow.push_back(new gameTile(filnamefood, 440, 80, false));
	secondRow.push_back(new gameTile(filnamefood, 480, 80, false));
	secondRow.push_back(new gameTile(filnamefood, 520, 80, false));
	secondRow.push_back(new gameTile(filnamefood, 560, 80, false));
	secondRow.push_back(new gameTile(filnamefood, 600, 80, false));
	secondRow.push_back(new gameTile(filnamefood, 640, 80, false));
	secondRow.push_back(new gameTile(filnamefood, 680, 80, false));
	secondRow.push_back(new gameTile(filnamefood, 720, 80, false));
	secondRow.push_back(new gameTile(filnamefood, 760, 80, false));
	secondRow.push_back(new gameTile(filnameg, 800, 80, false));
	secondRow.push_back(new gameTile(filnameg, 840, 80, true));

	tiles.push_back(secondRow);
	vector<gameTile*> thirdRow;

	thirdRow.push_back(new gameTile(filnamevll, 0, 120, true));
	thirdRow.push_back(new gameTile(filnamefood, 40, 120, false));
	thirdRow.push_back(new gameTile(filnamevll, 80, 120, true));
	thirdRow.push_back(new gameTile(filnamefood, 120, 120, false));
	thirdRow.push_back(new gameTile(filnamehl, 160, 120, true));
	thirdRow.push_back(new gameTile(filnamehl, 200, 120, true));
	thirdRow.push_back(new gameTile(filnamehl, 240, 120, true));
	thirdRow.push_back(new gameTile(filnamehl, 280, 120, true));
	thirdRow.push_back(new gameTile(filnamehl, 320, 120, true));
	thirdRow.push_back(new gameTile(filnamehl, 360, 120, true));
	thirdRow.push_back(new gameTile(filnamehl, 400, 120, true));
	thirdRow.push_back(new gameTile(filnamehl, 440, 120, true));
	thirdRow.push_back(new gameTile(filnamehl, 480, 120, true));
	thirdRow.push_back(new gameTile(filnamehl, 520, 120, true));
	thirdRow.push_back(new gameTile(filnamehl, 560, 120, true));
	thirdRow.push_back(new gameTile(filnamehl, 600, 120, true));
	thirdRow.push_back(new gameTile(filnamehl, 640, 120, true));
	thirdRow.push_back(new gameTile(filnamefood, 680, 120, false));
	thirdRow.push_back(new gameTile(filnameg, 720, 120, true));
	thirdRow.push_back(new gameTile(filnamefood, 760, 120, false));
	thirdRow.push_back(new gameTile(filnameg, 800, 120, true));
	thirdRow.push_back(new gameTile(filnameg, 840, 120, true));

	tiles.push_back(thirdRow);
	vector<gameTile*> fourthRow;

	fourthRow.push_back(new gameTile(filnamevll, 0, 160, true));
	fourthRow.push_back(new gameTile(filnamefood, 40, 160, false));
	fourthRow.push_back(new gameTile(filnamevll, 80, 160, true));
	fourthRow.push_back(new gameTile(filnamefood, 120, 160, false));
	fourthRow.push_back(new gameTile(filnamevll, 160, 160, true));
	fourthRow.push_back(new gameTile(filnamefood, 200, 160, false));
	fourthRow.push_back(new gameTile(filnamefood, 240, 160, false));
	fourthRow.push_back(new gameTile(filnamefood, 280, 160, false));
	fourthRow.push_back(new gameTile(filnamefood, 320, 160, false));
	fourthRow.push_back(new gameTile(filnamefood, 360, 160, false));
	fourthRow.push_back(new gameTile(filnamefood, 400, 160, false));
	fourthRow.push_back(new gameTile(filnamefood, 440, 160, false));
	fourthRow.push_back(new gameTile(filnamefood, 480, 160, false));
	fourthRow.push_back(new gameTile(filnamefood, 520, 160, false));
	fourthRow.push_back(new gameTile(filnamefood, 560, 160, false));
	fourthRow.push_back(new gameTile(filnamefood, 600, 160, false));
	fourthRow.push_back(new gameTile(filnameg, 640, 160, true));
	fourthRow.push_back(new gameTile(filnamefood, 680, 160, false));
	fourthRow.push_back(new gameTile(filnameg, 720, 160, true));
	fourthRow.push_back(new gameTile(filnamefood, 760, 160, false));
	fourthRow.push_back(new gameTile(filnameg, 800, 160, true));

	tiles.push_back(fourthRow);
	vector<gameTile*> fifthRow;

	fifthRow.push_back(new gameTile(filnamevll, 0, 200, true));
	fifthRow.push_back(new gameTile(filnamefood, 40, 200, false));
	fifthRow.push_back(new gameTile(filnamevll, 80, 200, true));
	fifthRow.push_back(new gameTile(filnamefood, 120, 200, false));
	fifthRow.push_back(new gameTile(filnamevll, 160, 200, true));
	fifthRow.push_back(new gameTile(filnamefood, 200, 200, false));
	fifthRow.push_back(new gameTile(filnamehl, 240, 200, true));
	fifthRow.push_back(new gameTile(filnamehl, 280, 200, true));
	fifthRow.push_back(new gameTile(filnamehl, 320, 200, true));
	fifthRow.push_back(new gameTile(filnamehl, 360, 200, true));
	fifthRow.push_back(new gameTile(filnamehl, 400, 200, true));
	fifthRow.push_back(new gameTile(filnamehl, 440, 200, true));
	fifthRow.push_back(new gameTile(filnamehl, 480, 200, true));
	fifthRow.push_back(new gameTile(filnamehl, 520, 200, true));
	fifthRow.push_back(new gameTile(filnamehl, 560, 200, true));
	fifthRow.push_back(new gameTile(filnamefood, 600, 200, false));
	fifthRow.push_back(new gameTile(filnameg, 640, 200, true));
	fifthRow.push_back(new gameTile(filnamefood, 680, 200, false));
	fifthRow.push_back(new gameTile(filnameg, 720, 200, true));
	fifthRow.push_back(new gameTile(filnamefood, 760, 200, false));
	fifthRow.push_back(new gameTile(filnameg, 800, 200, true));

	tiles.push_back(fifthRow);
	vector<gameTile*> sixthRow;

	sixthRow.push_back(new gameTile(filnamevll, 0, 240, true));
	sixthRow.push_back(new gameTile(filnamefood, 40, 240, false));
	sixthRow.push_back(new gameTile(filnamevll, 80, 240, true));
	sixthRow.push_back(new gameTile(filnamefood, 120, 240, false));
	sixthRow.push_back(new gameTile(filnamevll, 160, 240, true));
	sixthRow.push_back(new gameTile(filnamefood, 200, 240, false));
	sixthRow.push_back(new gameTile(filnamefood, 240, 240, false));
	sixthRow.push_back(new gameTile(filnamefood, 280, 240, false));
	sixthRow.push_back(new gameTile(filnamefood, 320, 240, false));
	sixthRow.push_back(new gameTile(filnamefood, 360, 240, false));
	sixthRow.push_back(new gameTile(filnamefood, 400, 240, false));
	sixthRow.push_back(new gameTile(filnamefood, 440, 240, false));
	sixthRow.push_back(new gameTile(filnamefood, 480, 240, false));
	sixthRow.push_back(new gameTile(filnamefood, 520, 240, false));
	sixthRow.push_back(new gameTile(filnamefood, 560, 240, false));
	sixthRow.push_back(new gameTile(filnamefood, 600, 240, false));
	sixthRow.push_back(new gameTile(filnameg, 640, 240, true));
	sixthRow.push_back(new gameTile(filnamefood, 680, 240, false));
	sixthRow.push_back(new gameTile(filnameg, 720, 240, true));
	sixthRow.push_back(new gameTile(filnamefood, 760, 240, false));
	sixthRow.push_back(new gameTile(filnameg, 800, 240, true));

	tiles.push_back(sixthRow);
	vector<gameTile*> seventhRow;

	seventhRow.push_back(new gameTile(filnamevll, 0, 280, true));
	seventhRow.push_back(new gameTile(filnamefood, 40, 280, false));
	seventhRow.push_back(new gameTile(filnamevll, 80, 280, true));
	seventhRow.push_back(new gameTile(filnamefood, 120, 280, false));
	seventhRow.push_back(new gameTile(filnamevll, 160, 280, true));
	seventhRow.push_back(new gameTile(filnamefood, 200, 280, false));
	seventhRow.push_back(new gameTile(filnamehl, 240, 280, true));
	seventhRow.push_back(new gameTile(filnamehl, 280, 280, true));
	seventhRow.push_back(new gameTile(filnamehl, 320, 280, true));
	seventhRow.push_back(new gameTile(filnamehl, 360, 280, false));//to be changed
	seventhRow.push_back(new gameTile(filnamehl, 400, 280, false));//to be changed
	seventhRow.push_back(new gameTile(filnamehl, 440, 280, false));//to be changed 
	seventhRow.push_back(new gameTile(filnamehl, 480, 280, true));
	seventhRow.push_back(new gameTile(filnamehl, 520, 280, true));
	seventhRow.push_back(new gameTile(filnamehl, 560, 280, true));
	seventhRow.push_back(new gameTile(filnamefood, 600, 280, false));
	seventhRow.push_back(new gameTile(filnameg, 640, 280, false));
	seventhRow.push_back(new gameTile(filnamefood, 680, 280, false));
	seventhRow.push_back(new gameTile(filnameg, 720, 280, true));
	seventhRow.push_back(new gameTile(filnamefood, 760, 280, false));
	seventhRow.push_back(new gameTile(filnameg, 800, 280, true));
	tiles.push_back(seventhRow);
	vector<gameTile*> eighthRow;
	eighthRow.push_back(new gameTile(filnamevll, 0, 320, true));
	eighthRow.push_back(new gameTile(filnamefood, 40, 320, false));
	eighthRow.push_back(new gameTile(filnamefood, 80, 320, false));
	eighthRow.push_back(new gameTile(filnamefood, 120, 320, false));
	eighthRow.push_back(new gameTile(filnamevll, 160, 320, true));
	eighthRow.push_back(new gameTile(filnamefood, 200, 320, false));
	eighthRow.push_back(new gameTile(filnamevll, 240, 320, true));
	eighthRow.push_back(new gameTile(filnameblack, 280, 320, false));//black
	eighthRow.push_back(new gameTile(filnameblack, 320, 320, false));//black
	eighthRow.push_back(new gameTile(filnameblack, 360, 320, false));//black
	eighthRow.push_back(new gameTile(filnameblack, 400, 320, false));//black
	eighthRow.push_back(new gameTile(filnameblack, 440, 320, false));//black
	eighthRow.push_back(new gameTile(filnameblack, 480, 320, false));//black
	eighthRow.push_back(new gameTile(filnameblack, 520, 320, false));//black
	eighthRow.push_back(new gameTile(filnameg, 560, 320, true));
	eighthRow.push_back(new gameTile(filnamefood, 600, 320, false));
	eighthRow.push_back(new gameTile(filnameg, 640, 320, true));
	eighthRow.push_back(new gameTile(filnamefood, 680, 320, false));
	eighthRow.push_back(new gameTile(filnamefood, 720, 320, false));
	eighthRow.push_back(new gameTile(filnamefood, 760, 320, false));
	eighthRow.push_back(new gameTile(filnameg, 800, 320, true));

	tiles.push_back(eighthRow);
	vector<gameTile*> ninthRow;

	ninthRow.push_back(new gameTile(filnamevll, 0, 360, true));
	ninthRow.push_back(new gameTile(filnamefood, 40, 360, false));
	ninthRow.push_back(new gameTile(filnamehl, 80, 360, true));
	ninthRow.push_back(new gameTile(filnamehl, 120, 360, true));
	ninthRow.push_back(new gameTile(filnamevll, 160, 360, true));
	ninthRow.push_back(new gameTile(filnamefood, 200, 360, false));
	ninthRow.push_back(new gameTile(filnamehldown, 240, 360, true));
	ninthRow.push_back(new gameTile(filnamehldown, 280, 360, true));
	ninthRow.push_back(new gameTile(filnamehldown, 320, 360, true));
	ninthRow.push_back(new gameTile(filnamehldown, 360, 360, true));
	ninthRow.push_back(new gameTile(filnamehldown, 400, 360, true));
	ninthRow.push_back(new gameTile(filnamehldown, 440, 360, true));
	ninthRow.push_back(new gameTile(filnamehldown, 480, 360, true));
	ninthRow.push_back(new gameTile(filnamehldown, 520, 360, true));
	ninthRow.push_back(new gameTile(filnamehldown, 560, 360, true));
	ninthRow.push_back(new gameTile(filnamefood, 600, 360, false));
	ninthRow.push_back(new gameTile(filnameg, 640, 360, true));
	ninthRow.push_back(new gameTile(filnamehl, 680, 360, true));
	ninthRow.push_back(new gameTile(filnamehl, 720, 360, true));
	ninthRow.push_back(new gameTile(filnamefood, 760, 360, false));
	ninthRow.push_back(new gameTile(filnameg, 800, 360, true));

	tiles.push_back(ninthRow);
	vector<gameTile*> tenthRow;

	tenthRow.push_back(new gameTile(filnamevll, 0, 400, true));
	tenthRow.push_back(new gameTile(filnamefood, 40, 400, false));
	tenthRow.push_back(new gameTile(filnamevll, 80, 400, true));
	tenthRow.push_back(new gameTile(filnamefood, 120, 400, false));
	tenthRow.push_back(new gameTile(filnamevll, 160, 400, true));
	tenthRow.push_back(new gameTile(filnamefood, 200, 400, false));
	tenthRow.push_back(new gameTile(filnamefood, 240, 400, false));
	tenthRow.push_back(new gameTile(filnamefood, 280, 400, false));
	tenthRow.push_back(new gameTile(filnamefood, 320, 400, false));
	tenthRow.push_back(new gameTile(filnamefood, 360, 400, false));
	tenthRow.push_back(new gameTile(filnamefood, 400, 400, false));
	tenthRow.push_back(new gameTile(filnamefood, 440, 400, false));
	tenthRow.push_back(new gameTile(filnamefood, 480, 400, false));
	tenthRow.push_back(new gameTile(filnamefood, 520, 400, false));
	tenthRow.push_back(new gameTile(filnamefood, 560, 400, false));
	tenthRow.push_back(new gameTile(filnamefood, 600, 400, false));
	tenthRow.push_back(new gameTile(filnameg, 640, 400, true));
	tenthRow.push_back(new gameTile(filnamefood, 680, 400, false));
	tenthRow.push_back(new gameTile(filnameg, 720, 400, true));
	tenthRow.push_back(new gameTile(filnamefood, 760, 400, false));
	tenthRow.push_back(new gameTile(filnameg, 800, 400, true));

	tiles.push_back(tenthRow);
	vector<gameTile*> eleventhRow;

	eleventhRow.push_back(new gameTile(filnamevll, 0, 440, true));
	eleventhRow.push_back(new gameTile(filnamefood, 40, 440, false));
	eleventhRow.push_back(new gameTile(filnamevll, 80, 440, true));
	eleventhRow.push_back(new gameTile(filnamefood, 120, 440, false));
	eleventhRow.push_back(new gameTile(filnamevll, 160, 440, true));
	eleventhRow.push_back(new gameTile(filnamefood, 200, 440, false));
	eleventhRow.push_back(new gameTile(filnamehl, 240, 440, true));
	eleventhRow.push_back(new gameTile(filnamehl, 280, 440, true));
	eleventhRow.push_back(new gameTile(filnamehl, 320, 440, true));
	eleventhRow.push_back(new gameTile(filnamehl, 360, 440, true));
	eleventhRow.push_back(new gameTile(filnamehl, 400, 440, true));
	eleventhRow.push_back(new gameTile(filnamehl, 440, 440, true));
	eleventhRow.push_back(new gameTile(filnamehl, 480, 440, true));
	eleventhRow.push_back(new gameTile(filnamehl, 520, 440, true));
	eleventhRow.push_back(new gameTile(filnamehl, 560, 440, true));
	eleventhRow.push_back(new gameTile(filnamefood, 600, 440, false));
	eleventhRow.push_back(new gameTile(filnameg, 640, 440, true));
	eleventhRow.push_back(new gameTile(filnamefood, 680, 440, false));
	eleventhRow.push_back(new gameTile(filnameg, 720, 440, true));
	eleventhRow.push_back(new gameTile(filnamefood, 760, 440, false));
	eleventhRow.push_back(new gameTile(filnameg, 800, 440, true));

	tiles.push_back(eleventhRow);
	vector<gameTile*> twelvthRow;

	twelvthRow.push_back(new gameTile(filnamevll, 0, 480, true));
	twelvthRow.push_back(new gameTile(filnameredghost, 40, 480, false));
	twelvthRow.push_back(new gameTile(filnamefood, 80, 480, false));
	twelvthRow.push_back(new gameTile(filnamefood, 120, 480, false));
	twelvthRow.push_back(new gameTile(filnamefood, 160, 480, false));
	twelvthRow.push_back(new gameTile(filnamefood, 200, 480, false));
	twelvthRow.push_back(new gameTile(filnamefood, 240, 480, false));
	twelvthRow.push_back(new gameTile(filnamefood, 280, 480, false));
	twelvthRow.push_back(new gameTile(filnamefood, 320, 480, false));
	twelvthRow.push_back(new gameTile(filnamepacman, 360, 480, false));
	twelvthRow.push_back(new gameTile(filnamevlmiddle, 400, 480, true));
	twelvthRow.push_back(new gameTile(filnamefood, 440, 480, false));
	twelvthRow.push_back(new gameTile(filnamefood, 480, 480, false));
	twelvthRow.push_back(new gameTile(filnamefood, 520, 480, false));
	twelvthRow.push_back(new gameTile(filnamefood, 560, 480, false));
	twelvthRow.push_back(new gameTile(filnamefood, 600, 480, false));
	twelvthRow.push_back(new gameTile(filnamefood, 640, 480, false));
	twelvthRow.push_back(new gameTile(filnamefood, 680, 480, false));
	twelvthRow.push_back(new gameTile(filnamefood, 720, 480, false));
	twelvthRow.push_back(new gameTile(filnamefood, 760, 480, false));
	twelvthRow.push_back(new gameTile(filnameg, 800, 480, true));

	tiles.push_back(twelvthRow);
	vector<gameTile*> thirteenthRow;

	thirteenthRow.push_back(new gameTile(filnamevll, 0, 520, true));
	thirteenthRow.push_back(new gameTile(filnamefood, 40, 520, false));
	thirteenthRow.push_back(new gameTile(filnamevll, 80, 520, true));
	thirteenthRow.push_back(new gameTile(filnamefood, 120, 520, false));
	thirteenthRow.push_back(new gameTile(filnamehl, 160, 520, true));
	thirteenthRow.push_back(new gameTile(filnamehl, 200, 520, true));
	thirteenthRow.push_back(new gameTile(filnamehl, 240, 520, true));
	thirteenthRow.push_back(new gameTile(filnamehl, 280, 520, true));
	thirteenthRow.push_back(new gameTile(filnamehl, 320, 520, true));
	thirteenthRow.push_back(new gameTile(filnamefood, 360, 520, false));
	thirteenthRow.push_back(new gameTile(filnamevlmiddle, 400, 520, true));
	thirteenthRow.push_back(new gameTile(filnamefood, 440, 520, false));
	thirteenthRow.push_back(new gameTile(filnamehl, 480, 520, true));
	thirteenthRow.push_back(new gameTile(filnamehl, 520, 520, true));
	thirteenthRow.push_back(new gameTile(filnamehl, 560, 520, true));
	thirteenthRow.push_back(new gameTile(filnamehl, 600, 520, true));
	thirteenthRow.push_back(new gameTile(filnamehl, 640, 520, true));
	thirteenthRow.push_back(new gameTile(filnamefood, 680, 520, false));
	thirteenthRow.push_back(new gameTile(filnameg, 720, 520, true));
	thirteenthRow.push_back(new gameTile(filnamefood, 760, 520, false));
	thirteenthRow.push_back(new gameTile(filnameg, 800, 520, true));

	tiles.push_back(thirteenthRow);
	vector<gameTile*> fourtenthRow;

	fourtenthRow.push_back(new gameTile(filnamevll, 0, 560, true));
	fourtenthRow.push_back(new gameTile(filnamefood, 40, 560, false));
	fourtenthRow.push_back(new gameTile(filnamevll, 80, 560, true));
	fourtenthRow.push_back(new gameTile(filnamefood, 120, 560, false));
	fourtenthRow.push_back(new gameTile(filnamevll, 160, 560, true));
	fourtenthRow.push_back(new gameTile(filnamefood, 200, 560, false));
	fourtenthRow.push_back(new gameTile(filnamefood, 240, 560, false));
	fourtenthRow.push_back(new gameTile(filnamefood, 280, 560, false));
	fourtenthRow.push_back(new gameTile(filnamefood, 320, 560, false));
	fourtenthRow.push_back(new gameTile(filnamefood, 360, 560, false));
	fourtenthRow.push_back(new gameTile(filnamefood, 400, 560, false));
	fourtenthRow.push_back(new gameTile(filnamefood, 440, 560, false));
	fourtenthRow.push_back(new gameTile(filnamefood, 480, 560, false));
	fourtenthRow.push_back(new gameTile(filnamefood, 520, 560, false));
	fourtenthRow.push_back(new gameTile(filnamefood, 560, 560, false));
	fourtenthRow.push_back(new gameTile(filnamefood, 600, 560, false));
	fourtenthRow.push_back(new gameTile(filnameg, 640, 560, true));
	fourtenthRow.push_back(new gameTile(filnamefood, 680, 560, false));
	fourtenthRow.push_back(new gameTile(filnameg, 720, 560, true));
	fourtenthRow.push_back(new gameTile(filnamefood, 760, 560, false));
	fourtenthRow.push_back(new gameTile(filnameg, 800, 560, true));
	tiles.push_back(fourtenthRow);
	vector<gameTile*> fifteenthRow;
	fifteenthRow.push_back(new gameTile(filnamevll, 0, 600, true));
	fifteenthRow.push_back(new gameTile(filnamefood, 40, 600, false));
	fifteenthRow.push_back(new gameTile(filnamevll, 80, 600, true));
	fifteenthRow.push_back(new gameTile(filnamefood, 120, 600, false));
	fifteenthRow.push_back(new gameTile(filnamevll, 160, 600, true));
	fifteenthRow.push_back(new gameTile(filnamefood, 200, 600, false));
	fifteenthRow.push_back(new gameTile(filnamehl, 240, 600, true));
	fifteenthRow.push_back(new gameTile(filnamehl, 280, 600, true));
	fifteenthRow.push_back(new gameTile(filnamehl, 320, 600, true));
	fifteenthRow.push_back(new gameTile(filnamehl, 360, 600, true));
	fifteenthRow.push_back(new gameTile(filnamehl, 400, 600, true));
	fifteenthRow.push_back(new gameTile(filnamehl, 440, 600, true));
	fifteenthRow.push_back(new gameTile(filnamehl, 480, 600, true));
	fifteenthRow.push_back(new gameTile(filnamehl, 520, 600, true));
	fifteenthRow.push_back(new gameTile(filnamehl, 560, 600, true));
	fifteenthRow.push_back(new gameTile(filnamefood, 600, 600, false));
	fifteenthRow.push_back(new gameTile(filnameg, 640, 600, true));
	fifteenthRow.push_back(new gameTile(filnamefood, 680, 600, false));
	fifteenthRow.push_back(new gameTile(filnameg, 720, 600, true));
	fifteenthRow.push_back(new gameTile(filnamefood, 760, 600, false));
	fifteenthRow.push_back(new gameTile(filnameg, 800, 600, true));
	tiles.push_back(fifteenthRow);
	vector<gameTile*> SixtenthRow;
	SixtenthRow.push_back(new gameTile(filnamevll, 0, 640, true));
	SixtenthRow.push_back(new gameTile(filnamefood, 40, 640, false));
	SixtenthRow.push_back(new gameTile(filnamefood, 80, 640, false));
	SixtenthRow.push_back(new gameTile(filnamefood, 120, 640, false));
	SixtenthRow.push_back(new gameTile(filnamefood, 160, 640, false));
	SixtenthRow.push_back(new gameTile(filnamefood, 200, 640, false));
	SixtenthRow.push_back(new gameTile(filnamefood, 240, 640, false));
	SixtenthRow.push_back(new gameTile(filnamefood, 280, 640, false));
	SixtenthRow.push_back(new gameTile(filnamefood, 320, 640, false));
	SixtenthRow.push_back(new gameTile(filnamefood, 360, 640, false));
	SixtenthRow.push_back(new gameTile(filnamefood, 400, 640, false));
	SixtenthRow.push_back(new gameTile(filnamefood, 440, 640, false));
	SixtenthRow.push_back(new gameTile(filnamefood, 480, 640, false));
	SixtenthRow.push_back(new gameTile(filnamefood, 520, 640, false));
	SixtenthRow.push_back(new gameTile(filnamefood, 640, 640, false));
	SixtenthRow.push_back(new gameTile(filnamefood, 600, 640, false));
	SixtenthRow.push_back(new gameTile(filnamefood, 640, 640, false));
	SixtenthRow.push_back(new gameTile(filnamefood, 680, 640, false));
	SixtenthRow.push_back(new gameTile(filnamefood, 720, 640, false));
	SixtenthRow.push_back(new gameTile(filnamefood, 760, 640, false));
	SixtenthRow.push_back(new gameTile(filnameg, 800, 640, true));
	tiles.push_back(SixtenthRow);
	vector<gameTile*> seventeenth;
	seventeenth.push_back(new gameTile(filnamevll, 0, 680, true));
	seventeenth.push_back(new gameTile(filnamefood, 40, 680, false));
	seventeenth.push_back(new gameTile(filnamevll, 80, 680, true));
	seventeenth.push_back(new gameTile(filnamefood, 120, 680, false));
	seventeenth.push_back(new gameTile(filnamevll, 160, 680, true));
	seventeenth.push_back(new gameTile(filnamefood, 200, 680, false));
	seventeenth.push_back(new gameTile(filnamehl, 240, 680, true));
	seventeenth.push_back(new gameTile(filnamehl, 280, 680, true));
	seventeenth.push_back(new gameTile(filnamehl, 320, 680, true));
	seventeenth.push_back(new gameTile(filnamehl, 360, 680, true));
	seventeenth.push_back(new gameTile(filnamehl, 400, 680, true));
	seventeenth.push_back(new gameTile(filnamehl, 440, 680, true));
	seventeenth.push_back(new gameTile(filnamehl, 480, 680, true));
	seventeenth.push_back(new gameTile(filnamehl, 520, 680, true));
	seventeenth.push_back(new gameTile(filnamehl, 560, 680, true));
	seventeenth.push_back(new gameTile(filnamefood, 600, 680, false));
	seventeenth.push_back(new gameTile(filnameg, 640, 680, true));
	seventeenth.push_back(new gameTile(filnamefood, 680, 680, false));
	seventeenth.push_back(new gameTile(filnameg, 720, 680, true));
	seventeenth.push_back(new gameTile(filnamefood, 760, 680, false));
	seventeenth.push_back(new gameTile(filnameg, 800, 680, true));
	tiles.push_back(seventeenth);
	vector<gameTile*> EightenthRow;
	EightenthRow.push_back(new gameTile(filnamevll, 0, 720, true));
	EightenthRow.push_back(new gameTile(filnamefood, 40, 720, false));
	EightenthRow.push_back(new gameTile(filnamevll, 80, 720, true));
	EightenthRow.push_back(new gameTile(filnamefood, 120, 720, false));
	EightenthRow.push_back(new gameTile(filnamevll, 160, 720, true));
	EightenthRow.push_back(new gameTile(filnamefood, 200, 720, false));
	EightenthRow.push_back(new gameTile(filnamefood, 240, 720, false));
	EightenthRow.push_back(new gameTile(filnamefood, 280, 720, false));
	EightenthRow.push_back(new gameTile(filnamefood, 320, 720, false));
	EightenthRow.push_back(new gameTile(filnamefood, 360, 720, false));
	EightenthRow.push_back(new gameTile(filnamevlmiddle, 400, 720, true));
	EightenthRow.push_back(new gameTile(filnamefood, 440, 720, false));
	EightenthRow.push_back(new gameTile(filnamefood, 480, 720, false));
	EightenthRow.push_back(new gameTile(filnamefood, 520, 720, false));
	EightenthRow.push_back(new gameTile(filnamefood, 560, 720, false));
	EightenthRow.push_back(new gameTile(filnamefood, 600, 720, false));
	EightenthRow.push_back(new gameTile(filnameg, 640, 720, true));
	EightenthRow.push_back(new gameTile(filnamefood, 680, 720, false));
	EightenthRow.push_back(new gameTile(filnameg, 720, 720, true));
	EightenthRow.push_back(new gameTile(filnamefood, 760, 720, false));
	EightenthRow.push_back(new gameTile(filnameg, 800, 720, true));
	tiles.push_back(EightenthRow);
	vector<gameTile*> ninteenthRow;
	ninteenthRow.push_back(new gameTile(filnamevll, 0, 760, true));
	ninteenthRow.push_back(new gameTile(filnamefood, 40, 760, false));
	ninteenthRow.push_back(new gameTile(filnamevll, 80, 760, true));
	ninteenthRow.push_back(new gameTile(filnamefood, 120, 760, false));
	ninteenthRow.push_back(new gameTile(filnamehldown, 160, 760, true));
	ninteenthRow.push_back(new gameTile(filnamehldown, 200, 760, true));
	ninteenthRow.push_back(new gameTile(filnamehldown, 240, 760, true));
	ninteenthRow.push_back(new gameTile(filnamehldown, 280, 760, true));
	ninteenthRow.push_back(new gameTile(filnamehldown, 320, 760, true));
	ninteenthRow.push_back(new gameTile(filnamefood, 360, 760, false));
	ninteenthRow.push_back(new gameTile(filnamevlmiddle, 400, 760, true));
	ninteenthRow.push_back(new gameTile(filnamefood, 440, 760, false));
	ninteenthRow.push_back(new gameTile(filnamehldown, 480, 760, true));
	ninteenthRow.push_back(new gameTile(filnamehldown, 520, 760, true));
	ninteenthRow.push_back(new gameTile(filnamehldown, 560, 760, true));
	ninteenthRow.push_back(new gameTile(filnamehldown, 600, 760, true));
	ninteenthRow.push_back(new gameTile(filnamehldown, 640, 760, true));
	ninteenthRow.push_back(new gameTile(filnamefood, 680, 760, false));
	ninteenthRow.push_back(new gameTile(filnameg, 720, 760, true));
	ninteenthRow.push_back(new gameTile(filnamefood, 760, 760, false));
	ninteenthRow.push_back(new gameTile(filnameg, 800, 760, true));
	ninteenthRow.push_back(new gameTile(filnameg, 840, 800, true));
	tiles.push_back(ninteenthRow);
	vector<gameTile*> twentiethRow;
	twentiethRow.push_back(new gameTile(filnamevll, 0, 800, true));
	twentiethRow.push_back(new gameTile(filnamefood, 40, 800, false));
	twentiethRow.push_back(new gameTile(filnamefood, 80, 800, false));
	twentiethRow.push_back(new gameTile(filnamefood, 120, 800, false));
	twentiethRow.push_back(new gameTile(filnamefood, 160, 800, false));
	twentiethRow.push_back(new gameTile(filnamefood, 200, 800, false));
	twentiethRow.push_back(new gameTile(filnamefood, 240, 800, false));
	twentiethRow.push_back(new gameTile(filnamefood, 280, 800, false));
	twentiethRow.push_back(new gameTile(filnamefood, 320, 800, false));
	twentiethRow.push_back(new gameTile(filnamefood, 360, 800, false));
	twentiethRow.push_back(new gameTile(filnamefood, 400, 800, false));
	twentiethRow.push_back(new gameTile(filnamefood, 440, 800, false));
	twentiethRow.push_back(new gameTile(filnamefood, 480, 800, false));
	twentiethRow.push_back(new gameTile(filnamefood, 520, 800, false));
	twentiethRow.push_back(new gameTile(filnamefood, 560, 800, false));
	twentiethRow.push_back(new gameTile(filnamefood, 600, 800, false));
	twentiethRow.push_back(new gameTile(filnamefood, 640, 800, false));
	twentiethRow.push_back(new gameTile(filnamefood, 680, 800, false));
	twentiethRow.push_back(new gameTile(filnamefood, 720, 800, false));
	twentiethRow.push_back(new gameTile(filnamefood, 760, 800, false));
	twentiethRow.push_back(new gameTile(filnameg, 800, 800, true));
	twentiethRow.push_back(new gameTile(filnameg, 840, 800, true));
	tiles.push_back(twentiethRow);
	vector<gameTile*> twentyfisrtRow;
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 0, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 40, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 80, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 120, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 160, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 200, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 240, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 280, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 320, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 360, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 400, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 440, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 480, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 520, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 560, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 600, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 640, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 680, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 720, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 760, 840, true));
	twentyfisrtRow.push_back(new gameTile(filnamehldown, 800, 840, true));
	tiles.push_back(twentyfisrtRow);

} 
int gameWorld::nodenumber(sf::Vector2i& positions, graph& gr)
{
	int x = positions.x;
	int y = positions.y;
	for (int i = 0; i < 44; i++) {
		if (gr.adj[i].posnodes.x == x && gr.adj[i].posnodes.y == y) {
			return i;
		}
	}
}
void gameWorld::randGhost(int random_direction) {

	int x = ghostpos[0].x;
	int y = ghostpos[0].y;

	int tilex = ghostpos[0].x * 40;
	int tiley = ghostpos[0].y * 40;

	if (random_direction == LEFT)
	{
		for (int i = (x + 1); i >= (x - 1); i--)
		{
			if (tiles[i][y]->wall == true)
			
				continue;
			else {
				tiles[i][y]->setupSprite(filnameghost);
				if (i != (x - 1))
				{

					tiles[i][y]->setupSprite(filnamefood);
				}
				tiles[i][y]->position.x = x * 40;
				tiles[i][y]->position.y = y * 40;
				ghostpos[0].x = i;
				ghostpos[0].y = y;
			}

		}
		if (ghostpos[0].x == pacmanpos.x && ghostpos[0].y == pacmanpos.y)
		{
			lose();
		}
	}

	else if (random_direction == RIGHT)
	{

		for (int i = x; i <= (x + 1); i++)
		{
			if (tiles[i][y]->wall == true)
			{
				continue;
			}
			else {
				tiles[i][y]->setupSprite(filnameghost);
				if (i != (x + 1))
				{
					tiles[i][y]->setupSprite(filnamefood);
				}

				tiles[i][y]->position.x = x * 40;
				tiles[i][y]->position.y = y * 40;

				ghostpos[0].x = i;
				ghostpos[0].y = y;
			}
		}
		if (ghostpos[0].x == pacmanpos.x && ghostpos[0].y == pacmanpos.y)
		{

			lose();

		}

	}
	else if (random_direction == UP)
	{
		for (int i = y; i >= (y - 1); i--)
		{
			if (tiles[x][i]->wall == true)
			{
				continue;
			}
			else
			{
				tiles[x][i]->setupSprite(filnameghost);
				if (i != (y - 1))
				{
					tiles[x][i]->setupSprite(filnamefood);
				}
				tiles[x][i]->position.x = x * 40;
				tiles[x][i]->position.y = y * 40;
				ghostpos[0].y = i;
				ghostpos[0].x = x;
			}
		}
		if (ghostpos[0].x == pacmanpos.x && ghostpos[0].y == pacmanpos.y)
		{
			lose();
		}

	}
	else {

		for (int i = y; i <= (y + 1); i++)
		{
			if (tiles[x][i]->wall == true)
			{
				continue;
			}
			else {
				tiles[x][i]->setupSprite(filnameghost);
				if (i != (y + 1))
				{
					tiles[x][i]->setupSprite(filnamefood);
				}
				tiles[x][i]->position.x = x * 40;
				tiles[x][i]->position.y = y * 40;

				ghostpos[0].y = i;
				ghostpos[0].x = x;
			}
		}
		if (ghostpos[0].x == pacmanpos.x && ghostpos[0].y == pacmanpos.y)
		{
			lose();
		}
	}
}
int food = 0;
void gameWorld::movingPac() {
	int yold = pacmanpos.y;
	int xold = pacmanpos.x;
	int xtileold = pacmanpos.x * 40;
	int ytileold = pacmanpos.y * 40;
	int n = nodenumber(pacmanpos, gr);
	auto l_front = gr.adj[n].list.begin();
	for (int i = 0; i < gr.adj[n].list.size(); i++)
	{
		int adjnode = l_front->first;
		int yadjn = gr.adj[adjnode].posnodes.y;
		int xadjn = gr.adj[adjnode].posnodes.x;

		if (tiles[yadjn][xadjn]->wall == true)
		{
			pacmanpos.y = gr.adj[n].posnodes.y;
			pacmanpos.x = gr.adj[n].posnodes.x;
		}
	}

	int destination = pac.moveUP(pacmanpos, gr, n);

	int xtilenew = pacmanpos.x * 40;
	int ytilenew = pacmanpos.y * 40;


	for (int i = (ytileold / 40); i >= ytilenew / 40; i--) {
		if (i == ytilenew / 40)
		{
			tiles[i][xtileold / 40]->setupSprite(filnamepacman);
		}
		else {
			tiles[i][xtileold / 40]->setupSprite(filnameblack);
			food++;
			GAMEOVER();
		}
		
	}
	
}

void gameWorld::movingPacdown() {
	int yold = pacmanpos.y;
	int xold = pacmanpos.x;
	int xtileold = pacmanpos.x * 40;
	int ytileold = pacmanpos.y * 40;

	int n = nodenumber(pacmanpos, gr);
	auto l_front = gr.adj[n].list.begin();
	for (int i = 0; i < gr.adj[n].list.size(); i++)
	{
		int adjnode = l_front->first;
		int yadjn = gr.adj[adjnode].posnodes.y;
		int xadjn = gr.adj[adjnode].posnodes.x;

		if (tiles[yadjn][xadjn]->wall == true)
		{
			pacmanpos.y = gr.adj[n].posnodes.y;
			pacmanpos.x = gr.adj[n].posnodes.x;
		}
	}
	int destination = pac.moveDOWN(pacmanpos, gr, n);
	int xtilenew = pacmanpos.x * 40;
	int ytilenew = pacmanpos.y * 40;
	for (int i = (ytileold / 40); i <= ytilenew / 40; i++) {
		if (i == ytilenew / 40)
		{
			tiles[i][xtileold / 40]->setupSprite(filnamepacman);
		}
		else {
			tiles[i][xtileold / 40]->setupSprite(filnameblack);
			food++;
			
			GAMEOVER();
			
		}
	}
	
}



void gameWorld::movingPacleft() {
	int yold = pacmanpos.y;
	int xold = pacmanpos.x;
	int xtileold = pacmanpos.x * 40;
	int ytileold = pacmanpos.y * 40;
	int n = nodenumber(pacmanpos, gr);
	auto l_front = gr.adj[n].list.begin();
	for (int i = 0; i < gr.adj[n].list.size(); i++)
	{
		int adjnode = l_front->first;
		int yadjn = gr.adj[adjnode].posnodes.y;
		int xadjn = gr.adj[adjnode].posnodes.x;

		if (tiles[yadjn][xadjn]->wall == true)
		{
			pacmanpos.y = gr.adj[n].posnodes.y;
			pacmanpos.x = gr.adj[n].posnodes.x;
		}
	}
	int destination = pac.moveLEFT(pacmanpos, gr, n);
	int xtilenew = pacmanpos.x * 40;
	int ytilenew = pacmanpos.y * 40;

	for (int i = (xtileold / 40); i >= xtilenew / 40; i--) {
		if (i == xtilenew / 40)
	
			tiles[ytileold / 40][i]->setupSprite(filnamepacman);
		else {
			tiles[ytileold / 40][i]->setupSprite(filnameblack);
			food++;
		   GAMEOVER();
			
		}
	}
	
}


void gameWorld::movingPacright() {
	int yold = pacmanpos.y;
	int xold = pacmanpos.x;
	int xtileold = pacmanpos.x * 40;
	int ytileold = pacmanpos.y * 40;
	int n = nodenumber(pacmanpos, gr);
	int destination = pac.moveRIGHT(pacmanpos, gr, n);
	int xtilenew = pacmanpos.x * 40;
	int ytilenew = pacmanpos.y * 40;
	for (int i = (xtileold / 40); i <= xtilenew / 40; i++) {
		if (i == xtilenew / 40)
			tiles[ytileold / 40][i]->setupSprite(filnamepacman);
		else {
			tiles[ytileold / 40][i]->setupSprite(filnameblack);
			food++;
		    GAMEOVER();
			
		}
	}
	
}
bool gameWorld::GAMEOVER()
{
	if (food == 60)
		return true;
	else
		return false;
}

bool gameWorld::lose()
{
	if (ghostpos[0].x == pacmanpos.x && ghostpos[0].y == pacmanpos.y)
	return true;
	
	else
		return false;
}
bool gameWorld::moveGhost(int cnt) {
	if (cnt < 30) {
		vector<int> path = Ghost.moving(ghostpos[1], pacmanpos, gr);
		for (int i = 0; i < path.size() - 1; i++) {
			int adjnode = path[i];
			int xtileold = ghostpos[1].x * 40;
			int ytileold = ghostpos[1].y * 40;
			int xtilenew = gr.adj[adjnode].posnodes.x * 40;
			int ytilenew = gr.adj[adjnode].posnodes.y * 40;
			if (xtilenew > xtileold) {
				for (int i = (xtileold / 40); i <= xtilenew / 40; i++) {
					if (i == xtilenew / 40)
					{
						tiles[ytileold / 40][i]->setupSprite(filnameredghost);
					}
					else {
						tiles[ytileold / 40][i]->setupSprite(filnameblack);
					}


				}
			}
			else if (xtilenew < xtileold) {
				for (int i = (xtileold / 40); i >= xtilenew / 40; i--) {
					if (i == xtilenew / 40)
					{

						tiles[ytileold / 40][i]->setupSprite(filnameredghost);
					}
					else {
						tiles[ytileold / 40][i]->setupSprite(filnameblack);
					}

				}
			}
			else if (ytilenew > ytileold) {
				for (int i = (ytileold / 40); i <= ytilenew / 40; i++) {
					if (i == ytilenew / 40)
					{
						tiles[i][xtileold / 40]->setupSprite(filnameredghost);
					}
					else {
						tiles[i][xtileold / 40]->setupSprite(filnameblack);
					}

				}
			}
			else if (ytilenew < ytileold) {
				for (int i = (ytileold / 40); i >= ytilenew / 40; i--) {
					if (i == ytilenew / 40)
					{
						tiles[i][xtileold / 40]->setupSprite(filnameredghost);
					}
					else {
						tiles[i][xtileold / 40]->setupSprite(filnameblack);
					}

				}

			}
			//sf::sleep(sf::milliseconds(500));
			ghostpos[1].x = gr.adj[adjnode].posnodes.x;
			ghostpos[1].y = gr.adj[adjnode].posnodes.y;
		}
		return false;
	}
	else {
		vector<int> path = Ghost.moving(ghostpos[1], pacmanpos, gr);
		for (int i = 0; i < path.size(); i++) {
			int adjnode = path[i];
			int xtileold = ghostpos[1].x * 40;
			int ytileold = ghostpos[1].y * 40;
			int xtilenew = gr.adj[adjnode].posnodes.x * 40;
			int ytilenew = gr.adj[adjnode].posnodes.y * 40;
			if (xtilenew > xtileold) {
				for (int i = (xtileold / 40); i <= xtilenew / 40; i++) {
					if (i == xtilenew / 40)
					{
						tiles[ytileold / 40][i]->setupSprite(filnameredghost);
					}
					else {
						tiles[ytileold / 40][i]->setupSprite(filnameblack);
					}


				}
			}
			else if (xtilenew < xtileold) {
				for (int i = (xtileold / 40); i >= xtilenew / 40; i--) {
					if (i == xtilenew / 40)
					{

						tiles[ytileold / 40][i]->setupSprite(filnameredghost);
					}
					else {
						tiles[ytileold / 40][i]->setupSprite(filnameblack);
					}

				}
			}
			else if (ytilenew > ytileold) {
				for (int i = (ytileold / 40); i <= ytilenew / 40; i++) {
					if (i == ytilenew / 40)
					{
						tiles[i][xtileold / 40]->setupSprite(filnameredghost);
					}
					else {
						tiles[i][xtileold / 40]->setupSprite(filnameblack);
					}

				}
			}
			else if (ytilenew < ytileold) {
				for (int i = (ytileold / 40); i >= ytilenew / 40; i--) {
					if (i == ytilenew / 40)
					{
						tiles[i][xtileold / 40]->setupSprite(filnameredghost);
					}
					else {
						tiles[i][xtileold / 40]->setupSprite(filnameblack);
					}

				}

			}
			ghostpos[1].x = gr.adj[adjnode].posnodes.x;
			ghostpos[1].y = gr.adj[adjnode].posnodes.y;
			return true;
		}
	}
}

