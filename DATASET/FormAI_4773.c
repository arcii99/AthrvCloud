//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function prototypes */
void printIntro();
int rollDie();
void playerTurn(int *score, int *current, int *dice, int *round, int *event, int *ghost, int *items, int *charm, int *defeat, int *escape);
void ghostTurn(int *score, int *current, int *dice, int *round, int *event, int *ghost, int *items, int *charm, int *defeat, int *escape);
void printStatus(int score, int current, int ghost, int items, int charm, int defeat, int escape);
void printResult(int score);

int main()
{
	/* Initialize variables */
	srand(time(NULL));
	int score = 0, current = 0, dice = 0, round = 1, event = 0, ghost = 0, items = 0, charm = 0, defeat = 0, escape = 0;
	
	printIntro();
	
	/* Start game loop */
	while(current < 100 && escape == 0 && defeat == 0)
	{
		printf("[- Round %d -]\n", round);
		playerTurn(&score, &current, &dice, &round, &event, &ghost, &items, &charm, &defeat, &escape);
		
		if(current >= 100)
			break;
		
		ghostTurn(&score, &current, &dice, &round, &event, &ghost, &items, &charm, &defeat, &escape);
		round++;
	}

	printResult(score);

	return 0;
}

/* Introduction to the game */
void printIntro()
{
	printf("Welcome to the Haunted House Simulator!\n");
	printf("You are on a quest to reach the end of the haunted house, but beware of the ghosts and traps that await you!\n");
	printf("In each round you will roll a die and move that many spaces.\n");
	printf("The spaces you land on may have an event, a ghost, an item, or nothing at all.\n");
	printf("You start with 0 points and you gain points for each space you reach.\n");
	printf("However, if you land on a space with a ghost, you lose all your points and start over!\n");
	printf("You can also collect items to help you along the way, but be careful not to trust them too much!\n");
	printf("Good luck!\n");
}

/* Rolls a die and returns the result */
int rollDie()
{
	return rand() % 6 + 1;
}

/* Player turn */
void playerTurn(int *score, int *current, int *dice, int *round, int *event, int *ghost, int *items, int *charm, int *defeat, int *escape)
{
	*dice = rollDie();
	
	printf("You rolled a %d!\n", *dice);
	
	*current += *dice;
	
	switch(*current)
	{
		case 5:
			printf("You found an item!\n");
			(*items)++;
			break;
		case 10:
			printf("You found an item!\n");
			(*items)++;
			break;
		case 15:
			printf("You found an item!\n");
			(*items)++;
			break;
		case 20:
			printf("You found an item!\n");
			(*items)++;
			break;
		case 25:
			*ghost = 1;
			printf("You encountered a ghost!\n");
			break;
		case 30:
			printf("You found an item!\n");
			(*items)++;
			break;
		case 35:
			printf("You found an item!\n");
			(*items)++;
			break;
		case 40:
			printf("You found an item!\n");
			(*items)++;
			break;
		case 45:
			printf("You found an item!\n");
			(*items)++;
			break;
		case 50:
			*ghost = 1;
			printf("You encountered a ghost!\n");
			break;
		case 55:
			printf("You found an item!\n");
			(*items)++;
			break;
		case 60:
			printf("You found an item!\n");
			(*items)++;
			break;
		case 65:
			printf("You found an item!\n");
			(*items)++;
			break;
		case 70:
			printf("You found an item!\n");
			(*items)++;
			break;
		case 75:
			*event = 1;
			printf("You encountered an event!\n");
			break;
		case 80:
			printf("You found an item!\n");
			(*items)++;
			break;
		case 85:
			printf("You found an item!\n");
			(*items)++;
			break;
		case 90:
			printf("You found an item!\n");
			(*items)++;
			break;
		case 95:
			printf("You found an item!\n");
			(*items)++;
			break;
		case 100:
			*defeat = 1;
			break;
	}
	
	if(*ghost == 1)
	{
		*current = 0;
		*score = 0;
		*ghost = 0;
		
		printf("You were defeated by the ghost and have to start over!\n");
	}
	else if(*event == 1)
	{
		*event = 0;
		
		switch(rand() % 3 + 1)
		{
			case 1:
				*score += 5;
				printf("You found some coins on the ground and gained 5 points!\n");
				break;
			case 2:
				*charm = 1;
				printf("You found a charm that will protect you from the next ghost encounter!\n");
				break;
			case 3:
				*escape = 1;
				printf("You found a secret passage that will allow you to skip the next round!\n");
				break;
		}
	}
	else
	{
		*score += *current;
		
		printStatus(*score, *current, *ghost, *items, *charm, *defeat, *escape);
	}
}

/* Ghost turn */
void ghostTurn(int *score, int *current, int *dice, int *round, int *event, int *ghost, int *items, int *charm, int *defeat, int *escape)
{
	printf("The ghosts are angry!\n");
	
	*dice = rollDie();
	
	if(*dice == 6)
	{
		printf("The ghosts were too scared to attack this round!\n");
	}
	else if(*charm == 1)
	{
		*charm = 0;
		printf("The charm protected you from the ghosts!\n");
	}
	else if(*escape == 1)
	{
		*escape = 0;
		printf("You used the secret passage to skip this round!\n");
		*round--;
	}
	else
	{
		*current = 0;
		*score = 0;
		
		printf("The ghosts attacked you and you have to start over!\n");
		
		if(*current < 0)
			*current = 0;
		
		if(*score < 0)
			*score = 0;
	}
	
	printStatus(*score, *current, *ghost, *items, *charm, *defeat, *escape);
}

/* Prints the current status of the game */
void printStatus(int score, int current, int ghost, int items, int charm, int defeat, int escape)
{
	printf("[Status]\n");
	printf("Points: %d\n", score);
	printf("Current Position: %d\n", current);
	
	if(ghost == 1)
		printf("You encountered a ghost!\n");
	
	if(charm == 1)
		printf("You have a charm that will protect you from the next ghost encounter!\n");
	
	if(escape == 1)
		printf("You have found a secret passage that will allow you to skip the next round!\n");
	
	if(items > 0)
		printf("You have %d items with you.\n", items);
	
	if(defeat == 1)
		printf("You have reached the end of the haunted house and have defeated all the ghosts!\n");
}

/* Prints the final result of the game */
void printResult(int score)
{
	printf("Final Score: %d\n", score);
	printf("Thank you for playing the Haunted House Simulator!\n");
}