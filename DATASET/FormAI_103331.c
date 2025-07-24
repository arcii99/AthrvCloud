//FormAI DATASET v1.0 Category: Text processing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    char str1[100], str2[100], str3[100], str4[100], str5[100]; //Declare variables for input strings
    char temp[100];

    printf("Enter a string: ");
    scanf("%s", str1); //Read input

    printf("Enter another string: ");
    scanf("%s", str2); //Read input

    printf("Enter a third string: ");
    scanf("%s", str3); //Read input

    printf("Enter a fourth string: ");
    scanf("%s", str4); //Read input

    printf("Enter a fifth string: ");
    scanf("%s", str5); //Read input

    //Swap str1 and str3
    strcpy(temp, str1);
    strcpy(str1, str3);
    strcpy(str3, temp);

    //Append str2 to str4
    strcat(str4, str2);

    //Find length of str5
    int len = strlen(str5);

    //Print the modified strings
    printf("\nModified strings: \n");
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("String 3: %s\n", str3);
    printf("String 4: %s\n", str4);
    printf("String 5 length: %d\n", len);

    return 0;
}