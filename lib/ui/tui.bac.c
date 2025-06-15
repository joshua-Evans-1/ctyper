#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "uiState.h"

WINDOW *mainWin;
WINDOW *stateWin[NUM_STATES];

uiState currState = MENU_STATE;

void init_win() {
	initscr();
	cbreak();
	noecho();
	curs_set( FALSE );
	keypad( stdscr, TRUE );
	refresh();
	
	mainWin = newwin( LINES, COLS, 0, 0 );
	for ( int i = 0; i < NUM_STATES; i++ ) {
		stateWin[i] = newwin( LINES / 4 * 3, COLS / 4 * 3, LINES / 8, COLS / 8 );
		box( stateWin[i], 0, 0 );
	}
}

void draw_statusline() {
	wattron( mainWin, A_REVERSE );
	mvwprintw( mainWin, LINES - 1, 0, " %d ", currState );
	mvwprintw( mainWin, LINES - 1, 4, "%s", " time: 60s " );
	mvwprintw( mainWin, LINES - 1, 16, "%s", " Lang: C " );
	mvwprintw( mainWin, LINES - 1, 16, "%s", " Lang: C " );
	mvwprintw( mainWin, LINES - 1, COLS - 10, "%s", " WPM: 110 " );
	mvwprintw( mainWin, LINES - 1, COLS - 21, "%s", " CPM: 110 " );
	mvwprintw( mainWin, LINES - 1, COLS - 33, "%s", " ACC: 100% " );
	wattroff( mainWin, A_REVERSE );
	wrefresh( mainWin );
}

void draw_help() {
	mvwprintw( stateWin[HELP_STATE], 1, 1, "HELP MENU BRO" );
	wrefresh( stateWin[HELP_STATE] );
}

void draw_menu() {
	mvwprintw( stateWin[MENU_STATE], 1, 1, "MAIN MENU BRO press ? for help press return to play" );
	wrefresh( stateWin[MENU_STATE] );
}

void kill_win() {
	for ( int i = 0; i < NUM_STATES; i++ ) {
		delwin( stateWin[i] );
	}
	delwin( mainWin );
	endwin();
}

void hide_win() {

	for ( int i = 0; i < NUM_STATES; i++ ) {
		wclear( stateWin[i] );
		box( stateWin[i], 0, 0 );
		wrefresh( stateWin[i] );
	}
}

void render() {
	
	hide_win();
	switch( currState ) {
		case HELP_STATE:
			draw_help();
			break;
		case MENU_STATE:
			draw_menu();
			break;
		default:
			break;
	}
	draw_statusline();
}

void handle_input( int ch ) {
	switch ( ch ) {
		case '?':
			currState = HELP_STATE;
			break;
		case 'm':
			currState = MENU_STATE;
			break;
		case KEY_RESIZE:
			refresh();
			init_win();
			render();
			break;
		case 'q':
			kill_win();
			exit( 0 );
	}
}

void tui() {
	init_win();

	while( 1 ) {
		render();
		int ch = getch();
		handle_input( ch );
	}
}


