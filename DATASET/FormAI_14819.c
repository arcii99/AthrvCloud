//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: excited
#include <stdio.h>
#include <string.h>

int main() {

    char cat_speak[100];
    printf("Enter what your cat is saying: ");
    scanf("%s", cat_speak);

    if(strcmp(cat_speak, "meow") == 0) {
        printf("Your cat is saying: Hello, human!\n");
    }
    else if(strcmp(cat_speak, "purr") == 0) {
        printf("Your cat is saying: I'm happy and content right now.\n");
    }
    else if(strcmp(cat_speak, "hiss") == 0) {
        printf("Your cat is saying: I'm feeling threatened, please leave me alone!\n");
    }
    else if(strcmp(cat_speak, "yowl") == 0) {
        printf("Your cat is saying: I need attention, play with me!\n");
    }
    else if(strcmp(cat_speak, "chirrup") == 0) {
        printf("Your cat is saying: You're my favorite human!\n");
    }
    else if(strcmp(cat_speak, "growl") == 0) {
        printf("Your cat is saying: I'm angry and you're in for it now!\n");
    }
    else {
        printf("I'm sorry, I don't understand what your cat is saying.\n");
    }

    return 0;
}