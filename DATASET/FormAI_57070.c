//FormAI DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Romeo's Digital Diary
int main() {
    char password[20];
    printf("Dearest Juliet, welcome to my digital diary.\nI have set a password to protect my personal thoughts. Please enter the password to proceed:\n");
    scanf("%s", &password);
    if(strcmp(password, "romeo123") == 0) {
        printf("Welcome to my diary, my sweet Juliet.\n");
        printf("Today is April 1, 1600.\n");
        printf("I have spent the entire day thinking about you, my love. Your beauty and grace takes my breath away.\n");
        printf("I long for the day when we can be together forever.\n");
        printf("I also wrote a small C program to express my feelings for you. Here it is:\n\n");

        printf("int main() {\n");
        printf("\tprintf(\"My sweet Juliet, you are the light of my life.\\n");
        printf("\tI long for the day when we can be together forever.\\n");
        printf("\tI love you more and more each day.\\n\");\n");
        printf("\treturn 0;\n");
        printf("}\n");

        printf("\nI hope you liked my little program, my dearest. I will write more tomorrow.\n\n");

        printf("Yours forever,\nRomeo");

    } else {
        printf("Wrong password. I'm sorry, Juliet, but I cannot let you access my personal thoughts.\n");
        printf("Here is a C program as an apology:\n\n");

        printf("int main() {\n");
        printf("\tprintf(\"My dearest Juliet, I apologize for denying you access to my diary.\\n");
        printf("\tI promise to make it up to you with my love and devotion.\\n");
        printf("\tPlease forgive me, my sweet.\\n\");\n");
        printf("\treturn 0;\n");
        printf("}\n");

        printf("\nI hope this makes up for my mistake. Please forgive me, my love.\n\n");

        printf("Yours forever,\nRomeo");
    }
    return 0;
}