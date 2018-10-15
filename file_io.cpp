#include "file_io.hpp"
#include <iostream>
FileIO::FileIO()
{
	//Open file for writing and place header row.
	file.open("./fv.out", std::ios::trunc | std::ios::out);
}
FileIO::~FileIO()
{
	file.close();
}
void FileIO::fileWrite(const char *a, const char *b)
{
	//write headers
	file << a << "," << b << std::endl;
}
void FileIO::fileWrite(double f, double v)
{
	//write data
	file << f << ", " << v << std::endl;
}
