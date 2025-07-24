//FormAI DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>

int recursive_joke(int a, int b){
    if(a<0 || b<0){
        printf("No negative numbers allowed, please try again\n");
        return 0;
    }
    else if(a == 0){
        printf("First number is 0, answer is 0 (why did you even bother)\n");
        return 0;
    }
    else if(b == 0){
        printf("Second number is 0, answer is 0 (you're multiplying by nothing)\n");
        return 0;
    }
    else if(b == 1){
        printf("Second number is 1, answer is %d (why did you need a calculator for this)\n", a);
        return a;
    }
    else{
        printf("Thinking...\n");
        return a + recursive_joke(a, b-1);
    }
}

int main(){
    int first, second, answer;
    printf("Welcome to Multiplication with a Recursive Twist!\n");
    printf("Enter two numbers to be multiplied: ");
    scanf("%d%d", &first, &second);
    answer = recursive_joke(first, second);
    printf("The answer is %d!\n", answer);
    printf("Thanks for playing, did we make you laugh?\n");
    return 0;
}