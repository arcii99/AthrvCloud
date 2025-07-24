//FormAI DATASET v1.0 Category: System boot optimizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>

void optimize_boot_system() {
    printf("Starting boot system optimization:\n");

    // Close all unnecessary processes
    printf("- Closing unnecessary processes...\n");
    system("taskkill /F /IM chrome.exe");
    system("taskkill /F /IM spotify.exe");
    system("taskkill /F /IM skype.exe");
    system("taskkill /F /IM discord.exe");

    // Disable unnecessary startup programs
    printf("- Disabling unnecessary startup programs...\n");
    system("reg add HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v Spotify /t REG_SZ /d \"\" /f");
    system("reg add HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v Skype /t REG_SZ /d \"\" /f");
    system("reg add HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v Discord /t REG_SZ /d \"\" /f");

    // Clean up unnecessary files
    printf("- Cleaning up unnecessary files...\n");
    system("DEL /F /S /Q %TEMP%\\*.*");
    system("DEL /F /S /Q %USERPROFILE%\\AppData\\Local\\Temp\\*.*");
    system("DEL /F /S /Q %USERPROFILE%\\AppData\\Local\\Microsoft\\Windows\\History\\*.*");
    system("DEL /F /S /Q %USERPROFILE%\\AppData\\Roaming\\Microsoft\\Windows\\Recent\\*.*");

    printf("Boot system optimization complete!");
}

int main() {
    printf("Welcome to the Boot System Optimizer!\n");
    printf("Press Y to start optimization or any other key to exit...\n");

    char input = getchar();

    if (input == 'Y' || input == 'y') {
        optimize_boot_system();
    } else {
        printf("Exiting...\n");
    }

    return 0;
}