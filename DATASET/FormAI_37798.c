//FormAI DATASET v1.0 Category: Color Code Converter ; Style: automated
#include <stdio.h>

int main() {
  int r, g, b;
  float h, s, v;

  printf("Please input the RGB values\n");
  scanf("%d %d %d", &r, &g, &b);

  // Convert RGB to HSV
  float maxColor = fmax(fmax(r, g), b);
  float minColor = fmin(fmin(r, g), b);
  v = maxColor / 255.0;
  if (maxColor != 0) {
    s = (maxColor - minColor) / maxColor;
  } else {
    s = 0;
  }
  if (s == 0) {
    h = 0;
  } else {
    float rc = (maxColor - r) / (maxColor - minColor);
    float gc = (maxColor - g) / (maxColor - minColor);
    float bc = (maxColor - b) / (maxColor - minColor);
    if (r == maxColor) {
      h = bc - gc;
    } else if (g == maxColor) {
      h = 2 + rc - bc;
    } else {
      h = 4 + gc - rc;
    }
    h /= 6;
    if (h < 0) h++;
  }

  // Convert HSV to RGB
  if (s == 0) {
    r = g = b = v * 255;
  } else {
    int i;
    float f, p, q, t;
    h *= 6;
    i = (int)h;
    f = h - i;
    p = v * (1 - s);
    q = v * (1 - s * f);
    t = v * (1 - s * (1 - f));
    switch (i) {
      case 0: r = v * 255; g = t * 255; b = p * 255; break;
      case 1: r = q * 255; g = v * 255; b = p * 255; break;
      case 2: r = p * 255; g = v * 255; b = t * 255; break;
      case 3: r = p * 255; g = q * 255; b = v * 255; break;
      case 4: r = t * 255; g = p * 255; b = v * 255; break;
      default: r = v * 255; g = p * 255; b = q * 255; break;
    }
  }

  printf("RGB: (%d, %d, %d)\n", r, g, b);
  printf("Hex Code: #%02X%02X%02X\n", r, g, b);
  return 0;
}