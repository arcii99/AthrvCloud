//FormAI DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// This program will change the wallpaper of the system
// when the user is taking a break, to help them relax and
// make their work environment more peaceful.

// Function that changes the wallpaper
void changeWallpaper() {
    system("gsettings set org.gnome.desktop.background picture-uri file:///usr/share/backgrounds/peaceful_nature.jpg");
}

int main() {
    // Set initial wallpaper when program starts
    changeWallpaper();
    
    // Loop to check if user is inactive
    while (1) {
        sleep(300);  // Wait 5 minutes
        
        // Check if user is inactive for past 5 minutes
        if (system("xprintidle") > 300000) {
            changeWallpaper();
        }
    }
    
    return 0;
}