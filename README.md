#vs2015����̨��Ŀ����ʾ��
vs2015  --> �½���Ŀ --> win32 ����̨���� -->����Ŀ 

x64  Release 

��� src/main.cpp    

-------------------------
#include <library/system/Console.hpp>

int main()
{
	Console::out("huang");

	Console::readString();

	return 0;
}
--------------------------



��� include�ļ���

���� ���� �ַ���--> ���ֽ��ַ���

�������� c/c++ Ԥ������   Ԥ���������� WIN32_LEAN_AND_MEAN     _CRT_SECURE_NO_WARNINGS

�������� c/c++ ����   SDL���    ��

���� ��Ӱ���Ŀ¼�� ���� include    ��Ŀ��Ŀ¼

���� pull_mysql.bat    pull_library.bat  pull_bb �� include�ļ����¡� ��Ҫ������⸴�Ƽ��ɡ�

include   src  �Ҽ� ��������Ŀ��



