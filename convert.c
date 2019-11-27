#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int rand_number(const int, const int);
void print_status(const int, const int, const int);
void print_menu(void);
void player_options(char);



int main()
{

	puts(MSG_WELCOME);
    print_menu();
	return 0;
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

/*Fucntion for Player Commands*/
void player_options(char player_command)
{
    do
    {
        scanf(" %c", &player_command);
		switch (player_command)
        {
            case 'p':
            
                break;

            case 'q':
                printf("Bye\n");
                break;
            
            case 'b':
                
                break;

            case 's':
        
                break;

            default:
                printf("Unknown option\n");
                break;
        }

    }
    while (player_command != 'q');
            return 0;
    
}