//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: ephemeral
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  

int main(int argc, char *argv[]) {  
    if (argc < 2) {
        printf("Error: No URL specified.\n");
        exit(1);
    }
    
    char *url = argv[1];
    time_t current_time;
    char* c_time_string;
    
    while(1) {
        FILE *fp = NULL;
        fp = fopen(url, "r");
        current_time = time(NULL);
        c_time_string = ctime(&current_time);
        
        if (fp == NULL) {
            printf("Website is down at %s", c_time_string);
        } else {
            printf("Website is up at %s", c_time_string);
            fclose(fp);
        }
        
        sleep(60);
    }
    
    return 0;
}