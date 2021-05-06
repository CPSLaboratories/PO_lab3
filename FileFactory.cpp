/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 5.9------------------------------
 ------------------Przemys³aw Papiernik/Jakub Wrzeszcz/Sebastian Likoñski-----------------------------*/

#include "FileFactory.h"
#include "iostream"

using namespace std;

IFile* FileFactory::Open(const std::string filePath, const std::string mode)
{
	IFile * file = nullptr;

	if (filePath.substr(filePath.find_last_of(".") + 1) == "bin")
	{
		file = new BinaryFile(filePath, mode + "b");
	}
	else if (filePath.substr(filePath.find_last_of(".") + 1) == "csv")
	{
		file = new CsvFile(filePath, mode + "b");
	}
	else
	{
		cout << "Nie rozpoznano typu pliku";
	}

	return file;
}
