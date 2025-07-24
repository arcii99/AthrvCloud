//FormAI DATASET v1.0 Category: QR code reader ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<linux/input.h>
#include<pthread.h>

#define TAG_SIZE 12
#define QR_CODE_SIZE 120
#define GPIO_VALUE "/sys/class/gpio/gpio26/value"
#define GPIO_EDGE "/sys/class/gpio/gpio26/edge"
#define MAX_BUFFER_SIZE 1024

volatile int keep_reading = 1;
int fd, gpio_fd, qr_code_index;
unsigned char last_tag[TAG_SIZE];

void read_code(char* filename, char* value);
void decode_qr();

int main(int argc, char** argv) {
  pthread_t thread_id;
  char* filename = "/dev/input/event0";
  char* button_value = "rising";
  unsigned char scan_code[strlen(button_value) + 1];
  struct input_event event;

  fd = open(filename, O_RDONLY);
  if(fd < 0) {
    fprintf(stderr, "Failed to open event device %s - %s\n", filename, strerror(errno));
    return -1;
  }

  gpio_fd = open(GPIO_VALUE, O_RDONLY);
  if(gpio_fd < 0) {
    fprintf(stderr, "Failed to open GPIO Value %d - %s\n", 26, strerror(errno));
    return -1;
  }

  if(write(gpio_fd, "falling", strlen("falling")) < 0) {
    fprintf(stderr, "Failed to write to GPIO Edge %d - %s\n", 26, strerror(errno));
    return -1;
  }

  if(read(gpio_fd, &scan_code, sizeof(scan_code)) < 0) {
    fprintf(stderr, "Failed to read from GPIO Value %d - %s\n", 26, strerror(errno));
    return -1;
  }

  printf("Press button to start scanning!\n");

  pthread_create(&thread_id, NULL, (void *)&decode_qr, NULL);

  while(keep_reading) {
    if(read(fd, &event, sizeof(event)) < 0) {
      fprintf(stderr, "Failed to read event - %s\n", strerror(errno));
      return -1;
    }

    if(event.type == EV_KEY && event.code == BTN_TOUCH && event.value == 1) {
        read_code(GPIO_VALUE, button_value);
    }
  }

  pthread_join(thread_id, NULL);
  close(fd);
  close(gpio_fd);
  return 0;
}

void read_code(char* filename, char* value) {
  int len = strlen(value);
  char buf[MAX_BUFFER_SIZE];
  snprintf(buf, sizeof buf, "%s", value);
  int fd = open(filename, O_WRONLY);
  if(fd < 0) {
    fprintf(stderr, "Failed to open %s - %s\n", filename, strerror(errno));
    return;
  }
  if(write(fd, buf, len) < 0) {
    fprintf(stderr, "Failed to write %s - %s\n", value, strerror(errno));
    return;
  }
  close(fd);
}

void decode_qr() {
  char qr_code[QR_CODE_SIZE];
  char qr_filename[] = "/dev/qr_code";
  int qr_fd = open(qr_filename, O_RDONLY);
  if(qr_fd < 0) {
    fprintf(stderr, "Failed to open QR Code device - %s\n", strerror(errno));
    return;
  }
  
  while(keep_reading) {
    if(read(qr_fd, &qr_code[qr_code_index], 1) < 0) {
      fprintf(stderr, "Failed to read QR Code - %s\n", strerror(errno));
      continue;
    }

    if(qr_code_index == TAG_SIZE - 1) {
      qr_code[qr_code_index] = '\0';
      if(strcmp(last_tag, qr_code)) {
        memcpy(last_tag, qr_code, TAG_SIZE);
        printf("New QR Code Detected: %s\n", qr_code);
      }
      qr_code_index = 0;
    }
    else qr_code_index++;
  }

  close(qr_fd);
}