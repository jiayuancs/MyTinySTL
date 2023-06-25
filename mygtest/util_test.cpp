// 测试util.h

#include "util.h"

#include <iostream>
#include <type_traits>

#include "gtest/gtest.h"

// test forward
namespace test_forward {

enum value_type { kLValue, kRValue };

value_type PrintType(const int &val) {
  std::cout << "get lvalue: " << val << std::endl;
  return kLValue;
}

value_type PrintType(int &&val) {
  std::cout << "get rvalue: " << val << std::endl;
  return kRValue;
}

template <typename Type>
value_type TestValueType(Type &&val) {
  // 只接受int或const int
  constexpr bool check_ok =
      std::is_same<int, typename std::remove_reference<Type>::type>::value ||
      std::is_same<const int,
                   typename std::remove_reference<Type>::type>::value;
  static_assert(check_ok, "bad type, the base type should be int or const int");

  return PrintType(mystl::forward<Type>(val));
}

}  // namespace test_forward

TEST(UtilTest, ForwardTest) {
  const int lvalue = 42;
  EXPECT_EQ(test_forward::TestValueType(lvalue), test_forward::kLValue);
  EXPECT_EQ(test_forward::TestValueType(24), test_forward::kRValue);
};

TEST(StdUtilTest, IsConvertibleTest) {
  // const int &可以隐式转换为int
  constexpr bool expect_true = std::is_convertible<const int &, int>::value;
  EXPECT_TRUE(expect_true);
}
