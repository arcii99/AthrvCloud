//FormAI DATASET v1.0 Category: Smart home automation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define NUM_ROOMS 3
#define NUM_DEVICES 4

// Define device types
enum DeviceType {
    LIGHTING,
    THERMOSTAT,
    SECURITY,
    AUDIO
};

// Define device struct
typedef struct {
    enum DeviceType type;
    bool status;
    int value; // For example, temperature setting for thermostat or volume setting for audio device
} Device;

// Define room struct
typedef struct {
    int id;
    Device devices[NUM_DEVICES];
} Room;

Room rooms[NUM_ROOMS];

pthread_mutex_t lock; // Mutex lock for thread synchronization

// Function to turn on/off a device in a room
void change_device_status(int room_id, int device_id, bool new_status) {
    pthread_mutex_lock(&lock);
    rooms[room_id].devices[device_id].status = new_status;
    pthread_mutex_unlock(&lock);
}

// Function to change value of a device in a room
void change_device_value(int room_id, int device_id, int new_value) {
    pthread_mutex_lock(&lock);
    rooms[room_id].devices[device_id].value = new_value;
    pthread_mutex_unlock(&lock);
}

// Thread function for lighting controller
void *lighting_controller(void* room_id_ptr) {
    int room_id = *((int*) room_id_ptr);

    // Continuously monitor the lighting devices of the room
    while (true) {
        int num_on = 0; // number of devices that are on
        int num_off = 0; // number of devices that are off

        pthread_mutex_lock(&lock);
        for (int i = 0; i < NUM_DEVICES; i++) {
            if (rooms[room_id].devices[i].type == LIGHTING) {
                if (rooms[room_id].devices[i].status) {
                    num_on++;
                } else {
                    num_off++;
                }
            }
        }
        pthread_mutex_unlock(&lock);

        // Logic for automatically turning on/off devices based on the current light levels
        if (num_on < num_off) {
            printf("Turning on lighting devices in room %d.\n", room_id);
            for (int i = 0; i < NUM_DEVICES; i++) {
                if (rooms[room_id].devices[i].type == LIGHTING) {
                    change_device_status(room_id, i, true);
                }
            }
        } else if (num_on > num_off) {
            printf("Turning off lighting devices in room %d.\n", room_id);
            for (int i = 0; i < NUM_DEVICES; i++) {
                if (rooms[room_id].devices[i].type == LIGHTING) {
                    change_device_status(room_id, i, false);
                }
            }
        }

        sleep(5); // Wait for 5 seconds before rechecking the devices
    }
}

// Thread function for thermostat controller
void *thermostat_controller(void* room_id_ptr) {
    int room_id = *((int*) room_id_ptr);

    // Continuously monitor the thermostat devices of the room
    while (true) {
        int temp_sum = 0; // summation of temperature values of all devices
        int num_devices = 0; // number of devices that are currently on

        pthread_mutex_lock(&lock);
        for (int i = 0; i < NUM_DEVICES; i++) {
            if (rooms[room_id].devices[i].type == THERMOSTAT && rooms[room_id].devices[i].status) {
                temp_sum += rooms[room_id].devices[i].value;
                num_devices++;
            }
        }
        pthread_mutex_unlock(&lock);

        // Logic for adjusting the temperature setting of the thermostat devices based on the average temperature of the devices
        if (num_devices > 0) {
            int average_temp = temp_sum / num_devices;
            printf("Setting thermostat devices in room %d to temperature %d.\n", room_id, average_temp);
            for (int i = 0; i < NUM_DEVICES; i++) {
                if (rooms[room_id].devices[i].type == THERMOSTAT) {
                    change_device_value(room_id, i, average_temp);
                }
            }
        }

        sleep(10); // Wait for 10 seconds before rechecking the devices
    }
}

// Function to initialize the rooms with devices
void initialize_rooms() {
    for (int room_id = 0; room_id < NUM_ROOMS; room_id++) {
        Room room;
        room.id = room_id;

        // Initialize devices of the room
        for (int device_id = 0; device_id < NUM_DEVICES; device_id++) {
            Device device;
            device.status = false;
            device.type = device_id % 4; // Rotate through the 4 device types cyclically

            if (device.type == LIGHTING) {
                device.value = 0; // No value needed for lighting devices
            } else if (device.type == THERMOSTAT) {
                device.value = 20; // Initial temperature setting of 20 degrees Celsius for thermostat devices
            } else if (device.type == SECURITY) {
                device.value = 0; // No value needed for security devices
            } else if (device.type == AUDIO) {
                device.value = 0; // Initial volume setting of 0 (muted) for audio devices
            }

            room.devices[device_id] = device;
        }

        rooms[room_id] = room;
    }
}

int main() {
    initialize_rooms();

    // Start separate threads for each room and each device type
    pthread_t threads[NUM_ROOMS * 4];
    int thread_index = 0;
    for (int room_id = 0; room_id < NUM_ROOMS; room_id++) {
        pthread_create(&threads[thread_index++], NULL, lighting_controller, &rooms[room_id].id);
        pthread_create(&threads[thread_index++], NULL, thermostat_controller, &rooms[room_id].id);
        pthread_create(&threads[thread_index++], NULL, NULL, &rooms[room_id].devices[2]); // Dummy thread for security controller
        pthread_create(&threads[thread_index++], NULL, NULL, &rooms[room_id].devices[3]); // Dummy thread for audio controller
    }

    // Wait for all threads to finish (should never happen in this program)
    for (int i = 0; i < NUM_ROOMS * 4; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}