//FormAI DATASET v1.0 Category: Recursive ; Style: surprised
#include<stdio.h>

void magic(int x){
    if(x == 0){
        printf("What just happened?! I'm surprised!\n");
    }else{
        printf("I can't believe it! You entered %d\n", x);
        magic(x-1);
    }
}

int main(){
    int num;
    printf("Enter a number, any number: ");
    scanf("%d", &num);
    printf("Here we go...\n");
    magic(num);
    printf("Wow! That was amazing!");
    return 0;
}