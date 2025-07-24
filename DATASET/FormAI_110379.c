//FormAI DATASET v1.0 Category: Browser Plugin ; Style: future-proof
/*
  This is a unique C Browser Plugin example program that demonstrates how to
  create a plugin that shows random quotes whenever a user clicks on it. It is
  future-proofed by using modern libraries and techniques for portability.

  Minimum 50 lines.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#define MAX_QUOTES 10

// Array of quotes to display.
const char* quotes[MAX_QUOTES] = {
  "The only way to do great work is to love what you do. -Steve Jobs",
  "Believe you can and you're halfway there. -Theodore Roosevelt",
  "Don't watch the clock; do what it does. Keep going. -Sam Levenson",
  "It always seems impossible until it's done. -Nelson Mandela",
  "You miss 100% of the shots you don't take. -Wayne Gretzky",
  "You must be the change you wish to see in the world. -Mahatma Gandhi",
  "The best way to predict your future is to create it. -Abraham Lincoln",
  "Setting goals is the first step in turning the invisible into the visible. -Tony Robbins",
  "Success is not the key to happiness. Happiness is the key to success. -Albert Schweitzer",
  "The only thing necessary for the triumph of evil is for good men to do nothing. -Edmund Burke"
};

// Get a random quote from the array.
const char* get_random_quote() {
  srand(time(NULL));
  int index = rand() % MAX_QUOTES;
  return quotes[index];
}

// Callback for when the plugin is clicked.
void plugin_click() {
  const char* quote = get_random_quote();
  printf("Clicked! Here's a quote: %s\n", quote);
  // TODO: Display quote in a popup or modal.
}

#ifdef __EMSCRIPTEN__
// JavaScript glue code for Emscripten.
EM_JS(void, register_plugin_click, (), {
  // TODO: Register plugin click with browser.
});

// Main function for Emscripten.
int main() {
  register_plugin_click();
  return 0;
}
#else
// Main function for native plugins.
int main() {
  printf("Browser plugin written in C!\n");
  // TODO: Register plugin click with browser.
  // TODO: Create plugin UI.
  while (true) {}  // Keep plugin running.
  return 0;
}
#endif