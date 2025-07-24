//FormAI DATASET v1.0 Category: Browser Plugin ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

// define plugin structure
typedef struct {
   char name[50];
   char version[10];
   char description[100];
   char author[50];
   char language[20];
} Plugin;

// function to initialize the plugin
void init_plugin(Plugin *plugin) {
   // set default values
   strcpy(plugin->name, "Beginner Plugin");
   strcpy(plugin->version, "1.0");
   strcpy(plugin->description, "A plugin for beginners");
   strcpy(plugin->author, "Codebot");
   strcpy(plugin->language, "C");
}

int main() {
   // create plugin instance
   Plugin my_plugin;
   // initialize plugin
   init_plugin(&my_plugin);
   // print plugin information
   printf("Plugin Name: %s\n", my_plugin.name);
   printf("Version: %s\n", my_plugin.version);
   printf("Description: %s\n", my_plugin.description);
   printf("Author: %s\n", my_plugin.author);
   printf("Language: %s\n", my_plugin.language);
   return 0;
}