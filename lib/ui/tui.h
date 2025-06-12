#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <signal.h>



typedef enum {
	HELP_STATE,
	MENU_STATE,
	GAME_STATE,
	RESULTS_STATE,
	NUM_STATES
} UiState;


void init_win();

void draw_help();

void draw_menu();

void kill_win();

void hide_win();

void handle_input( int ch );

void render();

void tui();


