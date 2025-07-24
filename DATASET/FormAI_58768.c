//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_PLAYERS 5

void sanitize_input(char* input) {
    int len = strlen(input);
    
    for(int i = 0; i < len; i++) {
        if(input[i] == '<' || input[i] == '>') {
            input[i] = '-';
        }
    }
}

int main() {
    char player_names[MAX_PLAYERS][MAX_NAME_LEN];
    int num_players = 0;
    
    printf("Welcome to the Multiplayer Input Sanitizer Game!\n");
    
    while(num_players < MAX_PLAYERS) {
        char name[MAX_NAME_LEN];
        printf("Enter name for player #%d: ", num_players+1);
        fgets(name, MAX_NAME_LEN, stdin);
        
        sanitize_input(name);
        
        if(strcmp(name, "\n") == 0) {
            break;
        }
        
        strcpy(player_names[num_players], name);
        num_players++;
    }
    
    printf("\nSanitized Player Names:\n");
    
    for(int i = 0; i < num_players; i++) {
        printf("%d. %s", i+1, player_names[i]);
    }
    
    return 0;
}