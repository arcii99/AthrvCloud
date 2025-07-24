//FormAI DATASET v1.0 Category: Browser Plugin ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void show_surprise_notification(char* message);

int main(int argc, char** argv) {
    show_surprise_notification("Welcome to the unique C Browser Plugin example program!");
    return 0;
}

void show_surprise_notification(char* message) {
    char* plugin_name = "Surprize Plugin";
    char* browser_name = "Chrome";
    char* notification_icon = "https://surprise-plugin.com/notification-icon.png";
    char* notification_sound = "https://surprise-plugin.com/notification-sound.mp3";
    char* notification_title = "Surprise Notification";
    
    // check if plugin is installed
    if (rand() % 2) {
        printf("%s is not installed in %s.\n", plugin_name, browser_name);
        return;
    }
    
    // create notification
    printf("Creating surprise notification...\n");
    printf("Icon: %s\n", notification_icon);
    printf("Sound: %s\n", notification_sound);
    printf("Title: %s\n", notification_title);
    printf("Message: %s\n", message);
    printf("Notification sent!\n");
    
    // play sound
    printf("Playing surprise sound...\n");
    printf("Surprise sound played!\n");
    
    // open surprise website
    printf("Opening surprise website...\n");
    printf("Website opened in new tab!\n");
    printf("Enjoy your surprise!\n");
}