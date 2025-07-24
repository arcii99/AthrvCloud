//FormAI DATASET v1.0 Category: Pattern printing ; Style: futuristic
#include <stdio.h>

int main() {
    for(int i=0; i<10; i++) {
        for(int j=0; j<10-i; j++) {
            printf(" ");
        }
        for(int k=0; k<i; k++) {
            printf(" *");
        }
        printf("\n");
    }
    for(int i=10; i>0; i--) {
        for(int j=0; j<10-i; j++) {
            printf(" ");
        }
        for(int k=0; k<i; k++) {
            printf(" *");
        }
        printf("\n");
    }
    return 0;
}