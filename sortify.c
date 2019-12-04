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
int game(int *, int *, int *);
void sorter(int *);


int main(int argc, char **argv)
{
	int seed;
	int level = 1, score = 0, plays = 0;
	char player_command;
	
	puts(MSG_WELCOME);
	print_menu();


	if (argc > 1)
	{
		seed = atoi(argv[1]);
		srand(seed);
	}
	else
	{
		seed = time(NULL);
		srand(seed);
	}
	
	
	do
    {
        scanf(" %c", &player_command);
		switch (player_command)
        {
            case 'p':
				game(&level, &score, &plays);
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

/*game it self*/
int game(int * nivel, int * pontuacao, int * jogadas)
{
	int number, min, max;

	/*prints */
	puts(MSG_SORT);

	/*defines the min and max value for the random function*/
	switch (*nivel)
	{
		case 1:
			min = 0;
			max = 10;
			break;
		case 2:
			min = 0;
			max = 30;
			break;
		case 3:
			min = -50;
			max = 30;
			break;
		case 4:
			min = -100;
			max = 0;
			break;
		case 5:
			min = -200;
			max = -100;
			break;
		default:
			break;
	} 

	/*cicle that generates 4 random numbers*/
	int unsortedlist[4];
	for (int i = 0; i < 4; i++)
	{
		number = (rand_number(min, max));
		if ( i == 3)
		{
			printf("%d", number);
		}
		else
		{
			printf("%d, " , number);
		}
        unsortedlist[i]=number;
	}
	printf("\n");
	
	/*função que me devolve o input do player*/
	int playerinput[4], num;
	for(int i = 0; i < 4; i++)
	{
		scanf(" %d", &num);
		*(playerinput+i) = num;
	}
	printf("%d %d %d %d \n", playerinput[0],playerinput[1], playerinput[2], playerinput[3]);
	
	/*implementa função que organiza o vetor*/
	int sortedlist[4];
	sortedlist[4] = unsortedlist[4];
	sorter(sortedlist);
	for (int i = 0; i < 4; i++){printf("%d ", *(sortedlist+i));}
	printf("\n");

	/*checks if the numbers in the input are the same of the pc*/
	int check;
	for (int i=0;i<4;i++)
    {
		for(int j = 0; j < 4; j++)
		{
			if (sortedlist[i] != playerinput[j])
			{
				check+=1;
			}
		}
		if (check==4)
		{

		}
		break;
    }

	*pontuacao += 5;
	if (*pontuacao % 10 == 0)
	{
		*nivel += 1;
		if (*nivel == 6)
		{
			//end game and you win
		}
	}
	*jogadas +=1;

	return 0;
}

/*sorts the numbers in the vector*/
void sorter(int list[])
{
	int maior = 0;
	int sorted = 0;
	while (sorted!=1)
    {
        sorted=1;
        for(int i=0;i<=2;i++)
        {
            if (list[i]>list[i+1])
            {
                maior = list[i];
                list[i]=list[i+1];
                list[i+1]=maior;
                sorted = 0;
            }
        }
    }
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