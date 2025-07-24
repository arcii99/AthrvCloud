//FormAI DATASET v1.0 Category: Color Code Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert RGB color code to hexadecimal string
void rgbToHex(int red, int green, int blue, char hex[]) {
    sprintf(hex, "#%02x%02x%02x", red, green, blue);
}

// Function to convert hexadecimal string to RGB color code
void hexToRgb(char hex[], int* red, int* green, int* blue) {
    sscanf(hex, "#%02x%02x%02x", red, green, blue);
}

// Function to check if two color codes are equal
int colorsEqual(char code1[], char code2[]) {
    int red1, green1, blue1, red2, green2, blue2;
    hexToRgb(code1, &red1, &green1, &blue1);
    hexToRgb(code2, &red2, &green2, &blue2);
    if (red1 == red2 && green1 == green2 && blue1 == blue2)
        return 1;
    else
        return 0;
}

int main() {
    int numPlayers;
    printf("Welcome to the Color Code Converter multiplayer game!\n");
    printf("How many players are there? ");
    scanf("%d", &numPlayers);
    char** playerNames = malloc(numPlayers * sizeof(char*));
    char** playerColors = malloc(numPlayers * sizeof(char*));
    int* scores = malloc(numPlayers * sizeof(int));
    for (int i = 0; i < numPlayers; i++) {
        playerNames[i] = malloc(20 * sizeof(char));
        playerColors[i] = malloc(8 * sizeof(char));
        scores[i] = 0;
        printf("Enter Player %d's name: ", i+1);
        scanf("%s", playerNames[i]);
        printf("Enter Player %d's starting color code: ", i+1);
        scanf("%s", playerColors[i]);
    }
    int currPlayer = 0;
    int gameWon;
    char input[10];
    while (1) {
        printf("\n%s's turn:\n", playerNames[currPlayer]);
        printf("Type 'c' to convert RGB color code to hexadecimal or 'h' to convert hexadecimal code to RGB: ");
        scanf("%s", input);
        if (strcmp(input, "c") == 0) {
            int red, green, blue;
            char hex[8];
            printf("Enter the red, green, and blue values (separated by spaces): ");
            scanf("%d %d %d", &red, &green, &blue);
            rgbToHex(red, green, blue, hex);
            printf("The hexadecimal color code is %s\n", hex);
            if (colorsEqual(hex, playerColors[currPlayer])) {
                printf("You got a point!\n");
                scores[currPlayer] = scores[currPlayer] + 1;
                if (scores[currPlayer] == 3) {
                    gameWon = currPlayer;
                    break;
                }
            }
            else {
                printf("Wrong color code. No points awarded.\n");
            }
        }
        else if (strcmp(input, "h") == 0) {
            char hex[8];
            int red, green, blue;
            printf("Enter the hexadecimal color code: ");
            scanf("%s", hex);
            hexToRgb(hex, &red, &green, &blue);
            printf("The RGB color code is (%d,%d,%d)\n", red, green, blue);
            if (colorsEqual(hex, playerColors[currPlayer])) {
                printf("You got a point!\n");
                scores[currPlayer] = scores[currPlayer] + 1;
                if (scores[currPlayer] == 3) {
                    gameWon = currPlayer;
                    break;
                }
            }
            else {
                printf("Wrong color code. No points awarded.\n");
            }
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
        currPlayer = (currPlayer + 1) % numPlayers;
    }
    printf("%s wins!\n", playerNames[gameWon]);
    printf("Final scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", playerNames[i], scores[i]);
    }
    // Free dynamic memory
    for (int i = 0; i < numPlayers; i++) {
        free(playerNames[i]);
        free(playerColors[i]);
    }
    free(playerNames);
    free(playerColors);
    free(scores);
    return 0;
}