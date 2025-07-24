//FormAI DATASET v1.0 Category: Pattern printing ; Style: detailed
#include<stdio.h>
int main(){
    int i,j,k;
    for(i=1;i<=7;i++){     //7 rows
        for(j=i;j<=7;j++)   //Printing spaces
            printf(" ");
        for(k=1;k<=i;k++)   //Printing stars
            printf("%d", k);
        for(k=i-1;k>=1;k--) //Printing stars in reverse order
            printf("%d", k);
        printf("\n");       //New line after every row
    }
    for(i=6;i>=1;i--){      //6 rows
        for(j=7;j>i;j--)   //Printing spaces
            printf(" ");
        for(k=1;k<=i;k++)   //Printing stars
            printf("%d", k);
        for(k=i-1;k>=1;k--) //Printing stars in reverse order
            printf("%d", k);
        printf("\n");      //New line after every row
    }
    return 0;
}