
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "uiCTX.h"

void status_line( uiCTX* uiCTX ) {

	wattron( uiCTX->mainWin, A_REVERSE );
	mvwprintw( uiCTX->mainWin, LINES - 1, 0, " %d ", uiCTX->state );
	mvwprintw( uiCTX->mainWin, LINES - 1, 4, "%s", " time: 60s " );
	mvwprintw( uiCTX->mainWin, LINES - 1, 16, "%s", " Lang: C " );
	mvwprintw( uiCTX->mainWin, LINES - 1, 16, "%s", " Lang: C " );
	mvwprintw( uiCTX->mainWin, LINES - 1, COLS - 10, "%s", " WPM: 110 " );
	mvwprintw( uiCTX->mainWin, LINES - 1, COLS - 21, "%s", " CPM: 110 " );
	mvwprintw( uiCTX->mainWin, LINES - 1, COLS - 33, "%s", " ACC: 100% " );
	wattroff( uiCTX->mainWin, A_REVERSE );
	wrefresh( uiCTX->mainWin );
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
	
	wattron( uiCTX->stateWin[MENU_STATE], A_REVERSE );
	mvwprintw( uiCTX->stateWin[MENU_STATE], 1, 1, "menu");
	wattroff( uiCTX->stateWin[MENU_STATE], A_REVERSE );
	box( uiCTX->stateWin[MENU_STATE], 0, 0 );
	wrefresh( uiCTX->stateWin[MENU_STATE] );
}
