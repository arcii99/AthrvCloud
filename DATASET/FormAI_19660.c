//FormAI DATASET v1.0 Category: Database querying ; Style: funny
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Function to create a funny message for query results
void printResult(char* result) {
    if(strcmp(result, "NULL") == 0) {
        printf("I searched high and low, but all I found was a NULL pointer. Sorry about that!\n");
        return;
    }
    printf("Ta-da! The search is finally over and I have found the result: %s\n", result);
    printf("I feel like a magician today. Who else needs a query to be performed?\n");
}

int main() {
    char dbName[200];
    printf("Greetings human, I am the querybot and I am here to assist you with querying your C database.\n");
    printf("Please enter the name of your database: ");
    scanf("%s", dbName);
    printf("Great choice! A database named %s is just what we need for our adventure today.\n", dbName);

    char query[500];
    printf("Now, tell me what you're searching for and I'll do my best to find it for you: ");
    scanf(" %[^\n]s", query);

    if(strstr(query, "SELECT") != NULL) {
        printf("SELECT, eh? I'm impressed with your taste in queries.\n");
        printf("Hm...let me look that up for you real quick...\n");
        char* result = "NULL"; // In case query doesn't match any results
        // Simulating a database search
        if(strcmp(query, "SELECT funny_jokes FROM database") == 0) {
            result = "Why don't scientists trust atoms?...Because they make up everything.";
        } else if(strcmp(query, "SELECT silly_puns FROM database") == 0) {
            result = "Why don't some couples go to the gym?...Because some relationships don't work out!";
        } else if(strcmp(query, "SELECT wacky_facts FROM database") == 0) {
            result = "A group of flamingos is called a flamboyance. Now that's fancy!";
        }
        // Function to print query result (and a funny message)
        printResult(result);
    } else {
        printf("Your query did not contain the sacred word 'SELECT', and therefore is not worthy of my database searching skills.\n");
    }

    printf("Thanks for playing along! Have a hilarious day!\n");

    return 0;
}