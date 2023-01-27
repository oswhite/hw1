#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
	ULListStr dat;
	dat.push_back("7");
	dat.push_front("8");
	dat.push_back("9");
	cout << "hi" << endl;
	cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
	// prints: 8 7 9
	cout << dat.size() << endl;  // prints 3 since there are 3 strings stored


	ULListStr sizec;
	sizec.push_back("5");
	sizec.push_back("5");
	sizec.push_back("5");
	sizec.push_back("5");
	sizec.push_back("7");
	sizec.push_back("5");
	sizec.push_back("5");
	sizec.push_back("5");

	cout << sizec.size() << endl;
	//expect 8

	cout << sizec.get(4) << endl;
	//expect 7

	ULListStr fb;
	fb.push_back("9");
	cout << fb.front() << " should be 9" << endl;
	fb.push_front("2");
	cout << fb.front() << " should be 2" << endl;

	//test pops
	fb.pop_front();
	cout << fb.front() << " " << fb.back() << " should both be 9" << endl;

	fb.push_front("6");
	fb.pop_back();
	cout << fb.back() << " " << fb.front() << " should both be 6" << endl;


}
