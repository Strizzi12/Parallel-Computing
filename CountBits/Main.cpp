// CountBytes.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "MyConstants.h"
#include "MyCalculator.h"
#include "MyController.h"
#include <string>
#include <chrono>
#include <iomanip>

using namespace std;

const char *path = "C:\\Users\\Andi\\Downloads";
const char *path2 = "C:\\Users\\Andi\\Downloads\\Neuer Ordner";
const char *path3 = "C:\\Users\\Andi\\Downloads\\Test Files";
const char *path4 = "..\\..";

int main(int argc, char* argv[])
{
	//Initialization
	MyController myController;
	MyCalculator myCalculator;

	//Input Parsing
	if (argc < 2)
	{
		myController.PrintHelp();
		return 0;
	}
	myController.ParseInputArguments(argc, argv);

	////Testing area
	//myController.MoreInfo = true;
	//myController.DepthOfRecursion = 0;
	////myController.FilePaths.push_back(path);
	//myController.FilePaths.push_back(path);
	//myController.PrintProcessTime = true;
	//myController.FileFilter.push_back("*.txt");
	//myController.FileFilter.push_back("*asdf*");

	if (myController.FilePaths.empty())
	{
		cerr << "No paths given to calculate." << endl;
		return 0;
	}

	high_resolution_clock::time_point start = high_resolution_clock::now();

	//Calculation area
	MyResult result;
	for (auto path : myController.FilePaths)
	{
		MyResult tempResult = myCalculator.CountBitsOf1ForPath(path.c_str(), myController);
		result.SumBit0 += tempResult.SumBit0;
		result.SumBit1 += tempResult.SumBit1;
		result.FileSize += tempResult.FileSize;
	}

	high_resolution_clock::time_point stop = high_resolution_clock::now();

	cout << "0er: " << result.FileSize * 8 - result.SumBit1 << endl;
	cout << "1er: " << result.SumBit1 << endl;
	cout << "Sum: " << result.FileSize * 8 << " in bits (= Filesize in Bytes " << result.FileSize << ")" << endl;

	//Workaround for printing high resolution time	
	if (myController.PrintProcessTime == true)
	{
		duration<double> time_span = duration_cast<duration<double>>(stop - start);
		cout << "Time taken (high resolution time): " << setprecision(3) << time_span.count() << "s" << endl;
	}
	myController.Wait();
	return 0;
}