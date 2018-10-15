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
void FileIO::fileWrite(char *a, char *b, char *c)
{
	file << a << "," << b << "," << c << std::endl;
}
void FileIO::fileWrite(double f, double v, double x)
{
	file << f << "," << v << "," << x << std::endl;
}
