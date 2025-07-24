//FormAI DATASET v1.0 Category: String manipulation ; Style: bold
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    char result[200];
    int choice;
    printf("\nEnter first string: ");
    fgets(str1, 100, stdin);
    printf("\nEnter second string: ");
    fgets(str2, 100, stdin);
    str1[strcspn(str1, "\n")] = 0; //Removing newline character
    str2[strcspn(str2, "\n")] = 0; //Removing newline character

    printf("\nChoose operation:\n1. Concatenate the two strings\n2. Compare the two strings\n3. Reverse the first string\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            strcpy(result, str1);
            strcat(result, str2);
            printf("\nConcatenated string: %s\n", result);
            break;
        case 2:
            if(strcmp(str1, str2) == 0)
                printf("\nStrings are equal\n");
            else
                printf("\nStrings are not equal\n");
            break;
        case 3:
            int len = strlen(str1);
            for(int i=0; i<len/2; i++) {
                char temp = str1[i];
                str1[i] = str1[len-i-1];
                str1[len-i-1] = temp;
            }
            printf("\nReversed string: %s\n", str1);
            break;
        default:
            printf("\nInvalid choice!\n");
    }

    return 0;
}