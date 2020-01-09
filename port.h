#ifndef PORT_H_
#define PORT_H_ 
#pragma once

#include <iostream>
using namespace std;

class Port
{
private:
	char * brand_m;
	char style_m[20];
	int bottles_m;
public:
	Port(const char * br="Brak",const char * st="Brak", int b=0);
	Port(const Port & p);
	virtual~Port() { delete[] brand_m; }
	Port & operator=(const Port & p);
	Port & operator+=(int b);//dodaje b do bottles;
	Port & operator-=(int b);//odejmuje b od bottles jeœli jest to mo¿liwe;
	int Bottle_count()const { return bottles_m; }
	virtual void Show()const;
	friend ostream & operator<<(ostream & os, const Port & p);
	char* Brand() { return brand_m; }

};
void strcpy_p(char * a, const char * b);
void strcpy_p(char * a, char * b);

#endif // !PORT_H_