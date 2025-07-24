//FormAI DATASET v1.0 Category: Data mining ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Creating a dataset for data mining
    int dataset[10][3] = {{1, 2, 1}, {2, 1, 0}, {1, 1, 1}, {0, 1, 0}, {3, 1, 1}, 
                          {0, 1, 1}, {1, 0, 0}, {1, 3, 0}, {2, 2, 1}, {3, 1, 0}};
                            
    // Calculating the total number of rows and columns
    int rows = sizeof(dataset) / sizeof(dataset[0]);
    int columns = sizeof(dataset[0]) / sizeof(int);
    
    // Creating an array to keep track of the count of each attribute in the dataset
    int counts[columns][2];
    
    // Initializing the counts array to 0
    for(int i = 0; i < columns; i++) {
        counts[i][0] = 0;
        counts[i][1] = 0;
    }
    
    // Counting the number of 0s and 1s for each attribute
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(dataset[i][j] == 0) {
                counts[j][0]++;
            } else if(dataset[i][j] == 1) {
                counts[j][1]++;
            }
        }
    }
    
    // Displaying the count of each attribute
    for(int i = 0; i < columns; i++) {
        printf("Attribute %d:\n", i+1);
        printf("0s: %d\n", counts[i][0]);
        printf("1s: %d\n", counts[i][1]);
    }
    
    return 0;
}