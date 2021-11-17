#include <cstddef>
#include <stdexcept>

template<typename T>
struct node {
	T value;
	node<T>* next;
};

template<typename T>
class list {
	node<T>* head{nullptr};
	constexpr static char* UNDERFLOW_MSG = "Fuck you, there are no elements";
public:
	std::size_t size() const {
		std::size_t counter = 0;
		for(node<T>* it = head; it != nullptr; ++counter, it = it->next) ;
		return counter;
	}
	bool empty() const {
		return head == nullptr;
	}

	const T& value_at(std::size_t index) const {
		node<T>* it = head;
		for(; index != 0; it = it->next, --index) ;
		return it->value;
	}
	T& value_at(std::size_t index) {
		node<T>* it = head;
		for(; index != 0; it = it->next, --index) ;
		return it->value;
	}

	void push_front(const T& value) {
		node<T>* new_element = new node<T>{value, head};
		head = new_element;
	}
	T& pop_front() {
		if(head == nullptr) {
			throw std::runtime_error{UNDERFLOW_MSG};
		}
		T& result = head->value;

		node<T>* next_node = head->next;
		delete head;
		head = next_node;
		
		return result;
	}

	void push_back(const T& value) {
		if(head == nullptr) {
			head = new node<T>{value, nullptr};
		} else {
			node<T>* it = head;
			for(; it->next != nullptr; it = it->next) ;
			it->next = new node<T>{value, nullptr};
		}
	}
	T& pop_back() {
		if(head == nullptr) {
			throw std::runtime_error{UNDERFLOW_MSG};
		} 
		node<T>* it = head;
		for(; it->next->next != nullptr; it = it->next) ;
		
		T& result = it->next->value;

		delete it->next;
		it->next = nullptr;

		return result;
	}

	const T& front() const {
		return this->head->value;
	}
	T& front() {
		return this->head->value;
	}

	const T& back() const {
		const node<T>* it = head;
		for(; it->next != nullptr; it = it->next) ;
		return it->value;
	}
	T& back() {
		node<T>* it = head;
		for(; it->next != nullptr; it = it->next) ;
		return it->value;
	}

	void insert(std::size_t index, const T& value) {
		if(index >= this->size()) {
			throw std::runtime_error{"Fuck you, I can't reach this index"};
		}
		node<T>* it = head;
		node<T>* previous = nullptr;

		for(; index; --index, previous = it, it = it->next) ;

		node<T>* new_element = new node<T>{value, it};
		previous->next = new_element;
	}
	void erase(std::size_t index) {
		if(index >= this->size()) {
			throw std::runtime_error{"Fuck you, I can't reach this index"};
		}
		node<T>* it = head;
		node<T>* previous = nullptr;

		for(; index; --index, previous = it, it = it->next) ;

		previous->next = it->next;
		delete it;
	}

	const T& value_n_from_end(std::size_t n) const {
		node<T>* it = head;
		for(; n; --n, it = it->next) ;
		return it->value;
	}
	T& value_n_from_end(std::size_t n) {
		node<T>* it = head;
		for(; n; --n, it = it->next) ;
		return it->value;
	}

	/// If there are 0 -> 1 -> 2 -> 3
	/// After reverse it'll become 3 -> 2 -> 1 -> 0
	/// --------------
	/// it->next = previous
	/// head = last
	void reverse() {
		node<T>* following = head;
		node<T>* it = head;
		node<T>* previous = nullptr;

		for(; it != nullptr; previous = it, it = following) {
			following = it->next;
			it->next = previous;
		}
		head = previous;
	}

	void remove_value(const T& value) {
		bool found = false;
		node<T>* it = head;
		node<T>* previous = nullptr;

		for(; it->next != nullptr; previous = it, it = it->next) {
			if(it->value == value) {
				found = true;
				break;
			}
		}

		if(!found) { 
			return;
		}

		previous->next = it->next;
		delete it;
	}
};