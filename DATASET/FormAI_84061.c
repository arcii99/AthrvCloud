//FormAI DATASET v1.0 Category: Error handling ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void handle_error(char* error_msg, int error_code){
    printf("Error code %d: %s\n", error_code, error_msg);
    printf("Do you want to try again? (y/n):\n");
    char choice;
    scanf("%c", &choice);
    if(choice == 'y' || choice == 'Y'){
        printf("Retrying...\n");
        main();
    }
    else{
        printf("Exiting...\n");
        exit(0);
    }
}

int recursive_factorial(int num){
    if(num < 0){
        handle_error("Input cannot be negative", 1);
    }
    else if(num == 0){
        return 1;
    }
    else{
        return num * recursive_factorial(num-1);
    }
}

int main(){
    int num;
    printf("Enter a number to calculate factorial: ");
    scanf("%d", &num);
    int result = recursive_factorial(num);
    printf("%d! = %d\n", num, result);
    return 0;
}