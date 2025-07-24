//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to get random number
int get_random_number(int min, int max) {
    srand(time(0));
    int num = rand() % (max - min + 1) + min;
    return num;
}

int main() {
    char question[100];
    int answer;

    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("What would you like to know?\n");
    scanf("%[^\n]s", question);

    answer = get_random_number(1, 5);

    switch(answer) {
        case 1: printf("The answer to \"%s\" is YES.", question);
                break;
        case 2: printf("The answer to \"%s\" is NO.", question);
                break;
        case 3: printf("The answer to \"%s\" is MAYBE.", question);
                break;
        case 4: printf("The answer to \"%s\" is NOT SURE.", question);
                break;
        case 5: printf("The answer to \"%s\" is ASK AGAIN LATER.", question);
                break;
    }

    return 0;
}