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
#include <thread>
#include <windows.h>
#include <string>
#include <boost/iostreams/device/mapped_file.hpp>
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>

using namespace std;

const char *fileName2 = "C:\\Users\\Andi\\Downloads\\HDP_2.6_1_docker_virtualbox_28_07_2017_15_12_53_hdp__ambari_.ova";

const char *path = "C:\\Users\\Andi\\Downloads"; //

int main(int argc, char* argv[])
{
	//Input Parsing
	/*if (argc < 2)
	{
	MyController::PrintHelp();
	return 0;
	}
	else
	{
	MyController::ParseInputArguments(argc, argv);
	}*/

	//Initialization
	MyController myController;
	MyCalculator myCalculator;
	myController.SetStartTime();

	myController.MoreInfo = true;
	myController.DepthOfRecursion = 0;

	MyResult result;
	int currentThreadCount = 0;
	int maxThreads = 8;
	//for (auto path : myController.FilePaths)
	{
		MyResult tempResult = myCalculator.CountBitsOf1ForPath(path, myController);
	}
	

	cout << "0er: " << result.SumBit0 << endl;
	cout << "1er: " << result.SumBit1 << endl;
	cout << "Sum: " << result.FileSize * 8 << " in bits" << endl;

	myController.SetStopTime();
	myController.PrintTime();
	myController.Wait();
	return 0;
}

/*
 *    // https://stackoverflow.com/questions/67273/how-do-you-iterate-through-every-file-directory-recursively-in-standard-c
{
	typedef recursive_directory_iterator iterator;
	recursive_directory_range(path p) : p_(p) {}

	iterator begin() { return recursive_directory_iterator(p_); }
	iterator end() { return recursive_directory_iterator(); }

	path p_;
};

for (auto it : recursive_directory_range(in_path)) { ... }
 */