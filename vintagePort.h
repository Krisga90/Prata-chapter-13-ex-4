#pragma once

#include "port.h"

class VintagePort:public Port
{
private:
	char * nickname_m;	//np. Szlachetny, aksamitny
	int year_m;	//rok produkcji
public:
	VintagePort();
	VintagePort(const char * br, const char * st, int b, const char * nn, int y);
	VintagePort(const VintagePort & vp);
	~VintagePort() { delete [] nickname_m; }
	VintagePort & operator=(const VintagePort & vp);
	virtual void Show()const;
	friend ostream & operator<<(ostream & os, const VintagePort & vp);
};

