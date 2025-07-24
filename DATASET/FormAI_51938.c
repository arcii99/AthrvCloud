//FormAI DATASET v1.0 Category: Browser Plugin ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for our browser plugin
typedef struct {
  char *name;
  char *author;
  int version;
} Plugin;

// Function to initialize a plugin
Plugin *initPlugin(char *name, char *author, int version) {
  Plugin *plugin = (Plugin *) malloc(sizeof(Plugin));
  plugin->name = (char *) malloc(strlen(name) + 1);
  strcpy(plugin->name, name);
  plugin->author = (char *) malloc(strlen(author) + 1);
  strcpy(plugin->author, author);
  plugin->version = version;
  return plugin;
}

// Function to display a plugin's details
void showPluginDetails(Plugin *plugin) {
  printf("Name: %s\nAuthor: %s\nVersion: %d\n", plugin->name, plugin->author, plugin->version);
}

int main() {
  // Initialize the plugin
  Plugin *myPlugin = initPlugin("MyBrowserPlugin", "John Doe", 1);
  
  // Display the plugin's details
  showPluginDetails(myPlugin);
  
  // Free memory
  free(myPlugin->name);
  free(myPlugin->author);
  free(myPlugin);
  
  return 0;
}