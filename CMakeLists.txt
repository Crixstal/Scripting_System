cmake_minimum_required(VERSION 3.16)
project("Scripting_System")

#macro
set(APP_SOURCE "${PROJECT_SOURCE_DIR}/source/Core")
set(APP_INCLUDE "${PROJECT_SOURCE_DIR}/include/Core")

set(MODULE_SOURCE "${PROJECT_SOURCE_DIR}/source/Game")
set(MODULE_INCLUDE "${PROJECT_SOURCE_DIR}/include/Game")

set(RESOURCES "${PROJECT_SOURCE_DIR}/resources")
set(EXTERNALS "${PROJECT_SOURCE_DIR}/externals")
set(HEADER "${PROJECT_SOURCE_DIR}/header")
set(LIB "${PROJECT_SOURCE_DIR}/lib")
set(PYTHON "PYTHONPATH=%PYTHONPATH%;${MODULE_SOURCE}/scripts")

#pybind11
add_subdirectory(${EXTERNALS}/pybind11)

#module
file(GLOB
	MODULE_FILES
	"${MODULE_SOURCE}/*.cpp"
	"${MODULE_INCLUDE}/*.hpp"
	"${APP_SOURCE}/Maths.cpp"
	"${APP_SOURCE}/glad.c"
)

pybind11_add_module (
	Game
	${MODULE_FILES} 
)

target_include_directories (
	Game
	PRIVATE ${MODULE_INCLUDE}
	PRIVATE ${APP_INCLUDE}
	PRIVATE "${HEADER}"
	PRIVATE "${HEADER}/glad"
	PRIVATE "${HEADER}/GLFW"
)

# app
file(GLOB
	APP_FILES
	"${APP_SOURCE}/*.c"
	"${APP_SOURCE}/*.cpp"
	"${APP_INCLUDE}/*.hpp"
	"${MODULE_SOURCE}/*.cpp"
)

add_executable (
	Core
	${APP_FILES}
)

add_dependencies(
	Core
	Game
)

target_include_directories (
	Core
	PRIVATE ${APP_INCLUDE}
	PRIVATE ${MODULE_INCLUDE}
	PRIVATE "${HEADER}"
	PRIVATE "${HEADER}/glad"
	PRIVATE "${HEADER}/GLFW"
	PRIVATE "${HEADER}/ImGui"
	PRIVATE "${HEADER}/KHR"
	PRIVATE "${HEADER}/STB"
)

set_target_properties(
	Core
	PROPERTIES VS_DEBUGGER_ENVIRONMENT
	"${PYTHON}"
)

target_link_libraries (
	Core
	PRIVATE pybind11::embed
	PRIVATE "${LIB}/glfw3.lib"
	PRIVATE "${LIB}/python3.lib"
	PRIVATE "${LIB}/python37.lib"
	PRIVATE "${LIB}/_tkinter.lib"
)

target_link_libraries (
	Game
	PRIVATE pybind11::embed
	PRIVATE "${LIB}/glfw3.lib"
	PRIVATE "${LIB}/python3.lib"
	PRIVATE "${LIB}/python37.lib"
	PRIVATE "${LIB}/_tkinter.lib"
)

set_property(
	DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	PROPERTY VS_STARTUP_PROJECT
 	Core
)
