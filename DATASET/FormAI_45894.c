//FormAI DATASET v1.0 Category: Text processing ; Style: Ken Thompson
#include<stdio.h>
#include<string.h>

int main() {

    char input[100], output[100];
    int i = 0, j = 0;

    printf("Enter a string: ");
    fgets(input, 100, stdin);

    while (input[i]) {
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') {
            input[i] = '\0';
        } else {
            output[j] = input[i];
            j++;
        }
        i++;
    }
    output[j] = '\0';

    printf("String with vowels removed: %s", output);

    return 0;
}