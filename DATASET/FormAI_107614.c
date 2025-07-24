//FormAI DATASET v1.0 Category: Pattern printing ; Style: minimalist
#include <stdio.h>

void print_space(int spaces) {
    for(int i=0;i<spaces;i++) {
        printf(" ");
    }
}

int main() {
    int size = 10; // size of the pattern
    int spaces = size; 
    int stars = 1;

    // upper half
    for(int i=0;i<size/2+1;i++) {
        print_space(spaces);
        for(int j=0;j<stars;j++) {
            printf("*");
        }
        printf("\n");
        spaces--;
        stars+=2;
    }

    spaces=0;
    stars-=4;

    // lower half
    for(int i=0;i<size/2;i++) {
        spaces++;
        print_space(spaces);
        for(int j=0;j<stars;j++) {
            printf("*");
        }
        printf("\n");
        stars-=2;
    }
    return 0;
}