//FormAI DATASET v1.0 Category: Pattern printing ; Style: secure
#include<stdio.h>
#include<string.h>

int main(){

// Declare variables
int i, j, row;

// Get input from user
printf("Enter the number of rows: ");
scanf("%d", &row);

// Make sure input is within range
while(row <= 0){
    printf("Invalid input, please enter a positive integer greater than 0: ");
    scanf("%d", &row);
}

// Print C pattern
for(i=1;i<=row;i++){
    for(j=1;j<=row;j++){
        if(i==1 || i==row || j==1){
            printf("*");
        }
        else{
            printf(" ");
        }
    }
    printf("\n");
}

return 0;

}