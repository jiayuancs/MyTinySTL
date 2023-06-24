// 测试allocator.h

#include "allocator.h"

#include <iostream>
#include <string>

#include "gtest/gtest.h"

using namespace mystl;

TEST(AllocatorTest, ConstructTest) {
  allocator<std::string> ai;
  std::string *const pi = ai.allocate(10);

  std::string *tmp = pi;

  ai.construct(tmp);
  ++tmp;
  ai.construct(tmp, "hello world ceshijsddddddd");
  ++tmp;
  ai.construct(tmp, std::string("string"));

  tmp = pi;
  for (int i = 0; i < 3; ++i, ++tmp) {
    std::cout << *tmp << std::endl;
    ai.destroy(tmp);
  }

  // 在deallocate前要先destroy，否则可能会产生内存泄漏
  ai.deallocate(pi, 10);
};
