//FormAI DATASET v1.0 Category: Database querying ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /* Initializing database */
    int n = 5; /* number of rows in database */
    char** table = (char**)malloc(n * sizeof(char*));
    for(int i=0; i<n; i++) {
        table[i] = (char*)malloc(20 * sizeof(char));
    }
    strcpy(table[0], "1. Today");
    strcpy(table[1], "2. Is");
    strcpy(table[2], "3. A");
    strcpy(table[3], "4. Great");
    strcpy(table[4], "5. Day");
    
    /* User input */
    printf("Enter query: ");
    char query[20];
    fgets(query, 20, stdin);
    strtok(query, "\n");
    
    /* Cryptic querying */
    int index = -1;
    for(int i=0; i<n; i++) {
        char* token = strtok(table[i], " ");
        if(strcmp(token, query) == 0) {
            index = i;
        }
    }
    
    if(index == -1) {
        printf("Data not found\n");
    } else {
        printf("Result: %s\n", table[index]);
    }
    
    /* Cleaning up */
    for(int i=0; i<n; i++) {
        free(table[i]);
    }
    free(table);
    
    return 0;
}