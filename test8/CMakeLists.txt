cmake_minimum_required(VERSION 3.16) #cmake版本至少是3.16

project(robot_demo LANGUAGES CXX) #名称是robot_demo 使用的语言是c++

add_executable(robot
    main.cpp
    robot.cpp
)#我要生成一个名为 robot 的可执行程序，这个程序由 main.cpp 和 robot.cpp 组成。

target_compile_features(robot PRIVATE cxx_std_17) 
#robot 这个目标至少需要 C++17   target就是cmake要管理的目标

if(MSVC)#微软编译器
    target_compile_options(robot PRIVATE /W4) #微软编译器的警告参数
else()
    target_compile_options(robot PRIVATE -Wall -Wextra) #g++的警告参数
endif()




#[[
在正式项目里面，hpp和cpp不在同一个文件夹的情况下，只这样写cmake的话，cmake有可能找不到hpp在哪里
所以说cmake里面就要写
target_include_directories(robot
    PRIVATE
    include
)
意思就是给robot 这个 target 增加一个头文件搜索目录：include
这时候编译器就知道除了默认位置还要去include这个文件下去找

如果用了某个外部的库 #include <some_library.hpp>
只是找到头文件还不行，头文件只是告诉编译器有这些函数和类，但是真正实现不在头文件里面
所以最后链接的时候要告诉链接器把这个库也要接进来
cmake就写
target_link_libraries(robot
    PRIVATE
    some_library
)


find_package(rclcpp REQUIRED)
意思是 cmake帮我找到这个叫rclcpp的包，而且这个包是必须的
rclcpp是包名  required就是必须的，如果找不到这个包就直接报错
这个不是去下载这个包，是在环境里面去寻找已经存在的第三方包

ament_target_dependencies(my_node xxx)
意思是把 xxx 这个依赖真正接到 my_node 上

find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

ament_target_dependencies(
    controller_node
    rclcpp
    geometry_msgs
)
直接读成 controller_node 需要 rclcpp 和 geometry_msgs这两个包

install(
    TARGETS scan_node
    DESTINATION lib/${PROJECT_NAME}
)
install()就是告诉系统，生成出来的目标编译完成之后应该放到安装目录的哪里
TARGETS scan_node 就是安装scan_node这个target
DESTINATION lib/${PROJECT_NAME} 就是把它放到当前包对应的包名下面
假设project(my_robot)  那么PROJECT_NAME 就是my_robot
所以DESTINATION lib/${PROJECT_NAME} 就是 DESTINATION lib/my_robot
但是由于系统会自动识别PROJECT_NAME的值，就不需要手动更改成my_robot了
所以使用变量的好处就是不用随手改包名

ament_package()这个一般放在ros2的cmakelist.txt最后
大概意思就是告诉ament：这个 ROS 2 包的 CMake 配置到这里结束，并完成包相关的导出/注册工作。
就是这个ros2包的收尾
]]


