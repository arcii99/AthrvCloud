//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Automated Fortune Teller Program!\n");
    
    srand(time(NULL)); // seed random generator with current time 
    
    char input[20];
    int num;
    
    printf("What is your name? \n");
    scanf("%s", input);
    printf("Hello, %s!\n", input);
    
    printf("Think of a question, and I will give you the answer! Press enter to continue...\n");
    getchar(); // clear input buffer
    getchar();
    
    num = rand() % 10 + 1;
    
    switch(num) {
        case 1: printf("The outlook is good.\n");
                break;
        case 2: printf("It is certain.\n");
                break;
        case 3: printf("Without a doubt.\n");
                break;
        case 4: printf("Yes - definitely.\n");
                break;
        case 5: printf("You may rely on it.\n");
                break;
        case 6: printf("As I see it, yes.\n");
                break;
        case 7: printf("Most likely.\n");
                break;
        case 8: printf("Outlook good.\n");
                break;
        case 9: printf("Signs point to yes.\n");
                break;
        case 10: printf("Very doubtful.\n");
                break;
    }
    
    printf("\nThank you for using the Automated Fortune Teller Program. Goodbye!\n");
    
    return 0;
}