#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

string x; // These strings will store the contents of filex.txt and filey.txt
string y; // ^^

vector<vector<int>> matrix; // This is the matrix that will memo

//sub() finds the LCS in a top-down, memoization fashion
// if a similarity is found between x and y, it is stored in the 2D vector matrix
// params xi and yi are used as indexes through x and y, to compare individual characters
int sub(int xi, int yi){
	if(xi == x.length() || yi == y.length()){
		return 0;
	}
	if(matrix[xi][yi] < 0){
		char one = x.at(xi); // one and two how the ith and jth emelent of x and y, respectively
		char two = y.at(yi); // ^^
		if(one == two){ //if two chars are equal, add 1 to LCS length
			matrix[xi][yi] = (1 + sub(xi+1, yi+1));
			//printf("%c", one);
		}else{ // if two chars are unequal, LCS length remains the same as for shorter x y.
			matrix[xi][yi] = max(sub(xi+1, yi), sub(xi, yi+1));
		}
	}
	return matrix[xi][yi];

}


int main(int argc, char *argv[]){

	string filex = argv[1]; //these are set to the files given in the program call
	string filey = argv[2]; //used to remember files to read/write from/into
	string output = argv[3];

	ifstream xfile(filex); //opening file to read info
	ifstream yfile(filey);

	xfile >> x; // set strings to their respective file's contents
	yfile >> y;


	//NOW LET'S RUN IT!

	auto start = high_resolution_clock::now(); //start timing the function
	//the other programs have a similar timing logic

	int answer; //will hold the LCS once it's found

	int iMax = x.length(); //iMax and jMax are the length and width of the matrix
	int jMax = y.length(); // they are the lengths of x and y


	matrix.resize(iMax);  //making sure the matrix has at iMax length
	for(int i = 0; i< iMax; i++){ // populate the matrix with -1 (means LCS has not been found yet)
		matrix[i].resize(jMax); //making sure the matrix has jMax width
		for(int j = 0; j < jMax ; j++){
			matrix[i][j] = (-1);
		}
	}


	answer = sub(0, 0); //sub starts at (0, 0) because we want to start at the start of x and y strings.

	auto stop = high_resolution_clock::now(); //stop timing function
	auto duration = duration_cast<microseconds>(stop - start); //find total elapsed time
	//printf("\n%d\n", answer);

	ofstream out;  // opening the output file to write into
	out.open(output);
	out << answer << "\n";
	out << duration.count();

	xfile.close(); //closing the files I opened to read/write from/into
	yfile.close();
	out.close();

}
