//FormAI DATASET v1.0 Category: Email Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char to[100], subject[100], message[500];

    printf("Hail traveller, you have come seeking to send a message via email.\n");
    printf("Please enter the recipient's electronic ravens name:\n");
    scanf("%s", to);
    printf("What is the subject of your missive, sire?\n");
    scanf("%s", subject);
    printf("Finally, what is the content of your message?\n");
    scanf("%s", message);

    FILE *fp;
    fp = fopen("ravens.txt", "a+"); // 'ravens' is medieval for 'emails'
    if (fp == NULL) {
        printf("Methinks the raven has flown the coop!\n");
        exit(1);
    }

    fprintf(fp, "To: %s\nSubject: %s\n\n%s\n\n", to, subject, message);
    printf("Your message has been sent via the electronic ravenry, sire!\n");

    fclose(fp);

    return 0;
}