#ifndef UI_DRIVER_H 
#define UI_DRIVER_H

#include <ncurses.h>
#include "uiCTX.h"

typedef struct uiDriver {
	void ( *init )( uiCTX* );
	void ( *kill )( uiCTX* );
	void ( *draw )( uiCTX* );
	int ( *readin )( uiCTX*, int );
} uiDriver;


void create_wins( uiCTX* uiCTX );
void init( uiCTX* uiCTX );
void kill( uiCTX* uiCTX );
void draw( uiCTX* uiCTX );
int readin( uiCTX* uiCTX, int ch );

extern const uiDriver driver;

#endif

