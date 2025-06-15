
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "uiCTX.h"
#include "uiDriver.h"
#include "component.h"

void init( uiCTX* uiCTX ) {
	initscr();
	cbreak();
	noecho();
	curs_set( FALSE );
	keypad( stdscr, TRUE );
	refresh();
	
	uiCTX->state = MENU_STATE;
	draw( uiCTX );
}

void kill( uiCTX* uiCTX ) {
	for( int i = 0; i < NUM_STATES; i++ ) {
		delwin( uiCTX->stateWin[i] );
	}
	delwin( uiCTX->mainWin );
}

void draw( uiCTX* uiCTX ) {
	clear();
	refresh();
	kill( uiCTX );
	uiCTX->mainWin = newwin( LINES, COLS, 0, 0 );
	for ( int i = 0; i < NUM_STATES; i++ ) {
		uiCTX->stateWin[i] = newwin( LINES / 4 * 3, COLS / 4 * 3, LINES / 8, COLS / 8 );
	}
		
	status_line( uiCTX );
	switch ( uiCTX->state ) {
		case HELP_STATE: help_win( uiCTX ); break;
		case MENU_STATE: menu_win( uiCTX ); break;
		default: break;
	}
}

int readin( uiCTX* uiCTX, int ch ) {

	switch ( ch ) {
		case 'q': kill( uiCTX ); endwin(); exit(0);
		case '?': uiCTX->state = HELP_STATE; draw( uiCTX ); break;
		case 'm': uiCTX->state = MENU_STATE; draw( uiCTX ); break;
		case KEY_RESIZE: draw( uiCTX ); break;
	}
	return 0;
}

const uiDriver driver = {
	.init = init,
	.kill = kill,
	.draw = draw,
	.readin = readin
};

