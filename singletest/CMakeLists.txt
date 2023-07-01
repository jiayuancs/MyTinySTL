# include_directories(${MYTINYSLT_HEAD_PATH} ${THIRD_PARTY_GTEST}/include)

project(stl_test)

# 要编译的源文件
set(SRC memory_test.cpp)

set(EXECUTABLE_OUTPUT_PATH ${TEST_EXE_PATH})

add_executable(${PROJECT_NAME} ${SRC})
