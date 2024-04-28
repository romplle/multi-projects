target_sources(scl_lib
	PRIVATE
		
	PUBLIC
		list_deque.hpp
		static_array_deque.hpp
		vector_deque.hpp
)

target_include_directories(scl_lib PUBLIC
	${PROJECT_SOURCE_DIR}/src/deque
)
