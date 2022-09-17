# CMakeList.txt: simple_uefi 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 指定C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置编译器选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4 /WX")

# 将源码文件路径添加到项目
file(GLOB_RECURSE sourcefiles "src/*.cpp")

# 将头文件路径添加到项目
include_directories("./inc" "./inc/efi")

# 将源代码添加到此项目的可执行文件。
add_executable (simple_uefi ${sourcefiles})

# 设置链接器参数
target_link_options(simple_uefi PUBLIC
	"/NODEFAULTLIB"
	"/ENTRY:EfiMain"
	"/SUBSYSTEM:EFI_APPLICATION"
	"/MANIFESTUAC:NO"
	"/DYNAMICBASE:NO"
	"/NXCOMPAT:NO"
	)

# 设置编译的文件的后缀
set(CMAKE_EXECUTABLE_SUFFIX ".efi")



# TODO: 如有需要，请添加测试并安装目标。
