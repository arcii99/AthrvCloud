//FormAI DATASET v1.0 Category: String manipulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i, j, k, l, m, n, o = 0;
    char input_str[1000], output_str[1000], alpha[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("Enter the input string: ");
    scanf("%s", input_str);
    l = strlen(input_str);
    //reverse the input string
    for (i = l - 1; i >= 0; i--) {
        output_str[o] = input_str[i];
        o++;
    }
    output_str[o] = '\0';
    printf("Reversed string: %s\n", output_str);
    //find the position of a character in the alphabet and replace it with the corresponding number
    for (i = 0; output_str[i] != '\0'; i++) {
        if (output_str[i] >= 'a' && output_str[i] <= 'z') {
            output_str[i] = output_str[i] - 'a' + 1 + '0';
        } else if (output_str[i] >= 'A' && output_str[i] <= 'Z') {
            output_str[i] = output_str[i] - 'A' + 27 + '0';
        }
    }
    printf("Numeric string: %s\n", output_str);
    //shift the digits to the right by one position
    m = strlen(output_str);
    n = output_str[m - 1];
    for (i = m - 2; i >= 0; i--) {
        k = output_str[i];
        output_str[i + 1] = k;
    }
    output_str[0] = n;
    printf("Shifted string: %s\n", output_str);
    //perform a Caesar cipher on the string
    for (i = 0; output_str[i] != '\0'; i++) {
        for (j = 0; j < 52; j++) {
            if (output_str[i] == alpha[j]) {
                int index = (j + 5) % 52;
                output_str[i] = alpha[index];
                break;
            }
        }
    }
    printf("Encrypted string: %s\n", output_str);
    return 0;
}