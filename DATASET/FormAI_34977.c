//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: automated
#include<stdio.h>
#include<string.h>

// Function to translate C Cat language to English
void translate(char c_cat[]) {
    char *english;
    if(strcmp(c_cat, "Mew") == 0) {
        english = "Print";
    } else if(strcmp(c_cat, "Wuff") == 0) {
        english = "Scan";
    } else if(strcmp(c_cat, "Purr") == 0) {
        english = "If";
    } else if(strcmp(c_cat, "Hiss") == 0) {
        english = "Else";
    } else if(strcmp(c_cat, "Scratch") == 0) {
        english = "For";
    } else if(strcmp(c_cat, "Lick") == 0) {
        english = "While";
    } else if(strcmp(c_cat, "Bite") == 0) {
        english = "Switch";
    } else if(strcmp(c_cat, "Nyan") == 0) {
        english = "Case";
    } else if(strcmp(c_cat, "Feline") == 0) {
        english = "Default";
    } else if(strcmp(c_cat, "Chase") == 0) {
        english = "Break";
    } else if(strcmp(c_cat, "Claw") == 0) {
        english = "Continue";
    } else if(strcmp(c_cat, "Tail") == 0) {
        english = "Return";
    } else {
        english = "Unknown";
    }
    printf("%s ", english);
}

int main() {
    char c_cat[50];
    printf("Enter C Cat language code: ");
    scanf("%s", c_cat);
    char *token;
    token = strtok(c_cat, "_");
    while(token != NULL) {
        translate(token);
        token = strtok(NULL, "_");
    }
    return 0;
}