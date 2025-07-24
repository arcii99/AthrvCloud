//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHANNELS 16

typedef struct {
    int num_channels;
    int current_channel;
    int channel_numbers[MAX_CHANNELS];
} drone_controller;

void init_controller(drone_controller *controller) {
    controller->num_channels = 0;
    controller->current_channel = 0;
}

void add_channel(drone_controller *controller, int channel_number) {
    if (controller->num_channels < MAX_CHANNELS) {
        controller->channel_numbers[controller->num_channels] = channel_number;
        controller->num_channels++;
    } else {
        printf("ERROR: Maximum number of channels reached.\n");
    }
}

void remove_channel(drone_controller *controller, int channel_number) {
    int i;
    for (i = 0; i < controller->num_channels; i++) {
        if (controller->channel_numbers[i] == channel_number) {
            // shift all channels after the removed one back one index
            while (i < controller->num_channels - 1) {
                controller->channel_numbers[i] = controller->channel_numbers[i+1];
                i++;
            }
            controller->num_channels--;
            if (controller->current_channel >= controller->num_channels) {
                controller->current_channel = 0;
            }
            return;
        }
    }
    printf("ERROR: Channel not found.\n");
}

void print_channels(drone_controller *controller) {
    int i;
    for (i = 0; i < controller->num_channels; i++) {
        printf("%d ", controller->channel_numbers[i]);
    }
    printf("\n");
}

void set_channel(drone_controller *controller, int channel_number) {
    int i;
    for (i = 0; i < controller->num_channels; i++) {
        if (controller->channel_numbers[i] == channel_number) {
            controller->current_channel = i;
            return;
        }
    }
    printf("ERROR: Channel not found.\n");
}

int main() {
    drone_controller controller;
    init_controller(&controller);

    add_channel(&controller, 1);
    add_channel(&controller, 2);
    add_channel(&controller, 3);
    add_channel(&controller, 4);
    print_channels(&controller); // should print "1 2 3 4"

    set_channel(&controller, 2);
    printf("%d\n", controller.current_channel); // should print 1 (index of channel 2 in array)

    remove_channel(&controller, 3);
    print_channels(&controller); // should print "1 2 4"

    remove_channel(&controller, 3); // should print "ERROR: Channel not found."

    return 0;
}