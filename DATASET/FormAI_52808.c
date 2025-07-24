//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_INPUT_SIZE 255
#define MAX_ASCII_SIZE 8000

// Function declaration
void* generate_ascii_art(void* arg);

int main(){
    char input[MAX_INPUT_SIZE];
    printf("Enter text to convert into ASCII art:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, generate_ascii_art, input);
    pthread_join(thread_id, NULL);
    return 0;
}

void* generate_ascii_art(void* arg){
    char* input = (char*) arg;
    int input_len = strlen(input) - 1; // len() counts trailing newline char
    int ascii_len = (input_len * 9) + (4 * 11) + 1; // Each char takes 9 lines (8 pixels + 1 newline),
                                                    // plus 4 extra lines for spacing between letters,
                                                    // plus 1 extra line for null terminator
    char* ascii_art = (char*) malloc(ascii_len * sizeof(char));
    if(ascii_art == NULL){
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < ascii_len; i++){
        ascii_art[i] = ' '; // Initialize ASCII art string with spaces
    }
    
    // Define pixel characters for each letter
    char a[8] = " MMMMM  "
                "MM   MM "
                "MM   MM "
                "MMMMMMM "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                "        ";

    char b[8] = "MMMMMM  "
                "MM   MM "
                "MM   MM "
                "MMMMMM  "
                "MM   MM "
                "MM   MM "
                "MMMMMM  "
                "       ";

    char c[8] = " MMMMM  "
                "MM   MM "
                "MM      "
                "MM      "
                "MM      "
                "MM   MM "
                " MMMMM  "
                "        ";

    char d[8] = "MMMMMM  "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                "MMMMMM  "
                "       ";

    char e[8] = "MMMMMMM "
                "MM      "
                "MM      "
                "MMMMM   "
                "MM      "
                "MM      "
                "MMMMMMM "
                "        ";

    char f[8] = "MMMMMMM "
                "MM      "
                "MM      "
                "MMMMM   "
                "MM      "
                "MM      "
                "MM      "
                "        ";

    char g[8] = " MMMMM  "
                "MM   MM "
                "MM      "
                "MM  MMM "
                "MM   MM "
                "MM   MM "
                " MMMMM  "
                "        ";

    char h[8] = "MM   MM "
                "MM   MM "
                "MM   MM "
                "MMMMMMM "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                "        ";

    char i[8] = "MMMMMMM "
                "   MM   "
                "   MM   "
                "   MM   "
                "   MM   "
                "   MM   "
                "MMMMMMM "
                "        ";

    char j[8] = "  MMMM  "
                "     MM "
                "     MM "
                "     MM "
                "MM   MM "
                "MM   MM "
                " MMMM   "
                "        ";

    char k[8] = "MM   MM "
                "MM  MM  "
                "MM MM   "
                "MMMM    "
                "MM MM   "
                "MM  MM  "
                "MM   MM "
                "        ";

    char l[8] = "MM      "
                "MM      "
                "MM      "
                "MM      "
                "MM      "
                "MM      "
                "MMMMMMM "
                "        ";

    char m[8] = "MM   MM "
                "MMM MMM "
                "MM M MM "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                "        ";

    char n[8] = "MM   MM "
                "MMM  MM "
                "MM M MM "
                "MM  MMM "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                "        ";

    char o[8] = " MMMMM  "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                " MMMMM  "
                "        ";

    char p[8] = "MMMMMM  "
                "MM   MM "
                "MM   MM "
                "MMMMMM  "
                "MM      "
                "MM      "
                "MM      "
                "        ";

    char q[8] = " MMMMM  "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                "MMMM MM "
                " MMMMM  "
                "       ";

    char r[8] = "MMMMMM  "
                "MM   MM "
                "MM   MM "
                "MMMMMM  "
                "MM MM   "
                "MM  MM  "
                "MM   MM "
                "        ";

    char s[8] = " MMMMM  "
                "MM   MM "
                "MM      "
                "MMMMM   "
                "     MM "
                "MM   MM "
                " MMMMM  "
                "        ";

    char t[8] = "MMMMMMM "
                "   MM   "
                "   MM   "
                "   MM   "
                "   MM   "
                "   MM   "
                "   MM   "
                "        ";

    char u[8] = "MM   MM "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                " MMMMM  "
                "        ";

    char v[8] = "MM   MM "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                " MM MM  "
                "  MMM   "
                "        ";

    char w[8] = "MM   MM "
                "MM   MM "
                "MM   MM "
                "MM   MM "
                "MM M MM "
                "MMM MMM "
                "MM   MM "
                "        ";

    char x[8] = "MM   MM "
                "MM   MM "
                " MM MM  "
                "  MMM   "
                " MM MM  "
                "MM   MM "
                "MM   MM "
                "        ";

    char y[8] = "MM   MM "
                "MM   MM "
                "MM   MM "
                " MMMMM  "
                "   MM   "
                "   MM   "
                "   MM   "
                "        ";

    char z[8] = "MMMMMMM "
                "     MM "
                "    MM  "
                "   MM   "
                "  MM    "
                " MM     "
                "MMMMMMM "
                "        ";
    
    // Map input text to corresponding pixel characters
    for(int i = 0; i < input_len; i++){
        char letter[8];
        switch(input[i]){
            case 'a':
            case 'A':
                memcpy(letter, a, sizeof letter);
                break;
            case 'b':
            case 'B':
                memcpy(letter, b, sizeof letter);
                break;
            case 'c':
            case 'C':
                memcpy(letter, c, sizeof letter);
                break;
            case 'd':
            case 'D':
                memcpy(letter, d, sizeof letter);
                break;
            case 'e':
            case 'E':
                memcpy(letter, e, sizeof letter);
                break;
            case 'f':
            case 'F':
                memcpy(letter, f, sizeof letter);
                break;
            case 'g':
            case 'G':
                memcpy(letter, g, sizeof letter);
                break;
            case 'h':
            case 'H':
                memcpy(letter, h, sizeof letter);
                break;
            case 'i':
            case 'I':
                memcpy(letter, i, sizeof letter);
                break;
            case 'j':
            case 'J':
                memcpy(letter, j, sizeof letter);
                break;
            case 'k':
            case 'K':
                memcpy(letter, k, sizeof letter);
                break;
            case 'l':
            case 'L':
                memcpy(letter, l, sizeof letter);
                break;
            case 'm':
            case 'M':
                memcpy(letter, m, sizeof letter);
                break;
            case 'n':
            case 'N':
                memcpy(letter, n, sizeof letter);
                break;
            case 'o':
            case 'O':
                memcpy(letter, o, sizeof letter);
                break;
            case 'p':
            case 'P':
                memcpy(letter, p, sizeof letter);
                break;
            case 'q':
            case 'Q':
                memcpy(letter, q, sizeof letter);
                break;
            case 'r':
            case 'R':
                memcpy(letter, r, sizeof letter);
                break;
            case 's':
            case 'S':
                memcpy(letter, s, sizeof letter);
                break;
            case 't':
            case 'T':
                memcpy(letter, t, sizeof letter);
                break;
            case 'u':
            case 'U':
                memcpy(letter, u, sizeof letter);
                break;
            case 'v':
            case 'V':
                memcpy(letter, v, sizeof letter);
                break;
            case 'w':
            case 'W':
                memcpy(letter, w, sizeof letter);
                break;
            case 'x':
            case 'X':
                memcpy(letter, x, sizeof letter);
                break;
            case 'y':
            case 'Y':
                memcpy(letter, y, sizeof letter);
                break;
            case 'z':
            case 'Z':
                memcpy(letter, z, sizeof letter);
                break;
            default:
                memcpy(letter, "         ", sizeof letter); // Use space char for unknown characters
        }
        // Add pixel characters to ASCII art string with correct spacing
        for(int j = 0; j < 8; j++){
            int index = (i * 9) + (j * 11);
            ascii_art[index] = letter[j];
            if(j == 7){
                ascii_art[index + 8] = '\n';
            }else{
                ascii_art[index + 8] = ' ';
                ascii_art[index + 9] = ' ';
                ascii_art[index + 10] = ' ';
            }
        }
    }
    ascii_art[ascii_len - 1] = '\0'; // Add null terminator
    printf("%s", ascii_art); // Print ASCII art
    free(ascii_art); // Free memory
    pthread_exit(NULL); // Exit thread
}