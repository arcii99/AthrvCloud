//FormAI DATASET v1.0 Category: File handling ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *dreams;
    char line[100];

    dreams = fopen("dreams.txt", "r");

    if (dreams == NULL) {
        printf("Sorry, I can't open my dreams right now. They're off exploring the multiverse.\n");
        exit(1);
    }

    while (fgets(line, 100, dreams)) {
        if (*line == 'z') {
            printf("In my dream, I was wandering through a forest of zippers. Every tree and every rock had a zipper on it. I tried to touch one, but it zipped away from me.\n");
        } else if (*line == 'w') {
            printf("Last night, I dreamt I was a walrus. I was swimming through a sea of whipped cream, and I was very pleased with myself.\n");
        } else if (*line == 'q') {
            printf("I had a dream that I was back in high school, taking a quiz. The teacher asked me what the square root of negative one was, and I blurted out 'quaternion.' Everyone looked at me like I was crazy.\n");
        } else if (*line == 'p') {
            printf("Last night, I dreamt I was a packet of peas. I was on a shelf in the grocery store, and every time someone picked me up, I would scream and wake up.\n");
        } else {
            printf("I can't remember what my dream was about, but I have this feeling that all of my variables were pointers to themselves.\n");
        }
    }

    fclose(dreams);

    return 0;
}