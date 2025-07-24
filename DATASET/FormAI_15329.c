//FormAI DATASET v1.0 Category: Funny ; Style: grateful
#include<stdio.h>

int main(){
    // A simple program that prints "Thank you" in a fun way.
    // Written with gratitude for the opportunity to learn and grow as a programmer.

    int i,j;
    char* s = "Than";
    char* t = "k yo";
    char* u = "u";

    printf("\n");
    printf("\t");
    for (i=0; i<4; i++){
        for (j=0; j<=i; j++){
            printf("%c",*(s+j));
        }
    }
    printf("\n");

    printf("\t");
    for (i=0; i<3; i++){
        printf("%c",*(t+i));
    }
    printf("\n");

    printf("\t");
    printf("%s",u);
    printf("\n");

    printf("\t");
    printf("For giving me the chance to learn and program\n");
    printf("\n");

    return 0;
}