//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("Welcome, my fellow adventurer, to the POP3 Client!\n");
    printf("I am the virtual assistant known as POPPIN, here to guide you through your surreal journey.\n");

    char user_input[100];
    printf("Please enter your email address: ");
    scanf("%s", user_input);
    printf("Wonderful! Now, please enter your password: ");
    scanf("%s", user_input);

    printf("Now, let us gaze upon the infinite void of your inbox...\n");

    int unread_count = 7;
    printf("You have %d unread messages. Would you like to read them?\n", unread_count);
    printf("Please enter 'yes' or 'no': ");
    scanf("%s", user_input);

    if(strcmp(user_input, "yes") == 0){
        printf("Excellent, we shall now descend into the depths of your unread messages...\n");

        char* message_list[] = {"From: a_cat_with_a_tiara@example.com\nSubject: The Missing Ingredient\n\nGreetings, esteemed feline friend! I have a most pressing matter to discuss with you. It seems I have misplaced my secret ingredient for my famous tuna casserole, and I simply cannot make it without your assistance. Please come to my aid at your earliest convenience.\n\nYours truly,\nThe Cat Chef",
                                "From: spider_mary@example.com\nSubject: The Spooky Sale\n\nSalutations, web-slinging pal! It is with great excitement that I announce my Spooky Sale, where all spider-related objects are discounted by 50%! I am counting on your support in spreading the word and making this a hauntingly successful event.\n\nYour creepy colleague,\nSpider Mary",
                                "From: the_moon_man@example.com\nSubject: Lunar Lullaby\n\nDear dreamer,\nI hope this message finds you well in your slumber. I come bearing a lunar lullaby, sung through the velvet night by the stars themselves. Close your eyes and open your heart, and let the music carry you to the edges of the universe.\n\nThe Moon Man",
                                "From: the_croissant_crusader@example.com\nSubject: The Great Pastry Mystery\n\nGreetings, brave baker! I write to you in distress, for a most dastardly phenomenon has occurred at my boulangerie. Each morning, my buttery, flaky croissants vanish without a trace. I have consulted the finest detectives in the land, but none have been able to crack the case. That is why I turn to you, my friend, in hopes that you may uncover the truth behind the Great Pastry Mystery.\n\nForever indebted,\nThe Croissant Crusader",
                                "From: the_wandering_dreamer@example.com\nSubject: The Island of Whispers\n\nHello, fellow traveler,\nI write to you from the Island of Whispers, a place shrouded in fog and steeped in secrets. I implore you, come join me on my journey and discover the mysteries hidden within. Bring nothing but an open mind and a sense of wonder, and let us embark on an adventure unlike any other.\n\nThe Wandering Dreamer",
                                "From: the_grand_illusionist@example.com\nSubject: The Great Disappearing Act\n\nGreetings, beloved audience,\nI write to you today with great humility and regret. It seems that all is not right within the world of magic, as I have unintentionally caused a man to vanish without a trace during my most recent performance. I am at a loss as to how to proceed, and so I turn to you, the cleverest and most discerning of audiences, for assistance. Please, help me uncover the secrets behind the Great Disappearing Act.\n\nSincerely,\nThe Grand Illusionist",
                                "From: the_melancholy_mermaid@example.com\nSubject: The Song of the Sea\n\nGreetings, kindred spirit,\nYou do not know me, but I have heard your heart's yearning through the ebb and flow of the tides. I come to you with a gift, a song sung by the mermaids themselves. Listen closely, and let it bring you comfort in your darkest hours.\n\nThe Melancholy Mermaid"};

        for(int i = 0; i < unread_count; i++){
            printf("\nMessage %d:\n\n%s\n", i+1, message_list[i]);
        }

        printf("\nAnd there you have it, my friend. I hope your surreal journey through your inbox has been fruitful and enlightening.\n");
    } else {
        printf("Very well, perhaps another time. Farewell, adventurer!\n");
    }

    return 0;
}