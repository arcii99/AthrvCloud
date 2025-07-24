//FormAI DATASET v1.0 Category: Browser Plugin ; Style: relaxed
#include <stdio.h>

// Define the structure for the browser plugin
typedef struct CBrowserPlugin {
  char name[50];
  char version[20];
  int numSupportedFormats;
  char supportedFormats[10][20];
  char description[200];
  char developer[50];

  // Function pointers for plugin actions
  void (*loadPlugin)();
  void (*unloadPlugin)();
  void (*playMedia)(char*);
} CBrowserPlugin;

// Function to load the plugin
void loadPlugin() {
  printf("Plugin loaded successfully\n");
}

// Function to unload the plugin
void unloadPlugin() {
  printf("Plugin unloaded successfully\n");
}

// Function to play supported media formats using the plugin
void playMedia(char* format) {
  printf("Playing %s media using the plugin\n", format);
}

// Define the plugin instance with sample data
CBrowserPlugin myPlugin = {
  "My Browser Plugin",
  "1.0",
  3,
  {"mp3", "mp4", "avi"},
  "A sample browser plugin for playing media files",
  "John Doe",
  loadPlugin,
  unloadPlugin,
  playMedia
};

// Application entry point
int main() {

  // Print plugin information
  printf("Plugin name: %s\n", myPlugin.name);
  printf("Plugin version: %s\n", myPlugin.version);
  printf("Number of supported formats: %d\n", myPlugin.numSupportedFormats);
  printf("Supported formats: ");
  for(int i=0; i<myPlugin.numSupportedFormats; i++) {
    printf("%s ", myPlugin.supportedFormats[i]);
  }
  printf("\n");
  printf("Plugin description: %s\n", myPlugin.description);
  printf("Plugin developer: %s\n", myPlugin.developer);

  // Load the plugin
  myPlugin.loadPlugin();

  // Play media formats using the plugin
  myPlugin.playMedia("mp3");
  myPlugin.playMedia("mp4");
  myPlugin.playMedia("avi");

  // Unload the plugin
  myPlugin.unloadPlugin();

  // Exit the application
  return 0;
}