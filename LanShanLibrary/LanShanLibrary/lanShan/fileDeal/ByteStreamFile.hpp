#ifndef __OFByteStreamFile_h_
#define __OFByteStreamFile_h_


#include <string>
#include <fstream>

#include <iostream>


class ByteStreamFile
{
private:
	unsigned char* m_buffer;
	long m_length;


public:
	ByteStreamFile(std::string filePath)
	{
		std::ifstream inFileStream(filePath, std::ios::binary);

		inFileStream.seekg(0, std::ios::end);
		m_length = inFileStream.tellg();

		if (m_length > 0)
		{
			inFileStream.seekg(0, std::ios::beg);
			m_buffer = new unsigned char[m_length];
			memset(m_buffer, 0, m_length);

			inFileStream.read((char*)m_buffer, m_length);
		}
		else
		{
			m_buffer = nullptr;
		}

		inFileStream.close();
	}

	~ByteStreamFile()
	{
		if (m_buffer != nullptr)
		{
			delete[] m_buffer;
		}
	}

public:
	unsigned char* getBuffer()
	{
		return m_buffer;
	}

	long getLength()
	{
		return m_length;
	}

public:
	static void writeFile(std::string filePath, const char* buffer, long bufferLength)
	{
		if (buffer == nullptr)
		{
			return;
		}

		std::ofstream outFileStream(filePath, std::ios::binary);
		outFileStream.write(buffer, bufferLength);

		outFileStream.close();
	}

	static void writeFile(std::string filePath, const unsigned char* buffer, long bufferLength)
	{
		writeFile(filePath, (char*)buffer, bufferLength);
	}

private:
	ByteStreamFile(const ByteStreamFile& byteStreamFile) {}
	void operator = (const ByteStreamFile& byteStreamFile) {}
};

#endif