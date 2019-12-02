#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MSG_WELCOME "WELCOME TO SORTIFY!"
#define MSG_SORT "Sort the following numbers:"
#define MSG_SORT2 "Please sort the numbers"
#define MSG_WELL "Well done!"
#define MSG_WIN "Congratulations, you win!"
#define MSG_OVER "Game Over."
#define MSG_WRONG "Wrong answer."
#define MSG_MAX "You have reached the maximum number of moves."
#define MSG_BYE "Bye."
#define MSG_UNKNOWN "Unknown option."
/* Use puts() to print constant strings */


void print_status(int level, int score, int plays);
void print_menu(void);
int rand_number( int *min, int *max, int *level);
void level_up(int *l);


int main(int argc, char **argv)
{	
	int level = 1;
	int score = 0;
	int plays = 0;
	char player_command;
	int min, max;
	puts(MSG_WELCOME);
    print_menu();
	
	/* Define rand function's seed */

	int seed;
	if (argc >= 2)
	{
		seed = atoi(argv[1]);
		srand(seed);
	}
	else
	{
		srand(time(0)); 
	}
	
	/* All of the players commands */
	
	do
    {
        scanf(" %c", &player_command);
		switch (player_command)
        {
            case 'p':
				puts(MSG_SORT);
				rand_number(&min, &max, &level);
                break;

            case 'q':
                puts(MSG_BYE);
                break;
            
            case 'm':
                print_menu();
                break;

            case 's':
            	print_status(level, score, plays);
                break;

            default:
                printf("Unknown option\n");
                break;
        }

    }
    while (player_command != 'q');
}

/*Function to print Menu*/

void print_menu(void)
{
	puts("+-----------------------------+");
	puts("| SORTIFY                     |");
	puts("| p - next chalenge           |");
	puts("| q - quit                    |");
	puts("| m - print this information  |");
	puts("| s - show your status        |");
	puts("+-----------------------------+");
}



/* Function to print game status*/
void print_status(int level, int score, int plays)
{ 
	puts("+-----------------------------+");
	printf("| level:  %02d                  |\n", level);
	printf("| points: %02d                  |\n", score);
	printf("| plays:  %02d                  |\n", plays);
	puts("+-----------------------------+");
}



/* generate a random integer between min and max */
int rand_number( int *min, int *max, int *level)
{
	int i;

/* Changes the min & max variables according to level */
	
	if (*level == 1)
	{
		*min = 0;
		*max = 10;
	}

	else if (*level == 2)
	{
		*min = 0;
		*max = 30;
	}

	else if (*level == 3)
	{
		*min = -50;
		*max = 30;
	}

	else if (*level == 4)
	{
		*min = -100;
		*max = 0;
	}

	else
	{
		*min = -200;
		*max = -100;
	}

	if (*max < *min)
	{
		puts("Max must be larger than Min");
		exit(0);
	}

/* Block of code that prints the array of numbers for that level */

	int number;
	int n = abs(*max - *min) + 1;
	for ( i = 0 ; i < 4; i++)
	{
		number = ((rand() % n) + *min);
		if ( i == 3)
		{
			printf("%d", number);
		}
		else
		{
			printf("%d, " , number);
		}
	}
	printf("\n");
	return 0;

}

/* Function for Leveling Up */
void level_up(int *l)
{
	int score = 0;
	for (score = 0; score > *l*10; score += 5)
	{
		*l += 1;
	}
}

/*Function for Game Over */
void Game