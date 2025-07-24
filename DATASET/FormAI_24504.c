//FormAI DATASET v1.0 Category: Recursive ; Style: irregular
#include <stdio.h>

int recursiveFunc(int num){
    if(num == 1){
        return 1;
    }
    else if(num % 2 == 0){
        printf("%d is even\n", num);
        return recursiveFunc(num/2);
    }
    else{
        printf("%d is odd\n", num);
        return recursiveFunc((3*num)+1);
    }
}

int main(){
    printf("Enter a number to start the chaotic recursion: ");
    int num;
    scanf("%d", &num);

    printf("Starting the exciting chaos...\n");

    int result = recursiveFunc(num);

    printf("Final result: %d\n", result);

    return 0;
}