#include "vintagePort.h"
const int ACTUAL_YEAR = 2018;


VintagePort::VintagePort()
	:Port()
{
	nickname_m = nullptr;
	year_m = ACTUAL_YEAR;
}
//gotowe

VintagePort::VintagePort(const char * br, const char * st, int b, const char * nn, int y)
	:Port(br,st,b)
{
	if (nn != nullptr)
	{
		nickname_m = new char[strlen(nn) + 1];
		strcpy_p(nickname_m, nn);
	}
	else
		nickname_m = nullptr;
	year_m = y;
}
//gotowe

VintagePort::VintagePort(const VintagePort & vp)
	:Port(vp)
{
	if (vp.nickname_m != nullptr)
	{
		nickname_m = new char[strlen(vp.nickname_m) + 1];
		strcpy_p(nickname_m, vp.nickname_m);
	}
	else
		nickname_m = nullptr;
	year_m = vp.year_m;
}
//gotowe

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	if (this == &vp)
		return *this;
	else
	{
		Port::operator=(vp);
		delete[] nickname_m;
		if (vp.nickname_m != nullptr)
		{
			nickname_m = new char[strlen(vp.nickname_m) + 1];
			strcpy_p(nickname_m, vp.nickname_m);
		}
		else
			nickname_m = nullptr;
		year_m = vp.year_m;
		return *this;
	}

}
//gotowe

void VintagePort::Show()const
{
	
	//if (nickname_m != nullptr)
	cout << nickname_m << " ";
	Port::Show();
	//if (year_m < ACTUAL_YEAR - 5)
	cout << "Rok produkcji: " << year_m << "\n";
}
//gotowe;

ostream & operator<<(ostream & os, const VintagePort & vp)
{
	if (vp.nickname_m != nullptr)
		os << vp.nickname_m << " ";
	os << Port(vp) << " ";
	if (vp.year_m < ACTUAL_YEAR - 5)
		os << vp.year_m;
	os << "\n";
	return os;
}
//gotowe;
