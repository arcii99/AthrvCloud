//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Function to convert character to Ascii Art
void convertToAscii(char character) {
    switch(character) {
        case 'A':
            printf("         _ \n");
            printf("   /\\   | |\n");
            printf("  /  \\  | |__   ___ _ __  _   _\n");
            printf(" / /\\ \\ | '_ \\ / _ \\ '_ \\| | | |\n");
            printf("/ ____ \\| | | |  __/ |_) | |_| |\n");
            printf("/_/    \\_\\_| |_|\\___| .__/ \\__, |\n");
            printf("                    | |     __/ |\n");
            printf("                    |_|    |___/\n");
            break;
        case 'B':
            printf(" ____  _     _ _         \n");
            printf("|  _ \\(_)___| (_) ___   \n");
            printf("| |_) | / __| | |/ _ \\  \n");
            printf("|  _ <| \\__ \\ | | (_) | \n");
            printf("|_| \\_\\_|___/_|_|\\___/  \n");
            break;
        case 'C':
            printf(" _______ ______ _______ _______ _     _\n");
            printf("(_______|_____ (_______|_______) |   | |\n");
            printf(" _____   _____) )______|______ | |__ | |\n");
            printf("|  ___) (_____ (|  ___)  ___  \\|  __)| |\n");
            printf("| |_____      | | |_____|   |  | |   |_| \n");
            printf("|_______)     |_|_______)___|  |_|   (__)\n");
            break;
        case 'D':
            printf(" _      _        ____   _    __  __ \n");
            printf("| |    (_)      / __ \\ / |  / / / / \n");
            printf("| |     _ _ __ | |  | |_  |/ / / /_ \n");
            printf("| |    | | '_ \\| |  | | | |\\ \\ \\__ \\\n");
            printf("| |____| | | | | |__| | |_| \\_\\ (_) |\n");
            printf("|______|_|_| |_|\\____/ \\___/\\__/\\___/ \n");
            break;
        case 'E':
            printf(" _______ ______ _______ _______ _______\n");
            printf("(_______|_____ (_______|_______|_______)\n");
            printf(" _____   _____) )______|______   __\n");
            printf("|  ___) (_____ (|  ___)  ___  | |__) \n");
            printf("| |_____      | | |_____|   | |  ___)\n");
            printf("|_______)     |_|_______)___|_|______)\n");
            break;
        case 'F':
            printf(" _______ ______ _______ _______ \n");
            printf("(_______|_____ (_______|_______)\n");
            printf(" _____   _____) )______|     __\n");
            printf("|  ___) (_____ (|  ___) | | | |\n");
            printf("| |_____      | | |_____|_|_| |\n");
            printf("|_______)     |_|_______|____/ \n");
            break;
        default:
            printf("Invalid Character!\n");
    }
}

int main() {
    char input_string[100];
    printf("Enter a string to convert to Ascii Art\n");
    // Get input string from user
    fgets(input_string, 100, stdin);
    
    printf("ASCII ART:\n");
    // Iterate over each character and convert it to Ascii Art
    for(int i = 0; input_string[i] != '\0'; i++) {
        convertToAscii(input_string[i]);
    }
    
    return 0;
}