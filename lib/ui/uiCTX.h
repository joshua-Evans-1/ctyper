#ifndef UI_STATE_H
#define UI_STATE_H

#include <ncurses.h>

typedef enum uiState {
	HELP_STATE,
	MENU_STATE,
	GAME_STATE,
	RESULTS_STATE,
	NUM_STATES
} uiState;

typedef struct uiCTX {
	uiState state; 
	WINDOW *mainWin;
	WINDOW *stateWin[NUM_STATES];
} uiCTX;

#endif

