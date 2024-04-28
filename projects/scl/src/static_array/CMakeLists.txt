target_sources(scl_lib
	PRIVATE
		static_array.cpp
	PUBLIC
		static_array.hpp
)

target_include_directories(scl_lib PUBLIC
	${PROJECT_SOURCE_DIR}/src/static_array
)
