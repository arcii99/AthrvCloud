//FormAI DATASET v1.0 Category: Email Client ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char from[50];
    char to[50];
    char subject[100];
    char message[1000];

    printf("----- C Email Client -----\n\n");

    printf("From: ");
    scanf("%s", from);

    printf("To: ");
    scanf("%s", to);

    printf("Subject: ");
    scanf("%s", subject);

    printf("Message: ");
    scanf("%s", message);

    FILE *fp = fopen("email.txt", "w");
    if(fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fp, "From: %s\n", from);
    fprintf(fp, "To: %s\n", to);
    fprintf(fp, "Subject: %s\n", subject);
    fprintf(fp, "Message: %s\n", message);

    fclose(fp);
    printf("\nEmail sent successfully!\n");

    return 0;
}