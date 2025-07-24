//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: careful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertToHex(char* input, char* output) {
    int length = strlen(input);
    char hex[16] = "0123456789ABCDEF";
    for(int i=0; i<length; i++) {
        if(isdigit(input[i])) {
            output[i*2] = hex[input[i]-'0'];
        } else {
            output[i*2] = hex[input[i]-'a'+10];
        }
        output[i*2+1] = ' ';
    }
}

int main() {
    char input[100];
    char output[200];

    printf("Enter an input string: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;

    convertToHex(input, output);

    printf("Hexadecimal format: %s", output);

    return 0;
}