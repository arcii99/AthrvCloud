//FormAI DATASET v1.0 Category: Arithmetic ; Style: minimalist
#include <stdio.h>

int main()
{
    int i, j;
    int table_size = 12; //Change this variable to change the size of the table

    printf("Multiplication Table:\n\n");

    for(i = 1; i <= table_size; i++) {
        for(j = 1; j <= table_size; j++) {
            printf("%d ", i*j); //Print the result of the multiplication
        }
        printf("\n"); //Move to the next line after each row
    }

    return 0;
}