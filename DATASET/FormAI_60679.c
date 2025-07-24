//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random generator with the current time
    srand(time(NULL));
    
    // Define an array of fortunes
    const char *fortunes[] = {
        "You will find success in your endeavors.",
        "A great journey lies ahead of you.",
        "You will receive unexpected good news.",
        "Beware of those who seek to bring you down.",
        "Love is coming your way.",
        "Fortune favors the bold.",
        "You will have a long and prosperous life.",
        "Your wildest dreams are about to come true.",
        "The road ahead is filled with many obstacles.",
        "An old friend will soon re-enter your life.",
        "Good things come to those who wait.",
        "Your hard work will pay off in the end.",
        "You are capable of achieving great things.",
        "Take risks now and reap the rewards later.",
        "Money will come to you when you least expect it.",
        "You will soon embark on a new adventure.",
        "The future is full of endless possibilities.",
        "A new and exciting chapter in your life is about to begin.",
        "You are destined for greatness.",
        "Your creativity will lead you to success."
    };
    
    // Get the number of fortunes in the array
    int numFortunes = sizeof(fortunes) / sizeof(fortunes[0]);
    
    // Generate a random index to get a fortune from the array
    int randomNumber = rand() % numFortunes;
    
    // Print out the fortune
    printf("Your fortune: %s\n", fortunes[randomNumber]);
    
    return 0;
}