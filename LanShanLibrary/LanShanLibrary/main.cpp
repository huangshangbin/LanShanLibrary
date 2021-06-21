#include<lanShan/system/Console.hpp>
#include<lanShan/fileDeal/TextFile.hpp>

int main()
{
	TextFile testFile("D:\\debug\\log\\test.txt");
	testFile.push("huang");
	testFile.save();

	Console::out("name", " huang, age ", 18);
	Console::readString();

	return 0;
}