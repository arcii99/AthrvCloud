//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MIN_LEN 8
#define MAX_LEN 20

// Function prototypes
int count_occurrences(char *password, char c);
bool is_password_valid(char *password);
int password_strength(char *password);

int main()
{
    // Get password from user
    char password[MAX_LEN + 1] = {0};
    printf("Enter password: ");
    fgets(password, MAX_LEN, stdin);
    password[strcspn(password, "\n")] = 0; // Trim newline character

    // Check if password is valid
    if (!is_password_valid(password))
    {
        printf("Invalid password\n");
        return 1;
    }

    // Get password strength
    int strength = password_strength(password);

    // Output password strength
    printf("Password strength: %d\n", strength);

    return 0;
}

// Count occurrences of a character in a string
int count_occurrences(char *password, char c)
{
    int count = 0;
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] == c)
            count++;
    }
    return count;
}

// Check if password is valid
bool is_password_valid(char *password)
{
    // Check length
    int len = strlen(password);
    if (len < MIN_LEN || len > MAX_LEN)
        return false;

    // Check for uppercase letters, lowercase letters, and digits
    bool has_upper = false, has_lower = false, has_digit = false;
    for (int i = 0; i < len; i++)
    {
        if (isupper(password[i]))
            has_upper = true;
        else if (islower(password[i]))
            has_lower = true;
        else if (isdigit(password[i]))
            has_digit = true;
    }

    if (!has_upper || !has_lower || !has_digit)
        return false;

    // Check for special characters
    if (count_occurrences(password, '!') == 0 && count_occurrences(password, '@') == 0 &&
        count_occurrences(password, '#') == 0 && count_occurrences(password, '$') == 0 &&
        count_occurrences(password, '%') == 0 && count_occurrences(password, '^') == 0 &&
        count_occurrences(password, '&') == 0 && count_occurrences(password, '*') == 0)
        return false;

    return true;
}

// Determine password strength
int password_strength(char *password)
{
    int len = strlen(password);
    int score = len * 4;

    // Check for digits
    int digit_count = count_occurrences(password, '0') + count_occurrences(password, '1') +
                      count_occurrences(password, '2') + count_occurrences(password, '3') +
                      count_occurrences(password, '4') + count_occurrences(password, '5') +
                      count_occurrences(password, '6') + count_occurrences(password, '7') +
                      count_occurrences(password, '8') + count_occurrences(password, '9');
    score += digit_count * 4;

    // Check for uppercase letters
    int uppercase_count = count_occurrences(password, 'A') + count_occurrences(password, 'B') +
                          count_occurrences(password, 'C') + count_occurrences(password, 'D') +
                          count_occurrences(password, 'E') + count_occurrences(password, 'F') +
                          count_occurrences(password, 'G') + count_occurrences(password, 'H') +
                          count_occurrences(password, 'I') + count_occurrences(password, 'J') +
                          count_occurrences(password, 'K') + count_occurrences(password, 'L') +
                          count_occurrences(password, 'M') + count_occurrences(password, 'N') +
                          count_occurrences(password, 'O') + count_occurrences(password, 'P') +
                          count_occurrences(password, 'Q') + count_occurrences(password, 'R') +
                          count_occurrences(password, 'S') + count_occurrences(password, 'T') +
                          count_occurrences(password, 'U') + count_occurrences(password, 'V') +
                          count_occurrences(password, 'W') + count_occurrences(password, 'X') +
                          count_occurrences(password, 'Y') + count_occurrences(password, 'Z');
    score += uppercase_count * 2;

    // Check for lowercase letters
    int lowercase_count = count_occurrences(password, 'a') + count_occurrences(password, 'b') +
                          count_occurrences(password, 'c') + count_occurrences(password, 'd') +
                          count_occurrences(password, 'e') + count_occurrences(password, 'f') +
                          count_occurrences(password, 'g') + count_occurrences(password, 'h') +
                          count_occurrences(password, 'i') + count_occurrences(password, 'j') +
                          count_occurrences(password, 'k') + count_occurrences(password, 'l') +
                          count_occurrences(password, 'm') + count_occurrences(password, 'n') +
                          count_occurrences(password, 'o') + count_occurrences(password, 'p') +
                          count_occurrences(password, 'q') + count_occurrences(password, 'r') +
                          count_occurrences(password, 's') + count_occurrences(password, 't') +
                          count_occurrences(password, 'u') + count_occurrences(password, 'v') +
                          count_occurrences(password, 'w') + count_occurrences(password, 'x') +
                          count_occurrences(password, 'y') + count_occurrences(password, 'z');
    score += lowercase_count * 2;

    // Check for special characters
    int special_count = count_occurrences(password, '!') + count_occurrences(password, '@') +
                        count_occurrences(password, '#') + count_occurrences(password, '$') +
                        count_occurrences(password, '%') + count_occurrences(password, '^') +
                        count_occurrences(password, '&') + count_occurrences(password, '*');
    score += special_count * 6;

    // Check for consecutive digits
    for (int i = 0; i < len - 1; i++)
    {
        if (isdigit(password[i]) && isdigit(password[i + 1]))
            score--;
    }

    // Check for consecutive letters
    int consecutive_count = 0;
    for (int i = 0; i < len - 1; i++)
    {
        if (isalpha(password[i]) && isalpha(password[i + 1]))
            consecutive_count++;
        else
            consecutive_count = 0;

        if (consecutive_count >= 3)
            score--;
    }

    // Check for repeated characters
    int repeat_count = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (password[i] == password[j])
            {
                repeat_count++;
                break;
            }
        }
    }
    score -= repeat_count * 2;

    return score;
}