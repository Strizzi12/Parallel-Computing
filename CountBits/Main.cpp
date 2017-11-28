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
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>

using namespace std;

const char *fileName = "Main.cpp";
const char *fileName2 = "C:\\Users\\Andi\\Downloads\\HDP_2.6_1_docker_virtualbox_28_07_2017_15_12_53_hdp__ambari_.ova";
const char *fileName3 = "Logo22.png";
const char *fileName4 = "C:\\Users\\Andi\\Downloads\\a\\a.txt";
const char *fileName5 = "C:\\Users\\Andi\\Downloads\\a\\BincountTest.exe";

int main(int argc, char* argv[])
{
	clock_t tStart = clock();
	auto myCalculator = new MyCalculator();
	auto myController = new MyController();
	
	//const char *fileToUse = fileName2;	
	////BOOST Test
	//
	//auto fileSize = myCalculator->GetFileSize(fileToUse);
	//boost::iostreams::mapped_file_source file;
	//file.open(fileToUse, fileSize);
	//uint64_t sum1 = 0;
	//// Check if file was successfully opened
	//if (file.is_open()) {

	//	// Get pointer to the data
	//	BYTE *data = (BYTE *)file.data();

	//	// Do something with the data
	//	sum1 = myCalculator->CountBits(data, fileSize);
	//			
	//	// Remember to unmap the file
	//	file.close();
	//}
	//else {
	//	cout << "could not map the file" << endl;
	//	return 0;
	//}
	//
	//uint64_t sum0 = (uint64_t)fileSize * (uint64_t)8 - sum1;
	//cout << "0er: " << sum0 << endl;
	//cout << "1er: " << sum1 << endl;
	//cout << "Sum: " << sum0 + sum1 << endl;

	/*if (argc < 2)
	{
		MyController::PrintHelp();
		return 0;
	}
	else 
	{
		MyController::ParseInputArguments(argc, argv);
	}*/
	char *path = "C:\\Users\\Andi\\Downloads\\a";
	boost::filesystem::path targetDir(path);
	boost::filesystem::directory_iterator it(targetDir), eod;
	uint64_t sumFromPath1 = 0;
	uint64_t sumFromPath0 = 0;
	BOOST_FOREACH(boost::filesystem::path const &p, std::make_pair(it, eod))
	{
		uint64_t sum1 = 0;
		uint64_t sum0 = 0;
		if (boost::filesystem::is_regular_file(p))
		{
			string filename = p.filename().string();
			string fullPath = string(path) + "\\" + filename;
			cout << filename << endl;
			auto fileSize = myCalculator->GetFileSize(fullPath.c_str()); 
			boost::iostreams::mapped_file_source file;
			file.open(fullPath.c_str(), fileSize);
			
			// Check if file was successfully opened
			if (file.is_open()) {

				// Get pointer to the data
				BYTE *data = (BYTE *)file.data();

				// Do something with the data
				sum1 = myCalculator->CountBits(data, fileSize);

				// Remember to unmap the file
				file.close();
			}
			else {
				cout << "could not map the file" << endl;
				return 0;
			}
			sum0 = (uint64_t)fileSize * (uint64_t)8 - sum1;
			
		}
		sumFromPath1 += sum1;
		sumFromPath0 += sum0;
	}

	cout << "0er: " << sumFromPath0 << endl;
	cout << "1er: " << sumFromPath1 << endl;
	cout << "Sum: " << sumFromPath1 + sumFromPath0 << endl;

	printf("Time taken: %.6fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	myController->WaitForTermination();
	return 0;
}
