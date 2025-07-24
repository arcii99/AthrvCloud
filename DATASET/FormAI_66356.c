//FormAI DATASET v1.0 Category: Browser Plugin ; Style: portable
#include <stdio.h>

#ifdef _WIN32
    #include "windows.h"
#else
    #include "unistd.h"
#endif

#ifdef __APPLE__
    #define BROWSER_PLUGIN_NAME "SafariPlugin"
#else
    #define BROWSER_PLUGIN_NAME "ChromePlugin"
#endif

int main()

{

    printf("Hello, welcome to the %s example plugin!", BROWSER_PLUGIN_NAME);

#ifdef _WIN32
    Sleep(2000); // Wait for 2 seconds on Windows
#else
    sleep(2); // Wait for 2 seconds on Unix-based systems
#endif

    printf("\nPlugin loaded successfully.");

    return 0;

}