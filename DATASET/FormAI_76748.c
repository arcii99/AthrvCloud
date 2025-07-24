//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void fortune_teller(char question[30]) {
    
    srand(time(NULL));
    int random = rand() % 10;
    
    if(random == 0) {
        printf("My dear friend, I see that love is in your future. Keep your heart open and let love in.\n");
    } else if(random == 1) { 
        printf("Oh, my dear, I see a long journey in the near future. Take good care of yourself and enjoy the ride.\n");
    } else if(random == 2) {
        printf("Ah, I sense that the answer you seek is already within you. Trust your intuition and make your move.\n");
    } else if(random == 3) {
        printf("My dearest, I see a great opportunity in your near future. Embrace it with open arms and success will be yours.\n");
    } else if(random == 4) {
        printf("My love, I see that your hard work and dedication will soon pay off. Keep pushing forward and all your dreams will come true.\n");
    } else if(random == 5) {
        printf("My beloved, I sense that a change is in order. Don't be afraid to take a risk and try something new.\n");
    } else if(random == 6) {
        printf("My darling, I see that you must let go of the past in order to move forward. Forgive yourself and others, and embrace the future with open arms.\n");
    } else if(random == 7) {
        printf("My sweet love, I see that your heart is full of love and kindness. Continue to spread love wherever you go.\n");
    } else if(random == 8) {
        printf("My precious, I sense that you are destined for great things. Believe in yourself and do not let self-doubt hold you back.\n");
    } else {
        printf("My beautiful, I see that happiness is in your future. Keep a positive outlook and good things will come your way.\n");
    }
}

int main() {
    char question[30];
    printf("Welcome, my dear. I am your automated fortune teller. Please ask me a yes or no question:\n");
    scanf("%s", question);
    fortune_teller(question);
    return 0;
}