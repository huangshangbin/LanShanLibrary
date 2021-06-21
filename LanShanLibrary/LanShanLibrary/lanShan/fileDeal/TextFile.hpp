#pragma once

#include <lanShan/utils/DequeUtils.hpp>
#include <lanShan/utils/StringUtils.hpp>
#include <lanShan/fileDeal/ByteStreamFile.hpp>


class TextFile
{
private:
	string m_filePath;
	deque<string> m_dataList;

public:
	TextFile(string filePath)
	{
		m_filePath = filePath;
		initDataList();
	}
	~TextFile() {}

public:
	void reWrite(deque<string>& dataList)
	{
		DequeUtils::copy(m_dataList, dataList);
	}

	void exportDataList(deque<string>& dataList)
	{
		DequeUtils::copy(dataList, m_dataList);
	}

	void push(string str)
	{
		m_dataList.push_back(str);
	}

	void set(int row, string data)
	{
		if (row >= m_dataList.size() || row < 0)
		{
			return;
		}

		m_dataList[row] = data;
	}

	string get(int row)
	{
		if (row >= m_dataList.size() || row < 0)
		{
			return "";
		}

		return m_dataList[row];
	}

	void erase(int row)
	{
		if (row < 0 || row >= m_dataList.size())
		{
			return;
		}

		auto eraseIt = m_dataList.begin();
		for (int i = 0; i < row; i++)
		{
			eraseIt++;
		}

		m_dataList.erase(eraseIt);
	}

public:
	int size()
	{
		return m_dataList.size();
	}

	void save()
	{
		string data;
		if (m_dataList.size() > 0)
		{
			data = m_dataList[0];
			for (int i = 1; i < m_dataList.size(); i++)
			{
				data = data + "\r\n" + m_dataList[i];
			}
		}

		ByteStreamFile::writeFile(m_filePath, data.c_str(), data.length());
	}

	void clear()
	{
		m_dataList.clear();
	}


private:
	void initDataList()
	{
		ifstream inFileStream(m_filePath, std::ios::binary);

		inFileStream.seekg(0, std::ios::end);
		int fileLength = inFileStream.tellg();

		if (fileLength <= 0)
		{
			return;
		}

		inFileStream.seekg(0, std::ios::beg);
		char* fileBuffer = new char[fileLength + 1];
		inFileStream.read(fileBuffer, fileLength);

		fileBuffer[fileLength] = '\0';

		string data(fileBuffer);
		if (fileLength > 0)
		{
			m_dataList = StringUtils::splitString(data, "\r\n");
		}

		delete[] fileBuffer;
	}


	//≤‚ ‘
public:
	void out()
	{
		for (auto& data : m_dataList)
		{
			cout << data << endl;
		}
	}
};

