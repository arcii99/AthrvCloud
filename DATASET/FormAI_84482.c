//FormAI DATASET v1.0 Category: Browser Plugin ; Style: detailed
// This is an example program for a unique C browser plugin
#include <stdio.h>

// Function to display a message in the browser
void displayInBrowser(char* message) {
    printf("<script>alert('%s');</script>", message);
}

// Function to add two numbers and return the result to the browser
int addInBrowser(int x, int y) {
    int sum = x + y;
    printf("<script>document.write(%d);</script>", sum);
    return sum;
}

// Main function to test the plugin
int main() {
    // Display a message in the browser
    displayInBrowser("Hello from C!");

    // Get two numbers from the browser and add them
    int x, y;
    printf("<script>var x = prompt('Enter first number:'); var y = prompt('Enter second number:'); x = parseInt(x); y = parseInt(y);</script>");
    scanf("%d %d", &x, &y);
    addInBrowser(x, y);

    return 0;
}