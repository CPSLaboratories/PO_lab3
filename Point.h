/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 5.9------------------------------
 ------------------Przemys�aw Papiernik/Jakub Wrzeszcz/Sebastian Liko�ski-----------------------------*/

#pragma once
struct Point
{
	Point() : x(0.0), y(0.0), z(0.0) {}
	Point(double x, double y, double z) : x(x), y(y), z(z) {}
	double x, y, z;
};