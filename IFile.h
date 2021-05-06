/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 5.9------------------------------
 ------------------Przemys³aw Papiernik/Jakub Wrzeszcz/Sebastian Likoñski-----------------------------*/

#pragma once
#include <fstream>
#include <vector>
#include "Point.h"
#include "FileError.h"

class IFile
{
protected:
	std::fstream file;
	std::string filePath;
	unsigned long length;
	std::fstream::openmode openMode;
public:
	IFile(const std::string filePath, const std::string mode);
	virtual ~IFile();

	enum Error
	{
		SUCCESS,
		ACCESS_DENIED,
		OUT_OF_BOUNDS,
		FILE_INVALID
	};

	virtual FileError Write(const std::vector<Point>&) = 0;
	virtual FileError Read(std::vector<Point>&) = 0;
	virtual FileError Read(Point&, const unsigned long) = 0;
};

