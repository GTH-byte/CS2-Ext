#pragma once
#include <iostream>
#include <Windows.h>

#include <thread>
#include <chrono>

#include "sdk/skCrypter.h"
#include "sdk/memory.h"
#include "sdk/csgo.hpp"

using namespace hazedumper;
using namespace netvars;
using namespace signatures;

p_module client_dll;
memory mem;

std::string random_string(int lenght)
{
	const char* charmap = crypt("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	std::string result;
	srand(time(NULL));
	for (int i = 0; i < lenght; ++i)
	{
		result += charmap[rand() % 52];
	}
	return result;
}