//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    FILE *fp;
    char path[1035];

    /* Open the command for reading. */
    fp = popen("/System/Library/PrivateFrameworks/Apple80211.framework/Versions/Current/Resources/airport -I | grep CtlRSSI", "r");
    if (fp == NULL) 
    {
        printf("Failed to run command\n" );
        exit(1);
    }

    /* Read the output a line at a time - buffer size is 1035. */
    while (fgets(path, sizeof(path)-1, fp) != NULL) 
    {
        printf("%s", path);
    }

    /* close */
    pclose(fp);
    
    return 0;
}