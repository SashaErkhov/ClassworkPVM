//#include <iostream>
//#include <fstream>
//
//struct Node
//{
//	char data[15];
//	unsigned char link;
//	//unsigned int link : 8;
//};
//
//int main()
//{
//	std::fstream rme;
//	rme.open("readme.txt", std::ios_base::in | std::ios_base::out | std::ios_base::binary);
//	if (!rme.is_open())
//	{
//		std::cout << "Can't open readme.txt" << std::endl;
//		return 1;
//	}
//	/*char sym;
//	for (int i = 0; i < 256 * 16; ++i)
//	{
//		sym = static_cast<char>(rand());
//		rme.put(sym);
//	}*/
//	Node Nodes[256];
//	for (int i = 0; i < 256; ++i)
//	{
//		rme.read((char*)(&Nodes[i]), 16);
//	}
//	int count=0;
//	bool OKs[256];
//	for (int i = 0; i < 256; ++i)
//	{
//		OKs[i] = false;
//	}
//	for (int i = 0; i < 256; ++i)
//	{
//		if (OKs[Nodes[i].link])
//		{
//			std::cout << "count = " << count << std::endl;
//			break;
//		}
//		OKs[Nodes[i].link] = true;
//		++count;
//	}
//	rme.close();
//	system("pause");
//    return 0;
//}
//
////rme.seekg(16);
////char buffer1[16];
////for (int i = 0; i < 16; ++i)
////{
////	rme.get(buffer1[i]);
////}
////rme.seekg(16*3);
////char buffer2[16];
////for (int i = 0; i < 16; ++i)
////{
////	rme.get(buffer2[i]);
////}
////rme.seekp(16);
////for (int i = 0; i < 16; ++i)
////{
////	rme.put(buffer2[i]);
////}
////rme.seekp(16*3);
////for (int i = 0; i < 16; ++i)
////{
////	rme.put(buffer1[i]);
////}
////*char buffer[64];
////for (int i = 0; i < 64; ++i)
////{
////	rme.get(buffer[i]);
////}
////char book[4][16];
////for (int i = 0; i < 4; ++i)
////{
////	for (int j = 0; j < 16; ++j)
////	{
////		book[i][j] = buffer[i * 4 + j];
////	}
////}
////std::swap(book[1], book[3]);
////for (int i = 0; i < 4; ++i)
////{
////	for (int j = 0; j < 16; ++j)
////	{
////		buffer[i * 4 + j]= book[i][j];
////	}
////}
////
////for (int i = 0; i < 64; ++i)
////{
////	rme.put(buffer[i]);
////}*/