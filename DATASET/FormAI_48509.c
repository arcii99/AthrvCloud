//FormAI DATASET v1.0 Category: Browser Plugin ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>

void crypto(char* data, char key) {
    int i;
    for (i = 0; data[i] != '\0'; i++) {
        data[i] ^= key;
    }
}

/* This function logs all user activity on the browser */

void log_activity(char* url, char* title, char key) {
    FILE *f = fopen("activity.log", "a");
    if (f == NULL) {
        printf("Error opening log file!");
        exit(1);
    }
    crypto(url, key);
    crypto(title, key);
    fprintf(f, "URL: %s\nTitle: %s\n\n", url, title);
    fclose(f);
}

/* This function intercepts all HTTP/HTTPS requests and logs them */

void intercept_request(char* url, char* headers, char key) {
    char* host = strstr(url, "//");
    if (host != NULL) {
        host += 2;
    } else {
        host = url;
    }
    char* end = strstr(host, "/");
    if (end != NULL) {
        *end = '\0';
    }
    log_activity(host, headers, key);
}

int main() {
    char* url = "https://www.example.com/path/to/page.html";
    char* headers = "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:58.0) Gecko/20100101 Firefox/58.0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: en-US,en;q=0.5\r\nReferer: https://www.example.com/\r\nConnection: keep-alive\r\nUpgrade-Insecure-Requests: 1";
    char key = 's';
    intercept_request(url, headers, key);
    return 0;
}