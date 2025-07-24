//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_URL_LENGTH 200
#define MAX_RESPONSE_SIZE 8192
#define TIMEOUT_IN_SECONDS 10

typedef struct Website {
    char url[MAX_URL_LENGTH];
    int status_code;
    time_t last_checked;
} Website;

int get_http_status_code(char* response) {
    char* code = strstr(response, "HTTP/1.");
    if (code != NULL) {
        return atoi(code + 9);
    }
    return -1;
}

char* get_website_response(char* url) {
    char command[MAX_URL_LENGTH + 50] = "curl --max-time ";
    char timeout_seconds[4];
    snprintf(timeout_seconds, 4, "%d", TIMEOUT_IN_SECONDS);
    strcat(command, timeout_seconds);
    strcat(command, " ");
    strcat(command, url);
    strcat(command, " 2>&1");
    FILE* cmd = popen(command, "r");
    if (!cmd) {
        return NULL;
    }

    char* response = (char*) malloc(MAX_RESPONSE_SIZE * sizeof(char));
    int response_length = 0;
    while(!feof(cmd)) {
        if (response_length >= MAX_RESPONSE_SIZE) {
            break;
        }
        response[response_length++] = fgetc(cmd);
    }
    pclose(cmd);
    return response;
}

void update_website_status(Website* website) {
    char* response = get_website_response(website->url);
    if (response == NULL) {
        website->status_code = -1;
        return;
    }
    website->status_code = get_http_status_code(response);
    free(response);
}

void print_website_status(Website* website) {
    char status_message[20] = "";
    time_t current_time = time(NULL);
    double seconds_since_check = difftime(current_time, website->last_checked);
    if (website->status_code == -1) {
        strcpy(status_message, "offline");
    } else {
        strcpy(status_message, "online");
    }
    printf("%s - %s [%d]", website->url, status_message, website->status_code);
    if (seconds_since_check > 120) {
        printf(" (checked %d seconds ago)\n", (int) seconds_since_check);
    } else {
        printf("\n");
    }
}

int main() {
    Website google = {"https://www.google.com", -1, time(NULL)};
    Website github = {"https://www.github.com", -1, time(NULL)};
    Website reddit = {"https://www.reddit.com", -1, time(NULL)};
    while(1) {
        update_website_status(&google);
        update_website_status(&github);
        update_website_status(&reddit);
        system("clear");
        printf("Cyberpunk Uptime Monitor\n\n");
        print_website_status(&google);
        print_website_status(&github);
        print_website_status(&reddit);
        fflush(stdout);
        sleep(10);
    }
    return 0;
}