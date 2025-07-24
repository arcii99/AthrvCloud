//FormAI DATASET v1.0 Category: Game ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
    char name[50];
    char partner[50];
    int compatibilityScore = 0;

    printf("Welcome to our love compatibility program!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter your partner's name: ");
    scanf("%s", partner);

    // Calculate compatibility
    int nameLength = strlen(name);
    int partnerLength = strlen(partner);

    for (int i = 0; i < nameLength; i++) {
        for (int j = 0; j < partnerLength; j++) {
            compatibilityScore += ((int)name[i] * (int)partner[j]) % 100;
        }
    }

    printf("Calculating love compatibility...\n\n");
    printf("Your love compatibility score is: %d\n", compatibilityScore);

    if (compatibilityScore >= 70) {
        printf("Congratulations, you and %s are a perfect match!\n", partner);
    } else if (compatibilityScore >= 50) {
        printf("%s and %s have potential for a great romance.\n", name, partner);
    } else {
        printf("Sorry %s, it doesn't look like %s is the one for you.\n", name, partner);
    }

    return 0;
}