// Fractal-Creator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdint>
#include <math.h>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"

int main()
{
    int const WIDTH = 400;
    int const HEIGHT = 400;

    ZoomList zoomList(WIDTH, HEIGHT);
    zoomList.add(Zoom(WIDTH/2, HEIGHT/2, 2.0/WIDTH));


    Bitmap bitmap(WIDTH, HEIGHT);

    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
    unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{ 0 });

    for (int y = 0; y < HEIGHT; y++) {
        printf("y: %d / %d\n", y, HEIGHT);
        for (int x = 0; x < WIDTH; x++) {
            pair<double, double> coords = zoomList.doZoom(x, y);

            int iterations = Mandelbrot::getIterations(coords.first, coords.second);

            fractal[WIDTH * y + x] = iterations;

            if (iterations != Mandelbrot::MAX_ITERATIONS)
				histogram[iterations]++;

        }
    }

    int total = 0;
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        total += histogram[i];
    }

    for (int y = 0; y < HEIGHT; y++) {
        printf("y: %d / %d\n", y, HEIGHT);
        for (int x = 0; x < WIDTH; x++) {
            int iterations = fractal[WIDTH * y + x];

            double hue = 0.0;
			for (int i = 0; i <= iterations; i++) {
				hue += ((double)histogram[i])/total;
			}


            uint8_t red = pow(255, hue);
            uint8_t green = pow(255, hue);
            uint8_t blue = pow(255, hue);
            red = red * (WIDTH - x) / WIDTH;
            green = green * y / HEIGHT;
            blue = blue * x / WIDTH;



			bitmap.setPixel(x, y, red, green, blue);

        }
    }


    bitmap.write("test.bmp");

    std::cout << "Written!\n";
    return 0;
}