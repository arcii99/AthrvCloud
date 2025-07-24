//FormAI DATASET v1.0 Category: Pattern printing ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the world of C pattern printing!\n");
    int size, num=1;
    printf("Enter the size of the pattern you want to print: ");
    scanf("%d", &size);
    if(size<1) {
        printf("Size cannot be less than 1! Better luck next time!\n");
        exit(0);
    }
    printf("\n");

    for(int i=1;i<=size;i++) {
        for(int j=i;j<=size;j++) {
            printf("* ");
        }
        if(num==1) {
            printf("404 pattern not found\n\n");
            num++;
        } else if(num==2) {
            printf("... loading ...\n\n");
            num++;
        } else if(num==3) {
            printf("Aborting...\n\n");
            num++;
            break;
        } else {
            printf("Too many errors, exiting for your safety...\n\n");
            exit(0);
        }
    }
    printf("Goodbye! Thank you for using C pattern printing!\n");
    return 0;
}