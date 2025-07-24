//FormAI DATASET v1.0 Category: QR code reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main() {

    char code[100];
    int i;
    
    printf("O Romeo, O Romeo, wherefore art thou QR code?\n");
    scanf("%s", code);
    
    int len = strlen(code);
    int sum = 0;
    
    for (i = 0; i < len; i++) {
        if (code[i] >= '0' && code[i] <= '9') {
            sum += code[i] - '0';
        }
    }
    
    if (sum % 2 == 0) {
        printf("O happy dagger! This code is as clear as morning sunshine.\n");
    } else {
        printf("O serpent heart! This code is as dark as night.\n");
        printf("I am sorry, my dear Romeo, I cannot interpret this code.\n");
        printf("But fear not, for I shall never leave thy side.\n");
    }
    
    return 0;
}