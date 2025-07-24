//FormAI DATASET v1.0 Category: Text processing ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]%*c", str);
    printf("\nInput string: %s\n", str);

    printf("\nProcessing the string. Please wait!");
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        if(str[i] == ' ') {
            printf("%c", str[i]);
        }
        else {
            printf("%c", str[i]+1);
        }
    }
    printf("\nWow, the string now looks like this. Boom!");

    return 0;
}