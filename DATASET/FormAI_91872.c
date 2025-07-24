//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length, strength;
    printf("Enter the length of the password: ");
    scanf("%d", &length);
    printf("Enter the strength of the password(1-5): ");
    scanf("%d", &strength);
    char* password = (char*)calloc(length + 1, sizeof(char));
    int i;
    srand(time(NULL));
    for (i = 0; i < length; i++) {
        switch (strength) {
            case 1:
                password[i] = 'a' + rand() % ('z' - 'a' + 1);
                break;
            case 2:
                password[i] = rand() % 2 ? 'A' + rand() % ('Z' - 'A' + 1) : 'a' + rand() % ('z' - 'a' + 1);
                break;
            case 3:
                password[i] = rand() % 3 == 0 ? 'A' + rand() % ('Z' - 'A' + 1) : rand() % 3 == 1 ? 'a' + rand() % ('z' - 'a' + 1) : '0' + rand() % 10;
                break;
            case 4:
                password[i] = rand() % 4 == 0 ? 'A' + rand() % ('Z' - 'A' + 1) : rand() % 4 == 1 ? 'a' + rand() % ('z' - 'a' + 1) : rand() % 4 == 2 ? '0' + rand() % 10 : '!' + rand() % ('~' - '!' + 1);
                break;
            case 5:
                password[i] = rand() % 5 == 0 ? 'A' + rand() % ('Z' - 'A' + 1) : rand() % 5 == 1 ? 'a' + rand() % ('z' - 'a' + 1) : rand() % 5 == 2 ? '0' + rand() % 10 : '!' + rand() % ('~' - '!' + 1);
                break;
            default:
                printf("Invalid strength entered! Valid values are integers 1 to 5.\n");
                free(password);
                return -1;
        }
    }
    printf("Your password is: %s\n", password);
    free(password);
    return 0;
}