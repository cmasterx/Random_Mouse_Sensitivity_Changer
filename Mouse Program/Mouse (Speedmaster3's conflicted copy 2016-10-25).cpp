#include <Windows.h>

#include <iostream>
#include <chrono>
#include <thread>
#include <string>

#include "MouseChanger.h"

#define TIME_SLEEP	  60000
#define TIME_INTERVAL  3000
#define NO_LIMIT	   true
#define CHANGE_COUNT     15
#define REVERT_SPEED   true

#define CONDITION	\
	std::cout << "Hello World!" << std::endl; \

int _main()
{
	//CONDITION

	//int *p_temp = new int[4];
	//*(p_temp+6) = 42;
	//delete[] p_temp;

	std::this_thread::sleep_for(std::chrono::milliseconds(TIME_SLEEP));

	// Start changing mouse every minute
	
	int mouseSpeed = MouseChanger::getMouseSpeed();
	std::cout << "Original mouse speed: " << std::to_string(mouseSpeed) << std::endl;

	for (int i = 0; i < CHANGE_COUNT || NO_LIMIT; ++i) {
		MouseChanger::changeMouseSpeed(rand() % 20 + 1);

		std::cout << "Speed: " << std::to_string(MouseChanger::getMouseSpeed()) << std::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(TIME_INTERVAL));
	}

	if (REVERT_SPEED) {
		std::cout << "Reverting to original mouse speed: " << std::to_string(mouseSpeed) << std::endl;
		MouseChanger::changeMouseSpeed(mouseSpeed);
	}


	return 0;
}

int WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       cmdShow)
{
	return _main();
}

//int main() 
//{
//	return _main();
//}