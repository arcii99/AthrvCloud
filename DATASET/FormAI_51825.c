//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: puzzling
// This program generates ASCII art based on user input

#include <stdio.h>

int main() {
    char message[50];
    int art[7][6] = { // ASCII art templates
        {0,0,0,0,0,0},
        {1,1,1,0,1,1},
        {1,0,0,0,0,1},
        {1,1,1,1,1,1},
        {1,0,0,0,0,1},
        {1,0,0,0,0,1},
        {1,0,0,0,0,1}
    };
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    printf("\n");
    for (int i = 0; message[i] != '\0'; i++) { // loop through each character in the user's message
        char c = message[i];
        switch(c) {
            case 'A': // print ASCII art for "A"
                for (int row = 0; row < 7; row++) {
                    for (int col = 0; col < 6; col++) {
                        if (art[row][col] == 1) {
                            printf("*");
                        } else {
                            printf(" ");
                        }
                    }
                    printf("\n");
                }
                break;
            case 'B': // print ASCII art for "B"
                for (int row = 0; row < 7; row++) {
                    for (int col = 0; col < 6; col++) {
                        if ((art[row][col] == 1 && (col == 0 || col == 5 || (row == 2 && col < 3)) || (row == 4 && col < 3))) {
                            printf("*");
                        } else {
                            printf(" ");
                        }
                    }
                    printf("\n");
                }
                break;
            case 'C': // print ASCII art for "C"
                for (int row = 0; row < 7; row++) {
                    for (int col = 0; col < 6; col++) {
                        if ((col == 0 && (row != 0 && row != 6)) || (row == 0 && (col > 0 && col < 5)) || (row == 6 && (col > 0 && col < 4)) || (col == 5 && (row != 0 && row != 6))) {
                            printf("*");
                        } else {
                            printf(" ");
                        }
                    }
                    printf("\n");
                }
                break;
            case 'D': // print ASCII art for "D"
                for (int row = 0; row < 7; row++) {
                    for (int col = 0; col < 6; col++) {
                        if (art[row][col] == 1 && (col == 0 || col == 5 || (row == 1 || row == 5) && col < 5) || (row == 2 || row == 4) && col == 4) {
                            printf("*");
                        } else {
                            printf(" ");
                        }
                    }
                    printf("\n");
                }
                break;
            case 'E': // print ASCII art for "E"
                for (int row = 0; row < 7; row++) {
                    for (int col = 0; col < 6; col++) {
                        if (art[row][col] == 1 && (col == 0 || row == 0 || row == 6)) {
                            printf("*");
                        } else {
                            printf(" ");
                        }
                    }
                    printf("\n");
                }
                break;
            case 'F': // print ASCII art for "F"
                for (int row = 0; row < 7; row++) {
                    for (int col = 0; col < 6; col++) {
                        if (art[row][col] == 1 && (col == 0 || row == 0)) {
                            printf("*");
                        } else {
                            printf(" ");
                        }
                    }
                    printf("\n");
                }
                break;
            default: // print blank space for characters not in the switch statement
                for (int row = 0; row < 7; row++) {
                    printf("      \n");
                }
                break;
        }
    }
    return 0;
}