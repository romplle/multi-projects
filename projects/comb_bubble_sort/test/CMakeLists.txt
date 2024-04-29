set(SOURCES 
	test_comb_bubble.cpp
)

add_executable(test_comb_bubble ${SOURCES})
target_link_libraries(test_comb_bubble 
	gtest_main 
	gmock_main 
	comb_bubble_sort_lib
)

add_test(test_comb_bubble test_comb_bubble)
