//FormAI DATASET v1.0 Category: Pattern printing ; Style: recursive
#include<stdio.h>

void C(int n, int m, int x, int y){

    if(n == 0) return;

    //print upper horizontal line
    if(n == x && m != 0){
        printf("*");
        C(n, m-1, x, y+1);
    }
    //print left vertical line
    else if(m == 0 && n<=x){
        printf("*");
        printf("\n");
        C(n-1, 0, x, y);
    }
    //print bottom horizontal line
    else if(n == 1 && m < y){
        printf("*");
        C(n, m+1, x, y);
    }
    //print right vertical line
    else if(m == y){
        printf("*");
        printf("\n");
        if(n > 1) C(n-1, 0, x, y);
    }
    //print empty spaces
    else{
        printf(" ");
        C(n, m+1, x, y);
    }
}

int main(){
    int n;
    printf("Enter size of C pattern: ");
    scanf("%d", &n);
    printf("\n");

    //check if n is even
    if(n%2 == 0) n--;

    C(n, 0, n/2 + 1, n/2 + 1);

    return 0;
}