//FormAI DATASET v1.0 Category: Error handling ; Style: excited
//Oh my goodness, you caught an error!
//But don't worry, we'll handle it gracefully with some C code!
//Let's get started, shall we?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_error(int line_number, char *message) {
    //This function will print out an error message, along with the line number
    //where the error occurred.
    printf("Error on line %d: %s\n", line_number, message);
    exit(1); //Exit the program with a non-zero exit code to indicate that an error occurred.
}

int main() {
    //Let's simulate an error by dividing by zero.
    int a = 10;
    int b = 0;
    int c;

    //Uh-oh, we just divided by zero! That's not allowed!
    if (b == 0) {
        handle_error(__LINE__, "Division by zero"); //Call our error handling function with the line number and message.
    }

    c = a / b; //Divide a by b and store the result in c.
    printf("Result: %d\n", c); //Print out the result.

    //Now let's simulate another error by allocating too much memory.
    char *s;

    //Allocate a huge amount of memory. This will most likely fail and return NULL.
    s = (char*) malloc(1000000000000 * sizeof(char));
    
    //Oops, we just allocated too much memory! That's not allowed either!
    if (s == NULL) {
        handle_error(__LINE__, "Memory allocation failed"); //Call our error handling function with the line number and message.
    }

    //If we got this far, it means everything worked out okay!
    printf("Yay, no errors!\n");

    //Don't forget to free the memory we allocated.
    free(s);

    return 0;
}