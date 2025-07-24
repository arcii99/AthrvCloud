//FormAI DATASET v1.0 Category: Recursive ; Style: immersive
#include <stdio.h>

void recursive_function(int num){
    if(num == 0){
        printf("The recursion has ended successfully!\n");
        return;
    }
    else{
        printf("The recursive function is called with parameter %d.\n",num);
        recursive_function(num-1);
    }
}

int main(){
    int input;
    printf("Please enter an integer value: ");
    scanf("%d",&input);
    recursive_function(input);
    return 0;
}