//FormAI DATASET v1.0 Category: Error handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define maximum length for input string
#define MAX_LENGTH 100

int main(){
    //declare variables
    char str[MAX_LENGTH];
    int num;
    //prompt user for input
    printf("Enter a number between 1 and 10: ");
    fgets(str, MAX_LENGTH, stdin);
    //convert input to integer
    num = atoi(str);
    //check if input is within range
    if(num<1 || num>10){
        fprintf(stderr, "Error: Number not within range.\n");
        exit(1);
    }
    //if input is within range, print success message
    printf("Success: Number entered is %d\n", num);
    return 0;
}