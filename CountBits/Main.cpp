// CountBytes.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
#include <fstream>
#include <iterator>
#include <iostream>
#include <bitset>
#include <stdio.h>
#include "MyConstants.h"
#include "MyCalculator.h"

using namespace std;

const char *fileName = "Naunspitze-Stpeterskoepfle-pyramidenspitze.kml";
const char *fileName2 = "C:\\Users\\Andi\\Downloads\\HDP_2.6_1_docker_virtualbox_28_07_2017_15_12_53_hdp__ambari_.ova";
const char *fileName3 = "Logo22.png";

int main(int argc, char* argv[])
{
	auto fileSize = MyCalculator::getFileSize(fileName2);
	cout << "After reading the word \" << " << fileName << " tellg() returns " << fileSize << '\n';

	// reserve capacity
	vector<BYTE> vec;
	vec.reserve(fileSize);
	ifstream in(fileName, ios::binary | ios::ate);
	in.seekg(0, ios::beg);
	//// read the data:
	vec.insert(vec.begin(),	istream_iterator<BYTE>(in), istream_iterator<BYTE>()); //VERY SLOW

		

	uint64_t sum0 = 8 * vec.size() - sum1;

	cout << sum0 << endl;
	cout << sum1 << endl;

	return 0;
}
