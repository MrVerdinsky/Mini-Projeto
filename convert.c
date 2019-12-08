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


int main(int argc, char **argv)
{
	int seed;
	int level = 1, score = 0, plays = 0;
	char player_command;
	
	puts(MSG_WELCOME);
	print_menu();

	/*Seed para gerar numeros aleatorios*/
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
	
	/*Ciclo que escolhe a opção do menu*/
	do
    {
        scanf(" %c", &player_command);
		switch (player_command)
        {
            
            case 'p':
				game(&level, &score, &plays);
                break;

            case 'q':
				print_status(level, score, plays);
                puts(MSG_BYE);
                break;
            
            case 'm':
                print_menu();
                break;

            case 's':
				print_status(level, score, plays);
                break;

            default:
                puts(MSG_UNKNOWN);
                break;
        }
        /*Se o numero de jogadas for igual a 30 ou se o jogador chegar ao nivel 6 o jogo acaba*/
        if (plays == 30)
        {
            return 0;
        }

		if (level==6)
		{
			print_status(level, score, plays);
			puts(MSG_OVER);
			return 0;
		}

    }
    while (player_command != 'q');
	return 0;
}

/*game it self*/
int game(int * nivel, int * pontuacao, int * jogadas)
{
	int number, min, max;
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
	*jogadas += 1;
	
	/*implementa função que organiza o vetor*/
	int sortedlist[4];
	for (int i = 0; i < 4; i++)
	{
		sortedlist[i] = unsortedlist[i];
	}
	int maior = 0;
	int sorted = 0;
	while (sorted!=1)
    {
        sorted=1;
        for(int i=0;i<=2;i++)
        {
            if (sortedlist[i]>sortedlist[i+1])
            {
                maior = sortedlist[i];
                sortedlist[i]=sortedlist[i+1];
                sortedlist[i+1]=maior;
                sorted = 0;
            }
        }
    }

    int i,j,check=0,different_num;

	/*checks if the numbers in the input are the same of the pc*/
	for (i = 0; i < 4; i++)
	{
        if (sortedlist[i]==playerinput[i])
        {
            check+=1;
        }
    }

    if (check==4)
    {
        puts(MSG_WELL);
        *pontuacao += 5;
			if (*pontuacao % 10 == 0)
			{
				*nivel += 1;
				if (*nivel == 6)
				{
					puts(MSG_WIN);
                    return 0;
				}
			}
    }
    else
    {
        for (i=0;i<4;i++)
        {
            different_num=0;
            
            for (j=0;j<4;j++)
            {
               if (playerinput[j]!=sortedlist[i])
               {
                   different_num+=1;
               }
           }
           /*One of the numbers is not on the list*/
           if (different_num==4)
           {
			   	int k,l;
			   	while (different_num ==4)
				{	
					puts(MSG_SORT2);
					for(int k = 0; k < 4; k++)
					{
						scanf(" %d", &num);
						*(playerinput+k) = num;
					}

					for (k=0;k<4;k++)
					{
						different_num=0;
							
						for (l=0;l<4;l++)
						{
							if (playerinput[l]!=sortedlist[k])
							{
								different_num+=1;
							}
						}					
					}   
           		}

				check=0;

				for (i = 0; i < 4; i++)
				{
					if (sortedlist[i]==playerinput[i])
					{
						check+=1;
					}
				}

				if (check==4)
				{
					puts(MSG_WELL);
					*pontuacao += 5;
					if (*pontuacao % 10 == 0)
					{
						*nivel += 1;
						if (*nivel == 6)
						{
							puts(MSG_WIN);
							return 0;
						}
					}
				}

				else
				puts(MSG_WRONG);
				
		   }
           /*The numbers are not ordered correctly*/
           if (i==3)
           {
               puts(MSG_WRONG);
           }
        }
        
    }
	
	if (*jogadas == 30)
	{
		puts(MSG_MAX);
		print_status( *nivel, *pontuacao, *jogadas);
		puts(MSG_OVER);
		return 0;
	}
    
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
	puts("+-----------------------------+");
	puts("| SORTIFY                      |");
	puts("| p - next chalenge            |");
	puts("| q - quit                     |");
	puts("| m - print this information   |");
	puts("| s - show your status         |");
	puts("+-----------------------------+");
}