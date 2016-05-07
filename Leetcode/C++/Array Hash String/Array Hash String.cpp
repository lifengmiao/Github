// Array Hash String.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include "stdafx.h"
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;



/*
int main()
{
	vector<int> nums{ 1, 1, 6 };
	int a = sqrt(15);
	//int val = -3;
	//string a = to_string(val);
	//char b = val + '0';
	//int ii = stoi(a);
	//printf("%c",b);
	char *str = "2147483648";
	Solution sol;
	int res = sol.selfatoi(str);
	//int a = 6 & 2;
	//bool res = sol.wordPattern;
	//bool res = hasduplicate(12300001);

	//char *word[6] = { {"abcw"}, {"baz"}, {"foo"}, {"bar"}, {"xtfn"}, {"abcdef"} };
	//int nums[4] = { 0,0,1,2 };
	//int a;
	//int * returnSize = &a;
	//int * res = singleNumber(nums, 4, returnSize);
    return 0;
}
*/

char *GetErrorString(int x, char* errorString)  //add parameter errorString passed from caller
{
	//char errorString[20]; //can't return local char array; use char pointer passed from caller

	switch (x)
	{
	case 0:
		errorString = "Success -- No error.";
		break;
	case 2:
		errorString = "Overflow!";
		break;
	default: //add default case to reduce the chance of bugs
		errorString = "Undefined error.";
		break;
	}

	//errorString[19] = 0;  //don't need
	return errorString;
}

void main(void)
{
	int err = 2;  //please make sure all the error codes returned by DoSomething will be hanlded by GetErrorString, such as error code = 1
	//char *errorString = NULL;  //caller declare errorString and passes it to the function; originally, function GetErrorString returns a local char array, this is not allowed
	//char errorString[25]; //not assignable
	if (err) //call GetErrorString only if the value err is not 0, so case 0 in GetErrorString will never be called, please check if this case is still required
	{
		errorString = GetErrorString(err, errorString);
		printf("%s\n", errorString);
	}

}

