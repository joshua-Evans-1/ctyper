#include <ncurses.h>

void color_init(  ){
	start_color();
	int colorNum = 1;
	for( int i = 0; i < 8; i++ ) {
		for( int j = 0; j < 8; j++ ) {
			if( i != j ) {
				init_pair( colorNum, i, j );
				colorNum++;
			}
		}
	}
}
