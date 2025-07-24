//FormAI DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LEN 1000

char inputString[MAX_LEN];  // Global variable to hold input string
char outputString[MAX_LEN]; // Global variable to hold output string

// Function to reverse the string
void reverseString(char *str)
{
    int len = strlen(str);
    char temp;
    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Thread function to reverse the string asynchronously
void *reverseStringThread(void *args)
{
    if (strlen(inputString) > MAX_LEN) {
        strcpy(outputString, "Error: String length exceeds maximum allowed!");
        pthread_exit(NULL);
    }
    else if (strlen(inputString) == 0) {
        strcpy(outputString, "Error: Empty string input!");
        pthread_exit(NULL);
    }
    
    // Reverse the string
    reverseString(inputString);
    
    // Copy the reversed string to the global output variable
    strcpy(outputString, inputString);
    
    pthread_exit(NULL);
}

// Main function to read user input, start the thread and output the result
int main()
{
    // Read user input string
    printf("Enter a string to reverse: ");
    fgets(inputString, MAX_LEN, stdin);
    inputString[strcspn(inputString, "\n")] = 0; // Remove the newline character from input string
    
    // Initialize thread
    pthread_t reverseThread;
    
    // Start the thread
    pthread_create(&reverseThread, NULL, reverseStringThread, NULL);
    
    // Display progress message
    printf("Reversing the string asynchronously. Please wait...\n");
    
    // Wait for the thread to complete
    pthread_join(reverseThread, NULL);
    
    // Output the result
    printf("The reversed string is: %s", outputString);
    
    return 0;
}