//FormAI DATASET v1.0 Category: Pattern printing ; Style: careful
#include <stdio.h>

int main() {
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    int space=rows-1;
    int num=1;
    for(int i=0; i<rows; i++){
        for(int j=0; j<space; j++){
            printf(" ");
        }
        space--;
        for(int j=0; j<num; j++){
            printf("%d",j+1);
        }
        num+=2;
        printf("\n");
    }
    space=1;
    num-=4;
    for(int i=0; i<rows-1; i++){
        for(int j=0; j<space; j++){
            printf(" ");
        }
        space++;
        for(int j=0; j<num; j++){
            printf("%d",j+1);
        }
        num-=2;
        printf("\n");
    }   
    return 0;
}