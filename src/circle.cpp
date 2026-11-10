#include "circle.hpp"
#include <iostream>
#include <numbers>

Circle::Circle(Point center, std::string name, int radius)
	: Shape(center, std::move(name)), radius(radius) {}

double Circle::area() {
	return 0.0;
}

void Circle::draw(std::ostream& out) const {
	
}

Circle* Circle::clone() const {
	return new Circle(*this);
}
