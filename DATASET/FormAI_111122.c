//FormAI DATASET v1.0 Category: Math exercise ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    int a = rand() % 20 + 1;
    int b = rand() % 20 + 1;
    
    printf("Oh Romeo, what result shall we get\n");
    printf("When we calculate the sum of %d and %d?\n", a, b);
    
    int answer;
    scanf("%d", &answer);
    
    int result = a + b;
    
    if (answer == result) {
        printf("Oh Juliet, your calculation skills are superb!\n");
    } else {
        printf("Oh Romeo, we have a problem here.\n");
        printf("The correct answer is %d, my dear.\n", result);
    }
    
    return 0;
}