//FormAI DATASET v1.0 Category: Recursive ; Style: intelligent
#include <stdio.h>

void printNums(int num) {
    
    if(num == 0) { // base case
        printf("Done!\n");
        return;
    }
    
    else {
        printf("Number: %d\n", num);
        printNums(num - 1); // recursive call
    }
}

int main() {
    int n = 10;
    
    printf("Printing recursively from %d to %d:\n", n, 1);
    printNums(n);
    
    return 0;
}