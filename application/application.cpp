#include <iostream>
#include <future>
#include <chrono>

int ReturnValue(int value)
{
	return value;
}

enum class STATE : int
{
	WAITING,
	INVOKE,
	NON_BLOCK,
};

int LibraryAsyncFunction(int(*callback)(int), int value)
{
	bool running = true;
	std::future<int> asyncFunction;
	STATE state = STATE::WAITING;
	constexpr double TICK_SECONDS = 10;
	const auto startTime = std::chrono::steady_clock::now();
	int result = INT_MIN;
	while(running)
	{
		switch (state)
		{
			case STATE::WAITING:
			{
				std::cout << "Waiting..." << "\n";
				const auto duration = std::chrono::duration<double>(std::chrono::steady_clock::now() - startTime);
				if (duration.count() >= TICK_SECONDS)
				{
					std::cout << "Done waiting, time to invoke!" << "\n";
					state = STATE::INVOKE;
				}
				break;
			}
			case STATE::INVOKE:
			{
				std::cout << "Invoking async function" << "\n";
				asyncFunction = std::async(callback, value);
				state = STATE::NON_BLOCK;
				break;
			}
			case STATE::NON_BLOCK:
			{
				std::cout << "Waiting for async function to resolve while we do other work" << "\n";
				if (asyncFunction.valid())
				{
					std::cout << "Async function resolved!" << "\n";
					result = asyncFunction.get();
					std::cout << "Async function result is: " << result << "\n";
					running = false;
				}
				break;
			}
		}
	}

	return result;
}

int main()
{
	LibraryAsyncFunction(&ReturnValue, 100);
}