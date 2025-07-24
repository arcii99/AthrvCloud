//FormAI DATASET v1.0 Category: Browser Plugin ; Style: paranoid
#include <stdio.h>
#include <string.h>

/* Define sample plugin functions */
void function1(){
    printf("This function does nothing.\n");
}

void function2(char *input){
    char buffer[100];
    strcpy(buffer, input);
    printf("Input was: %s\n", buffer);
}

void function3(){
    printf("This function accesses sensitive data.\n");
}

int main(){

    /* Initialize plugin status variables */
    int pluginInstalled = 0;
    int sensitiveDataAccessed = 0;

    /* Check if plugin is installed */
    if(pluginInstalled == 0){
        printf("Plugin not installed. Aborting.\n");
        return 0;
    }

    /* Call function1 */
    function1();

    /* Call function2 with user input */
    char userInput[100];
    printf("Enter user input: ");
    scanf("%s", userInput);
    function2(userInput);

    /* Check if sensitive data is accessed */
    if(sensitiveDataAccessed == 0){
        printf("No sensitive data accessed. Exiting.\n");
        return 0;
    }

    /* If sensitive data is accessed, notify user and exit */
    printf("Sensitive data accessed. Exiting in paranoid mode.\n");
    return -1;
}