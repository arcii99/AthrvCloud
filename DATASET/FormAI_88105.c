//FormAI DATASET v1.0 Category: Recursive ; Style: content
#include<stdio.h>
void printStars(int n); // Function declaration

int main(){
    int n;
    printf("Enter the number of stars you want to print: ");
    scanf("%d",&n);
    printf("Printing %d stars using recursion: \n",n);
    printStars(n);
    return 0;
}

// Recursive function to print stars
void printStars(int n){
    if(n==0) // Base case
        return;
    printStars(n-1);  // Recursive call
    printf("* ");
}