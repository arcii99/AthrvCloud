//FormAI DATASET v1.0 Category: Pattern printing ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Let's make a C pattern!\n");
    int i, j, k, l;

    // generate the top half of the pattern
    for(i=0; i<=3; i++) {
        for(j=0; j<=3-i; j++){
            printf(" ");
        }
        for(k=1; k<=2*i+1; k++){
            printf("C");
        }
        printf("\n");
    }

    // generate the bottom half of the pattern
    for(i=2; i >= 0; i--){
        for(j=0; j<=3-i; j++){
            printf(" ");
        }
        for(k=1; k<=2*i+1; k++){
            printf("C");
        }
        printf("\n");
    }

    printf("Yay, we made a C pattern! :)\n");
    return 0;
}