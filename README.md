#vs2015控制台项目创建示例
vs2015  --> 新建项目 --> win32 控制台程序 -->空项目 

x64  Release 

添加 src/main.cpp    

-------------------------
#include <library/system/Console.hpp>

int main()
{
	Console::out("huang");

	Console::readString();

	return 0;
}
--------------------------



添加 include文件夹

属性 常规 字符集--> 多字节字符集

配置属性 c/c++ 预处理器   预处理器定义 WIN32_LEAN_AND_MEAN     _CRT_SECURE_NO_WARNINGS

配置属性 c/c++ 常规   SDL检查    否

属性 添加包含目录。 包含 include    项目根目录

复制 pull_mysql.bat    pull_library.bat  pull_bb 到 include文件夹下。 需要哪种类库复制即可。

include   src  右键 包括在项目中



