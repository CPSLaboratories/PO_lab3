/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 5.9------------------------------
 ------------------Przemys³aw Papiernik/Jakub Wrzeszcz/Sebastian Likoñski-----------------------------*/

#include "BinaryFile.h"
#include "CsvFile.h"
#include "Point.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	//char ktoryplik;
	//char tryb;
	
	//cout << "Ktory plik chcesz otworzyc? Wybierz odpowiednia litere:" << endl;
	//cout << "b - plik binarny" << endl;
	//cout << "c - plik tekstowy o wartosciach rozdzielonych" << endl;

	//cin >> ktoryplik;

	//if (ktoryplik != 'b' && ktoryplik != 'c')
	//{
	//	cout << "Nie rozpoznano typu pliku" << endl;
	//}

	//cout << "Jak chcesz otworzyc plik? Wybierz odpowiednia litere:\n" << endl;
	//cout << "r - odczytywanie danych" << endl;
	//cout << "w - zapisywanie danych" << endl;
	//cout << "a - zapisywanie danych na koncu pliku" << endl;
	//cout << "t - kasowanie zawatosci" << endl;
	//cout << "e - ustawienie wskaznika na koniec pliku\n" << endl;
	
	//cin >> tryb;

	//if (ktoryplik == 'b')
	//{
	//	//otwarcie BinaryFile
	//}

	//else
	//{
		//otwarcie CsvFile
		vector <Point> dane;
		dane.push_back(Point(1,2,30));
		dane.push_back(Point(1,2,31));
		dane.push_back(Point(1,2,32));
		dane.push_back(Point(1,2,33));
		dane.push_back(Point(1,2,34));
		//CsvFile Plik = CsvFile("test2.csv", "w");
		CsvFile Plik("test2.csv", "w");
		Plik.Write(dane);

	//}

}

