//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    printf("Welcome to the IMAP client program!\n");
    printf("Please enter your email username: ");

    char username[100];
    scanf("%s", username);

    printf("Please enter your email password: ");

    char password[100];
    scanf("%s", password);

    if(strcmp(username, "superman") == 0 && strcmp(password, "LoisLane") == 0){
        printf("Login successful! Retrieving email...\n");

        printf("[1] From: Batman <batman@gotham.com>\n");
        printf("Subject: Urgent!\n");
        printf("Message: Hey Supes, need your help in Gotham City ASAP! Robin's gone missing again...\n");

        printf("[2] From: Green Lantern <greenlantern@dccomics.com>\n");
        printf("Subject: Potential Threat\n");
        printf("Message: Hal Jordan here. I've received intel on a potential attack on Earth. Need your assistance, Superman.\n");

        printf("[3] From: The Flash <flash@justiceleague.com>\n");
        printf("Subject: Lunch Plans\n");
        printf("Message: Hey buddy, how about grabbing some burgers at the usual spot today? Let me know if you're in.\n");
    } else {
        printf("Invalid username or password. Please try again.\n");
    }

    return 0;
}