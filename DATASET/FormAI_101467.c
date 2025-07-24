//FormAI DATASET v1.0 Category: Browser Plugin ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum length of the URL
#define MAX_URL_LENGTH 100

// Create a struct to hold the plugin data
typedef struct pluginData {
  char url[MAX_URL_LENGTH];
  bool isEnabled;
} PluginData;

// Initialize an array to hold the plugins
PluginData plugins[10];

// Initialize the number of plugins
int numPlugins = 0;

// Add a plugin to the array
void addPlugin(char* url, bool isEnabled) {
  if (numPlugins < 10) { // Check if there is space for a new plugin
    // Create a new PluginData instance with the given url and isEnabled values
    PluginData plugin;
    strcpy(plugin.url, url);
    plugin.isEnabled = isEnabled;
    plugins[numPlugins] = plugin; // Add the new plugin to the array
    numPlugins++; // Increment the number of plugins
  }
}

// Remove a plugin from the array
void removePlugin(int index) {
  if (index >= 0 && index < numPlugins) { // Check if the index is valid
    for (int i = index; i < numPlugins-1; i++) { // Shift elements to fill the gap
      plugins[i] = plugins[i+1];
    }
    numPlugins--; // Decrement the number of plugins
  }
}

// Display plugin data
void displayPluginData() {
  printf("Plugins:\n");
  for (int i = 0; i < numPlugins; i++) {
    printf("%d. %s [%s]\n", i+1, plugins[i].url, plugins[i].isEnabled ? "Enabled" : "Disabled");
  }
}

// Enable or disable a plugin
void togglePlugin(int index) {
  if (index >= 0 && index < numPlugins) { // Check if the index is valid
    plugins[index].isEnabled = !plugins[index].isEnabled; // Toggle the isEnabled value
  }
}

// Main program
int main() {
  // Add some sample plugins
  addPlugin("www.google.com", true);
  addPlugin("www.facebook.com", true);

  // Display the plugins
  displayPluginData();

  // Disable the second plugin
  togglePlugin(1);

  // Display the plugins again
  displayPluginData();

  // Remove the first plugin
  removePlugin(0);

  // Display the plugins one last time
  displayPluginData();

  return 0;
}