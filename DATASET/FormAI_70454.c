//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void check_website(char *url) {
    char command[256];
    sprintf(command, "curl -Is --connect-timeout 5 %s | head -n 1 | grep -i -E '200|302|301'", url);
    FILE *fp = popen(command, "r");
    char result[256];
    if(fgets(result, sizeof(result), fp) != NULL) {
        printf("%s is up!\n", url);
    } else {
        printf("%s is down!\n", url);
    }
    pclose(fp);
}

int main() {
    char *urls[] = {"http://www.example.com", "http://www.google.com", "http://www.github.com"};
    int num_urls = 3;
    while(1) {
        for(int i = 0; i < num_urls; i++) {
            check_website(urls[i]);
        }
        printf("----------------\n");
        sleep(10);
    }
    return 0;
}