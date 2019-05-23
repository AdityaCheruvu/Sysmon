# Sysmon

To compile the project, first the godot game engine must be built from the source on this fork on my github: https://github.com/AdityaCheruvu/godot

The obtained godot binary can be used to open the godot project in the sysmon directory on this repository.

To build the project for different platforms, please follow these guides: https://docs.godotengine.org/ko/latest/development/cpp/custom_modules_in_cpp.html 
http://docs.godotengine.org/en/3.0/development/compiling/index.html

This is an application which monitors computer’s CPU usage and Memory usage dynamically. The code for CPU and memory status retrieval is written in C++ and used Godot game engine for GUI. Also, it is compatible with any unix based OS.

This system monitoring application presents the individual cpu usage, average cpu usage information, memory usage and swap usage. Also, the application identifies number of cores, and presents a meter for each core, thus allowing it to be used on different systems. This data is calculated from the information in the following unix files:
i. /proc/stat – for CPU info.
ii. /proc/meminfo – for Memory info.

The CPU usage is calculated for a period of ‘one sec’ using difference in CPU jiffies used.

