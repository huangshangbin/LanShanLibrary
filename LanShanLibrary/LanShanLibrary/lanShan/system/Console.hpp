#ifndef __OFConsole_h_
#define __OFConsole_h_



#include <string>
#include <deque>

#include <iostream>




class Console
{
public:
	static std::string readString()
	{
		std::string str;
		std::cin >> str;
		return move(str);
	}

	static std::string readLine()
	{
		std::string str;
		getline(std::cin, str);
		return move(str);
	}


public:
	template<typename T, typename ... Args>
	static void out(T data, Args ... dataList)
	{
		std::cout << data << " ";
		out(dataList...);
	}

	template<typename T>
	static void out(T data)
	{
		std::cout << data << std::endl;
	}


	template<class T>
	static void out(std::deque<T>& dataList)
	{
		for (int i = 0; i < dataList.size(); i++)
		{
			std::cout << dataList[i] << std::endl;
		}
	}

public:
	static void clear()
	{
		system("cls");
	}
};

#endif