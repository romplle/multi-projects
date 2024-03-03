target_sources(comb_bubble_sort_lib 
	PRIVATE
		comb_bubble_sort.cpp
	PUBLIC
		comb_bubble_sort.hpp
)

target_include_directories(comb_bubble_sort_lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)
