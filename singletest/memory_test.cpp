// 测试memory.h

#include "../MyTinySTL/memory.h"

#include <iostream>

using namespace mystl;

int main() {


  get_temporary_buffer<int>(ptrdiff_t(10));

  int *p = nullptr;
  get_temporary_buffer(ptrdiff_t(10), p);
  
  return 0;
}
