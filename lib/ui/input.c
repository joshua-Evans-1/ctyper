#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include "uiCTX.h"
#include "uiDriver.h"

void menu_input( uiCTX* uiCTX, int ch ) {
	switch ( ch ) {
		case 'q': kill( uiCTX ); endwin(); exit(0);
		case '?': uiCTX->state = HELP_STATE; draw( uiCTX ); break;
		case 't': uiCTX->state = TEST_STATE; draw( uiCTX ); break;
		case 'g': uiCTX->state = GAME_STATE; draw( uiCTX ); break;
		default: break;
	}
}

void help_input( uiCTX* uiCTX, int ch ) {
	switch ( ch ) {
		case 'q': kill( uiCTX ); endwin(); exit(0);
		case 'm': uiCTX->state = MENU_STATE; draw( uiCTX ); break;
		case 't': uiCTX->state = TEST_STATE; draw( uiCTX ); break;
		default: break;
	}
}

void game_input( uiCTX* uiCTX, int ch ) {
	switch ( ch ) {
		default: break;
	}
}

