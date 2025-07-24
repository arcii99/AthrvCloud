//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int get_fortune();
int random_number(int min, int max);
void print_fortune(int fortune);

int main() {
    int fortune = get_fortune();
    print_fortune(fortune);
    return 0;
}

int get_fortune() {
    srand(time(NULL));
    int fortune = random_number(1, 5); //get a random number between 1 and 5
    return fortune;
}

int random_number(int min, int max) {
    return rand() % (max - min + 1) + min; //generate a random number within the range
}

void print_fortune(int fortune) {
    switch(fortune) {
        case 1:
            printf("You will soon meet someone special.\n");
            break;
        case 2:
            printf("A financial opportunity will come your way.\n");
            break;
        case 3:
            printf("Your hard work will pay off in the near future.\n");
            break;
        case 4:
            printf("A close friend will seek your advice and guidance.\n");
            break;
        case 5:
            printf("A long journey is in your future.\n");
            break;
        default:
            printf("Hmm, something went wrong.\n");
    }
}