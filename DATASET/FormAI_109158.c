//FormAI DATASET v1.0 Category: Browser Plugin ; Style: random
/* This is a fun C Browser Plugin example program! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define some variables */
char browser[] = "chrome";
char pluginName[] = "SuperPlugin";
int version = 1;

/* Define our plugin functions */
void initPlugin();
void getVersion();
void performAction(char*);

/* Main function */
int main()
{
    printf("Welcome to %s plugin %s (Version %d)!\n", browser, pluginName, version);
    
    /* Initialize our plugin */
    initPlugin();
    
    /* Get our plugin version */
    getVersion();
    
    /* Perform some actions */
    performAction("action1");
    performAction("action2");
    performAction("action3");
    
    printf("Thanks for using %s plugin %s (Version %d)!\n", browser, pluginName, version);
    
    /* Exit */
    return 0;
}

/* Initialize our plugin */
void initPlugin()
{
    printf("%s plugin initializing...\n", pluginName);
    /* Perform some initialization tasks */
    printf("%s plugin initialized!\n", pluginName);
}

/* Get our plugin version */
void getVersion()
{
    printf("Current %s plugin version is %d.\n", pluginName, version);
}

/* Perform an action */
void performAction(char* action)
{
    printf("Performing %s action...\n", action);
    /* Perform some action tasks */
    printf("%s action completed!\n", action);
}