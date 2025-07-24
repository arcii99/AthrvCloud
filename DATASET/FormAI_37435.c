//FormAI DATASET v1.0 Category: Pattern printing ; Style: standalone
#include <stdio.h>

int main() {
    int size, i, j, k;

    printf("Enter the size of the pattern (odd number):\n");
    scanf("%d", &size);

    if(size%2 == 0){
        printf("Please enter an odd number.\n");
        return 0;
    }

    for(i=1; i<=size; i++) {
        if(i <= (size+1)/2) {
            for(k=1; k<=i; k++) {
                printf("*");
            }
            for(j=(size-2*i); j>=1; j--) {
                printf(" ");
            }
            for(k=1; k<=i; k++) {
                printf("*");
            }
        }
        else {
            for(k=i; k<=size; k++) {
                printf("*");
            }
            for(j=2*(i-(size+1)/2); j>=1; j--) {
                printf(" ");
            }
            for(k=i; k<=size; k++) {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}