cmake_minimum_required(VERSION 3.22)

project(MyTinySTL "CXX")

# gtest要求版本不得低于C++14
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-sign-compare -Wno-unused-but-set-variable -Wno-array-bounds")

# 构建模式：Debug, Release, ...
set(CMAKE_BUILD_TYPE Debug)

# MyTinySTL头文件目录
set(MYTINYSLT_HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/MyTinySTL)

# gtest目录
set(THIRD_PARTY_GTEST ${CMAKE_CURRENT_SOURCE_DIR}/third_party/gtest)

# 测试程序生成路径
set(TEST_EXE_PATH ${CMAKE_BINARY_DIR}/bin)

# 构建mygtest目录下的测试代码
# 由于gtest与MyTinySTL有冲突，链接时报错，因此不再使用
# add_subdirectory(${PROJECT_SOURCE_DIR}/mygtest)

# 构建singletest目录下的测试代码
add_subdirectory(${PROJECT_SOURCE_DIR}/singletest)
