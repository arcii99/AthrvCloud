//FormAI DATASET v1.0 Category: Browser Plugin ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Define a struct for each plugin
typedef struct {
    char *name;
    int version;
    bool enabled;
} Plugin;

// Define a struct for a linked list of plugins
typedef struct plugin_list {
    Plugin plugin;
    struct plugin_list *next;
} PluginList;

// Function to create a new plugin
Plugin *create_plugin(char *name, int version) {
    Plugin *plugin = malloc(sizeof(Plugin));
    plugin->name = malloc(strlen(name) + 1);
    strcpy(plugin->name, name);
    plugin->version = version;
    plugin->enabled = false;
    return plugin;
}

// Function to add a plugin to the linked list
PluginList *add_plugin_to_list(Plugin *plugin, PluginList *list) {
    PluginList *new_node = malloc(sizeof(PluginList));
    new_node->plugin = *plugin;
    new_node->next = list;
    return new_node;
}

// Function to remove a plugin from the linked list
PluginList *remove_plugin_from_list(char *name, PluginList *list) {
    if (!list) {
        // No plugins in list
        return list;
    } else if (strcmp(name, list->plugin.name) == 0) {
        // Found plugin to remove, remove and return new list head
        PluginList *next_node = list->next;
        free(list->plugin.name);
        free(list);
        return next_node;
    } else {
        // Plugin not found in this node, keep searching
        list->next = remove_plugin_from_list(name, list->next);
        return list;
    }
}

// Function to enable a plugin
void enable_plugin(char *name, PluginList *list) {
    PluginList *node = list;
    while (node) {
        if (strcmp(name, node->plugin.name) == 0) {
            node->plugin.enabled = true;
            break;
        }
        node = node->next;
    }
}

// Function to disable a plugin
void disable_plugin(char *name, PluginList *list) {
    PluginList *node = list;
    while (node) {
        if (strcmp(name, node->plugin.name) == 0) {
            node->plugin.enabled = false;
            break;
        }
        node = node->next;
    }
}

int main() {
    // Create some plugins
    Plugin *plugin1 = create_plugin("Plugin A", 1);
    Plugin *plugin2 = create_plugin("Plugin B", 2);
    Plugin *plugin3 = create_plugin("Plugin C", 3);

    // Add plugins to linked list
    PluginList *list = NULL;
    list = add_plugin_to_list(plugin1, list);
    list = add_plugin_to_list(plugin2, list);
    list = add_plugin_to_list(plugin3, list);

    // Enable a plugin and disable another
    enable_plugin("Plugin A", list);
    disable_plugin("Plugin C", list);

    // Print list of plugins
    PluginList *node = list;
    while (node) {
        printf("Name: %s\n", node->plugin.name);
        printf("Version: %d\n", node->plugin.version);
        printf("Enabled: %s\n", node->plugin.enabled ? "true" : "false");
        printf("------\n");
        node = node->next;
    }

    // Remove a plugin from list
    list = remove_plugin_from_list("Plugin B", list);

    // Free memory for plugins and linked list
    free(plugin1->name);
    free(plugin1);
    free(plugin2->name);
    free(plugin2);
    free(plugin3->name);
    free(plugin3);
    PluginList *temp;
    while (list) {
        temp = list->next;
        free(list->plugin.name);
        free(list);
        list = temp;
    }

    return 0;
}