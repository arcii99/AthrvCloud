//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <string.h>

void sanitize(char input[50]){
    int i, j=0;
    char temp[50];

    for(i=0;input[i]!='\0';i++){
        // Check if input character is alphanumeric or a space
        if(isalnum(input[i]) || input[i]==' '){
            temp[j] = input[i];
            j++;
        }
    }

    temp[j] = '\0'; // Add null character at the end of sanitized string
    strcpy(input, temp); // Copy sanitized string back to original input string
}

int main(){
    char player1_input[50], player2_input[50];

    printf("Welcome to Sanitize It! A multiplayer input sanitizer game.\n\n");
    printf("Player 1 enter your input (less than 50 characters): ");
    fgets(player1_input, 50, stdin);
    sanitize(player1_input);

    printf("Player 2 enter your input (less than 50 characters): ");
    fgets(player2_input, 50, stdin);
    sanitize(player2_input);

    printf("\nPlayer 1's sanitized input: %s\n", player1_input);
    printf("Player 2's sanitized input: %s\n", player2_input);

    return 0;
}