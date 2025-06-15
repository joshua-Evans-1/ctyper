#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "uiDriver.h"
#include "uiCTX.h"


void tui() {
	uiCTX ctx;

	driver.init( &ctx );
	
	while( 1 ) {
		int ch = getch();
		driver.readin( &ctx, ch );
	}
}


