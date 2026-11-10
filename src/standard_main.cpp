#include <iostream>
#include <string>
#include "picture.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "triangle.hpp"
using namespace std;

int main(int argc, char * argv[])
{
    cout << argv[argc-1] << " says Hello World\n";

	Picture collage {};
	collage.add(Circle(Point{0, 0}, "circle", 5));
	collage.print_all(cout);
	collage.draw_all(cout);
	double total = collage.total_area();
}
