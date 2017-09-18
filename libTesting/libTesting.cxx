#include "../include/boostServiceFunctions.h"

int main(int argn, char* argv[]){

	string inFile = "randomText.txt";
	vector<string> strVec = GetColumnFromFile(inFile, 1);
	for (auto i=0; i<strVec.size(); i++)
		cout << i << ":\t" << strVec[i] << endl;

	return 0;
}
