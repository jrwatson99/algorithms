#include "SortingList.h" 
#include <iostream>



int main() {
	std::vector<int> testList1 = { 1,4,2,6,2,3,4,8,6,3,14,52,63,2,3,0,-5,2,99,43,2,5,11 };
	for (int i = 0; i < testList1.size(); i++) {
		std::cout << testList1[i] << " ";
	}
	std::cout << std::endl;
	std::vector<int> sortedList1 = quicksort(testList1);
	for (int i = 0; i < sortedList1.size(); i++) {
		std::cout << sortedList1[i] << " ";
	}
	std::cout << std::endl;
}

std::vector<int> quicksort(std::vector<int> list) {
	if (list.size() > 1) {
		//split list
		std::vector<int> sublist1, sublist2;
		int pivot = list.size() / 2;
		for (int i = 0; i < pivot; i++) {
			sublist1.push_back(list[i]);
		}
		for (int i = pivot; i < list.size(); i++) {
			sublist2.push_back(list[i]);
		}
		sublist1 = quicksort(sublist1);
		sublist2 = quicksort(sublist2);
		
		//merge sublists
		std::vector<int> newList;
		int i1 = 0;
		int i2 = 0;
		while ((i1 < sublist1.size()) && (i2 < sublist2.size())) {
			if (sublist1[i1] <= sublist2[i2]) {
				newList.push_back(sublist1[i1]);
				i1++;
			}
			else {
				newList.push_back(sublist2[i2]);
				i2++;
			}
		}
		//add all elements remaining
		while (i1 < sublist1.size()) {
			newList.push_back(sublist1[i1]);
			i1++;
		}
		while (i2 < sublist2.size()) {
			newList.push_back(sublist2[i2]);
			i2++;
		}
		list = newList;
	}
	return list;
}

//sort all entries in the list via quicksort
void SortingList::sort() {
	this->list = quicksort(this->list);
}
