#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

string x; // These strings will store the contents of filex.txt and filey.txt
string y;

//sub() is a recursive function that tries to find the LCS. Compares each character in x to each character in y
// does not use memoization, so it is less efficient
// xi and yi increment through x and y, they vary depending on which character is being compared (they are indexes)

int sub(int xi, int yi){
	if(xi == x.length() || yi == y.length()){
		return 0;
	}
	char one = x.at(xi); // one and two hold the ith and jth character in x and y, respectively
	char two = y.at(yi); // ^^
	if(one == two ){ 
		return 1 + sub(xi+1, yi+1);
	}else{
		return max(sub(xi+1, yi), sub(xi, yi+1));
	}
}


int main(int argc, char *argv[]){

	string filex = argv[1]; //these are set to the files given in the program call
	string filey = argv[2]; // ^^
	string output = argv[3]; // ^^

	ifstream xfile(filex); // reading in info
	ifstream yfile(filey);

	xfile >> x; //set the file contents to their respective strings
	yfile >> y;


	//NOW LET'S RUN IT!

	auto start = high_resolution_clock::now(); //begin timing function

	int answer; //this will hold the LCS when it is found

	answer = sub(0, 0); //sub() is called at (0, 0), since we want to start searching for the LCS at the beginning on the strings

	auto stop = high_resolution_clock::now();  // stop timing
	auto duration = duration_cast<microseconds>(stop - start);  //find total elapsed time in microseconds

	ofstream out;   // opening output file to print into it
	out.open(output);
	out << answer << "\n"; // putting the answer and time into the output file
	out << duration.count();

	xfile.close(); //closing all the files I openned
	yfile.close();
	out.close();



}

