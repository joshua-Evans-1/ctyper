
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
}
