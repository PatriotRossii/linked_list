#include <iostream>
#include "list.hpp"

int main() {
	list<int> myList;
	std::cout << "Is empty? " << myList.empty() << std::endl;

	myList.push_back(2);
	myList.push_back(3);
	myList.push_front(0);

	std::cout << "Is empty? " << myList.empty() << std::endl;
	std::cout << "Size: " << myList.size() << std::endl;

	myList.insert(1, 1);

	std::cout << "Size: " << myList.size() << std::endl;
	for(int i = 0; i < myList.size(); ++i) {
		std::cout << "Value at " << i << " is " << myList.value_at(i) << std::endl;
	}

	std::cout << "Front: " << myList.front() << std::endl;
	std::cout << "Back: " << myList.back() << std::endl;

	myList.erase(2);
	for(int i = 0; i < myList.size(); ++i) {
		std::cout << "Value at " << i << " is " << myList.value_at(i) << std::endl;
	}

	std::cout << "Value of the node at 1th position from the end: " << 
		myList.value_n_from_end(1) << std::endl;

	myList.reverse();
	for(int i = 0; i < myList.size(); ++i) {
		std::cout << "Value at " << i << " is " << myList.value_at(i) << std::endl;
	}
}