//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    int i, j, flag = 1;
    printf("Welcome to the Palindrome Checker 2.0\n");
    printf("Enter a string to check if it is a palindrome: ");
    scanf("%s", input);
    int len = strlen(input);
    for (i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        if (input[i] != input[j])
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        printf("\nCongratulations! The string is a palindrome.\n");
        printf("###########################################\n");
        printf("##          __   __     ____             ##\n");
        printf("##        /    |   |   /    \\            ##\n");
        printf("##       /     |   |  /      \\           ##\n");
        printf("##      /      |   | /   /\\   \\          ##\n");
        printf("##     /       |   |/   /__\\   \\         ##\n");
        printf("##     \\       |   |\\         /         ##\n");
        printf("##      \\      |   | \\_______/          ##\n");
        printf("##       \\_____|___|                     ##\n");
        printf("###########################################\n");
    }
    else
    {
        printf("\nSorry! The string is not a palindrome.\n");
        printf("########################################\n");
        printf("##          ___________                ##\n");
        printf("##         /           \\               ##\n");
        printf("##        /             \\              ##\n");
        printf("##       /   __     __   \\             ##\n");
        printf("##      /   / /\\   /\\ \\   \\            ##\n");
        printf("##      \\   \\_____/____/   /            ##\n");
        printf("##       \\                 /            ##\n");
        printf("##        \\_______________/             ##\n");
        printf("########################################\n");
    }
    return 0;
}