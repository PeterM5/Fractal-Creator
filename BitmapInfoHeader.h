#pragma once
#include <cstdint>

using namespace std;

#pragma pack(2) // We want to make sure what is written to the file is the bytes shown below.
struct BitmapInfoHeader
{
	int32_t headerSize{ 40 }; //InfoHeader is 40 bytes
	int32_t width; // Width of bitmap
	int32_t height; // Height of bitmap
	int16_t planes{ 1 }; 
	int16_t bitsPerPixel{ 24 }; // Using one byte to represent a color. RGB: 8*3 = 24
	int32_t compression{ 0 }; // Not using compression
	int32_t dataSize{ 0 }; // Set later. Size of data that we write to bitmap
	int32_t horizontalResolution{ 2400 }; 
	int32_t verticalResolution{ 2400 };
	int32_t colors{ 0 };
	int32_t importantColors{ 0 };
};
