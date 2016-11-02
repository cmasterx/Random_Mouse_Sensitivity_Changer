#include <Windows.h>

#include <iostream>
#include <chrono>
#include <thread>
#include <string>

#include "MouseChanger.h"

#define RELEASE true
#define _main main()

#if RELEASE
#undef _main
#define _main WinMain(HINSTANCE hInstance, \
HINSTANCE hPrevInstance, \
LPTSTR    lpCmdLine, \
int       cmdShow) \

#endif

#define TIME_SLEEP	   60000
#define TIME_INTERVAL  3000
#define NO_LIMIT	   true
#define CHANGE_COUNT   3
#define REVERT_SPEED   true

int _main
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
		int currentSpeed = MouseChanger::getMouseSpeed();
		int changeSpeed = currentSpeed;

		if (currentSpeed > 10)
			changeSpeed = rand() % (currentSpeed - 1) + 1;
		else
			changeSpeed = rand() % (20 - currentSpeed);

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

//int WinMain(HINSTANCE hInstance,
//	HINSTANCE hPrevInstance,
//	LPTSTR    lpCmdLine,
//	int       cmdShow)
//{
//	return _main();
//}