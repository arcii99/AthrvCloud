//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Cryptic
#include <stdio.h>

int main() {
    int bOOl = 1;
    int mY_Numb3r = 1000;
    char aBUf[32];
    for (int i = 0; i < 32; i++) {
        aBUf[i] = 'A';
    }
    for (int j = 0; j < mY_Numb3r; j++) {
        if (bOOl) {
            for (int k = 0; k < 32; k++) {
                aBUf[k] += 5;
            }
        } else {
            for (int l = 0; l < 32; l++) {
                aBUf[l] -= 5;
            }
        }
        bOOl = !bOOl;
    }
    printf("%s\n", aBUf);
    return 0;
}