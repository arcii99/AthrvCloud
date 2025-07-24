//FormAI DATASET v1.0 Category: Database querying ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to get user input for searching the database
void get_search_query(char query[]) {
    printf("Enter the name to search in database: ");
    fgets(query, 20, stdin);
    query[strlen(query) - 1] = '\0'; // Removing the trailing newline character
}

int main() {
    // Initializing the database with some data
    char database[5][20] = {"Alice", "Bob", "Chris", "David", "Emma"};

    // Variables for holding the database search query and result
    char search_query[20];
    int result_index = -1;

    while(1) {  // The game loop
        // Get the user's search query
        get_search_query(search_query);

        // Searching the database for the query
        for(int i=0; i<5; i++) {
            if(strcmp(database[i], search_query) == 0) {
                result_index = i;
                break;
            }
        }

        // Printing the search result to all the players
        printf("The search for '%s' returned %s.\n", search_query, (result_index == -1 ? "no results" : "a match"));
    }

    return 0;
}