#pragma once

#include <deque>
#include <iostream>

using namespace std;

class DequeUtils
{
public:
	template<class T>
	static void copy(deque<T>& targetDeque, deque<T>& srcDeque)
	{
		targetDeque.clear();
		for (T& data : srcDeque)
		{
			targetDeque.push_back(data);
		}
	}

	template<class T>
	static bool isExistData(deque<T>& dataList, T data)
	{
		for (T& itemData : dataList)
		{
			if (itemData == data)
			{
				return true;
			}
		}

		return false;
	}
};

