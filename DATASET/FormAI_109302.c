//FormAI DATASET v1.0 Category: Browser Plugin ; Style: mind-bending
#include <stdio.h>

typedef struct {
    const char* name;
    void (*fn)();
} Plugin;

void myPlugin() {
    printf("Hello, I am a browser plugin written in C!");
}

Plugin plugins[] = {
    {"My Plugin", myPlugin},
};

void load_plugins() {
    int num_plugins = sizeof(plugins) / sizeof(plugins[0]);

    printf("Loading Browser Plugins...\n");

    for (int i = 0; i < num_plugins; i++) {
        printf("Loading Plugin: %s\n", plugins[i].name);
        plugins[i].fn();
    }

    printf("All Plugins Loaded Successfully.");
}

int main() {
    load_plugins();
    return 0;
}