//FormAI DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main() 
{
    int n, i, j;
    char name[20], index[MAX][20], temp[20];
    
    // Get the number of names to be indexed
    printf("Enter number of names to be indexed: ");
    scanf("%d", &n);

    // Get the names from the user and add them to the index
    printf("\nEnter the names to be indexed:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", name);
        
        // Add the name to the index
        for (j = 0; j < strlen(name); j++) {
            index[i][j] = name[j];
        }
        index[i][j] = '\0'; // Add null terminator to the end of the string
    }
    
    // Sort the index using bubble sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(index[j], index[j + 1]) > 0) {
                // Swap the two names
                strcpy(temp, index[j]);
                strcpy(index[j], index[j + 1]);
                strcpy(index[j + 1], temp);
            }
        }
    }
    
    // Print the sorted index
    printf("\nIndex:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", index[i]);
    }
    
    return 0;
}