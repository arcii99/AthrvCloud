//FormAI DATASET v1.0 Category: File Synchronizer ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PATH_LEN 1024

void syncFiles(const char* src, const char* dest)
{
    char srcPath[MAX_PATH_LEN];
    char destPath[MAX_PATH_LEN];
    char cmd[MAX_PATH_LEN * 2];
    
    sprintf(cmd, "mkdir -p %s", dest);
    system(cmd);
    
    sprintf(cmd, "find %s -type f | sed 's,%s,%s,' | while read source; do " \
        "dest=\"$dest/$(echo \"$source\" | sed 's,%s,,')\" && " \
        "mkdir -p \"$(dirname \"$dest\")\" && " \
        "cp \"$source\" \"$dest\" && " \
        "echo \"Copied $source to $dest\"; done",
        src, src, dest, src);
    
    system(cmd);
}

int main()
{
    const char* src = "/path/to/source";
    const char* dest = "/path/to/destination";
    
    syncFiles(src, dest);
    
    return 0;
}