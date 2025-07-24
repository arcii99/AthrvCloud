//FormAI DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], str3[100];
    int option, len;

    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Choose an option\n");
    printf("1. To reverse the string\n");
    printf("2. To remove spaces from string\n");
    scanf("%d", &option);

    switch(option) {
        case 1: 
            len = strlen(str1) - 1;
            for(int i = 0; i < len/2; i++) {
                char temp = str1[i];
                str1[i] = str1[len - i - 1];
                str1[len - i - 1] = temp;
            }
            printf("Reversed string: %s", str1);
            break;

        case 2:
            len = strlen(str1);
            int index = 0;
            for(int i = 0; i < len; i++) {
                if(str1[i] != ' ') {
                    str2[index] = str1[i];
                    index++;
                }
            }
            str2[index] = '\0';
            printf("String without spaces: %s", str2);
            break;

        default: 
            printf("Invalid option");
            break;
    }

    return 0;
}