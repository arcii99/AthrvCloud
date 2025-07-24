//FormAI DATASET v1.0 Category: Pattern printing ; Style: recursive
#include <stdio.h>

void printPattern(int n, int currRow, int currCol, int num) {
    if(currRow == n) return; // base case
    
    if(currCol == currRow) { // move to next row
        printf("\n");
        printPattern(n, currRow+1, 0, 1);
        return;
    }
    
    printf("%d", num);
    if(num == 0) { // increment or decrement based on current value
        printPattern(n, currRow, currCol+1, 1);
    } else {
        printPattern(n, currRow, currCol+1, 0);
    }
}

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printPattern(n, 0, 0, 0);
    return 0;
}