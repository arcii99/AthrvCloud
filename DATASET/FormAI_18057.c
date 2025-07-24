//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000
#define MAX_IP_LEN 16
#define MAX_USER_LEN 20

typedef struct IPNode{
    char ip[MAX_IP_LEN];
    struct IPNode* next;
}IPNode;

typedef struct UserNode{
    char user[MAX_USER_LEN];
    IPNode* ip_list;
    struct UserNode* next;
}UserNode;

int main(){
    FILE* log_file = fopen("log.txt", "r");
    if (log_file == NULL){
        printf("Error opening log file.\n");
        return 1;
    }

    char curr_line[MAX_STR_LEN];
    UserNode* user_list = NULL;
    while (fgets(curr_line, MAX_STR_LEN, log_file)){
        char* curr_ip_str = strstr(curr_line, "SRC=");
        char* curr_user_str = strstr(curr_line, "user=");
        if (curr_ip_str != NULL && curr_user_str != NULL){
            curr_ip_str = strtok(curr_ip_str + 4, " ");
            curr_user_str = strtok(curr_user_str + 5, " ");
            int ip_exists = 0;
            UserNode* curr_user_node = user_list;
            while (curr_user_node != NULL){
                if (strcmp(curr_user_node->user, curr_user_str) == 0){
                    IPNode* curr_ip_node = curr_user_node->ip_list;
                    while (curr_ip_node != NULL){
                        if (strcmp(curr_ip_node->ip, curr_ip_str) == 0){
                            ip_exists = 1;
                            break;
                        }
                        curr_ip_node = curr_ip_node->next;
                    }
                    if (!ip_exists){
                        IPNode* new_ip_node = (IPNode*)malloc(sizeof(IPNode));
                        strcpy(new_ip_node->ip, curr_ip_str);
                        new_ip_node->next = curr_user_node->ip_list;
                        curr_user_node->ip_list = new_ip_node;
                        printf("Intrusion detected: User %s accessed from new IP %s.\n", curr_user_str, curr_ip_str);
                    }
                    break;
                }
                curr_user_node = curr_user_node->next;
            }
            if (curr_user_node == NULL){
                UserNode* new_user_node = (UserNode*)malloc(sizeof(UserNode));
                IPNode* new_ip_node = (IPNode*)malloc(sizeof(IPNode));
                strcpy(new_user_node->user, curr_user_str);
                strcpy(new_ip_node->ip, curr_ip_str);
                new_ip_node->next = NULL;
                new_user_node->ip_list = new_ip_node;
                new_user_node->next = user_list;
                user_list = new_user_node;
            }
        }
    }

    fclose(log_file);
    return 0;
}