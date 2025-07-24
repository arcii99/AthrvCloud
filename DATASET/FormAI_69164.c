//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: artistic
#include <stdio.h>
#include <string.h>

void morse(char *s);
void print_morse(char ch);

// Morse code representation of alphabets, numbers and some special characters
char *morse_table[40] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", 
    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..",
    "----.", "//", ".-.-.-", "--..--"
};

int main()
{
    char input[50];
    printf("Enter the text to convert to Morse code: ");
    fgets(input, 50, stdin);
    printf("\nMorse code representation: \n\n");
    morse(input);
    return 0;
}

//function to convert text to morse code
void morse(char *s)
{
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == ' ') {
            printf(" ");
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            print_morse(s[i] - 'A');
        }
        else if (s[i] >= 'a' && s[i] <= 'z') {
            print_morse(s[i] - 'a');
        }
        else if (s[i] >= '0' && s[i] <= '9') {
            printf("%s ", morse_table[s[i] - 21]);
        }
        else {
            switch (s[i]) {
                case '.':
                    printf("%s ", morse_table[36]);
                    break;
                case ',':
                    printf("%s ", morse_table[37]);
                    break;
                default:
                    break;
            }
        }
        i++;
    }
}

//function to print morse code for given character
void print_morse(char ch)
{
    int i;
    for (i = 0; morse_table[ch][i] != '\0'; i++) {
        printf("%c ", morse_table[ch][i]);
    }
    printf("  "); //two spaces between two characters
}