target_sources(scl_lib
	PRIVATE
		text.cpp
		utility.cpp
	PUBLIC
		ctext.hpp
		text.hpp
		utility.hpp
)

target_include_directories(scl_lib PUBLIC
	${PROJECT_SOURCE_DIR}/src/text
)
