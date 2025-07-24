//FormAI DATASET v1.0 Category: Table Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This function prints the table
void printTable(int table[][4]) {
    printf("\n");

    for (int i = 0; i < 4; i++) {
        printf("|");
        
        for (int j = 0; j < 4; j++) {
            printf(" %2d |", table[i][j]);
        }
        
        printf("\n");
    }
}

// This function shuffles the table
void shuffleTable(int table[][4]) {
    srand(time(0));
    
    for(int i = 0; i < 16; i++) {
        int x1 = rand() % 4;
        int y1 = rand() % 4;
        int x2 = rand() % 4;
        int y2 = rand() % 4;
        int tmp = table[x1][y1];
        table[x1][y1] = table[x2][y2];
        table[x2][y2] = tmp;
    }
}

// This function checks if the table is solved
int isSolved(int table[][4]) {
    int cnt = 1;
    
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(cnt == 16) {
                return 1;
            }
            if(table[i][j] != cnt) {
                return 0;
            }
            cnt++;
        }
    }
    
    return 0;
}

int main() {
    // Initialize table
    int table[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0}
    };
    
    shuffleTable(table);
    
    while(!isSolved(table)) {
        printTable(table);
        
        int x1, y1, x2, y2;
        printf("Please enter first card's coordinates: ");
        scanf("%d %d", &x1, &y1);
        printf("Please enter second card's coordinates: ");
        scanf("%d %d", &x2, &y2);
        
        if(table[x1][y1] != table[x2][y2]) {
            printf("The cards do not match. Try again.\n");
            continue;
        }
        
        int tmp = table[x1][y1];
        table[x1][y1] = table[x2][y2];
        table[x2][y2] = tmp;
    }
    
    printf("\nCongratulations! You won the game.\n");
    
    return 0;
}