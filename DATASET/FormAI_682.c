//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Cryptic
#include<stdio.h>

int main(){
    int x=10,y=5;
    printf("x=%d, y=%d\n",x,y);
    x=x^y;
    y=y^x;
    x=x^y;
    printf("After swapping\nx=%d, y=%d",x,y);
    return 0;
}