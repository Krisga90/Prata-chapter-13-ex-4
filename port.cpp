#include "port.h"



Port::Port(const char * br , const char * st , int b )
{
	bottles_m += b;
	brand_m = new char[strlen(br) + 1];
	strcpy_p(brand_m, br);
	strcpy_p(style_m, st);
}
//gotowe

Port::Port(const Port & p)
{
	bottles_m += p.bottles_m;
	brand_m = new char[strlen(p.brand_m) + 1];
	strcpy_p(brand_m, p.brand_m);
	strcpy_p(style_m, p.style_m);
}
//gotowe

Port & Port::operator=(const Port & p)
{
	if (this == &p)
		return *this;
	else
	{
		bottles_m += p.bottles_m;
		delete[] brand_m;
		brand_m=new char[strlen(p.brand_m) + 1];
		strcpy_p(brand_m, p.brand_m);
		strcpy_p(style_m, p.style_m);
		return *this;
	}
}
//gotowe

Port & Port::operator+=(int b)//dodaje b do bottles;
{
	bottles_m += b;
	return *this;
}
//gotowe

Port & Port::operator-=(int b)//odejmuje b od bottles jeœli jest to mo¿liwe;
{
	if (bottles_m < b)
		cout << "Za malo butelek w magazynie";
	else
	{
		bottles_m -= b;
		//cout << "Wydano " << b << " butelek, w magazynie zostalo " << bottles_m << " butelek.\n";
	}
	return *this;
}
//gotowe

void Port::Show()const
{
	cout << "Marka: " << brand_m << "\nRodzaj: " << style_m << "\nButelek: " << bottles_m << "\n";
}
//gotowe

ostream & operator<<(ostream & os, const Port & p)
{
	os<< p.brand_m << ", " << p.style_m << ", " << p.bottles_m << "\n";
	return os;
}
//gotowe

void strcpy_p(char * a, const char * b)
{
	int i = 0;
	while (b[i])
	{
		a[i] = b[i];
		i++;
	}
	a[i] = '\0';
}
//gotowe

void strcpy_p(char * a, char * b)
{
	int i = 0;
	while (b[i])
	{
		a[i] = b[i];
		i++;
	}
	a[i] = '\0';
}
//gotowe
