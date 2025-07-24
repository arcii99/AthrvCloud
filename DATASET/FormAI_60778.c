//FormAI DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>

int main() {
    int temp = 25;
    printf("Hark! What is the current temperature in ye olde village square?\n");
    scanf("%d", &temp);
    if(temp > 30) {
        printf("By St. George! 'Tis a scorcher today!\n");
    } else if(temp > 20) {
        printf("Verily, 'tis a pleasant day today.\n");
    } else if(temp > 10 ){
        printf("Brrr! 'Tis a bit nippy today.\n");
    } else {
        printf("By the Black Death! 'Tis freezing today!\n");
    }
    return 0;
}