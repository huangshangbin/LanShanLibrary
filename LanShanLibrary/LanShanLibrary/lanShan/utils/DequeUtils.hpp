#pragma once

#include <deque>
#include <iostream>



class DequeUtils
{
public:
	template<class T>
	static void copy(std::deque<T>& targetDeque, std::deque<T>& srcDeque)
	{
		targetDeque.clear();
		for (T& data : srcDeque)
		{
			targetDeque.push_back(data);
		}
	}

	template<class T>
	static bool isExistData(std::deque<T>& dataList, T data)
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

