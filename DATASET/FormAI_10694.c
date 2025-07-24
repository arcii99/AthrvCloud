//FormAI DATASET v1.0 Category: Pattern printing ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

int main(){
    int size;
    printf("Enter the size of pattern: ");
    scanf("%d",&size);

    int n = (size/2)+1, x = 1, y = size-2;
    for(int i=1; i<=size; i++){
        for(int j=1; j<=size; j++){
            if(j>=n && j<=x) printf("* ");
            else if(j>=y && j<=size-n) printf("* ");
            else printf("  ");
        }
        if(i<=(size/2)) x++, y--;
        else x--, y++;
        printf("\n");
    }   
    return 0;
}