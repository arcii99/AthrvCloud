//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: thoughtful
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

const char *morse_code_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A to I
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J to R
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // S to Z
};

const char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *numeric = "0123456789";

void to_upper_case(char *s)
{
    int i = 0;
    while (s[i]) {
        s[i] = toupper(s[i]);
        i++;
    }
}

int is_alpha_numeric(char c)
{
    return (strchr(alphabet, c) != NULL || strchr(numeric, c) != NULL);
}

void get_morse_code_string(char *input, char *output)
{
    to_upper_case(input);
    int i = 0, j = 0;
    while (input[i]) {
        if (!is_alpha_numeric(input[i])) {
            // ignore non alpha-numeric characters
            i++;
            continue;
        }
        if (input[i] >= 'A' && input[i] <= 'Z') {
            // index into morse code table using (ASCII value - 'A')
            strcat(output, morse_code_table[input[i] - 'A']);
        } else if (input[i] >= '0' && input[i] <= '9') {
            // index into morse code table using (numeric value + 25)
            strcat(output, morse_code_table[input[i] - '0' + 25]);
        }
        strcat(output, " ");
        i++;
    }
}

int main()
{
    char input[MAX_STRING_LENGTH];
    char output[MAX_STRING_LENGTH] = "";

    printf("Enter string to convert to Morse code:\n");
    fgets(input, MAX_STRING_LENGTH, stdin);

    input[strcspn(input, "\n")] = 0; // remove trailing newline from fgets

    get_morse_code_string(input, output);

    printf("Morse code: %s\n", output);

    return 0;
}