PROJECT (${WIKI}SimpleOperations)

IF(NOT WikiExamples_BINARY_DIR)
FIND_PACKAGE(VTK REQUIRED)
IF(NOT VTK_USE_RENDERING)
  MESSAGE(FATAL_ERROR "Example ${PROJECT_NAME} requires VTK_USE_RENDERING.")
ENDIF(NOT VTK_USE_RENDERING)
INCLUDE(${VTK_USE_FILE})
ENDIF(NOT WikiExamples_BINARY_DIR)

if("${VTK_MAJOR_VERSION}.${VTK_MINOR_VERSION}" LESS 5.8)
  SET(KIT_LIBS vtkRendering vtkHybrid)
else()
  SET(KIT_LIBS ${VTK_LIBRARIES})
endif()
#
# Build all .cxx files in the directory
FILE(GLOB ALL_FILES *.cxx)
foreach(SOURCE_FILE ${ALL_FILES})
  STRING(REPLACE ".cxx" "" TMP ${SOURCE_FILE})
  STRING(REPLACE ${CMAKE_CURRENT_SOURCE_DIR}/ "" EXAMPLE ${TMP})
  ADD_EXECUTABLE(${WIKI}${EXAMPLE} ${EXECUTABLE_FLAG} ${EXAMPLE}.cxx)
  TARGET_LINK_LIBRARIES(${WIKI}${EXAMPLE} ${KIT_LIBS})
endforeach(SOURCE_FILE)

if (BUILD_TESTING)

# Testing
SET(KIT SimpleOperations)

SET (EXCLUDE_TEST
  FloatingPointExceptions
)

INCLUDE(${WikiExamples_SOURCE_DIR}/CMake/ExamplesTesting.cmake)
# set_tests_properties(
#     SimpleOperations-FloatingPointExceptions
#     PROPERTIES WILL_FAIL TRUE
#     )
endif()
