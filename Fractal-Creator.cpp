// Fractal-Creator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Bitmap.h"

int main()
{
    int const WIDTH = 800;
    int const HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);

    // 800 * i = 255
    // 255/800 = i
    // x * 255/800
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            uint8_t red = x * (255.0 / (double)WIDTH);
            uint8_t green = (WIDTH - x) * (255.0 / (double)WIDTH);
            uint8_t blue = y * (255.0 / (double)HEIGHT);
            bitmap.setPixel(x, y, red, green, blue);
        }
    }

    bitmap.write("test.bmp");

    std::cout << "Hello World!\n";
    return 0;
}