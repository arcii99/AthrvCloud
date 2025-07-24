//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: immersive
#include<stdio.h>
#include<string.h>

void convert_to_morse_code(char input_char);
// Function to convert character to Morse code

int main(void) {

    char input_str[100]; // stores user input
    int len; // stores length of input
    int i; // loop counter

    printf("Enter a string to convert to Morse code:\n");
    fgets(input_str, 100, stdin);

    len = strlen(input_str);

    for(i=0;i<len;i++){
        convert_to_morse_code(input_str[i]);
    }
    printf("Conversion completed!");

    return 0;
}

// Function to convert character to Morse code
void convert_to_morse_code(char input_char){
    char code[37][10] = {
        {'A', '.-'}, {'B', '-...'}, {'C', '-.-.'}, {'D', '-..'}, {'E', '.'},
        {'F', '..-.'}, {'G', '--.'}, {'H', '....'}, {'I', '..'}, {'J', '.---'},
        {'K', '-.-'}, {'L', '.-..'}, {'M', '--'}, {'N', '-.'}, {'O', '---'},
        {'P', '.--.'}, {'Q', '--.-'}, {'R', '.-.'}, {'S', '...'}, {'T', '-'},
        {'U', '..-'}, {'V', '...-'}, {'W', '.--'}, {'X', '-..-'}, {'Y', '-.--'},
        {'Z', '--..'}, {'1', '.----'}, {'2', '..---'}, {'3', '...--'},
        {'4', '....-'}, {'5', '.....'}, {'6', '-....'}, {'7', '--...'},
        {'8', '---..'}, {'9', '----.'}, {'0', '-----'}, {' ', '/'}
    };
    input_char = toupper(input_char);
    // converting input char to uppercase
    for(int i = 0; i < 37; ++i) {
        if(input_char == code[i][0]) {
            printf("%s ", code[i][1]);
            break;
        }
    }
}