#pragma once

namespace AsyncFunctions
{
	int RunCallbackAfterTenSeconds(int(*callback)(int), int value);
}