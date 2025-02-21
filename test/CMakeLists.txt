Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.2 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(test_srec
  test.cpp
)
target_link_libraries(test_srec PRIVATE Catch2::Catch2WithMain)
target_link_libraries(test_srec PUBLIC srec)
target_include_directories(test_srec PUBLIC
	${PROJECT_BINARY_DIR}
	${PROJECT_SOURCE_DIR}/srec
	${PROJECT_SOURCE_DIR}
)
