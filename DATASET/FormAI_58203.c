//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main()
{
    char morse_table[26][6] = { // Morse Code table
        {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, {".."}, {".---"},
        {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"},
        {"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}
    };
    char input_str[100];
    printf("Enter text to convert to Morse Code: ");
    fgets(input_str, 100, stdin); // Maximum input length of 100 characters
    int input_length = strlen(input_str);

    printf("Morse Code: ");
    for (int i = 0; i < input_length; i++)
    {
        if (input_str[i] == ' ') // If space is found, print a slash instead
            printf("/");
        else if (input_str[i] >= 'A' && input_str[i] <= 'Z') // Convert uppercase letters to lowercase
            printf("%s ", morse_table[input_str[i]-'A']);
        else if (input_str[i] >= 'a' && input_str[i] <= 'z')
            printf("%s ", morse_table[input_str[i]-'a']);
    }
    return 0;
}