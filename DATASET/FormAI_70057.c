//FormAI DATASET v1.0 Category: Pattern printing ; Style: dynamic
#include<stdio.h>

int main(){

    int length = 5; // length of the pattern
    int outerSpace = length;  // initialize the number of spaces to be printed in each row
    int innerSpace = 0;  // initialize the number of spaces to be printed in each row
    int i,j,k,p;  // loop counters

    // First half of the pattern
    for(i=0; i<length; i++){
        
        // print outer space
        for(k=0; k<outerSpace; k++){
             printf(" ");
        }
        
        // print pattern
        for(j=0; j<=i; j++){
             printf("* ");
        }
        
        // print inner space
        for(p=0; p<innerSpace; p++){
             printf(" ");
        }
        
        // print pattern
        for(j=0; j<=i; j++){
             printf("* ");
        }

        // print new line
        printf("\n");

        // update outer and inner space
        outerSpace--;
        innerSpace += 2;
    }

    // second half of the pattern
    outerSpace = 1;  // reset the outer space counter
    innerSpace = 2 * length - 4; // reset the inner space counter

    for(i=0; i<length-1; i++){

        // print outer space
        for(k=0; k<outerSpace; k++){
             printf(" ");
        }

        // print pattern
        for(j=length-i-1; j>0; j--){
             printf("* ");
        }

        // print inner space
        for(p=0; p<innerSpace; p++){
             printf(" ");
        }

        // print pattern
        for(j=length-i-1; j>0; j--){
             printf("* ");
        }

        // print new line
        printf("\n");

        // update outer and inner space
        outerSpace++;
        innerSpace -= 2;
    }

    return 0;
}