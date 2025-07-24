//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {
    int luckyNum, age, birthMonth, favoriteColor, sum;
    char name[50], horoscope[50];
    
    printf("Greetings, traveler! My name is Zoltar, and I am a fortunetelling bot. Please answer the following questions:");
    
    printf("\nWhat's your name?\n");
    scanf("%s", name);
    
    printf("What is your age?\n");
    scanf("%d", &age);
    
    printf("What is your birth month (1-12)?\n");
    scanf("%d", &birthMonth);
    
    printf("What is your favorite color?\n");
    printf("(1)Red\n(2)Blue\n(3)Green\n(4)Yellow\n");
    scanf("%d", &favoriteColor);
    
    printf("What is your lucky number?\n");
    scanf("%d", &luckyNum);
    
    sum = age + birthMonth + favoriteColor + luckyNum;
    
    switch(sum % 4) {
        case 0:
            strcpy(horoscope, "The future looks bright, as the stars align in your favor. Expect good news very soon.");
            break;
        case 1:
            strcpy(horoscope, "Beware of false friends and dangerous situations. Keep your wits about you, and be cautious.");
            break;
        case 2:
            strcpy(horoscope, "A major event is looming on the horizon. It may be a difficult challenge, but you have the strength to overcome it.");
            break;
        case 3:
            strcpy(horoscope, "There are some unexpected surprises in store for you. Be open to change, and seize new opportunities as they arise.");
            break;
    }
    
    printf("\n%s, your fortune for today is:\n%s\n", name, horoscope);
    
    return 0;
}