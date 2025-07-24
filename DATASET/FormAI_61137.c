//FormAI DATASET v1.0 Category: Graph representation ; Style: genious
#include<stdio.h>

// Function to print rows of graph
void printRow(int num, int count) {
    for(int i=1; i<=num; i++) {
        // Handle middle row
        if(i == num/2 + 1) {
            printf("|");
            for(int j=1; j<=count; j++) printf("X");
            printf("|");
        }
        // Print empty spaces
        else {
            printf("|");
            for(int j=1; j<=count; j++) printf(" ");
            printf("|");
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Get input from user
    int num, count;
    printf("Enter the number of rows: ");
    scanf("%d", &num);
    printf("Enter the number of columns for each row: ");
    scanf("%d", &count);
    
    // Print top row
    printf("+");
    for(int i=1; i<=count*num; i++) {
        printf("-");
    }
    printf("+\n");
    
    // Print middle rows
    printRow(num, count);
    
    // Print bottom row
    printf("+");
    for(int i=1; i<=count*num; i++) {
        printf("-");
    }
    printf("+\n");
    
    return 0;
}