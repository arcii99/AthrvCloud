//FormAI DATASET v1.0 Category: Error handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>

// Set up a global buffer to track the error message
static char* error_msg = NULL;

// Define a jump target for our error handling
static jmp_buf env;

// Define an error handler function
void handle_error(int sig) {
    // Save the error message to our global buffer
    error_msg = "An error has occurred";
    
    // Jump to our error handling code
    longjmp(env, 1);
}

int main() {
    // Install our error handling function for SIGSEGV
    if (signal(SIGSEGV, handle_error) == SIG_ERR ) {
        fprintf(stderr, "Unable to install signal handler for SIGSEGV\n");
        return 1;
    }
    
    // Set up a null pointer to trigger a SEGMENTATION FAULT (SIGSEGV)
    int* ptr = NULL;
    *ptr = 42; // This will cause a SIGSEGV
    
    // Use a setjmp to save the current execution context for later
    if (setjmp(env) == 0) {
        // We haven't encountered an error yet, so continue with the program
        printf("The answer is %d\n", *ptr);
    } else {
        // We encountered an error, so clean up and print the error message
        free(error_msg);
        printf("%s\n", error_msg);
        return 1;
    }
    
    // Clean up and exit
    free(error_msg);
    return 0;
}