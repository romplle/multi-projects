#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "bubble_sort.hpp"

TEST(ArraysEqual, AnyElementsCount) {
	std::vector<int> actual = {1, 8, 2, 5, 3, 11};
	BubbleSort::sort(actual);
	std::vector<int> expected = {1, 2, 3, 5, 8, 11};
	
	ASSERT_EQ(expected.size(), actual.size())
		<< "Different sizes of expected and sorted arrays";

	for (int i = 0; i < actual.size(); i++) {
		ASSERT_EQ(expected[i], actual[i])
			<< "The expected and sorted array differ in the element with the index "
			<< i;
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
