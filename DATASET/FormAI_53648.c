//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    char password[20];
    int length = 0;
    printf("Enter Password Length: ");
    scanf("%i", &length);
    while (length < 8 || length > 16) {
        printf("Password Length Must be Between 8 and 16 Characters!\n");
        printf("Enter Password Length: ");
        scanf("%i", &length);
    }
    password[0] = '@' + rand()%26; /*Random Uppercase Character*/
    password[1] = '#' + rand()%9;  /*Random Digit*/
    password[length-2] = '$' + rand()%7;   /*Random Special Character*/
    for (int i = 2; i < length-2; i++) {
        int r = rand()%4;
        if (r == 0) password[i] = 'a' + rand()%26; /*Random Lowercase Character*/
        if (r == 1) password[i] = 'A' + rand()%26; /*Random Uppercase Character*/
        if (r == 2) password[i] = '0' + rand()%10; /*Random Digit*/
        if (r == 3) password[i] = '%' + rand()%5;  /*Random Special Character*/
    }
    password[length-1] = '\0';
    /*Shuffle String*/
    int n = strlen(password);
    for (int i = n-1; i > 0; i--) {
        int j = rand()%(i+1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    printf("Your Secure Password is: %s", password);
    return 0;
}