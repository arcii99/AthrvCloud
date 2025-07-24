//FormAI DATASET v1.0 Category: Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

struct love {
    char name[20];
    int age;
    char gender[10];
    char hobby[20];
};

int main() {
    printf("Hello, my love!\n\n");
    printf("I just wanted to create something special for you.\n");
    printf("Just to show you how much I love you and how happy you make me.\n\n");

    printf("So, I decided to create a program that tells the world that I love you, and I will always love you.\n");
    printf("I know it's not much, but I hope you like it.\n\n");

    struct love me;
    printf("Enter your name: ");
    scanf("%s", me.name);

    printf("Enter your age: ");
    scanf("%d", &me.age);

    printf("Enter your gender: ");
    scanf("%s", me.gender);

    printf("Enter your hobby: ");
    scanf("%s", me.hobby);

    printf("\n\n");

    printf("Hello, %s!\n", me.name);
    printf("You are %d years old, and you are a %s who enjoys %s.\n", me.age, me.gender, me.hobby);
    printf("But more importantly, you are the love of my life, and I would do anything for you.\n\n");

    printf("I love you more than words could ever express, and I am so grateful to have you in my life.\n");
    printf("I promise to always love you, cherish you, and make you happy.\n");
    printf("I hope this silly little program puts a smile on your face and lets you know how much you mean to me.\n");

    return 0;
}