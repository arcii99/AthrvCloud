//FormAI DATASET v1.0 Category: Educational ; Style: inquisitive
#include <stdio.h>

int main() {
    char name[20];
    int age, height, weight;

    printf("Hello there! What's your name? ");
    scanf("%s", name);

    printf("Hi, %s! How old are you? ", name);
    scanf("%d", &age);

    printf("Interesting! And how tall are you in centimeters? ");
    scanf("%d", &height);

    printf("Got it. Lastly, what's your weight in kilograms? ");
    scanf("%d", &weight);

    printf("\n\nSo let me see if I understood everything correctly...\n\n");
    printf("Your name is %s.\n", name);
    printf("You are %d years old.\n", age);
    printf("Your height is %d centimeters.\n", height);
    printf("And your weight is %d kilograms.\n\n", weight);

    printf("Impressive! Thank you for answering these questions, %s. Have a great day!\n\n", name);

    return 0;
}