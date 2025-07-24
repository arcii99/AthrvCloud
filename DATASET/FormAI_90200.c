//FormAI DATASET v1.0 Category: Scientific ; Style: happy
#include <stdio.h>

// This program will calculate your happiness index based on various factors

int main() {
    float money, health, relationships, hobbies, freedom, happinessIndex;

    printf("Welcome to the happiness index calculator!\n");
    printf("Enter your estimated monthly income: ");
    scanf("%f", &money);
    printf("Enter your average rating for your physical health (out of 10): ");
    scanf("%f", &health);
    printf("Enter your average rating for your relationships (out of 10): ");
    scanf("%f", &relationships);
    printf("Enter your average rating for your hobbies/interests (out of 10): ");
    scanf("%f", &hobbies);
    printf("Enter your average rating for your sense of freedom (out of 10): ");
    scanf("%f", &freedom);

    // Calculating the happiness index
    happinessIndex = (money/1000 * 3) + (health * 1.5) + (relationships * 2) + (hobbies * 1.2) + (freedom * 1.5);

    printf("\n");
    printf("Your happiness index is %.2f out of 10!\n", happinessIndex);

    if(happinessIndex >= 8) {
        printf("Congrats! You are extremely happy and have a positive outlook on life!\n");
    } else if(happinessIndex >= 6) {
        printf("You are doing pretty well, but could make some small improvements to increase your happiness index!\n");
    } else {
        printf("Don't worry, there is always room for improvement. Try making some positive changes in your life!\n");
    }

    return 0;
}