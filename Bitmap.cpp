#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace std;

Bitmap::Bitmap(int width, int height) : 
	m_width(width), 
	m_height(height),
	m_pPixels(new uint8_t[(int64_t)width * (int64_t)height * 3]{})
{
	
}

bool Bitmap::write(string filename) {
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
	fileHeader.fileSize = fileHeader.dataOffset + m_width * m_height * 3;
	
	infoHeader.width = m_width;
	infoHeader.height = m_height;

	ofstream file;
	file.open(filename, ios::out | ios::binary);

	if (!file) {
		return false;
	}

	file.write(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
	file.write(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));
	file.write(reinterpret_cast<char*>(m_pPixels.get()), 
		(int64_t)m_width * (int64_t)m_height * 3);


	file.close();

	if (!file) {
		return false;
	}

	return true;
}


void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
	uint8_t* pPixel = m_pPixels.get();

	pPixel += (y * 3) * m_width + (x * 3);
	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;


}


Bitmap::~Bitmap() {

}
 
