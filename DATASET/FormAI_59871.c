//FormAI DATASET v1.0 Category: Data mining ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

#define MAX_ROW 4
#define MAX_COL 5

int main() {
    int i, j, max_index = -1, min_index = -1;
    float max_value = -9999.99, min_value = 9999.99, data[MAX_ROW][MAX_COL];

    // Input the data
    for(i=0; i<MAX_ROW; i++) {
        printf("\nEnter the data for row %d\n", i+1);
        for(j=0; j<MAX_COL; j++) {
            scanf("%f", &data[i][j]);
        }
    }

    // Find the maximum and minimum value and their indices
    for(i=0; i<MAX_ROW; i++) {
        for(j=0; j<MAX_COL; j++) {
            if(data[i][j] > max_value) {
                max_value = data[i][j];
                max_index = i*MAX_COL + j;  // Flattening the 2D array to 1D array index
            }
            if(data[i][j] < min_value) {
                min_value = data[i][j];
                min_index = i*MAX_COL + j;  // Flattening the 2D array to 1D array index
            }
        }
    }

    // Print the data in a tabular form
    printf("\nThe data entered is:\n");
    for(i=0; i<MAX_ROW; i++) {
        for(j=0; j<MAX_COL; j++) {
            printf("%.2f\t", data[i][j]);
        }
        printf("\n");
    }

    // Print the maximum and minimum value and their indices
    printf("\nMaximum value: %.2f, Index: (%d, %d)\n", max_value, max_index/MAX_COL+1, max_index%MAX_COL+1);
    printf("Minimum value: %.2f, Index: (%d, %d)\n", min_value, min_index/MAX_COL+1, min_index%MAX_COL+1);

    return 0;
}