#include <iostream>
#include "AsyncFunctions.h"

int ReturnValue(int value)
{
	return value;
}

int main()
{
	std::cout << "Running main" << "\n";
	constexpr int testValue = 100;
	AsyncFunctions::RunCallbackAfterTenSeconds(&ReturnValue, testValue);
	return 0;
}