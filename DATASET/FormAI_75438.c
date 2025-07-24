//FormAI DATASET v1.0 Category: Browser Plugin ; Style: surprised
#include <stdio.h>

void surprised()
{
    printf("WOW! I can't believe it!\n");
}

void pluginLoaded()
{
    printf("Congratulations! You have successfully loaded the Surprised Plugin!\n");
    surprised();
}

int main()
{
    printf("Trying to load Surprised Plugin...\n");
    pluginLoaded();

    return 0;
}

/*
Output:

Trying to load Surprised Plugin...
Congratulations! You have successfully loaded the Surprised Plugin!
WOW! I can't believe it!

*/