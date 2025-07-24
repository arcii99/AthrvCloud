//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>

char *morse_codes[] = {    // Morse code array
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

char *alphabet = "abcdefghijklmnopqrstuvwxyz";   // Alphabet for matching

void sig_handler(int sig){   // Signal handler for cleanup
    fcntl(STDIN_FILENO, F_SETFL, O_ASYNC);    // Disable asynchronous mode
    printf("\n\rProgram terminated.\n\r");
    exit(0);
}

int main(){
    fcntl(STDIN_FILENO, F_SETOWN, getpid());  // Set process ID to receive signals
    fcntl(STDIN_FILENO, F_SETFL, O_ASYNC);    // Enable asynchronous mode
    signal(SIGINT, sig_handler);    // Signal handler for cleanup
    char in_buf[100];   // Input buffer
    int in_len; // Length of input
    bool valid; // Checks if input is valid
    int i,j;    // Loop counters
    int morse_len;  // Length of morse code
    while(1){   // Infinite loop
        printf("Enter text to convert to Morse code (Type \"exit\" to quit): ");
        fflush(stdout); // Force display of statement
        in_len = read(0, in_buf, sizeof(in_buf)); // Get input
        if(in_len < 0){
            if(errno == EINTR){ // Interrupt signal received
                continue;
            }
            perror("read");
            exit(1);
        }
        in_buf[in_len-1] = '\0'; // Replace newline with null terminator
        if(strcmp(in_buf, "exit") == 0){    // Check for exit command
            printf("\n\rProgram terminated.\n\r");
            exit(0);
        }
        valid = true;
        for(i = 0; i < in_len; i++){   // Check if input contains non-alphabetic characters
            if(in_buf[i] == ' '){
                continue;
            }
            for(j = 0; j < 26; j++){
                if(in_buf[i] == alphabet[j]){
                    break;
                }
                if(j == 25){
                    valid = false;
                }
            }
            if(!valid){
                break;
            }
        }
        if(valid){
            for(i = 0; i < in_len; i++){   // Convert input to morse code
                if(in_buf[i] == ' '){  // Space
                    printf(" ");
                    continue;
                }
                morse_len = strlen(morse_codes[in_buf[i] - 'a']);
                for(j = 0; j < morse_len; j++){ // Print morse code
                    printf("%c", morse_codes[in_buf[i] - 'a'][j]);
                    fflush(stdout); // Force display of character
                    usleep(200000); // Wait between dots and dashes
                }
                printf(" ");    // Space between letters
            }
            printf("\n\r"); // Newline after each input
        }
        else{
            printf("Invalid input. Please enter alphabetic characters only.\n\r");    // Error message for invalid input
        }
    }
    return(0);
}