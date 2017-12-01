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
#include <string>
#include <boost/iostreams/device/mapped_file.hpp>
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>

using namespace std;

const char *fileName2 = "C:\\Users\\Andi\\Downloads\\HDP_2.6_1_docker_virtualbox_28_07_2017_15_12_53_hdp__ambari_.ova";

const char *path = "C:\\Users"; //\\Andi\\Downloads

int main(int argc, char* argv[])
{
	clock_t tStart = clock();
	
	MyController myController;
	MyCalculator myCalculator;

	myController.depthOfRecursion = 0;

	/*if (argc < 2)
	{
		MyController::PrintHelp();
		return 0;
	}
	else
	{
		MyController::ParseInputArguments(argc, argv);
	}*/		

	MyResult result = myCalculator.CountBitsOf1ForPath(path, myController);

	cout << "0er: " << result.SumBit0 << endl;
	cout << "1er: " << result.SumBit1 << endl;
	cout << "Sum: " << result.FileSize << endl;

	printf("Time taken: %.6fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	myController.WaitForTermination();
	return 0;
}
