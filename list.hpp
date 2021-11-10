#include <cstddef>

template<typename T>
class node {
	T value;
	node<T>* next;
};

template<typename T>
class list {
	node<T>* head{nullptr};
public:
	std::size_t size() const {

	}
	bool empty() const {
		return head == nullptr;
	}

	const T& value_at(std::size_t index) const {

	}
	T& value_at(std::size_t index) {
		
	}

	void push_front(const T& value) {

	}
	T& pop_front() {

	}

	void push_back(const T& value) {

	}
	T& pop_back() {

	}

	const T& front() const {

	}
	T& front() {

	}

	const T& back() const {

	}
	T& back() {

	}

	void insert(std::size_t index, const T& value) {

	}
	void erase(std::size_t index) {

	}

	const T& value_n_from_end(std::size_t n) const {

	}
	T& value_n_from_end(std::size_t n) {
		
	}

	void reverse() {

	}
	void remove_value(const T& value) {

	}

};