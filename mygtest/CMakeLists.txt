include_directories(${MYTINYSLT_HEAD_PATH} ${THIRD_PARTY_GTEST}/include)

project(stl_test)

aux_source_directory(./ SRC)

set(EXECUTABLE_OUTPUT_PATH ${TEST_EXE_PATH})

link_directories(${THIRD_PARTY_GTEST}/lib)

link_libraries(gtest)

add_executable(${PROJECT_NAME} ${SRC})
