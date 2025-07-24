//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    // Set up random number generator
    srand(time(NULL));
    
    // Welcome message
    printf("Welcome to the Medieval Fortune Teller!\n");
    printf("Think of any question you have and press enter to continue...\n");
    getchar();
    
    // Generate random number from 0-4
    int rand_num = rand() % 5;
    
    // Display fortune based on random number
    switch(rand_num) {
        case 0:
            printf("The stars are not aligned in your favor, the answer is no.\n");
            break;
        case 1:
            printf("The gods smile upon you, the answer is yes.\n");
            break;
        case 2:
            printf("The path you are currently on will lead to success, keep going.\n");
            break;
        case 3:
            printf("Beware of a dark force that seeks to derail your plans.\n");
            break;
        case 4:
            printf("Your future is cloudy, but do not despair, for the sun always shines after the rain.\n");
            break;
  }
  
  // Farewell message
  printf("Thank you for consulting me, may your future be bright!\n");
  
  return 0;
}