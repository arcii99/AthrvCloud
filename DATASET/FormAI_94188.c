//FormAI DATASET v1.0 Category: Browser Plugin ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Function to check if the current URL contains the word "cheerful"
bool checkCheerful(char* url) {
    char* cheerful = "cheerful";
    char* result = strstr(url, cheerful);
    if(result != NULL)
        return true;
    else
        return false;
}

//Function to display a cheerful message
void displayCheerfulMessage() {
    printf("Yay! You are on a cheerful website :)\n");
}

//Main function
int main() {
    char* currentURL = "https://www.cheerful.com";
    
    //Check if the current URL is cheerful and display message accordingly
    if(checkCheerful(currentURL)) {
        displayCheerfulMessage();
    }
    else {
        printf("Sorry, this website is not cheerful :(\n");
    }
    
    return 0;
}