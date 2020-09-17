#ifndef __TRIANGLE_H_
#define __TRIANGLE_H_

int TypeOfTriangle(int, int, int);

#endif
/* Return values
 * 1 for equilateral, 2 for isosceles, 3 for scalan
 * 0 if triangle can't be formed with given sides
 * -1 if any side value is invalid,say -ve
 */
int TypeOfTriangle(int a, int b, int c) {
  if (a < 0 || b < 0 || c < 0) return -1;
  if (!(a + b > c && b + c > a && a + c > b))
    return 0;
  else if (a == b && b == c)
    return 1;
  else if (a == b || b == c || c == a)
    return 2;
  else  // a!=b && b!=c && c!=a
    return 3;
}

#include <gtest/gtest.h>
namespace {
TEST(TriangleTest, InvalidSides) {
  EXPECT_EQ(-1, TypeOfTriangle(-10, 20, 30));
  EXPECT_EQ(-1, TypeOfTriangle(10, -20, 30));
  EXPECT_EQ(-1, TypeOfTriangle(3, 4, -8));
}
TEST(TriangleTest, NonFormation) {
  EXPECT_EQ(0, TypeOfTriangle(10, 20, 30));
  EXPECT_EQ(0, TypeOfTriangle(3, 4, 8));
}
TEST(TriangleTest, Equivalateral) {
  EXPECT_EQ(1, TypeOfTriangle(10, 10, 10));
  EXPECT_EQ(1, TypeOfTriangle(5, 5, 5));
}
TEST(TriangleTest, Isosceles) {
  EXPECT_EQ(2, TypeOfTriangle(10, 10, 15));
  EXPECT_EQ(2, TypeOfTriangle(15, 10, 10));
  EXPECT_EQ(2, TypeOfTriangle(10, 15, 10));
}
TEST(TriangleTest, Scalan) {
  EXPECT_EQ(3, TypeOfTriangle(3, 4, 5));
  EXPECT_EQ(3, TypeOfTriangle(10, 12, 15));
  EXPECT_EQ(3, TypeOfTriangle(10, 25, 18));
}
}
