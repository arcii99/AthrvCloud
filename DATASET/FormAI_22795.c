//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_header() {
    printf("\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
    printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
    printf("\n:::::::'#######::'########:'########::'##::::'##::'######::'##:::::");
    printf("\n::::::::'##.... ##: ##.....:: ###... ##:. ##::'##::'##... ##: ##:::::");
    printf("\n:::::::: ##:::: ##: ##::::::: ####:: ##::. ##'##::: ##:::..:: ##:::::");
    printf("\n:::::::: ########:: ######::: ##. ##:::'. ###::::. ######::: ##:::::");
    printf("\n:::::::: ##.... ##: ##...:::: ##:. ##::: ## ##:::::..... ##: ##:::::");
    printf("\n:::::::: ##:::: ##: ##::::::: ##::. ##:: ##:. ##::'##::: ##: ##:::::");
    printf("\n:::::::'#######::: ########: ##:::. ##:'##:::. ##:..######:: ########");
    printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
    printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
}

char* convert(char* input) {
    int len = strlen(input);
    char* output = malloc(sizeof(char) * (len * 6 + 1));
    output[0] = '\0';
    for (int i = 0; i < len; i++) {
        char current = input[i];
        switch(current) {
            case 'A': strcat(output, "    ____    \n");
                      strcat(output, "   / __ \\   \n");
                      strcat(output, "  / /_/ /   \n");
                      strcat(output, " / ____/ _  \n");
                      strcat(output, "/_/ |____| \n\n");
                      break;
            case 'B': strcat(output, " ______    \n");
                      strcat(output, "|  ____|   \n");
                      strcat(output, "| |____    \n");
                      strcat(output, "|  ____|   \n");
                      strcat(output, "| |____    \n");
                      strcat(output, "|______| \n\n");
                      break;
            case 'C': strcat(output, "  _______  \n");
                      strcat(output, " / ___ \\   \n");
                      strcat(output, "/ /___\\_\\  \n");
                      strcat(output, "|_____ _ \\ \n");
                      strcat(output, "\\_____/ \\_\\ \n\n");
                      break;
            case 'D': strcat(output, " _____    \n");
                      strcat(output, "|  __ \\   \n");
                      strcat(output, "| |  | |  \n");
                      strcat(output, "| |  | |  \n");
                      strcat(output, "| |__| |  \n");
                      strcat(output, "|_____/ \n\n");
                      break;                  
            case 'E': strcat(output, " _______ \n");
                      strcat(output, "|  ______|\n");
                      strcat(output, "| |_____ \n");
                      strcat(output, "|_____  |\n");
                      strcat(output, " _____| |\n");
                      strcat(output, "|_______|\n\n");
                      break;
            case 'F': strcat(output, " _______ \n");
                      strcat(output, "|  ______|\n");
                      strcat(output, "| |_____ \n");
                      strcat(output, "|_____  |\n");
                      strcat(output, "|  __  |_| \n");
                      strcat(output, "|__| |_|\n\n");
                      break;
            case 'G': strcat(output, "  _______ \n");
                      strcat(output, "/  ____ \\ \n");
                      strcat(output, "| /____\\ | \n");
                      strcat(output, "| |  ____| \n");
                      strcat(output, "| |______ \n");
                      strcat(output, " \\______/ \n\n");
                      break;
            case 'H': strcat(output, " __    __ \n");
                      strcat(output, "|  |__|  |\n");
                      strcat(output, "|   __   |\n");
                      strcat(output, "|  |  |  |\n");
                      strcat(output, "|__|  |__|\n\n");
                      break;
            case 'I': strcat(output, " _____  \n");
                      strcat(output, "|  _  | \n");
                      strcat(output, "| |_| | \n");
                      strcat(output, "|_____| \n\n");
                      break;
            case 'J': strcat(output, " ______ \n");
                      strcat(output, "/_  __ \\\n");
                      strcat(output, "  | |_) |\n");
                      strcat(output, "  |  __/\n");
                      strcat(output, "  | |\n");
                      strcat(output, "  |_| \n\n");
                      break;
            case 'K': strcat(output, " __   __ \n");
                      strcat(output, "|  | / / \n");
                      strcat(output, "|  |/ /  \n");
                      strcat(output, "|    <   \n");
                      strcat(output, "|  |\\ \\  \n");
                      strcat(output, "|__| \\_\\ \n\n");
                      break;
            case 'L': strcat(output, " __      \n"); 
                      strcat(output, "|  |     \n"); 
                      strcat(output, "|  |     \n"); 
                      strcat(output, "|  |     \n"); 
                      strcat(output, "|  `----.\n"); 
                      strcat(output, "|_______|\n\n"); 
                      break;
            case 'M': strcat(output, "__    __ \n"); 
                      strcat(output, "|  |  |  |\n"); 
                      strcat(output, "|  |__|  |\n"); 
                      strcat(output, "|   __   |\n"); 
                      strcat(output, "|  |  |  |\n"); 
                      strcat(output, "|__|  |__|\n\n"); 
                      break;
            case 'N': strcat(output, " ___  ____\n"); 
                      strcat(output, "|   \\/   |\n"); 
                      strcat(output, "|  \\  /  |\n"); 
                      strcat(output, "|  |\\/|  |\n"); 
                      strcat(output, "|  |  |  |\n"); 
                      strcat(output, "|__|  |__|\n\n"); 
                      break;
            case 'O': strcat(output, "  ______  \n"); 
                      strcat(output, " / ____ \\ \n"); 
                      strcat(output, "| /    \\ | \n"); 
                      strcat(output, "| |    | | \n"); 
                      strcat(output, " \\ \\____/ / \n"); 
                      strcat(output, "  \\______/ \n\n"); 
                      break;
            case 'P': strcat(output, " _______ \n");
                      strcat(output, "|  __   |\n");
                      strcat(output, "| |__)  |\n");
                      strcat(output, "|  ___ / \n");
                      strcat(output, "| |     \n");
                      strcat(output, "|_|     \n\n");
                      break;
            case 'Q': strcat(output, "  ______  \n");
                      strcat(output, " / ____ \\ \n");
                      strcat(output, "| /    \\ | \n");
                      strcat(output, "| |    | | \n");
                      strcat(output, " \\ \\____\\_\\ \n");
                      strcat(output, "  \\______\\| \n\n");
                      break;
            case 'R': strcat(output, " _______ \n");
                      strcat(output, "|  __   |\n");
                      strcat(output, "| |__)  |\n");
                      strcat(output, "|  __  / \n");
                      strcat(output, "| |  \\ \\ \n");
                      strcat(output, "|_|   \\_\\ \n\n");
                      break;
            case 'S': strcat(output, "  ______ \n");
                      strcat(output, "/____  / \n");
                      strcat(output, "     / /  \n");
                      strcat(output, "    / /   \n");
                      strcat(output, "  _/ /__  \n");
                      strcat(output, "|_______| \n\n");
                      break;
            case 'T': strcat(output, " _______ \n");
                      strcat(output, "|   _   |\n");
                      strcat(output, "|  |_|  |\n");
                      strcat(output, "|       |\n");
                      strcat(output, "|   _   |\n");
                      strcat(output, "|__| |__|\n\n");
                      break;
            case 'U': strcat(output, " __    __ \n");
                      strcat(output, "|  |  |  |\n");
                      strcat(output, "|  |  |  |\n");
                      strcat(output, "|  |  |  |\n");
                      strcat(output, "|  `--'  |\n");
                      strcat(output, " \\______/ \n\n");
                      break;
            case 'V': strcat(output, "__       __\n");
                      strcat(output, "\\ \\     / /\n");
                      strcat(output, " \\ \\   / / \n");
                      strcat(output, "  \\ \\ / /  \n");
                      strcat(output, "   \\ V /   \n");
                      strcat(output, "    \\_/    \n\n");
                      break;
            case 'W': strcat(output, "__          __\n");
                      strcat(output, "\\ \\        / /\n");
                      strcat(output, " \\ \\  /\\  / / \n");
                      strcat(output, "  \\ \\/  \\/ /  \n");
                      strcat(output, "   \\  /\\  /   \n");
                      strcat(output, "    \\/  \\/    \n\n");
                      break;
            case 'X': strcat(output, "__     __\n");
                      strcat(output, "\\ \\   / /\n");
                      strcat(output, " \\ \\_/ / \n");
                      strcat(output, "  \\   /  \n");
                      strcat(output, "  /  /\\  \n");
                      strcat(output, " /__/  \\__\\ \n\n");
                      break;
            case 'Y': strcat(output, "__     __\n");
                      strcat(output, "\\ \\   / /\n");
                      strcat(output, " \\ \\_/ / \n");
                      strcat(output, "  \\   /  \n");
                      strcat(output, "   | |   \n");
                      strcat(output, "   |_|   \n\n");
                      break;
            case 'Z': strcat(output, " _______\n");
                      strcat(output, "/_______\\\n");
                      strcat(output, "|__    __\n");
                      strcat(output, "   |  |\n");
                      strcat(output, "  _|  |_ \n");
                      strcat(output, "|________|\n\n");
                      break;
            case ' ': strcat(output, "\n\n"); 
                      break;
            default: break;
        }
    }
    return output;
}

int main() {
    print_header();
    char input[100];
    printf("Enter your text: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;
    char* output = convert(input);
    printf("%s", output);
    free(output);
    return 0;
}