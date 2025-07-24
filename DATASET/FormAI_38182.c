//FormAI DATASET v1.0 Category: Firewall ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

const char* WHITE_LIST[] = {"www.google.com", "www.facebook.com", "www.twitter.com"};   // list of allowed websites
const int WHITE_LIST_SIZE = 3;   // number of allowed websites

int is_allowed(const char* website) {
    for(int i = 0; i < WHITE_LIST_SIZE; i++) {
        if(strcmp(website, WHITE_LIST[i]) == 0) {
            return 1;   // website is allowed
        }
    }
    return 0;   // website is not allowed
}

int main() {
    char website[100];
    printf("Enter website address: ");
    fgets(website, 100, stdin);
    website[strcspn(website, "\n")] = '\0';   // remove newline character
    
    if(is_allowed(website)) {
        printf("Access granted to %s", website);
    } else {
        printf("Access denied to %s", website);
    }
    
    return 0;
}