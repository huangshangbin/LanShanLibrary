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
	ByteStreamFile(std::string filePath);

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

//----
	ByteStreamFile(const ByteStreamFile& byteStreamFile) = delete;
	void operator = (const ByteStreamFile& byteStreamFile) = delete;
};

#endif