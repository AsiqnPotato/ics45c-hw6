// ------------------------- Your tests - student_gtests.cpp ----------------------------- //
// Your own GoogleTest suite for the shapes and Picture. It is graded: the autograder runs it
// against a correct implementation and against several with one bug each. A test is worth
// something only when it passes on the correct implementation and fails on a broken one, so a
// test that always fails (or that tests nothing) earns nothing.
//
// Two examples are given. Add tests of your own for the areas, for print_all and draw_all,
// for total_area, and for copying a Picture.
// --------------------------------------------------------------------------------------- //

#include <gtest/gtest.h>

#include "circle.hpp"
#include "picture.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "square.hpp"
#include "triangle.hpp"

TEST(ShapeTests, RectangleAreaIsWidthTimesHeight) {
    EXPECT_NEAR(Rectangle({0, 0}, "R", 7, 3).area(), 21.0, 0.001);
}

TEST(PictureTests, AnEmptyPictureHasNoArea) {
    const Picture p;
    EXPECT_DOUBLE_EQ(p.total_area(), 0.0);
}

// ADD YOUR TESTS HERE:

TEST(ShapeTests, CircleArea) {
	Circle c(Point{0, 0}, "circle", 5);
	EXPECT_NEAR(c.area(), 78.5398, 0.001);

	Circle degenerate(Point{1, 1}, "deg_circle", 0);
	EXPECT_EQ(degenerate.area(), 0.0);
}

TEST(ShapeTests, RectangleArea) {
	Rectangle r(Point{0, 0}, "rectangle", 4, 5);
	EXPECT_NEAR(r.area(), 20.0, 0.01);

	Rectangle degenerate(Point{1, 1}, "deg_retangle", 0, 5);
	EXPECT_EQ(degenerate.area(), 0.0);
}

TEST(ShapeTests, TriangleArea) {
	Triangle t(Point{0, 0}, "triangle", 5, 6);
	EXPECT_NEAR(t.area(), 15.0, 0.01);

	Triangle degenerate(Point{2, 3}, "deg_triangle", 12, 0);
	EXPECT_EQ(degenerate.area(), 0.0);
}

TEST(ShapeTests, SquareArea) {
	Square s(Point{0, 0}, "square", 4);
	EXPECT_NEAR(s.area(), 16.0, 0.01);

	Square degenerate(Point{1, 1}, "square", 0);
	EXPECT_EQ(degenerate.area(), 0.0);
}
