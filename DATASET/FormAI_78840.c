//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* theories[] = {
    "The moon landing was faked by the government.",
    "Area 51 is a center for extraterrestrial research.",
    "The Illuminati control global affairs.",
    "9/11 was an inside job.",
    "The government is hiding the cure for cancer.",
    "Bigfoot is real and the government is covering it up.",
    "The Loch Ness Monster is a government experiment gone wrong.",
    "The earth is flat.",
    "The government is using chemtrails to control our minds.",
    "Prince Charles is a vampire.",
    "The world is run by reptilian aliens.",
};

char* generate_theory() {
    int random_num = rand() % (sizeof(theories)/sizeof(char*));
    return theories[random_num];
}

void print_recursive(int n) {
    if(n==0) {
        return;
    }
    printf("%s\n", generate_theory());
    print_recursive(n-1);
}

int main() {
    srand(time(0));
    int num_theories = 10;
    print_recursive(num_theories);
    return 0;
}