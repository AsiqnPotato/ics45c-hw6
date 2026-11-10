#include "circle.hpp"
#include <iostream>
#include <numbers>

Circle::Circle(Point center, std::string name, int radius)
	: Shape(center, std::move(name)), radius(radius) {
}

double Circle::area() const {
	double circ_area = radius * std::numbers::pi;
	return circ_area;
}

void Circle::draw(std::ostream& out) const {
	for (int y = -radius; y <= radius; y += 2) {
		for (int x = -radius; x <= radius; ++x) {
			out << (x * x + y * y <= radius * radius ? '*' : ' ');
		}
		out << '\n';
	}
}

Circle* Circle::clone() const {
	return new Circle(*this);
}
