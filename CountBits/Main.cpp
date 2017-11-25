// CountBytes.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
#include <fstream>
#include <iterator>
#include <iostream>
#include <bitset>
#include <stdio.h>

using namespace std;
typedef unsigned char BYTE;

static unsigned char cheating[] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3,
4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2,
3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4,
5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2,
3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4,
5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5,
6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3,
4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3,
4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6,
7, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4,
5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5,
6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8 };


const char *fileName = "Naunspitze-Stpeterskoepfle-pyramidenspitze.kml";
const char *fileName2 = "C:\\Users\\Andi\\Downloads\\HDP_2.6_1_docker_virtualbox_28_07_2017_15_12_53_hdp__ambari_.ova";
const char *fileName3 = "Logo22.png";

ifstream::pos_type getFileSize(const char* fileName)
{
	ifstream in(fileName, ios::binary | ios::ate);
	return in.tellg();
}

int main(int argc, char* argv[])
{
	auto fileSize = getFileSize(fileName2);
	cout << "After reading the word \" << " << fileName << " tellg() returns " << fileSize << '\n';

	// reserve capacity
	vector<BYTE> vec;
	vec.reserve(fileSize);
	ifstream in(fileName, ios::binary | ios::ate);
	in.seekg(0, ios::beg);
	//// read the data:
	vec.insert(vec.begin(),	istream_iterator<BYTE>(in), istream_iterator<BYTE>()); //VERY SLOW
	/*
	*https://stackoverflow.com/questions/3902609/how-do-i-count-the-zeros-and-ones-in-a-file
	*/
	uint64_t sum1 = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		//sum0 += 8 - cheating[vec[i]];
		sum1 += cheating[vec[i]];
		cout << "WORK WORK WORK" << endl;

		/*if(i % 10 == 0)
		{
			cout << "WORK WORK WORK" << endl;
		}*/
	}

	uint64_t sum0 = 8 * vec.size() - sum1;

	cout << sum0 << endl;
	cout << sum1 << endl;

	return 0;
}
