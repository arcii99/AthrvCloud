//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: surprised
#include<stdio.h>
#include<string.h>

int main()
{
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter your candidate's name:\n");
    char candidate[50]; //max 50 characters for candidate's name
    fgets(candidate, 50, stdin); //getting input from user
    
    //removing newline character from input
    if (candidate[strlen(candidate) - 1] == '\n')
        candidate[strlen(candidate) - 1] = '\0';
    
    printf("You have voted for %s\nThank you for using our system!\n", candidate);
    return 0;
}