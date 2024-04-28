target_sources(scl_lib 
	PRIVATE
		logger.cpp
	PUBLIC
		logger.hpp
)

target_include_directories(scl_lib PUBLIC
	${PROJECT_SOURCE_DIR}/src/logger
)
