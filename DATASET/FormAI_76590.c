//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    char name[20];
    int age;
    int fortune_number;
    
    printf("Welcome to the automated fortune teller!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    
    printf("Hello there, %s! What is your age?\n", name);
    scanf("%d", &age);
    
    printf("Hmm, interesting. Now, let me see into your future...\n");
    srand(time(NULL));
    fortune_number = rand() % 4;
    
    switch(fortune_number) {
        case 0:
            printf("Oh, how lucky! Your future looks bright. You will find true love and live happily ever after with your soulmate.\n");
            break;
        case 1:
            printf("Hmm, I see some challenges in your future. But do not fear, for you will overcome them and become stronger because of it. Your true love is just around the corner!\n");
            break;
        case 2:
            printf("Oh no, I sense heartbreak in your future. But remember, everything happens for a reason and it will eventually lead you to your true love.\n");
            break;
        case 3:
            printf("Ah, your future looks like a mysterious adventure! You will have exciting experiences and meet many new people, but your heart will ultimately lead you to your true love.\n");
            break;
        default:
            printf("Uh oh, I seem to have encountered an error. Please try again later.\n");
            break;
    }
    
    printf("Thank you for using the automated fortune teller, %s. May your future be filled with love and happiness!\n", name);
    
    return 0;
}