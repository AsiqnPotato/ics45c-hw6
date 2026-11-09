#include "shape.hpp"
#include <iostream>

Shape::Shape(Point center, std::string name) {}

void Shape::print(std::ostream& out) const {}

Shape& Shape::operator=(const Shape* other) {}

virtual double Shape::area() const {}

virtual void Shape::draw(std::ostream& out) const {}

virtual Shape* Shape::clone() const {}

// virtual ~Shape() {}

Shape::Shape(const Shape& other) {}
