//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fortune_teller(int num) {
    // Define an array of possible fortunes
    char fortunes[6][100] = {"Good things will come to you soon",
                             "You will meet someone special",
                             "Your hard work will pay off",
                             "A new opportunity will come your way",
                             "You will find peace and happiness",
                             "Your dreams will come true soon"};
	
    // Exit condition - when num reaches 0
    if (num == 0) {
        printf("Thank you for using our fortune teller!\n");
        return;
    }
	
    // Pick a random number between 0 and 5 
    srand(time(NULL));
    int index = rand() % 6;

    // Print out the fortune and decrease num by 1
    printf("\n%s\n", fortunes[index]);
    num--;

    // Recursive function call with updated num value
    fortune_teller(num);
}

int main() {
    printf("Welcome to our automated fortune teller!\n");
    printf("How many fortunes would you like? (1-10) ");

    // Get user input and call fortune_teller function
    int num;
    scanf("%d", &num);
    fortune_teller(num);

    return 0;
}