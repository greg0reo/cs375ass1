#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
	string x; // this will store the contents of filex.txt
	string y; // this will store the contents of filey.txt

	string filex = argv[1]; //these are set to the files given in the program call
	string filey = argv[2];
	string output = argv[3];

	ifstream xfile(filex); // reading in info
	ifstream yfile(filey);

	xfile >> x; //set the file contents to their respective strings
	yfile >> y;


//-------------------- Recursive computing function (no memoization) ------------------

	char one; // used as temporary holders for value at x[x] and y[y]
	char two;

	int sub(int x, int y){ // this is the subproblem. Find the LCS for the smaller strings
		one = x.at(x);
		two = y.at(y);
		if(one == '\0' || two == '\0'){ // if at end of string, return 0
			return 0;
		}else{
			return max(sub(x+1, y), sub(x, y+1));
		}
	}


	//NOW LET'S RUN IT!

	int answer;

	answer = sub(0, 0);

	ofstream out;
	out.open(output);
	out << answer ;

	xfile.close();
	yfile.close();
	out.close();



}

