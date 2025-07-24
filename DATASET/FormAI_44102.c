//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multivariable
#include<stdio.h>
#define ROW 5
#define COL 5

void search(int arr[ROW][COL], int key);

int main() {
    int arr[ROW][COL] = { {1, 4, 7, 8, 10},
                        {12, 13, 18, 20, 25},
                        {30, 40, 49, 50, 55},
                        {60, 65, 70, 75, 80},
                        {85, 90, 95, 100, 105} };
                        
    int key = 70;
    
    search(arr, key);
    
    return 0;
}

void search(int arr[ROW][COL], int key) {
    int i = 0, j = COL-1;
    
    while(i<ROW && j>=0) {
        if(arr[i][j] == key) {
            printf("Key found at position (%d,%d)", i+1, j+1);
            return;
        }
        else if(arr[i][j] > key)
            j--;
        else
            i++;
    }
    printf("Key not found.");
}