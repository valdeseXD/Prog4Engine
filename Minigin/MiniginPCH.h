#pragma once

#include <stdio.h>
#include <iostream> // std::cout
#include <sstream> // stringstream
#include <memory> // smart pointers
#include <vector>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

template <typename T>
void SafeDelete(T* pObjectToDelete)
{
	delete(pObjectToDelete);
	pObjectToDelete = nullptr;
}
