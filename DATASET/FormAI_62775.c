//FormAI DATASET v1.0 Category: Browser Plugin ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// This program demonstrates a simple browser plugin that counts the number of times a user clicks on a button in the browser

// This function will be called every time the user clicks on the button in the browser
void click_handler() {
  static int count = 0; // static variable to store the number of clicks
  count++; // increment the click count every time the function is called
  printf("Button clicked %d times\n", count);
}

// Main function - this will be the entry point of the plugin
int main() {
  printf("Browser plugin started...\n");

  // Register a callback function for the 'click' event on the button
  // In a real plugin, this would be done using the plugin API provided by the browser
  // For this example, we will simulate the 'click' event by calling the click_handler() function
  for (int i=0; i<5; i++) {
    click_handler(); // simulate a click event
  }

  printf("Browser plugin stopped.\n");
  return 0;
}