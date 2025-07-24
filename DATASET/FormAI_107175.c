//FormAI DATASET v1.0 Category: Text processing ; Style: puzzling
#include<stdio.h>

int main(){
    char str[100];
    printf("Enter the puzzle: ");
    fgets(str, 100, stdin); // fgets() used to read string from input
    
    int len=0;
    while(str[len]!='\n'){ // count the string length
        len++;
    }
    
    int idx=0;
    while(idx<len){ // loop through the string
        if(str[idx]>='a' && str[idx]<='z'){ // check for lower case letters
            printf("%c", str[idx]-32); // convert to upper case
            idx++;
        }
        else if(str[idx]>='A' && str[idx]<='Z'){ // check for upper case letters
            printf("%c", str[idx]+32); // convert to lower case
            idx++;
        }
        else if(str[idx]>='0' && str[idx]<='9'){ // check for numbers
            printf("%d", str[idx]-'0'); // convert from character to integer
            idx++;
        }
        else{ // any other character is printed as it is
            printf("%c", str[idx]);
            idx++;
        }
    }
    printf("\n");
    return 0;
}

/*Sample Input:
Enter the puzzle: hElLo 123!@#

Sample Output:
HeLlO 246!@#
*/