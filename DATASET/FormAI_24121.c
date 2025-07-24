//FormAI DATASET v1.0 Category: Pattern printing ; Style: surprised
#include<stdio.h>
int main(){
    printf("Oh boy, prepare to be amazed!\n");
    printf("Behold the magic of a C Pattern printing program!\n");
    printf("This program will print an epic pattern on the screen!\n");
    printf("Sit back, relax and enjoy the show!\n");

    int n;
    printf("Enter the number of lines you want in the pattern: ");
    scanf("%d", &n);

    printf("\n\n");

    int i, j, k;
    for(i=0; i<=4*n; i++){
        
        for(j=0; j<=4*n; j++){
            if((i<=n && (j==n-i || j==n+i)) || ((i>n && i<3*n) && (j==n || j==3*n)) || (i>=3*n && (j==i-2*n || j==6*n-i))){
                printf("*");
            }
            else if((i<=n && j>n-i && j<n+i) || (i>=3*n && j<i-2*n) || ((i>n && i<3*n) && (j<n || j>3*n))){
                printf("+");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("Wasn't that amazing?! I hope you're as impressed as I am!\n");
    return 0;
}