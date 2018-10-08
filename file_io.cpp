#include "file_io.hpp"
#include <iostream>
FileIO::FileIO()
{
	file.open("../../fv.out", std::ios::trunc | std::ios::out);
	file << "f" << "," << "v" << std::endl;
}
FileIO::~FileIO()
{
	file.close();
}
void FileIO::fileWrite(double f, double v)
{
	file << f << "," << v << std::endl;
}
