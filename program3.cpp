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

vector<vector<int>> matrix; // This is the matrix that will memo

int sub(int xi, int yi){
	if(xi == x.length() || yi == y.length()){
		return 0;
	}
	if(matrix[xi][yi] < 0){
		char one = x.at(xi);
		char two = y.at(yi);
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

	string filex = argv[1]; //these are set to teh files given in the program call
	string filey = argv[2];
	string output = argv[3];

	ifstream xfile(filex); //openning file to read info
	ifstream yfile(filey);

	xfile >> x; // set strings to their respective file's contents
	yfile >> y;


	//NOW LET'S RUN IT!

	auto start = high_resolution_clock::now();

	int answer;

	int iMax = x.length();
	int jMax = y.length();


	matrix.resize(iMax);
	for(int i = 0; i< iMax; i++){ // populate the matrix with -1 (means LCS has not been found yet)
		matrix[i].resize(jMax);
		for(int j = 0; j < jMax ; j++){
			matrix[i][j] = (-1);
		}
	}


	answer = sub(0, 0);

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	//printf("\n%d\n", answer);

	ofstream out;
	out.open(output);
	out << answer << "\n";
	out << duration.count();

	xfile.close();
	yfile.close();
	out.close();

}
