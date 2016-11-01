#include "MouseChanger.h"

#include <iostream>
#include <windows.h>
#include<winuser.h>
#pragma comment(lib, "user32.lib")

bool MouseChanger::changeMouseSpeed(int speed)
{
	if (speed > 0 && speed < 21) {
		return SystemParametersInfo(SPI_SETMOUSESPEED,
			0,
			(LPVOID)speed,
			SPIF_UPDATEINIFILE ||
			SPIF_SENDCHANGE ||
			SPIF_SENDWININICHANGE);
	}

	return false;
};

int MouseChanger::getMouseSpeed()
{
	int buff = 0;
	int *MouseSpeed = &buff;
	bool b = SystemParametersInfo(SPI_GETMOUSESPEED, 0, MouseSpeed, 0);

	return buff;
}