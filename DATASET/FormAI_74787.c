//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

// Define the cyberpunk ASCII art
char cyberpunkArt[] = "\n"
" ___________████__████▓▓▓▓▓▓▓▓▓▓▓▓▓\n"
" ___________█▓▓▓▓█░░░█▓▓▓█░░░░░█▓▓█\n"
" __________█▓▓▓▓█░░░░░█▓▓▓█░░░░░░░█\n"
" _________█▓▓▓▓▓█░░░░░░░█▓▓▓█░░░░░░█\n"
" _________█▓▓▓▓▓█░░░░░░░░░█░█░░░░░░░█\n"
" _________█▓▓▓▓▓█░░░░░░░░░█░█░░░░░░█\n"
" _________█▓▓▓▓▓█░░░░░░░░░█░█░░░░░░█\n"
" _________█▓▓▓▓▓█░░░░░░░░░░░█░░░░░░█\n"
" _________█▓▓▓▓▓▓█░░░░░░░█░░░░░░░░░█\n"
" __________█▓▓▓▓▓██▓▓▓▓▓█░░░░░░░░░░░█\n"
" __________█▓▓▓▓██░░░░███░░░░░░░░░░█\n"
" ___________█▓▓██░░░░░░█▓██░░░░░░░░█\n"
" ___________█▓██░░░░░░░░█▓█░░░░░░░█\n"
" ____________█░░░░░░░░░░░░░░░░░░░█\n"
" ____________█░░░░░░░░░░░░░░░░░░█▓██\n"
" ___________█░░░░░░░░░░░░░░░░░░░█▓▓█\n"
" _________█▓█░░░░░░░░░░░░░░░░░░░█▓▓█\n"
" ________█▓▓█░░░░░░░░░░░░░░░░░░░█▓▓█\n"
" ________█▓▓█░░░░░░░░░░░░░░░░░░░████\n"
" ________█▓▓█░░░░░░░░░░░░░░░░░██▓▓█\n"
" ________▓▓█░░░░░░░░░░░░░░░░░██▓▓▓█\n"
" ________▓█▓██▓░░░░░░░░░░░░░░██▓██\n"
" ________██░░░█░░░░░░░░░░░░░██▓▓█\n"
" ________█░░░░░█░░░░░░░░░░░░██▓▓█\n"
" ________█░░░░░░█░░░░░░░░░░██▓▓██\n"
" ________██░░░░░░█░░░░░░░░███▓▓█\n"
" ________██░░░░░░█░░░░░░░███▓▓█\n"
" ________██░░░░░░░░░░░░░░██▓▓█\n"
" ________██░░░░░░░░░░░░░██▓▓██\n"
" _______██░░░░░░░░░░░░░██▓▓▓█\n"
" _______█░░░░░░░░░░░░░░█▓███\n"
" _______█░░░░░░░░░░░░░░████\n"
" _______█░░░░░░░░░░░░░░░█▓█▓█\n"
" _______██░░░░░░░░░░░░░████▓█\n"
" _______██░░░░░░░░░░░░░███▓▓█\n"
" _______█████░░░░░░░░░██▓▓██\n"
" ____█▓▓▓▓▓▓▓███░░░░░█▓▓▓██\n"
" __█▓▓░░░░░░░░░░█░░░██▓██\n"
" _█░░░░░░░░░░░░░░█░░░███\n"
" ██░░░░░░░░░░░░░░░█░░███\n"
" ██░░░░░░░░░░░░░░░░████\n"
" ██░░░░░░░░░░░░░░░░░██\n"
" ██░░░░░░░░░░░░░░░░░█░\n"
" _█░░░░░░░░░░░░░░░░░██\n"
" _██░░░░░░░░░░░░░░░█▓██\n"
" __██░░░░░░░░░░░░░█▓▓▓█\n"
" __██░░░░░░░░░░░░░█▓▓█\n"
" __█▓█░░░░░░░░░░░██▓█\n"
" ███░░██░░░░░░░░███░\n"
" █▓▓█░░░░░█░░░░░██▓█\n"
" █▓▓█████░░░░░░██▓▓█\n"
" _█▓▓█▓▓██░░░░░██▓▓█\n"
" _█▓▓▓▓▓██░░░░░░██▓█\n"
" __█▓▓█▓██░░░░░░░███\n";

// Function to convert an input string to a Cyberpunk style ASCII art
void toCyberpunkArt(char input[]) {
    int len = strlen(input);

    if (len > MAX_LEN) { // if input is too long, exit the function
        printf("Input is too long, please enter a string with max %d characters", MAX_LEN);
        return;
    }

    // Define the upscaled ASCII art properties
    int scale = 2;
    int artWidth = 48;
    int artHeight = 54;

    // Upscale the art
    char upscaledArt[artHeight * scale][artWidth * scale];
    for (int i = 0; i < artHeight; i++) {
        for (int j = 0; j < artWidth; j++) {
            char currentChar = cyberpunkArt[(i * artWidth) + j];
            for (int k = 0; k < scale; k++) {
                for (int l = 0; l < scale; l++) {
                    upscaledArt[(i * scale) + k][(j * scale) + l] = currentChar;
                }
            }
        }
    }

    // Print the upscaled ASCII art with the input string
    for (int i = 0; i < artHeight * scale; i++) {
        for (int j = 0; j < artWidth * scale; j++) {
            printf("%c", upscaledArt[i][j]);
        }

        if (i == artHeight / 2) { // Print the input string in the middle of the art
            printf("\t%s", input);
        }
        printf("\n");
    }
}

int main() {
    char input[MAX_LEN];
    printf("Enter a string with max %d characters: ", MAX_LEN);
    fgets(input, MAX_LEN, stdin);

    toCyberpunkArt(input);

    return 0;
}