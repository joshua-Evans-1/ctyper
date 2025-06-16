#ifndef COMPONENT_H

#define COMPONENT_H

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "uiCTX.h"

void status_line( uiCTX* uiCTX );
void help_win( uiCTX* uiCTX );
void menu_win( uiCTX* uiCTX );
void color_win( uiCTX* uiCTX );
void game_win( uiCTX* uiCTX );

#endif 

