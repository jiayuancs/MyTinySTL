#include "vector.h"
#include "heap_algo.h"

#include <iostream>
#include <algorithm>

int main() {
  mystl::vector<int> h{0,1,2,3,4,5};
  mystl::make_heap(h.begin(), h.end());

  std::for_each(h.cbegin(), h.cend(), [](const int x){std::cout << x << " ";});
  std::cout << std::endl;
  return 0;
}
