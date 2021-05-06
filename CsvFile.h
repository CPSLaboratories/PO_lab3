/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 5.9------------------------------
 ------------------Przemys�aw Papiernik/Jakub Wrzeszcz/Sebastian Liko�ski-----------------------------*/

#pragma once 
#include <fstream> 
#include <vector>
#include <string>
#include "Point.h"
#include "FileError.h"
#include "IFile.h"

using namespace std;

class CsvFile : public IFile
{
private:

	std::fstream file;                 // Strumie� pliku
	std::string filePath;              // Nazwa pliku
	unsigned long length;              // Rozmiar pliku
	std::fstream::openmode openMode;   // Tryb otwarcia pliku

public:

	CsvFile(const std::string a, const std::string b) : IFile(a, b) {};   // Konstruktor klasy 
	~CsvFile();                                      // Destruktor klasy

	FileError Write(const std::vector<Point>&);   // Zapis wektora punkt�w do pliku
	FileError Read(std::vector<Point>&);          // Odczyt do wektora punkt�w z pliku
	vector<string> Split(string str, char delim);
	FileError Read(Point&, const unsigned long);  // Odczyt do struktury point punkt�w z pliku
};

