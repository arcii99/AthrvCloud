//FormAI DATASET v1.0 Category: Browser Plugin ; Style: Cryptic
//The Cryptic Browser Plugin
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char* name;
    void (*function)();
} Plugin;

void plugin1(){
    printf("Plugin 1 activated.\n");
}

void plugin2(){
    printf("Plugin 2 activated.\n");
}

void plugin3(){
    printf("Plugin 3 activated.\n");
}

int main(){

    Plugin plugins[3];
    char* plugin_names[] = {"Plugin 1", "Plugin 2", "Plugin 3"};

    printf("The Cryptic Browser Plugin is activated!\n");

    plugins[0].name = plugin_names[0];
    plugins[0].function = plugin1;
    plugins[1].name = plugin_names[1];
    plugins[1].function = plugin2;
    plugins[2].name = plugin_names[2];
    plugins[2].function = plugin3;

    int i;
    for(i=0;i<3;i++){
        printf("Plugin %d: %s\n", i+1, plugins[i].name);
        if(i % 2 == 0)
            plugins[i].function();
    }

    printf("The Cryptic Browser Plugin has finished its job!\n");
    return 0;
}