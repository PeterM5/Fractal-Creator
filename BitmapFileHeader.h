#pragma once
#include <cstdint>

using namespace std;

/// <summary>
/// BitmapFileHeader is used to create bitmap headers efficiently. 
/// The format of struct replicates that of the file header so you only need to write directly to the header.
/// </summary>
// #pragma pack(2): We must instruct c++ to align struct on 2 byte bounderies. Normally compiler would automatically align on 4 or 8 byte bounderies for efficency.
// We need to do this as we are writing this struct directly to bitmap header so it has to replicate the format of a bitmap header. Cant have any whitespace.
#pragma pack(2) 
struct BitmapFileHeader
{
	char header[2]{ 'B','M' }; // Header starts with B and M (Bit Map)
	int32_t fileSize; // Integer must be 32 bits.
	int32_t reserved{0}; // Reserved, we set to 0.
	int32_t dataOffset; // How long into the file the data begins.
};

