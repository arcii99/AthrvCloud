//FormAI DATASET v1.0 Category: Recursive ; Style: introspective
#include<stdio.h>

//introducing the function 
void recursiveFunction(int x){
    printf("I am a recursive function with an input value of %d\n", x);
    if(x>0){
        printf("I am entering into a recursive call with %d-1 = %d\n", x,x-1);
        recursiveFunction(x-1); //recursive call
        printf("I am out of the recursive call with %d-1 = %d\n", x,x-1);
    }
    else{
        printf("Base condition reached. I will not make any further recursive calls.\n");
    }
}

int main(){
    printf("Hello! I am an introspective program demonstrating the use of recursion.\n");
    printf("I am going to call a recursive function now.\n");
    recursiveFunction(5); //calling the recursive function
    printf("That's all folks!\n");
    return 0;
}