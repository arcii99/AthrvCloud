//FormAI DATASET v1.0 Category: Browser Plugin ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This program will keep track of the number of times a user visits a certain website and display a greeting message

int main() {
    char* website = "www.example.com";
    int visits = 0;
    
    //check if the website has been visited before
    FILE* file = fopen("visited_websites.txt", "r");
    if(file) {
        char line[100];
        while(fgets(line, sizeof(line), file)) {
            if(strstr(line, website)) {
                visits = atoi(strchr(line, ':') + 1);
                break;
            }
        }
        fclose(file);
    }
    
    //increment the visit counter
    visits++;
    
    //update the visited_websites.txt file
    file = fopen("visited_websites.txt", "a+");
    if(file) {
        char buffer[100];
        sprintf(buffer, "%s:%d\n", website, visits);
        fputs(buffer, file);
        fclose(file);
    }
    
    //display a welcome message
    if(visits == 1) {
        printf("Welcome to %s! Enjoy your stay.\n", website);
    } else {
        printf("Welcome back to %s! You have visited %d times.\n", website, visits);
    }
    
    return 0;
}