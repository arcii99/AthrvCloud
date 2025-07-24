//FormAI DATASET v1.0 Category: Browser Plugin ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for holding plugin metadata
struct PluginMetadata {
  char author[100];
  char version[10];
  char description[200];
};

// Initialize the metadata for the plugin
struct PluginMetadata thisPlugin = {
  "John Doe",
  "1.0",
  "A browser plugin for automatically generating random passwords.",
};

// Declare the browser plugin function (this will be called by the browser when the plugin is used)
void browser_plugin(char* url) {
  printf("You are on URL: %s\n", url);
  printf("Here's a random password for you: ");

  // Generate a random password
  char password[20];
  const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  for (int i = 0; i < 8; i++) {
    password[i] = charset[rand() % strlen(charset)];
  }
  password[8] = '\0';

  printf("%s\n", password);
}

// Declare the function for getting the plugin metadata
struct PluginMetadata get_plugin_metadata() {
  return thisPlugin;
}

// Define the main method (this will not be called by the browser, just used for testing)
int main() {
  char url[100] = "https://www.google.com";

  // Call the browser plugin function
  browser_plugin(url);

  // Get the plugin metadata and output it
  struct PluginMetadata metadata = get_plugin_metadata();
  printf("Plugin Author: %s\n", metadata.author);
  printf("Plugin Version: %s\n", metadata.version);
  printf("Plugin Description: %s\n", metadata.description);

  return 0;
}