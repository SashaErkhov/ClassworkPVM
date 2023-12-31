#include <iostream>
#include <fstream>

int main()
{
	std::fstream InFile;
	InFile.open("readme.rle", std::ios_base::in | std::ios_base::binary);
	if (!InFile.is_open())
	{
		std::cout << "Can't open readme.rle" << std::endl;
		std::system("pause");
		return 1;
	}
	std::fstream OutFile;
	OutFile.open("newreadme.txt", std::ios_base::out | std::ios_base::binary);
	if (!OutFile.is_open())
	{
		std::cout << "Can't open newreadme.txt" << std::endl;
		InFile.close();
		std::system("pause");
		return 1;
	}
	
	bool itsall = false;
	char sym;
	int size;
	char buffer;
	while (!itsall)
	{
		InFile.get(sym);
		if ((sym >> 7) == 1)
		{
			size = (sym & 0b01111111) + 1;
			for (int i = 0; i < size; ++i)
			{
				InFile.get(buffer);
				OutFile.put(buffer);
			}
			if (InFile.eof())
			{
				itsall = true;
			}
		}
		else
		{
			InFile.get(buffer);
			size = sym + 2;
			for (int i = 0; i < size; ++i)
			{
				OutFile.put(buffer);
			}
			if (InFile.eof())
			{
				itsall = true;
			}
		}
	}
	std::system("pause");
    return 0;
}

