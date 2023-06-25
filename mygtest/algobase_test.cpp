// 测试algobase.h

#include "algobase.h"

#include <cstddef>
#include <iostream>
#include <string>
#include <type_traits>

#include "gtest/gtest.h"

using namespace mystl;

TEST(AlgobaseTest, FillBoolArrayTest) {
  constexpr int kArraySize = 100;
  bool array_bool[kArraySize]{false};

  for (int i = 0; i < kArraySize; ++i) {
    EXPECT_FALSE(array_bool[i]);
  }

  memset(array_bool, true, sizeof(array_bool));
  for (int i = 0; i < kArraySize; ++i) {
    EXPECT_TRUE(array_bool[i]);
  }

  fill_n(array_bool, kArraySize, false);

  for (int i = 0; i < kArraySize; ++i) {
    EXPECT_FALSE(array_bool[i]);
  }
};
