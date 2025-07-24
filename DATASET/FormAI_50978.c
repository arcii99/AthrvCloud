//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: funny
#include<stdio.h>

int main(){

    printf("Welcome to the Geometree Program! \n");
    printf("Please enter the height of the tree: \n");
    int height;
    scanf("%d",&height);

    //Printing the trunk of the tree
    for(int i=0; i<height/2; i++){
        for(int j=0; j<height/2; j++)
            printf(" ");
        printf("||\n");
    }

    //Printing the branches of the tree
    for(int i=1; i<=height/2; i++){
        for(int j=height/2-i; j>=0; j--)
            printf(" ");
        for(int k=1; k<=2*i-1; k++)
            printf("*");
        printf("\n");
    }
    printf("Congratulations! You have successfully grown a geometric tree. \n");
    return 0;
}