/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 5.9------------------------------
 ------------------Przemys³aw Papiernik/Jakub Wrzeszcz/Sebastian Likoñski-----------------------------*/

#include "CsvFile.h"
#include "FileError.h"
#include <string>

using namespace std;

CsvFile::CsvFile(const std::string filePath, const std::string mode) : filePath(filePath), length(0)
{
	//openMode = std::fstream::out;

	if (mode.find("r") != std::string::npos) openMode |= std::fstream::in;
	if (mode.find("w") != std::string::npos) openMode |= std::fstream::out;
	if (mode.find("a") != std::string::npos) openMode |= std::fstream::app;
	if (mode.find("t") != std::string::npos) openMode |= std::fstream::trunc;
	if (mode.find("e") != std::string::npos) openMode |= std::fstream::ate;

	file.open(filePath, openMode);

	//if (file.is_open()) 
	//{
	//	file.seekg(0, std::fstream::end);
	//	length = file.tellg();
	//	file.seekg(0, std::fstream::beg);
	//}
}

CsvFile::~CsvFile()
{
	file.close();
}

FileError CsvFile::Write(const std::vector<Point>& v)
{
	int Rozmiar = v.size();

	FileError retVal = FileError(ACCESS_DENIED);

	if (!file.is_open())
	{
		retVal = FileError(FILE_INVALID);
	}
	else if (openMode & std::fstream::out)
	{
		string Dane = "";

		for(int i = 0; i < Rozmiar; i++)
		{
			Dane += to_string(v[i].x) + "," + to_string(v[i].y) + "," + to_string(v[i].z) + "\n";
		}

		file << Dane;

		retVal = FileError(SUCCESS);
	}

	return retVal;
}

FileError CsvFile::Read(std::vector<Point>& v)
{
	FileError retVal = FileError(ACCESS_DENIED);

	if (!file.is_open())
	{
		retVal = FileError(FILE_INVALID);
	}
	else if (openMode & std::fstream::in)
	{
		v.clear();
		v.resize(length / sizeof(Point));
		file.seekg(0, std::fstream::beg);
		file.read((char*)v.data(), length);
		retVal = FileError(SUCCESS);
	}

	return retVal;
}

FileError CsvFile::Read(Point& p, const unsigned long idx)
{
	FileError retVal = FileError(ACCESS_DENIED);

	if (!file.is_open())
	{
		retVal = FileError(FILE_INVALID);
	}
	else if (idx * sizeof(Point) > length)
	{
		retVal = FileError(OUT_OF_BOUNDS);
	}
	else if (openMode & std::fstream::in)
	{
		file.seekg(idx * sizeof(Point));
		file.read((char*)(&p), sizeof(Point));
		retVal = FileError(SUCCESS);
	}

	return retVal;
}