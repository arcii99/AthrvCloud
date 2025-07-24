//FormAI DATASET v1.0 Category: Syntax parsing ; Style: multiplayer
#include <stdio.h>
#include <string.h>

// Define the maximum input size for our program
#define MAX_INPUT_SIZE 256

// Define the maximum number of players
#define MAX_PLAYERS 4

// Define a custom strtok function that takes into consideration multiple delimiters
char* strtok2(char* str, const char* delimiters) {
    static char* p = NULL; // Static variable to hold pointer between calls
    if (str != NULL) p = str; // If str is not NULL, set p to point to it
    if (p == NULL) return NULL; // If p is still NULL, return NULL
    char* start = p; // Set start to be the current value of p
    char* end = strpbrk(p, delimiters); // Find the first occurrence of a delimiter in p
    if (end != NULL) *end++ = '\0'; // If a delimiter was found, set it to be a NULL char and move the pointer
    p = end; // Set p to point to the next non-delimiter character
    return start; // Return the start of the token
}

int main() {
    // Define variables to hold input and tokens
    char input[MAX_INPUT_SIZE];
    char* tokens[MAX_INPUT_SIZE];

    // Define the players array
    int players[MAX_PLAYERS] = {0};

    // Loop indefinitely to keep accepting input
    while (1) {
        // Print a prompt to the user
        printf("Enter a C statement or 'exit' to quit: ");

        // Get the user input and remove the newline character
        fgets(input, MAX_INPUT_SIZE, stdin);
        input[strcspn(input, "\n")] = '\0';

        // If the user wants exit, break out of the loop
        if (strcmp(input, "exit") == 0) break;

        // Tokenize the input using our custom strtok function
        int num_tokens = 0;
        for (char* token = strtok2(input, " \t\n"); token != NULL; token = strtok2(NULL, " \t\n")) {
            tokens[num_tokens++] = token;
        }

        // Placeholder logic to parse and process the input
        if (num_tokens > 0) {
            for (int i = 0; i < num_tokens; i++) {
                if (strcmp(tokens[i], "player") == 0) {
                    if (i+1 < num_tokens) {
                        int player_num = atoi(tokens[i+1]);
                        if (player_num > 0 && player_num <= MAX_PLAYERS) {
                            players[player_num-1]++;
                        }
                    }
                }
            }
        }

        // Print the current state of the players array
        printf("Current player scores: ");
        for (int i = 0; i < MAX_PLAYERS; i++) {
            printf("%d ", players[i]);
        }
        printf("\n");
    }

    return 0;
}