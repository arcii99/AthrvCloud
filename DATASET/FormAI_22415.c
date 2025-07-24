//FormAI DATASET v1.0 Category: Pattern printing ; Style: mind-bending
#include <stdio.h>

int main() {
    
    int rows;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    
    int i, j;
    for (i = 1; i <= rows; i++) {
        
        for (j = 1; j <= rows; j++) {
            
            //mind-bending conditional statements
            if ((i == 1 || i == rows) && (j == 1 || j == rows))
                printf("+");
            
            else if (i == 1 || i == rows)
                printf("-");
            
            else if (j == 1 || j == rows)
                printf("|");
            
            else if (i == j)
                printf("\\");
            
            else if (j == (rows - i + 1))
                printf("/");
            
            else
                printf("*");
        }
        printf("\n");
    }
    return 0;
}