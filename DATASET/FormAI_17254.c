//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: systematic
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool contains_special_characters(char *password);
bool contains_uppercase_letters(char *password);
bool contains_lowercase_letters(char *password);
bool contains_numbers(char *password);

int main()
{
    char password[50];
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin); // Read input from user
    password[strcspn(password, "\n")] = '\0'; // Remove newline character from input
    
    bool contains_special = contains_special_characters(password);
    bool contains_upper = contains_uppercase_letters(password);
    bool contains_lower = contains_lowercase_letters(password);
    bool contains_numbers_chars = contains_numbers(password);
    
    int score = 0;
    if (strlen(password) >= 8 && strlen(password) <= 16)
    {
        score += 30;
    }
    if (contains_special)
    {
        score += 20;
    }
    if (contains_upper)
    {
        score += 20;
    }
    if (contains_lower)
    {
        score += 20;
    }
    if (contains_numbers_chars)
    {
        score += 10;
    }
    
    printf("Password strength: %d\n", score);
    return 0;
}

bool contains_special_characters(char *password)
{
    char *special_chars = "!@#$%^&*()_+{}[];:<>,./?";
    for (int i = 0; i < strlen(special_chars); i++)
    {
        if (strchr(password, special_chars[i]) != NULL)
        {
            return true;
        }
    }
    return false;
}

bool contains_uppercase_letters(char *password)
{
    for (int i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            return true;
        }
    }
    return false;
}

bool contains_lowercase_letters(char *password)
{
    for (int i = 0; i < strlen(password); i++)
    {
        if (islower(password[i]))
        {
            return true;
        }
    }
    return false;
}

bool contains_numbers(char *password)
{
    for (int i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            return true;
        }
    }
    return false;
}