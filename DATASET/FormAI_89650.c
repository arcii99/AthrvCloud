//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

// function to calculate minimum value
int min(int a, int b, int c)
{
    int minVal = a;

    if (minVal > b)
        minVal = b;
    if (minVal > c)
        minVal = c;

    return minVal;
}

// Recursive function to calculate Levenshtein Distance
int calcDistance(char *str1, char *str2, int m, int n)
{
    // If any of the string is empty
    if (m == 0)
        return n;
    if (n == 0)
        return m;

    // If the last characters are the same, ignore the last character
    if (str1[m - 1] == str2[n - 1])
        return calcDistance(str1, str2, m - 1, n - 1);

    // If the last characters are not same, consider all the 3 operations
    return 1 + min(
        calcDistance(str1, str2, m, n - 1),
        calcDistance(str1, str2, m - 1, n),
        calcDistance(str1, str2, m - 1, n - 1));
}

// struct that holds the input
typedef struct input {
    char *str1;
    char *str2;
    int m;
    int n;
    int ans;
} Input;

// async function that calculates Levenshtein Distance
void *calcLevDistAsync(void *arg)
{
    Input *input = (Input *)arg;
    input->ans = calcDistance(input->str1, input->str2, input->m, input->n);
}

int main()
{
    // Input strings
    char *str1 = "cat";
    char *str2 = "carpet";

    int m = strlen(str1);
    int n = strlen(str2);

    // Declare variables that will hold the answers
    int ans1, ans2;

    // calculate Levenshtein distance of str1 and str2 in a synchronous way
    ans1 = calcDistance(str1, str2, m, n);

    // Calculate Levenshtein Distance of str1 and str2 in an async way
    pthread_t tid;
    Input *input = (Input *)malloc(sizeof(Input));
    input->str1 = str1;
    input->str2 = str2;
    input->m = m;
    input->n = n;
    pthread_create(&tid, NULL, calcLevDistAsync, (void *)input);
    pthread_join(tid, NULL);
    ans2 = input->ans;

    if (ans1 == ans2)
    {
        printf("Both the synchronous and asynchronous implementations calculated the same Levenshtein Distance: %d\n", ans1);
    }
    else
    {
        printf("Asynchronous implementation gave a different Levenshtein Distance: %d\n", ans2);
    }

    return 0;
}