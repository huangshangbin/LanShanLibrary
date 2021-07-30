#include<lanShan/system/Console.hpp>
#include<lanShan/fileDeal/TextFile.hpp>

class  A
{
private: 
	int m_a;


public:
	A()
	{
		m_a = 0;
	}

	const int& getA() const { return m_a; }

	void out()
	{
		Console::out("m_a = ", m_a);
	}
};

int main()
{
	A a;
	int& copyA = a.getA();

	Console::out(copyA);

	copyA = copyA + 1;

	a.out();

	Console::out("name", " huang, age ", 18);
	Console::readString();

	return 0;
}