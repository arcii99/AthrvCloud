//FormAI DATASET v1.0 Category: Pattern printing ; Style: energetic
#include<stdio.h>
void main() {
    int n = 7; //Declaring integer variable and initializing it to 7
    int i,j; //Declaring integer variables
    for(i=0 ; i<=n ; i++) { //Outer loop to iterate rows
        for(j=0 ; j<=n-i ; j++) { 
            printf(" "); //Printing spaces
        }
        for(j=0 ; j<=i ; j++) {
            printf("%c ",'C'-j); //Printing characters in pattern
        }
        printf("\n"); //Printing new line
    }
    for(i=1 ; i<=n ; i++) { //Outer loop to iterate rows
        for(j=0 ; j<=i ; j++) {
            printf(" "); //Printing spaces
        }
        for(j=0 ; j<=n-i ; j++) {
            printf("%c ",'C'-j); //Printing characters in pattern
        }
        printf("\n"); //Printing new line
    }
}