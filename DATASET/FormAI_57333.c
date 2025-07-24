//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate random integer */
int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

/* Main function */
int main() {
    srand(time(0)); // Initialize random number generator

    // Array of fortunes
    char *fortunes[] = {
        "You will find true love soon.",
        "Your hard work will soon pay off.",
        "You will receive unexpected money.",
        "You will achieve great success in life.",
        "Your creative talents will soon be recognized.",
        "You have a bright future ahead of you.",
        "You will travel to a foreign land and have a life-changing experience.",
        "You will meet someone who will change your life.",
        "You will live a long and fulfilling life.",
        "You will soon find the solution to a problem that has been troubling you."
    };

    // Ask user for their name
    char name[50];
    printf("Hello! What is your name?\n");
    scanf("%s", name);

    // Generate fortune
    int fortune_index = random_int(0, 9);
    printf("Hello %s, your fortune is: %s\n", name, fortunes[fortune_index]);

    return 0;
}