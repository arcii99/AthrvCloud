//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: mind-bending
#include <stdio.h>
#include <string.h>

void delay(int delay_time) {
    // Wait for some amount of time
    int i = 0;
    while (i < delay_time) {
        i++;
    }
}

int main() {
    // Mind-bending text to Morse code converter
    char message[] = "Hello World!";
    int length = strlen(message);
    printf("Converting text to Morse code...\n\n");
    delay(1000000);
    
    // Mapping of characters to Morse code
    char *morse_letter[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                            "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                            "-.--", "--..", " "};
    char *morse_number[] = {"-----", ".----", "..---", "...--", "....-", ".....",
                            "-....", "--...", "---..", "----."};
    
    // Convert the text to Morse code
    for (int i = 0; i < length; i++) {
        char current_char = message[i];
        if (current_char >= 'a' && current_char <= 'z') {
            printf("%s ", morse_letter[current_char - 'a']);
        } else if (current_char >= 'A' && current_char <= 'Z') {
            printf("%s ", morse_letter[current_char - 'A']);
        } else if (current_char >= '0' && current_char <= '9') {
            printf("%s ", morse_number[current_char - '0']);
        } else {
            printf(" ");
        }
        delay(500000);
    }
    
    // Print out the converted message
    printf("\n\nMorse code conversion complete!\n");
    return 0;
}