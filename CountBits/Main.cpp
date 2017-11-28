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
#include "MyController.h"
#include <boost/iostreams/device/mapped_file.hpp>

using namespace std;

const char *fileName = "Naunspitze-Stpeterskoepfle-pyramidenspitze.kml";
const char *fileName2 = "C:\\Users\\Andi\\Downloads\\HDP_2.6_1_docker_virtualbox_28_07_2017_15_12_53_hdp__ambari_.ova";
const char *fileName3 = "Logo22.png";

int main(int argc, char* argv[])
{
	auto myCalculator = new MyCalculator();
	auto myController = new MyController();
	//BOOST Test
	boost::iostreams::mapped_file_source file;
	int numberOfElements = 1000000;
	int numberOfBytes = numberOfElements * sizeof(int);
	file.open(fileName, myCalculator->GetFileSize(fileName));

	// Check if file was successfully opened
	if (file.is_open()) {
		// Get pointer to the data
		int * data = (int *)file.data();

		// Do something with the data
		for (int i = 0; i < numberOfElements; i++)
		{
			cout << data[i] << " ";
		}
		// Remember to unmap the file
		file.close();
	}
	else {
		cout << "could not map the file filename.raw" << endl;
	}


	/*if (argc < 2)
	{
		MyController::PrintHelp();
	}
	else 
	{
		MyController::ParseInputArguments(argc, argv);
	}*/

	//auto fileSize = myCalculator->GetFileSize(fileName2);
	//cout << "After reading the word \" << " << fileName << " tellg() returns " << fileSize << '\n';

	//// reserve capacity
	//vector<BYTE> vec;
	//vec.reserve(fileSize);
	//ifstream in(fileName, ios::binary | ios::ate);
	//in.seekg(0, ios::beg);
	////// read the data:
	//vec.insert(vec.begin(),	istream_iterator<BYTE>(in), istream_iterator<BYTE>()); //VERY SLOW


	//uint64_t sum1 = myCalculator->CountBits(vec);
	//uint64_t sum0 = 8 * vec.size() - sum1;

	//cout << sum0 << endl;
	//cout << sum1 << endl;

	//myController->WaitForTermination();
	return 0;
}
