//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: real-life
#include <stdio.h>
#include <string.h>

int main(){
    char string[100];
    int length, i, j, flag = 0;
    printf("Enter a string: ");
    scanf("%s", string);
    length = strlen(string);

    // Checking if the string is a palindrome or not
    for(i=0,j=length-1;i<j;i++,j--) {
        if(string[i]!=string[j]) {
            flag = 1;
            break;
        }
    }

    // Displaying the results
    if(flag==1) {
        printf("%s is not a palindrome.\n", string);
    } else {
        printf("%s is a palindrome.\n", string);
    }

    return 0;
}