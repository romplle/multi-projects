target_sources(scl_lib
	PRIVATE
		
	PUBLIC
		list_stack.hpp
		static_array_stack.hpp
		vector_stack.hpp
)

target_include_directories(scl_lib PUBLIC
	${PROJECT_SOURCE_DIR}/src/stack
)
