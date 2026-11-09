#include "picture.hpp"
#include <iostream>
#include <utility>

Picture::Picture() : head(nullptr), tail(nullptr) {}

void Picture::add(const Shape& shape) {
	ListNode* newnode = new ListNode{shape.clone(), nullptr};
	if (tail == nullptr) {
		tail = newnode;
		head = tail;
	} else {
		tail->next = newnode;
		tail = newnode;
	}
}

void Picture::print_all(std::ostream& out) const {
	ListNode* current = head;
	while (current != nullptr) {
		current->shape->print(out);
		current = current->next;
	}
}


