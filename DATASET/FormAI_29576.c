//FormAI DATASET v1.0 Category: Recursive ; Style: lively
#include<stdio.h>

// function to draw a Christmas tree using recursion
void drawTree(int height, int space, int stars) {
    if(height < 1) return; // base case
    
    drawTree(height-1, space+1, stars-2); // recursive case 
    
    for(int i=0; i<space; i++) printf(" "); // print spaces for indentation
    for(int i=0; i<stars; i++) printf("*"); // print stars for tree branches
    printf("\n");
}

int main() {
    int height;
    printf("Enter the height of the Christmas tree: ");
    scanf("%d", &height);

    drawTree(height, 0, 1); // call the drawTree function
    
    return 0;
}