//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

int main()
{
   struct sysinfo info;
   sysinfo(&info);
   
   float total_memory = info.totalram / 1024.0 / 1024.0;
   float free_memory = info.freeram / 1024.0 / 1024.0;
   float used_memory = total_memory - free_memory;
   int percentage = (used_memory / total_memory) * 100;
   
   printf("Welcome to the C RAM Usage Monitor!\n\n");
   printf("Total memory available: %.2f MB\n", total_memory);
   printf("Free memory: %.2f MB\n", free_memory);
   printf("Used memory: %.2f MB\n", used_memory);
   printf("Percentage used: %d%%\n\n", percentage);
   
   printf("Watching the memory usage can be mind-bending. Let me explain...\n");
   printf("Imagine a world where memory is a physical space, like a room. The room has a\n");
   printf("finite amount of space, just like the memory in our computer. Everything we\n");
   printf("store in our computer takes up space in this room.\n\n");
   
   printf("In this world, our code is like a decorator. It's our job to make sure that\n");
   printf("everything we put in the room looks nice and tidy. If we're not careful,\n");
   printf("we'll run out of space in the room, and things will start to look cluttered.\n\n");
   
   printf("That's where the RAM monitor comes in. It's like our memory-arranging assistant.\n");
   printf("It shows us how much space we've used up, so we can make sure we're not\n");
   printf("overloading the room with too much stuff. It's important to keep a close eye\n");
   printf("on this monitor so that we don't run out of room, or worse yet, crash the room.\n\n");
   
   printf("So, keep an eye on the RAM monitor, decorate your memory, and enjoy a clutter-free\n");
   printf("and mind-bending coding experience!\n");
   
   return 0;
}