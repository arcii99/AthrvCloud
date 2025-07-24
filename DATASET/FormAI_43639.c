//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

int main() {
    char input[100], output[100];
    int i, k;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    for(i=0, k=0; input[i]!='\0'; i++) {
        if((input[i]>='A' && input[i]<='Z') || (input[i]>='a' && input[i]<='z') || (input[i]>='0' && input[i]<='9')) {
            output[k++] = input[i];
        }
    }

    output[k] = '\0';

    printf("Sanitized output: ");
    puts(output);

    return 0;
}