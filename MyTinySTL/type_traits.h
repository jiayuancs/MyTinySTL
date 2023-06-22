#ifndef MYTINYSTL_TYPE_TRAITS_H_
#define MYTINYSTL_TYPE_TRAITS_H_

// 这个头文件用于提取类型信息

// use standard header for type_traits
#include <type_traits>

namespace mystl {

// helper struct

template <class T, T v>
struct m_integral_constant {
  static constexpr T value = v;
};

template <bool b>
using m_bool_constant = m_integral_constant<bool, b>;

typedef m_bool_constant<true> m_true_type;
typedef m_bool_constant<false> m_false_type;

/*****************************************************************************************/
// type traits

// is_pair

// --- forward declaration begin
// C++ primer P250: forward declaration
// 此时的pair是一个incomplete type
template <class T1, class T2>
struct pair;
// --- forward declaration end

// 主模板：表示默认情况下不是pair类型
template <class T>
struct is_pair : mystl::m_false_type {};

// 偏特化：当传入的类型为pair<T1, T2>时，is_pair类型为m_true_type
template <class T1, class T2>
struct is_pair<mystl::pair<T1, T2>> : mystl::m_true_type {};

}  // namespace mystl

#endif  // !MYTINYSTL_TYPE_TRAITS_H_
