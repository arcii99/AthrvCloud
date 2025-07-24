//FormAI DATASET v1.0 Category: Smart home light control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define ON 1
#define OFF 0

typedef struct Light {
   bool state;
   int brightness;
} Light;

void toggleLight(Light *light) {
   light->state = !light->state;
}

void setBrightness(Light *light, int brightness) {
   light->brightness = brightness;
}

void printLight(Light *light) {
   printf("Light is %s and brightness is %d\n", (light->state ? "On" : "Off"), light->brightness);
}

int main() {
   Light bedroomLight = {OFF, 0};
   Light livingRoomLight = {OFF, 0};

   while (true) {
      // Check if there is still electricity
      if (access("/home/grid/electricity", F_OK) == -1) {
         printf("No electricity. Shutting down lights.\n");
         setBrightness(&bedroomLight, 0);
         setBrightness(&livingRoomLight, 0);
         toggleLight(&bedroomLight);
         toggleLight(&livingRoomLight);
         sleep(10);
      }

      // Check radiation levels
      if (access("/home/air/radiation", F_OK) != -1) {
         printf("Radiation levels too high. Shutting down lights.\n");
         setBrightness(&bedroomLight, 0);
         setBrightness(&livingRoomLight, 0);
         toggleLight(&bedroomLight);
         toggleLight(&livingRoomLight);
         sleep(10);
      }

      // Check if there is an intruder
      if (access("/home/security/intruder", F_OK) != -1) {
         printf("Intruder detected. Turning on lights at full brightness.\n");
         setBrightness(&bedroomLight, 100);
         setBrightness(&livingRoomLight, 100);
         toggleLight(&bedroomLight);
         toggleLight(&livingRoomLight);
         sleep(10);
      }

      // Check if it's night
      if (access("/home/time/daytime", F_OK) == -1) {
         printf("It's night. Turning on bedroom light.\n");
         setBrightness(&bedroomLight, 50);
         toggleLight(&bedroomLight);
         sleep(5);

         // Check if someone's watching TV
         if (access("/home/livingroom/tv", F_OK) != -1) {
            printf("Someone is watching TV. Turning on living room light.\n");
            setBrightness(&livingRoomLight, 50);
            toggleLight(&livingRoomLight);
            sleep(5);
         }
      }

      printLight(&bedroomLight);
      printLight(&livingRoomLight);

      sleep(2);
   }

   return 0;
}