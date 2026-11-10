#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(Point center, std::stream, int width, int height) 
	: Shape(center, std::move(name)), width(width), height(height) {}

double Rectangle::area() const {
	double rec_area = width * height * 1.0;
	return rec_area;
}

void Rectangle::draw(std::ostream& out) const {
	for (int i = 0; i < height; i += 2) {
		for (int j = 0; j < width; ++j) {
			out << '*';
		}
		out << '\n';
	}
}

Rectangle* Rectangle::clone() const {
	return new Rectangle(*this);
}
