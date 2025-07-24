//FormAI DATASET v1.0 Category: Date and time ; Style: enthusiastic
#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    printf("Hello, my fellow humans! It is currently %02d:%02d:%02d on %02d/%02d/%d.\n", tm.tm_hour, tm.tm_min, tm.tm_sec, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    
    printf("Wow, the time really flies, doesn't it? It feels like just yesterday it was %02d:%02d:%02d, and now it's already %02d:%02d:%02d on %02d/%02d/%d!\n", tm.tm_hour - 1, tm.tm_min, tm.tm_sec, tm.tm_hour, tm.tm_min, tm.tm_sec, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    
    printf("But let's not dwell on the past, let's focus on the here and now. And right now, the time is %02d:%02d:%02d on %02d/%02d/%d.\n", tm.tm_hour, tm.tm_min, tm.tm_sec, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    
    printf("Isn't it incredible how something as simple as the time can connect us all? No matter where we are in the world, we all share this moment in time.\n");
    
    return 0;
}