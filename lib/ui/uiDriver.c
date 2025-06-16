
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "uiCTX.h"
#include "uiDriver.h"
#include "component.h"
#include "color.h"
#include "input.h"

void create_wins( uiCTX* uiCTX ) {
	uiCTX->state = MENU_STATE;
	uiCTX->mainWin = newwin( LINES, COLS, 0, 0 );
	uiCTX->statusWin = newwin( 1, COLS, LINES-1, 0 );
	for ( int i = 0; i < NUM_STATES; i++ ) {
		uiCTX->stateWin[i] = newwin( LINES / 4 * 3, COLS / 4 * 3, LINES / 8, COLS / 8 );
	}
}

void init( uiCTX* uiCTX ) {
	initscr();
	cbreak();
	noecho();
	curs_set( FALSE );
	keypad( stdscr, TRUE );
	color_init();
	create_wins( uiCTX );
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
	status_line( uiCTX );
	switch ( uiCTX->state ) {
		case HELP_STATE: help_win( uiCTX ); break;
		case MENU_STATE: menu_win( uiCTX ); break;
		case GAME_STATE: game_win( uiCTX ); break;
		case TEST_STATE: color_win( uiCTX ); break;
		default: break;
	}
}

int readin( uiCTX* uiCTX, int ch ) {
	
	switch ( ch ) {
		case KEY_RESIZE:
			kill( uiCTX );
			create_wins( uiCTX );
			draw( uiCTX );
			break;
		case 27:
			nodelay(stdscr, TRUE);
			int ch2 = getch();
			nodelay(stdscr, FALSE);
			if( ch2 != ERR ) ungetch( ch2 );
			if( uiCTX->state == MENU_STATE ) { 
				kill( uiCTX ); 
				endwin(); 
				exit(0);
			};
			uiCTX->state = MENU_STATE;
			draw( uiCTX );
			break;
		default: break;

	}
	switch ( uiCTX->state ) {
		case MENU_STATE: menu_input( uiCTX, ch ); break;
		case HELP_STATE: help_input( uiCTX, ch ); break;
		case GAME_STATE: game_input( uiCTX, ch ); break;
		default: break;
	}
	return 0;
}

const uiDriver driver = {
	.init = init,
	.kill = kill,
	.draw = draw,
	.readin = readin
};

