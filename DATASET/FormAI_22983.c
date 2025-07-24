//FormAI DATASET v1.0 Category: Text processing ; Style: peaceful
#include<stdio.h>
#include<string.h>

int main(){

    char str1[50], str2[50], res[100];

    printf("Enter the first string: ");
    fgets(str1, 50, stdin);  // Reading input string 1
    printf("Enter the second string: ");
    fgets(str2, 50, stdin);  // Reading input string 2

    // Removing newline characters from the strings
    int len1 = strlen(str1);
    if (str1[len1-1] == '\n'){
        str1[len1-1] = '\0';
    }
    int len2 = strlen(str2);
    if (str2[len2-1] == '\n'){
        str2[len2-1] = '\0';
    }

    // Concatenating the two strings with a space in between
    strcat(res, str1);
    strcat(res, " ");
    strcat(res, str2);

    printf("\nThe concatenated string is: %s\n", res);

    // Counting the number of words in the concatenated string
    int count = 1;
    for(int i=0; i<strlen(res); i++){
        if(res[i] == ' '){
            count++;
        }
    }
    printf("The number of words in the concatenated string is: %d\n", count);

    return 0;
}