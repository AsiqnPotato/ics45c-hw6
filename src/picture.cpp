#include "picture.hpp"
#include <iostream>
#include <utility>

Picture::Picture() : head(nullptr), tail(nullptr) {
}

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

Picture::Picture(const Picture& other) : head(other.head), tail(other.tail) {
	ListNode* current = other.head;
	while (current != nullptr) {
		if (current->shape != nullptr) {
			add(*(current->shape));
		}
		current = current->next;
	}
}

Picture::Picture(Picture&& other) noexcept : head(other.head), tail(other.tail) {
	other.head = nullptr;
	other.tail = nullptr;
}

void Picture::swap(Picture& other) {
	std::swap(head, other.head);
	std::swap(tail, other.tail);
}

Picture& Picture::operator=(const Picture& other) {
	if (this != &other) {
		Picture temp(other);
		swap(temp);
	}
	return *this;
}

Picture& Picture::operator=(Picture&& other) noexcept {
	if (this != &other) {
		ListNode* current = head;
		while (current != nullptr) {
			ListNode* next_node = current->next;
			delete current->shape;
			delete current;
			current = next_node;
		}
		head = other.head;
		tail = other.tail;

		other.head = nullptr;
		other.tail = nullptr;
	}
	return *this;
}

void Picture::print_all(std::ostream& out) const {
	ListNode* current = head;
	while (current != nullptr) {
		current->shape->print(out);
		current->shape->draw(out);
		current = current->next;
	}
}

void Picture::draw_all(std::ostream& out) const {
	ListNode* current = head;
	while (current != nullptr) {
		current->shape->draw(out);
		current = current->next;
	}
}

double Picture::total_area() const {
	double total = 0.0;
	ListNode* current = head;
	while(current != nullptr) {
		total += current->shape->area();
		current = current->next;
	}
	return total;
}

Picture::~Picture() {
	ListNode* current = head;
	while (current != nullptr) {
		ListNode* next_node = current->next;
		delete current->shape;
		delete current;
		current = next_node;
	}
}
