//FormAI DATASET v1.0 Category: Smart home automation ; Style: visionary
#include <stdio.h>
#include <string.h>

// Define the maximum number of devices and rooms
#define MAX_DEVICES 10
#define MAX_ROOMS 5

// Define device and room structures
struct device {
  char name[20];
  int state;
};

struct room {
  char name[20];
  int num_devices;
  struct device devices[MAX_DEVICES];
};

// Define global list of rooms
struct room rooms[MAX_ROOMS];

// Function to add a new device to a room
void add_device(int room_index, char device_name[20]) {
  // Check if the maximum number of devices has been reached
  if (rooms[room_index].num_devices == MAX_DEVICES) {
    printf("Sorry, you have reached the maximum number of devices for this room.\n");
    return;
  }
  // Add the device to the room
  struct device new_device;
  strcpy(new_device.name, device_name);
  new_device.state = 0;
  rooms[room_index].devices[rooms[room_index].num_devices] = new_device;
  rooms[room_index].num_devices++;
  printf("Device %s added to room %s.\n", device_name, rooms[room_index].name);
}

// Function to toggle the state of a device
void toggle_device(int room_index, int device_index) {
  // Check if the device is valid
  if (device_index >= rooms[room_index].num_devices) {
    printf("Sorry, that is an invalid device index.\n");
    return;
  }
  // Toggle the state of the device
  if (rooms[room_index].devices[device_index].state == 0) {
    rooms[room_index].devices[device_index].state = 1;
    printf("Device %s in room %s turned on.\n", rooms[room_index].devices[device_index].name, rooms[room_index].name);
  } else {
    rooms[room_index].devices[device_index].state = 0;
    printf("Device %s in room %s turned off.\n", rooms[room_index].devices[device_index].name, rooms[room_index].name);
  }
}

int main() {
  // Initialize the rooms
  struct room bedroom = {"Bedroom", 0, {}};
  struct room living_room = {"Living Room", 0, {}};
  rooms[0] = bedroom;
  rooms[1] = living_room;

  // Add devices to the bedroom
  add_device(0, "Lamp");
  add_device(0, "Fan");
  
  // Add devices to the living room
  add_device(1, "TV");
  add_device(1, "Speakers");
  add_device(1, "Light");

  // Turn on the TV and speakers in the living room
  toggle_device(1, 0);
  toggle_device(1, 1);

  // Turn off the lamp in the bedroom
  toggle_device(0, 0);

  return 0;
}