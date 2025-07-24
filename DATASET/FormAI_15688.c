//FormAI DATASET v1.0 Category: String manipulation ; Style: content
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char *str1, *str2;
    int len1, len2;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    //Concatenation of strings
    strcat(str1, str2);
    printf("Concatenation: %s\n", str1);

    //Copy string1 into string2
    strcpy(str2, str1);
    printf("Copy: %s\n", str2);

    //Finding the length of both strings
    len1 = strlen(str1);
    len2 = strlen(str2);
    printf("Length of string1: %d\n", len1);
    printf("Length of string2: %d\n", len2);

    //Freeing the dynamically allocated memory
    free(str1);
    free(str2);

    return 0;
}