//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shocked
#include <stdio.h>

char ascii[128][15] = {
    "                 ",
    "                 ",
    "  _____________  ",
    " /             \\ ",
    "|  0       0  |  ",
    "|       ^     |  ",
    "|   \\_______/  |  ",
    " \\___________/  ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "                 ",
    "  ██████████████ ",
    " ███████████████",
    "███████░░███████",
    "███████░░░░█████",
    " ███████░░░████ ",
    "  ████████████  ",
};

void display_ascii_art(char *input) {
    int i,j;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] > 127 || input[i] < 0) {
            printf("Sorry, can't convert\n");
            return;
        }
        else {
            for (j = 0; j < 15; j++) {
                printf("%c", ascii[input[i]][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    printf("Enter a string to display as ASCII art:\n");
    char input[100];
    fgets(input, 100, stdin);
    printf("\n");
    printf("┌───────────────────────────────┐\n");
    printf("│  Generated ASCII Art Below:   │\n");
    printf("└───────────────────────────────┘\n\n");
    display_ascii_art(input);
    return 0;
}