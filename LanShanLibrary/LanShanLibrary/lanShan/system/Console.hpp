#pragma once



#include <string>
#include <deque>

#include <iostream>

using namespace std;


class Console
{
public:
	static string readString()
	{
		string str;
		cin >> str;
		return move(str);
	}

	static string readLine()
	{
		string str;
		getline(cin, str);
		return move(str);
	}


public:
	template<typename T, typename ... Args>
	static void out(T data, Args ... dataList)
	{
		cout << data << " ";
		out(dataList...);
	}

	template<typename T>
	static void out(T data)
	{
		cout << data << endl;
	}


	template<class T>
	static void out(deque<T>& dataList)
	{
		for (int i = 0; i < dataList.size(); i++)
		{
			cout << dataList[i] << endl;
		}
	}

public:
	static void clear()
	{
		system("cls");
	}
};

