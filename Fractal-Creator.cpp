// Fractal-Creator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Bitmap.h"
#include "Mandelbrot.h"

int main()
{
    int const WIDTH = 800;
    int const HEIGHT = 600;

    double const XSHIFT = 1.5;
    double const YSHIFT = 1;

    double const XSCALE = 2;
    double const YSCALE = 2;

    Bitmap bitmap(WIDTH, HEIGHT);

    double min = 999999;
    double max = -999999;

    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double xFractal = ((x * 2.0 * XSCALE) / WIDTH) - (1.0 + XSHIFT);
            double yFractal = ((y * 2.0 * YSCALE) / HEIGHT) - (1.0 + YSHIFT);

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);


            uint8_t red = (uint8_t)(256.0 * (double)iterations / Mandelbrot::MAX_ITERATIONS);

			//printf("%d: %d:  %d\n", x, y, iterations);


			bitmap.setPixel(x, y, red, 0, 0);

            if (red < min) min = red;
            if (red > max) max = red;
        }
    }

    cout << min << ", " << max << endl;


    /*
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            uint8_t red = x * (255.0 / (double)WIDTH);
            uint8_t green = (WIDTH - x) * (255.0 / (double)WIDTH);
            uint8_t blue = y * (255.0 / (double)HEIGHT);
            bitmap.setPixel(x, y, red, green, blue);
        }
    }
    */

    bitmap.write("test.bmp");

    std::cout << "Hello World!\n";
    return 0;
}