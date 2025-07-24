//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: thriller
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 500

// Function to read a file line by line
void read_lines(const char* filename, char lines[][MAX_LINE_LENGTH]) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    int line_count = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        strcpy(lines[line_count], line);
        line_count++;
    }

    fclose(file);
}

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Initialize random number generator
    srand(time(NULL));
    
    // Read fortune database
    char fortunes[1000][MAX_LINE_LENGTH];
    read_lines("fortunes.txt", fortunes);

    // Start the thriller story
    printf("You find yourself in a dark room. Your heart is pounding and your palms are sweaty.\n");
    printf("In front of you lies an old computer. It turns on by itself and you see a program menu open.\n");
    printf("You could press any key to exit, but there is something peculiar about the program. You decide to investigate.\n\n");

    printf("The program presents itself as an Automated Fortune Teller. It asks you to enter your name: ");
    char name[50];
    scanf("%s", name);

    printf("\nWelcome, %s. Please think of a question and I shall give you an answer.\n\n", name);
    printf("The computer works for a while, its fans whirring loudly. Finally, a new message appears on the screen:\n\n");

    // Choose a random fortune and display it
    int index = random_number(0, 999);
    printf("%s\n\n", fortunes[index]);

    // End the story with a cliffhanger
    printf("You feel uneasy. The fortune seems to reveal more than it should. As you try to exit the program, ");
    printf("the screen turns black and a message appears:\n\n");
    printf("You cannot escape your fate, %s. Beware the dangers that lurk around every corner.\n\n", name);
    printf("You suddenly hear a creaking sound behind you. You turn around, but there is nothing there. ");
    printf("You feel like you're being watched. You run outside, but it's too late. They've found you.\n");
    printf("The last thing you see is a cloaked figure before you black out.\n\n");
    printf("Game over.\n");

    return 0;
}