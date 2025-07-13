# CMakeList.txt : CMake project for RayTracingWeekend, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.27)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("RayTracingWeekend")

set ( CMAKE_CXX_STANDARD 20 )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )
set ( CMAKE_CXX_COMPILER_ID "MSVC" )

add_compile_options("/W4")

set ( SOURCE_ONE_WEEKEND
    src/main.cpp
    src/color.h
    src/hittable.h
    src/hittable_list.h
    src/interval.h
    src/ray.h
    src/rtweekend.h
    src/sphere.h
    src/vec3.h)

include_directories(src)

# Add source to this project's executable.
add_executable (RayTracingWeekend ${SOURCE_ONE_WEEKEND})

# TODO: Add tests and install targets if needed.
