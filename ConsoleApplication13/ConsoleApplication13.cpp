#include <iostream>
#include <fstream>

int main()
{
	std::fstream InFile;
	InFile.open("readme.txt", std::ios_base::in | std::ios_base::binary);
	if (!InFile.is_open())
	{
		std::cout << "Can't open readme.txt" << std::endl;
		std::system("pause");
		return 1;
	}
	std::fstream OutFile;
	OutFile.open("readme.rle", std::ios_base::out | std::ios_base::binary);
	if (!OutFile.is_open())
	{
		InFile.close();
		std::cout << "Can't open readme.rle" << std::endl;
		std::system("pause");
		return 1;
	}

	char sym;
	int countRepeat = 1;
	int countNotRepeat = 1;
	bool okRepeat = false;
	bool okNotRepeat = false;
	int lenBuffer = 0;
	char buffer[128];
	char bufferRepeat;
	while (!InFile.eof())
	{
		InFile.get(sym);
		if ((InFile.peek() == sym))
		{
			bufferRepeat = sym;
			okRepeat = true;
			if (countRepeat==129)
			{
				OutFile.put(countRepeat - 2);
				OutFile.put(bufferRepeat);
				countRepeat = 0;
			}
			else if ((okNotRepeat)and countNotRepeat>1)
			{
				--countNotRepeat;
				OutFile.put(0b10000000|(countNotRepeat - 1));
				OutFile.write(buffer, lenBuffer);
				lenBuffer = 0;
				okNotRepeat = false;
			}
			++countRepeat;
			countNotRepeat = 1;
		}
		else
		{
			okNotRepeat = true;
			if (countNotRepeat == 128)
			{
				OutFile.put(0b10000000 | (countNotRepeat - 1));
				OutFile.write(buffer, lenBuffer);
				lenBuffer = 0;
			}
			else if (okRepeat)
			{
				OutFile.put(countRepeat - 2);
				OutFile.put(bufferRepeat);
				okRepeat = false;
			}
			else
			{
				buffer[lenBuffer] = sym;
				++lenBuffer;
				++countNotRepeat;
			}
			countRepeat = 1;
		}
	}
	if (okNotRepeat and countNotRepeat>1)
	{
		--countNotRepeat;
		OutFile.put(0b10000000 | (countNotRepeat - 1));
		OutFile.write(buffer, lenBuffer);
		lenBuffer = 0;
	}
	else if (okRepeat)
	{
		--countRepeat;
		OutFile.put(countRepeat - 2);
		OutFile.put(bufferRepeat);
		okRepeat = false;
	}
	std::system("pause");
    return 0;
}

