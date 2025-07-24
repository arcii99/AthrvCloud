//FormAI DATASET v1.0 Category: Educational ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int guess, randomNum;

	srand(time(0));
	randomNum=rand()%100+1;

	printf("Welcome to the Guess the Number Game!\n");
	printf("You will have 6 tries to guess a number between 1 and 100.\n\n");

	for(int i=1; i<=6; i++){
		printf("Guess #%d: ", i);
		scanf("%d", &guess);

		if(guess<1 || guess>100){
			printf("Out of range! Your guess must be between 1 and 100.\n");
			continue;
		}

		if(guess<randomNum){
			printf("Too low. ");
		} else if(guess>randomNum){
			printf("Too high. ");
		} else {
			printf("You got it! Congratulations!\n");
			return 0;
		}

		if(i==6){
			printf("Sorry, you ran out of tries. The correct number was %d.\n", randomNum);
		} else {
			printf("Try again.\n");
		}
	}

	return 0;
}