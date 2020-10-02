#pragma once
#include <vector>

std::vector<int> quicksort(std::vector<int> list);

class SortingList {
private:
	std::vector<int> list;

public:
	void sort();
};