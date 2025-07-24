//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  
    char password[20];
    int passwordLength;
    int i, randomIndex;

    char alphaSmall[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char alphaCaps[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char specialChars[8] = {'@', '#', '$', '%', '&', '*', '+', '-'};

    srand(time(NULL));

    printf("Enter length of password to be generated (max 20 characters) : ");
    scanf("%d", &passwordLength);

    if (passwordLength > 20) {
        printf("Invalid length...\n");
        exit(0);
    }

    for (i = 0; i < passwordLength; i++) {

        randomIndex = rand() % 4;

        if (randomIndex == 0) {
            password[i] = alphaSmall[rand() % 26];
        }
        else if (randomIndex == 1) {
            password[i] = alphaCaps[rand() % 26];
        }
        else if (randomIndex == 2) {
            password[i] = numbers[rand() % 10];
        }
        else {
            password[i] = specialChars[rand() % 8];
        }
    }

    password[i] = '\0';

    printf("\nGenerated password of length %d : %s\n", passwordLength, password);

    return 0;
}