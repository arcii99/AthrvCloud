//FormAI DATASET v1.0 Category: Word Count Tool ; Style: automated
#include <stdio.h>
#include <string.h>
#define MAX 1000

int main(){

    char string[MAX];
    int count=0, length;
    char split_char = ' ';
    int i;
    
    printf("Enter a string : ");
    fgets(string, sizeof(string), stdin); // Take input from user
    
    length = strlen(string);
    
    for(i=0;i<length;i++){
        if(string[i]==split_char){  // Loop through each character of the string
            count++;
        }
    }
    printf("Total number of words in the given string is : %d", count+1);
    return 0; // End of program
}