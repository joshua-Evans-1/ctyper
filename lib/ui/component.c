#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "uiCTX.h"

void status_line( uiCTX* uiCTX ) {
	
	wclear( uiCTX->statusWin );
	wmove( uiCTX->statusWin, 0, 0 );
	wattron( uiCTX->statusWin, COLOR_PAIR(3) );
	wprintw( uiCTX->statusWin, " ctyper " );
	wattroff( uiCTX->statusWin, COLOR_PAIR(3) );
	
	switch ( uiCTX->state ) {
		case MENU_STATE:
			wattron( uiCTX->statusWin, COLOR_PAIR(1) );
			wprintw( uiCTX->statusWin, " Menu " );
			wattroff( uiCTX->statusWin, COLOR_PAIR(1) );
						break;
		case HELP_STATE:
			wattron( uiCTX->statusWin, COLOR_PAIR(1) );
			wprintw( uiCTX->statusWin, " Help " );
			wattroff( uiCTX->statusWin, COLOR_PAIR(1) );
			break;
		
		case GAME_STATE:
			wattron( uiCTX->statusWin, COLOR_PAIR(1) );
			wprintw( uiCTX->statusWin, " lvl " );
			wattroff( uiCTX->statusWin, COLOR_PAIR(1) );
			break;
		
		case TEST_STATE:
			wattron( uiCTX->statusWin, COLOR_PAIR(1) );
			wprintw( uiCTX->statusWin, " test " );
			wattroff( uiCTX->statusWin, COLOR_PAIR(1) );
			break;

		default: break;
	}
	wmove( uiCTX->statusWin, 0, COLS-6 );
	wattron( uiCTX->statusWin, COLOR_PAIR(3) );
	wprintw( uiCTX->statusWin, " V1.0 " );
	wattroff( uiCTX->statusWin, COLOR_PAIR(3) );
	wrefresh( uiCTX->statusWin );
}

void help_win( uiCTX* uiCTX ) {
	wattron( uiCTX->stateWin[HELP_STATE], A_REVERSE );
	mvwprintw( uiCTX->stateWin[HELP_STATE], 1, 1, "KEYBINDS" );
	wattroff( uiCTX->stateWin[HELP_STATE], A_REVERSE );
	mvwprintw( uiCTX->stateWin[HELP_STATE], 2, 1, "q - quit" );
	mvwprintw( uiCTX->stateWin[HELP_STATE], 3, 1, "? - help" );
	box( uiCTX->stateWin[HELP_STATE], 0, 0 );
	wrefresh( uiCTX->stateWin[HELP_STATE] );
}

void menu_win( uiCTX* uiCTX ) {
	wmove( uiCTX->stateWin[MENU_STATE], 1, 1);	
		wattron( uiCTX->stateWin[MENU_STATE], COLOR_PAIR(3) );
		wprintw( uiCTX->stateWin[MENU_STATE], " MENU " );
		wattroff( uiCTX->stateWin[MENU_STATE], COLOR_PAIR(3) );
	box( uiCTX->stateWin[MENU_STATE], 0, 0 );
	wrefresh( uiCTX->stateWin[MENU_STATE] );
}

void game_win( uiCTX* uiCTX ) {
	mvwprintw( uiCTX->stateWin[GAME_STATE], 1, 1, "#include <stdio.h>\n int main() {\n \tprintf( \"Hello, World!\\n\" );\n \treturn 0;\n } \n" );
	box( uiCTX->stateWin[GAME_STATE], 0, 0 );
	wrefresh( uiCTX->stateWin[GAME_STATE] );
}

void color_win( uiCTX* uiCTX ) {
	wmove( uiCTX->stateWin[TEST_STATE], 1, 1);
	for( int i = 1; i <= 56; i++ ) {
		wattron( uiCTX->stateWin[TEST_STATE], COLOR_PAIR(i) );
		wprintw( uiCTX->stateWin[TEST_STATE], " color%2d ", i );
		wattroff( uiCTX->stateWin[TEST_STATE], COLOR_PAIR(i) );
		if( i % 7 == 0 ) {
			wmove( uiCTX->stateWin[TEST_STATE], i / 7 + 1, 1 );
		}
	}
	box( uiCTX->stateWin[TEST_STATE], 0, 0 );
	wrefresh( uiCTX->stateWin[TEST_STATE] );
}
