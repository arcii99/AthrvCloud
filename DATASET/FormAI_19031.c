//FormAI DATASET v1.0 Category: Pattern printing ; Style: energetic
#include <stdio.h>

int main() {
    int rows = 9;
    int cols = 10;
    
    printf("Let's print a fun C pattern!\n\n");

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(i==0 && (j==0 || j==1 || j==2 || j==3 || j==4 || j==5 || j==6 || j==7 || j==8)) {
                printf("*");
            } else if(i>0 && i<rows-1 && j==0) {
                printf("*");
            } else if(i==rows-1 && (j==0 || j==1 || j==2 || j==3 || j==4 || j==5 || j==6 || j==7 || j==8)) {
                printf("*");
            } else if(i==rows/2 && (j==1 || j==2 || j==3 || j==4)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}