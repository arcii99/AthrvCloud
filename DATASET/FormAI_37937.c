//FormAI DATASET v1.0 Category: QR code generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 25

int main() {
    char input[SIZE]; // Input string from user
    char url[SIZE + 28] = "https://www.example.com/"; // Base URL for QR code
    char qrCode[SIZE + 52]; // Final QR code string
    int i, j; // Loop counters
    
    printf("Enter data to encode as a QR code: ");
    fgets(input, SIZE, stdin); // Get user input
    
    // Add input to URL and replace any spaces with %20
    for(i = 0, j = strlen(url); input[i] != '\n'; i++, j++) {
        if(input[i] == ' ') {
            url[j++] = '%';
            url[j++] = '2';
            url[j] = '0';
        } else {
            url[j] = input[i];
        }
    }
    
    // Generate QR code by encoding URL with Cyberpunk style
    strcpy(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░█▀░░░░░░░░░░░░░░░░░░░\n");
    strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░▀█▄░░░░░░░░░░░░░░░░░░\n");
    strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░▀█▄░░░░░░░░░░░░░░░░░\n");
    strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░▀█▄░░░░░░░░░░░░░░\n");
    strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▀█▄░░░░░░░░░░░\n");
    strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▀█░░░░░░░░░\n");
    
    // Encode URL
    for(i = 0; i < strlen(url); i++) {
        switch(url[i]) {
            case '0':
                strcat(qrCode, "░?\033[0m█░");
                break;
            case '1':
                strcat(qrCode, "░░?\033[0m░");
                break;
            case '2':
                strcat(qrCode, "░░░?\033[0m");
                break;
            case '3':
                strcat(qrCode, "?\033[0m░░░");
                break;
            case '4':
                strcat(qrCode, "█?\033[0m░");
                break;
            case '5':
                strcat(qrCode, "░█?\033[0m");
                break;
            case '6':
                strcat(qrCode, "?░█\033[0m░");
                break;
            case '7':
                strcat(qrCode, "░?\033[0m░█");
                break;
            case '8':
                strcat(qrCode, "\033[0m?░░?");
                break;
            case '9':
                strcat(qrCode, "\033[0m░?░?");
                break;
            case 'A':
                strcat(qrCode, "░█?\033[0m░");
                break;
            case 'B':
                strcat(qrCode, "?░█\033[0m░");
                break;
            case 'C':
                strcat(qrCode, "░?\033[0m?░");
                break;
            case 'D':
                strcat(qrCode, "\033[0m░░?█");
                break;
            case 'E':
                strcat(qrCode, "░𝓐░\033[0m░");
                break;
            case 'F':
                strcat(qrCode, "?░𝓞\033[0m░");
                break;
            case 'G':
                strcat(qrCode, "░▒▓\033[0m░░");
                break;
            case 'H':
                strcat(qrCode, "░⚡░\033[0m░");
                break;
            case 'I':
                strcat(qrCode, "░░⚡\033[0m░");
                break;
            case 'J':
                strcat(qrCode, "░░░?\033[0m░");
                break;
            case 'K':
                strcat(qrCode, "\033[0m░█?");
                break;
            case 'L':
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░░?░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░𝓓░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                break;
            case 'M':
                strcat(qrCode, "?█░\033[0m░░");
                break;
            case 'N':
                strcat(qrCode, "\033[0m░?█░");
                break;
            case 'O':
                strcat(qrCode, "\033[0m░░█?");
                break;
            case 'P':
                strcat(qrCode, "░░░⚡\033[0m");
                break;
            case 'Q':
                strcat(qrCode, "░▒?░\033[0m");
                break;
            case 'R':
                strcat(qrCode, "░░▓?\033[0m");
                break;
            case 'S':
                strcat(qrCode, "?░▓░\033[0m░");
                break;
            case 'T':
                strcat(qrCode, "░░░?░\033[0m");
                break;
            case 'U':
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░░░░░░?░░░░░░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                break;
            case 'V':
                strcat(qrCode, "\033[0m░░██");
                break;
            case 'W':
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░░░░░░░░░░░?░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                break;
            case 'X':
                strcat(qrCode, "░░░▓?\033[0m░");
                break;
            case 'Y':
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░\033[0m█?\n");
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                break;
            case 'Z':
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░?█\n");
                break;
            case '.':
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                strcat(qrCode, "░░░░░░░░░░░?█\033[0m░░░░░░░░░░\n");
                break;
            default:
                strcat(qrCode, "░𝓠░\033[0m░░");
                break;
        }
    }
    
    // Print final QR code
    printf("\n%s\n", qrCode);
    
    return 0;
}