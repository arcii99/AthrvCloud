//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shape shifting
#include <stdio.h>

// Recursive function to solve Tower of Hanoi problem
void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
	if(n == 1)
	{
		printf("Shift disk 1 from rod %c to rod %c\n", source, destination);
		return;
	}
	
	towerOfHanoi(n-1, source, destination, auxiliary);
	
	printf("Shift disk %d from rod %c to rod %c\n", n, source, destination);
	
	towerOfHanoi(n-1, auxiliary, source, destination);
}

int main()
{
	printf("\n\tWelcome to the Shapeshifting Tower of Hanoi!\n");
	
	int n = 0, player_choice;
	
	while(n < 3)
	{
		printf("\nHow many disks would you like to play with? (Minimum 3)\n");
		scanf("%d", &n);
	}
	
	printf("\nWould you like to play Shapeshifting Tower of Hanoi Mode?\n1. Yes\n2. No\n");
	scanf("%d", &player_choice);
	
	if(player_choice == 1)
	{
		printf("\nShapeshifting Tower of Hanoi Mode Enabled!\n");
		
		printf("\nYou are given a choice to enter a number after each move to 'shape shift' one disk into an 'elemental' form, which can only be moved to a rod with the same element!\n");
		
		towerOfHanoi(n, 'A', 'B', 'C'); // A, B and C are the names of rods
	}
	else
	{
		printf("\nVanilla Tower of Hanoi Mode Enabled!\n");	
		towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are the names of rods
	}
	
	return 0;
}