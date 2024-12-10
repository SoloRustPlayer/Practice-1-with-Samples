#pragma once
#include <iostream>

class Array
{
private:
	int* data;
	size_t size;
public:
	Array();
	Array(size_t n);
	Array(size_t n, int min, int max);
	~Array();


};