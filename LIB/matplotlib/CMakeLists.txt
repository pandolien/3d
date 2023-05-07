project()#your project name
cmake_minimum_required(VERSION 3.0.0)
find_package(python3 COMPONENTS Intrepreter Development Numpy)
include_directories(
${Python3_INCLUDE_DIRS}
)# include directory set
add_executable(
	#Project exe file name
)
target_link_libraries(
	#Project exe file name
	${Python3_LIBRARIES}
)
