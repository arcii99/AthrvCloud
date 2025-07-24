//FormAI DATASET v1.0 Category: Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[50];
    char crush[50];
    char answer[10];
    
    printf("Enter your name: ");
    scanf("%s", name);
    
    printf("Enter the name of your crush: ");
    scanf("%s", crush);
    
    printf("Hello %s, do you want to send a love letter to %s? (y/n): ", name, crush);
    scanf("%s", answer);
    
    if (strcmp(answer, "y") == 0 || strcmp(answer, "Y") == 0) {
        printf("Dear %s,\n\n", crush);
        printf("I just wanted to let you know how I feel about you. Every time I see you, my heart skips a beat and I can't help but smile. You are the light in my life that keeps me going, and I am so grateful to have you in my life.\n\n");
        printf("I hope that you feel the same way about me, and that we can be more than just friends. I promise to always be there for you, to support you in everything you do, and to love you with all my heart.\n\n");
        printf("Yours truly,\n%s", name);
    } else {
        printf("Maybe another time then. Goodbye!");
    }
    
    return 0;
}