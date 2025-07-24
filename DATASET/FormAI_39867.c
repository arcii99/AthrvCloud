//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 100
#define MAX_RESPONSE_LENGTH 200

bool is_online(char* url){
    char command[MAX_URL_LENGTH + 20];
    char result[MAX_RESPONSE_LENGTH];

    sprintf(command, "curl --silent --head %s | grep \"HTTP/1.[01]\" | cut -d ' ' -f 2", url);

    FILE* fp = popen(command, "r");
    fgets(result, MAX_RESPONSE_LENGTH, fp);
    pclose(fp);

    if (strcmp(result, "200\n") == 0){
        return true;
    }
    return false;
}

int main(){
    char url[MAX_URL_LENGTH];
    printf("Enter the URL you wish to monitor: ");
    scanf("%s", url);

    while(true){
        if(is_online(url)){
            printf("%s is ONLINE\n", url);
        }else{
            printf("%s is OFFLINE\n", url);
        }
        sleep(10); // Sleep for 10 seconds before checking again
    }

    return 0;
}