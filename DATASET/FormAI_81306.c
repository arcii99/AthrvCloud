//FormAI DATASET v1.0 Category: Compression algorithms ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

void compress(char *str);

int main()
{
    char str[SIZE];
    printf("Enter the string: ");
    scanf("%[^\n]s", str);  //reads the string with spaces
    compress(str);  //calls the compression function
    return 0;
}

void compress(char *str)
{
    int count = 1, i, j;
    char compressed[SIZE];
    compressed[0] = str[0];  //stores the first character of the string in compressed array

    for (i = 1, j = 1; i < strlen(str); i++) {
        if (str[i] == str[i-1]) {  //if the characters are same
            count++;  //increment the count by 1
        } else {
            //otherwise add the count value and the character to the compressed array
            compressed[j] = count + '0'; 
            compressed[j+1] = str[i];
            count = 1;
            j += 2;  //increment the index of the compressed array
        }
    }
    //add the last character count and character to the compressed array
    compressed[j] = count + '0';
    compressed[j+1] = '\0'; //end the compressed array with null character
    printf("Compressed String: %s\n", compressed); //print the compressed string
}