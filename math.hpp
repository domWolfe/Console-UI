#pragma once
#include <Windows.h>
#include "common_includes.hpp"

namespace Math {
	int clamp(int val, int minimum, int maximum);

	int wrap(int val, int minimum, int maximum);

	int menu_wrap(int val, int minimum, int maximum);
}

namespace Util {
	std::vector<std::string> splitString(std::string str, char splitter);
}