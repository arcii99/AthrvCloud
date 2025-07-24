//FormAI DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define LOG_BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Usage: log-analysis <log-file-path>\n");
        return -1;
    }

    FILE *fp = fopen(argv[1], "r");
    char log_buffer[LOG_BUFFER_SIZE];

    if(fp == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    // Let's count how many requests were made in total
    int total_requests = 0;
    while(fgets(log_buffer, LOG_BUFFER_SIZE, fp)) {
        if(strstr(log_buffer, "GET") != NULL || strstr(log_buffer, "POST") != NULL || strstr(log_buffer, "PUT") != NULL || strstr(log_buffer, "DELETE") != NULL) {
            total_requests++;
        }
    }
    printf("Total Requests: %d\n", total_requests);

    // Let's count how many requests were made by each unique IP address
    rewind(fp);
    int ip_address_count = 0;
    char* ip_addresses[100];
    int num_requests_by_ip[100];

    while(fgets(log_buffer, LOG_BUFFER_SIZE, fp)) {
        char* ip_address = strtok(log_buffer, " ");
        char* request = strtok(NULL, " ");
        char* protocol = strtok(NULL, " ");
        char* status_code = strtok(NULL, " ");

        // Only count requests with a successful status code (2xx or 3xx)
        if(strstr(status_code, "2") != NULL || strstr(status_code, "3") != NULL) {
            int found_match = -1;
            for(int i=0; i<ip_address_count; i++) {
                if(strcmp(ip_address, ip_addresses[i]) == 0) {
                    found_match = i;
                    break;
                }
            }
            if(found_match == -1) {
                ip_addresses[ip_address_count] = malloc(strlen(ip_address)+1);
                strcpy(ip_addresses[ip_address_count], ip_address);
                num_requests_by_ip[ip_address_count] = 1;
                ip_address_count++;
            } else {
                num_requests_by_ip[found_match]++;
            }
        }
    }

    printf("\nRequests by IP Address:\n");
    for(int i=0; i<ip_address_count; i++) {
        printf("%s: %d\n",ip_addresses[i], num_requests_by_ip[i]);
    }

    // Let's find out which user agents were used to make requests to the server
    rewind(fp);
    int user_agent_count = 0;
    char* user_agents[100];
    int num_requests_by_user_agent[100];

    while(fgets(log_buffer, LOG_BUFFER_SIZE, fp)) {
        char* user_agent = strstr(log_buffer, "User-Agent:");
        if(user_agent != NULL) {
            user_agent += strlen("User-Agent:");
            int found_match = -1;
            for(int i=0; i<user_agent_count; i++) {
                if(strcmp(user_agent, user_agents[i]) == 0) {
                    found_match = i;
                    break;
                }
            }
            if(found_match == -1) {
                user_agents[user_agent_count] = malloc(strlen(user_agent)+1);
                strcpy(user_agents[user_agent_count], user_agent);
                num_requests_by_user_agent[user_agent_count] = 1;
                user_agent_count++;
            } else {
                num_requests_by_user_agent[found_match]++;
            }
        }
    }

    printf("\nRequests by User Agent:\n");
    for(int i=0; i<user_agent_count; i++) {
        printf("%s: %d\n",user_agents[i], num_requests_by_user_agent[i]);
    }

    fclose(fp);
    return 0;
}