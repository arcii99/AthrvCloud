//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Sherlock Holmes
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char message[] = "z1n4 j4r4k4p1 s4k4r4n3l s1n3t3z3 h4r1p4p4";
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz1234567890 ";
    char translation[] = "ckmobgraldqzfvsjhxwitnueyp7234156890 ";
    char result[100];
    int i, j;
    printf("Decrypting Alien Language Message...\n\n");
    printf("Input message: %s\n\n", message);
    for(i = 0; i < strlen(message); i += 2) {
        int index = 0;
        for(j = 0; j < strlen(alphabet); j++) {
            if(message[i] == alphabet[j]) {
                index = j;
                break;
            }
        }
        result[i / 2] = translation[index];
        index = 0;
        for(j = 0; j < strlen(alphabet); j++) {
            if(message[i + 1] == alphabet[j]) {
                index = j;
                break;
            }
        }
        result[(i / 2) + 1] = translation[index];
    }
    printf("Decrypted message: %s\n\n", result);
    return 0;
}