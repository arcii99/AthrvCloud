//FormAI DATASET v1.0 Category: Recursive ; Style: happy
#include <stdio.h>

void happy(int n){
    if(n <= 0){
        printf("YAY, we're done being happy!\n");
    }
    else{
        printf("I am so happy! Counting down from %d...\n", n);
        happy(n-1);
    }
}

int main(){
    printf("Let's get happy!\n");
    happy(10);
    return 0;
}