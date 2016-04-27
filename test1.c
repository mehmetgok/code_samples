#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> /* usleep */

#include <ncurses.h>
#include <pthread.h>

int v_exit;

pthread_t th1;

void readSensors();

int main()
{	
	int ch;

	v_exit = 0,

	initscr();			/* Start curses mode 		*/
	// raw();			/* Line buffering disabled	*/
	curs_set(0); 		/* Makes the cursor invisible */
	
	noecho();			/* Don't echo() while we do getch */
	
	nodelay(stdscr, TRUE); // do not wait for getch()

    printw("Type any character to see it in bold\n");
		
	pthread_create(&th1, NULL, (void *) &readSensors, NULL);
		
	while (1) {
		
		
		
		ch = getch();			/* If raw() hadn't been called
					 * we have to press enter before it
					 * gets to the program 		*/
	
		if (ch == ERR) 
		{
          
		}	
		else
		if (ch == 27)
		{
				
			v_exit = 1;
			
			break;
			
		}
		else
		{	
			printw("The pressed key is ");
			attron(A_BOLD);
			printw("%c", ch);
			attroff(A_BOLD);
		
			refresh();		
	}
	
	
			/* Print it on to the real screen */
   			/* Wait for user input */
	}
	

	
	// refresh();		
						
	
	
	endwin();			/* End curses mode		  */

	return 0;
}


void readSensors()
{
		while (v_exit == 0)
		{
			mvprintw(1, 0, "Hello");
			move(2, 0);
			usleep(100);
		}
		printw("Exit");
		
}