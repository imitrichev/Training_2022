#include "gtest/gtest.h"

int Factorial(int n)
{
	if (n<0)
		throw std::invalid_argument("received negative value");
	if (n==0)
		return 1;
	else
		return n*Factorial(n-1);
}

TEST(FactorialTest, NegativeInput) {
  ASSERT_THROW(Factorial(-1), std::invalid_argument);
}

TEST(FactorialTest, ZeroInput) {
  EXPECT_EQ(Factorial(0), 1);
}

TEST(FactorialTest, PositiveInput) {
  EXPECT_EQ(Factorial(1), 1);
  EXPECT_EQ(Factorial(2), 2);
  EXPECT_EQ(Factorial(3), 6);
  EXPECT_EQ(Factorial(5), 120);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
