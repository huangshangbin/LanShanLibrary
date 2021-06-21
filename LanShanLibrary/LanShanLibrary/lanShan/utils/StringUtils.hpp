#pragma once

#include <deque>
#include <string>
#include <algorithm>
#include <windows.h>

#include <iostream>
using namespace std;


class StringUtils
{
public:
	static deque<string> splitString(string srcStr, string splitStr)
	{
		deque<string> dataList;
		if (srcStr.length() == 0)
		{
			return std::move(dataList);
		}

		string str = srcStr;

		string::size_type pos1, pos2;
		pos2 = str.find(splitStr);
		pos1 = 0;
		while (string::npos != pos2)
		{
			dataList.push_back(str.substr(pos1, pos2 - pos1));

			pos1 = pos2 + splitStr.size();
			pos2 = str.find(splitStr, pos1);
		}
		dataList.push_back(str.substr(pos1));

		return std::move(dataList);
	}

	static string splitStringGetOneStr(string srcStr, string splitStr, int index)
	{
		deque<string> strList = splitString(srcStr, splitStr);
		if (index >= strList.size() || index < 0)
		{
			return "";
		}

		return strList[index];
	}

	static string replaceString(string srcStr, string replaceStr, string targetStr)
	{
		for (string::size_type pos(0); pos != string::npos; pos += targetStr.length())
		{
			if ((pos = srcStr.find(replaceStr, pos)) != string::npos)
			{
				srcStr.replace(pos, replaceStr.length(), targetStr);
			}
			else { break; }
		}
		return   srcStr;
	}

	static bool isExistStringInString(string srcStr, string existStr)
	{
		deque<string> srcStrList = splitString(srcStr, existStr);
		if (srcStrList.size() < 2)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	static bool isEqualString(string srcStr1, string srcStr2)
	{
		if (srcStr1 == srcStr2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	static bool isIncludeChinese(string str)
	{
		char c;
		for (int i = 0; i < str.length(); i++)
		{
			c = str[i];
			if (c == 0) break;
			if (c & 0x80)
				if (str[i + 1] & 0x80) return true;
		}
		return false;
	}

	static bool isUseStringEnd(string srcStr, string endStr)
	{
		string compareCS = getStringUsePos(srcStr, srcStr.length() - endStr.length(), srcStr.length());

		return StringUtils::isEqualString(compareCS, endStr);
	}

	static string getStringUsePos(string src, int startPos, int endPos)
	{
		return src.substr(startPos, endPos - startPos + 1);
	}

	static string getStringUseCharStart(string src, char startChar)
	{
		int index = -1;
		for (int i = 0; i < src.length(); i++)
		{
			if (src[i] == startChar)
			{
				index = i;
				break;
			}
		}
		if (index == -1)
		{
			return "";
		}

		return getStringUsePos(src, index + 1, src.length());
	}

	static string getStringUseCharEnd(string src, char endChar)
	{
		int index = -1;
		for (int i = 0; i < src.length(); i++)
		{
			if (src[i] == endChar)
			{
				index = i;
				break;
			}
		}
		if (index == -1)
		{
			return src;
		}

		return getStringUsePos(src, 0, index - 1);
	}

	static string getStringUseStringEnd(string src, string endStr)
	{
		return splitStringGetOneStr(src, endStr, 0);
	}

	static string getStringDeleteStartNone(string srcStr)
	{
		int index;
		for (int i = 0; i < srcStr.length(); i++)
		{
			if (srcStr[i] != ' ')
			{
				index = i;
				break;
			}
		}

		return getStringUsePos(srcStr, index, srcStr.length());
	}

	static string getStringDeleteEndNone(string srcStr)
	{
		int index;
		for (int i = srcStr.size() - 1; i > 0; i--)
		{
			index = i;
			if (srcStr[i] != ' ')
			{
				break;
			}
		}

		return getStringUsePos(srcStr, 0, index);
	}

	static string getLowerCaseString(string srcStr)
	{
		string resultStr;
		resultStr.resize(srcStr.size());
		transform(srcStr.begin(), srcStr.end(), resultStr.begin(), ::tolower);

		return resultStr;
	}

	static string getUpperString(string srcStr)
	{
		string resultStr;
		resultStr.resize(srcStr.size());
		transform(srcStr.begin(), srcStr.end(), resultStr.begin(), ::toupper);

		return resultStr;
	}

	static void addChar(string& srcStr, char ch)
	{
		string tempStr(1, ch);

		srcStr = srcStr + tempStr;
	}

	static string deleteChar(string srcStr, char ch)
	{
		char* newCharArray = new char[srcStr.length()];
		int newCharArrayIndex = 0;
		for (int i = 0; i < srcStr.length(); i++)
		{
			if (srcStr[i] != ch)
			{
				newCharArray[newCharArrayIndex] = srcStr[i];
				newCharArrayIndex++;
			}
		}

		newCharArray[newCharArrayIndex] = '\0';

		string result = newCharArray;

		delete newCharArray;

		return result;
	}

	static string getUtf8UseGbk(string content)
	{
		string strGBK = content;

		int len = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, NULL, 0);
		unsigned short* wszUtf8 = new unsigned short[len + 1];
		memset(wszUtf8, 0, len * 2 + 2);
		MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, (LPWSTR)wszUtf8, len);

		len = WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)wszUtf8, -1, NULL, 0, NULL, NULL);
		char* szUtf8 = new char[len + 1];
		memset(szUtf8, 0, len + 1);
		WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)wszUtf8, -1, szUtf8, len, NULL, NULL);

		content = szUtf8;

		delete[] szUtf8;
		delete[] wszUtf8;

		return content;
	}

	static string getGbkUserUtf8(string content)
	{
		unsigned short* wszGBK;
		char* szGBK;

		int len = MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)content.c_str(), -1, NULL, 0);
		wszGBK = new unsigned short[len + 1];
		memset(wszGBK, 0, len * 2 + 2);

		MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)content.c_str(), -1, (LPWSTR)wszGBK, len);

		len = WideCharToMultiByte(CP_ACP, 0, (LPWSTR)wszGBK, -1, NULL, 0, NULL, NULL);
		szGBK = new char[len + 1];
		memset(szGBK, 0, len + 1);
		WideCharToMultiByte(CP_ACP, 0, (LPWSTR)wszGBK, -1, szGBK, len, NULL, NULL);

		content = szGBK;

		delete[] szGBK;
		delete[] wszGBK;

		return content;
	}
};

