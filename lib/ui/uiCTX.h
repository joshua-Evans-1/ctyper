#ifndef UI_CTX_H
#define UI_CTX_H

#include <ncurses.h>

typedef enum uiState {
	HELP_STATE,
	MENU_STATE,
	GAME_STATE,
	RESULTS_STATE,
	TEST_STATE,
	NUM_STATES
} uiState;

typedef struct gameState {
	int x, y;
	char* name;
	char* text;
	float wpm, cpm, accuracy;
} gameState;

typedef struct uiCTX {
	uiState state;
	gameState gameState;
	WINDOW *mainWin;
	WINDOW *statusWin;
	WINDOW *stateWin[NUM_STATES];
} uiCTX;

#endif

