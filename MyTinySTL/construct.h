#ifndef MYTINYSTL_CONSTRUCT_H_
#define MYTINYSTL_CONSTRUCT_H_

// 这个头文件包含两个函数 construct，destroy
// construct : 负责对象的构造
// destroy   : 负责对象的析构

#include <new>

#include "iterator.h"
#include "type_traits.h"
// jiayuancs: 本文件使用到了mystl::forward，但没有包含util.h文件，故添加
#include "util.h"

// 此代码用于抑制Microsoft Visual c++编译器在编译具有未使用参数的代码时生成的警告
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4100)  // unused parameter
#endif                           // _MSC_VER

namespace mystl {

// construct 构造对象

// 默认构造
template <class Ty>
void construct(Ty* ptr) {
  ::new ((void*)ptr) Ty();
}

// 拷贝构造
template <class Ty1, class Ty2>
void construct(Ty1* ptr, const Ty2& value) {
  ::new ((void*)ptr) Ty1(value);
}

// 参数构造
template <class Ty, class... Args>
void construct(Ty* ptr, Args&&... args) {
  ::new ((void*)ptr) Ty(mystl::forward<Args>(args)...);
}

// destroy 将对象析构

template <class Ty>
void destroy_one(Ty*, std::true_type) {}

template <class Ty>
void destroy_one(Ty* pointer, std::false_type) {
  if (pointer != nullptr) {
    pointer->~Ty();
  }
}

template <class ForwardIter>
void destroy_cat(ForwardIter, ForwardIter, std::true_type) {}

template <class ForwardIter>
void destroy_cat(ForwardIter first, ForwardIter last, std::false_type) {
  for (; first != last; ++first) destroy(&*first);
}

// trivially: 无关紧要的
// 如果Ty的构造函数是trivially，则没必要调用构造函数
template <class Ty>
void destroy(Ty* pointer) {
  destroy_one(pointer, std::is_trivially_destructible<Ty>{});
}

template <class ForwardIter>
void destroy(ForwardIter first, ForwardIter last) {
  destroy_cat(first, last,
              std::is_trivially_destructible<
                  typename iterator_traits<ForwardIter>::value_type>{});
}

}  // namespace mystl

#ifdef _MSC_VER
#pragma warning(pop)
#endif  // _MSC_VER

#endif  // !MYTINYSTL_CONSTRUCT_H_
