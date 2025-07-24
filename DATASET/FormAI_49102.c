//FormAI DATASET v1.0 Category: Browser Plugin ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/* Define the plugin type */
typedef struct {
    char* name;
    char* description;
} Plugin;

/* Define the browser type */
typedef struct {
    char* name;
    int version;
    Plugin** plugins;
} Browser;

/* Define the function to add a plugin to a browser */
void add_plugin(Browser* browser, Plugin* plugin) {
    int num_plugins = 0;
    if (browser->plugins != NULL) {
        while (browser->plugins[num_plugins] != NULL) {
            num_plugins++;
        }
    }
    browser->plugins = realloc(browser->plugins, sizeof(Plugin*) * (num_plugins + 2));
    browser->plugins[num_plugins] = plugin;
    browser->plugins[num_plugins + 1] = NULL;
}

int main() {
    /* Initialize the variables */
    Plugin* plugin1 = malloc(sizeof(Plugin));
    Plugin* plugin2 = malloc(sizeof(Plugin));
    Browser* browser = malloc(sizeof(Browser));

    plugin1->name = "AdBlock";
    plugin1->description = "Block ads on websites";
    plugin2->name = "Grammarly";
    plugin2->description = "Check grammar on websites";
    browser->name = "Chrome";
    browser->version = 90;
    browser->plugins = NULL;

    /* Add the plugins to the browser */
    add_plugin(browser, plugin1);
    add_plugin(browser, plugin2);

    /* Print the browser and plugins information */
    printf("Browser Name: %s\n", browser->name);
    printf("Browser Version: %d\n", browser->version);
    printf("\nPlugins:\n");
    for (int i = 0; browser->plugins[i] != NULL; i++) {
        printf("%s: %s\n", browser->plugins[i]->name, browser->plugins[i]->description);
    }

    /* Free the memory */
    free(plugin1);
    free(plugin2);
    free(browser);

    return 0;
}