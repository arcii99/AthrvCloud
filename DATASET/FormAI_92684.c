//FormAI DATASET v1.0 Category: Firewall ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_IP_LEN 15
#define MAX_RULES 50
#define ALLOW 1
#define DENY 0

// Structure to hold IP address and permission
struct Rule{
    char IP[MAX_IP_LEN+1];
    int permission;
};

// Function to validate IP address format
int validIPAddress(char* IP) {
    int count = 0;
    char* token = strtok(IP, ".");
    while (token != NULL) {
        count++;
        if (count > 4) return 0;
        int len = strlen(token);
        if (len < 1 || len > 3) return 0;
        for (int i = 0; i < len; i++) {
            if (!isdigit(token[i])) return 0;
        }
        int num = atoi(token);
        if (num < 0 || num > 255) return 0;
        if (len > 1 && token[0] == '0') return 0;
        token = strtok(NULL, ".");
    }
    return count == 4;
}

// Function to add a new rule
void addRule(struct Rule rules[], char* IP, int permission, int* rule_count){
    struct Rule new_rule;
    strcpy(new_rule.IP, IP);
    new_rule.permission = permission;
    rules[*rule_count] = new_rule;
    (*rule_count)++;
}

// Function to check if a given IP address is allowed or not
int checkPermission(struct Rule rules[], char* IP, int rule_count){
    for(int i=0; i<rule_count; i++){
        if(strcmp(IP, rules[i].IP) == 0){
            return rules[i].permission;
        }
    }
    return DENY;
}

int main(){
    struct Rule rules[MAX_RULES];
    int rule_count = 0;

    // Add some example rules
    addRule(rules, "192.168.0.1", ALLOW, &rule_count);
    addRule(rules, "192.168.0.2", DENY, &rule_count);

    // Test some IP addresses
    char IP[MAX_IP_LEN+1];
    printf("Enter an IP address to check permission: ");
    scanf("%s", IP);
    if(validIPAddress(IP)){
        int permission = checkPermission(rules, IP, rule_count);
        if(permission == ALLOW){
            printf("Access granted!\n");
        }
        else{
            printf("Access denied!\n");
        }
    }
    else {
        printf("Invalid IP address format!\n");
    }
    
    return 0;
}