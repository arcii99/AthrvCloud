//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: immersive
#include <stdio.h>

int main(){
    printf("Welcome to Time Travel Simulator!\n");
    printf("You will go back in time to experience the life of a famous person.\n");

    int year_of_travel;
    printf("Enter the year of travel: ");
    scanf("%d", &year_of_travel);

    switch(year_of_travel){
        case 1969:
            printf("You have landed in Woodstock, New York!\n");
            printf("You see hippies everywhere, listening to music and smoking weed.\n");
            printf("You are approached by a man with long hair and a tie-dye shirt. He introduces himself as Jimi Hendrix.\n");
            printf("He invites you to sit with him and watch his performance. You feel the music in your bones and your soul is filled with peace.\n");
            break;
        case 1944:
            printf("You have landed in Normandy, France!\n");
            printf("You see soldiers everywhere, fighting for their country and their freedom.\n");
            printf("You are approached by a soldier with a friendly smile. He introduces himself as Dwight D. Eisenhower.\n");
            printf("He takes you under his wing and shows you what it means to be a leader. You witness bravery, sacrifice, and love for country.\n");
            break;
        case 1920:
            printf("You have landed in Paris, France!\n");
            printf("You see artists and writers everywhere, expressing themselves in creative and unique ways.\n");
            printf("You are approached by a woman with a stylish haircut and a cigarette in her hand. She introduces herself as Coco Chanel.\n");
            printf("She takes you to a small cafe and tells you about her life and her passion for fashion. You learn that anything is possible if you have a vision and the courage to pursue it.\n");
            break;
        default:
            printf("Oops! Looks like we don't have a time machine for that year. Please choose a different year.\n");
            break;
    }

    printf("Thank you for using Time Travel Simulator! Safe travels!\n");
    return 0;
}