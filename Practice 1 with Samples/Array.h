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
	void display() const;
	void init(int min, int max);
	void resize(size_t newSize);
	int findMin() const;
	int findMax() const;
	void sort();

};