//FormAI DATASET v1.0 Category: Browser Plugin ; Style: accurate
#include <stdio.h>

// struct to hold browser plugin information
typedef struct browser_plugin {
  char* name; // plugin name
  char* version; // plugin version
  char* description; // plugin description
  char* author; // plugin author
} BrowserPlugin;

// function to initialize plugin information
void initialize_plugin(BrowserPlugin* plugin, char* name, char* version, char* description, char* author) {
  plugin->name = name;
  plugin->version = version;
  plugin->description = description;
  plugin->author = author;
}

// function to display plugin information
void display_plugin_info(BrowserPlugin* plugin) {
  printf("Plugin Name: %s\n", plugin->name);
  printf("Version: %s\n", plugin->version);
  printf("Description: %s\n", plugin->description);
  printf("Author: %s\n", plugin->author);
}

int main() {
  // create new plugin
  BrowserPlugin myPlugin;
  initialize_plugin(&myPlugin, "My Plugin", "1.0", "This is my plugin", "James Smith");

  // display plugin information
  display_plugin_info(&myPlugin);

  return 0;
}