//FormAI DATASET v1.0 Category: Pattern printing ; Style: happy
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Hello, this is a happy C pattern printer!\n");

    //loop through rows
    for(int i=1; i<=10; i++){
        //loop through columns
        for(int j=1;j<=10;j++){
            if(i==j){
                printf(":-) "); //happy face
            }
            else if((i+j)%2==0){
                printf("* "); //star for even numbers
            }
            else{
                printf("+ "); //plus sign for odd numbers
            }
        }
        printf("\n"); //move to the next row
    }
    printf("\n");

    //loop through rows
    for(int i=1; i<=10; i++){
        //loop through spaces
        for(int k=10;k>i;k--){
        printf(" "); //print space
        }
        //loop through columns
        for(int j=1;j<=i;j++){
            printf("%d ",i); //print row number
        }
        printf("\n"); //move to the next row
    }
    printf("\n");

    printf("Thank you for using our happy C pattern printer!\n");

    return 0;
}