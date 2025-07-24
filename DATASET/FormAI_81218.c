//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char question[100]; 
    time_t t;
    srand((unsigned) time(&t));
    printf("Hello, I am the Automated Fortune Teller! Ask me a yes or no question: \n");
    scanf("%[^\n]%*c", question); 
    
    int random_num = rand() % 10;

    if (random_num < 3) {
        printf("\nI'm sorry, I cannot predict the future.\n");
    } else if (random_num < 6) {
        printf("The outlook is not good. %s\n", question);
    } else if (random_num < 8) {
        printf("Signs point to yes. %s\n", question);
    } else {
        printf("It is certain. %s\n", question);
    }

    return 0;
}