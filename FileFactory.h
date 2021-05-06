/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 5.9------------------------------
 ------------------Przemys³aw Papiernik/Jakub Wrzeszcz/Sebastian Likoñski-----------------------------*/

#pragma once
#include <string>
#include "IFile.h"
#include "BinaryFile.h"
#include "CsvFile.h"

static class FileFactory
{
public:
	static IFile* Open(const std::string, const std::string);
};

