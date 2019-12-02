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

int rand_number(const int, const int);
void print_status(const int, const int, const int);
void print_menu(void);
int player_options();


int main(int argc, char **argv)
{
	puts(MSG_WELCOME);
	print_menu();
	int seed;
	int level = 1, score = 0, plays = 0;
	char player_command;
	if (argc > 1)
	{
		seed = atoi(argv[1]);
	}
	else
	{
		seed = time(NULL);
	}
    do
    {
        scanf(" %c", &player_command);
		switch (player_command)
        {
            case 'p':
				//inserir função que vai fazer o jogo
				printf("you're playing the game\n");
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
	return 0;
}

/* generate a random integer between min and max */
int rand_number(const int min, const int max)
{
	if (max < min)
	{
		puts("Max must be larger than Min");
		exit(0);
	}
	int n = abs(max - min) + 1;
	return (rand() % n) + min;
}

/* print the game status */
void print_status(const int level, const int score, const int plays)
{
	puts("+-----------------------------+");
	printf("| level:  %02d                  |\n", level);
	printf("| points: %02d                  |\n", score);
	printf("| plays:  %02d                  |\n", plays);
	puts("+-----------------------------+");
}

/* print the option menu */
void print_menu(void)
{
	puts("+------------------------------+");
	puts("| SORTIFY                      |");
	puts("| p - next chalenge            |");
	puts("| q - quit                     |");
	puts("| m - print this information   |");
	puts("| s - show your status         |");
	puts("+------------------------------+");
}