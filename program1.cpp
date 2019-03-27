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

// sub is the function that fills in the matrix.
// looping through each element in reverse order (start at end of vector, work your way back), it looks for similar characters, 
// and fills in the appropriate value
int sub(){
	for(int i = x.length(); i >= 0; i--){  //i and j used to loop through 2D vector
		for(int j = y.length(); j >= 0; j--){
			if(i == x.length() || j == y.length()){
				matrix[i][j] = 0;
			}else{
				char one = x.at(i); //one and two have the ith and jth character of the x and y strings
				char two = y.at(j);

				 if(one == two){
					matrix[i][j] = (matrix[i+1][j+1])+1;
				}else{
				matrix[i][j] = max(matrix[i+1][j], matrix[i][j+1]);
				}
			}
		}
	}
	return matrix[0][0];

}


int main(int argc, char *argv[]){

	string filex = argv[1]; // these are set to the files given in the program call
	string filey = argv[2]; // used to know what file to read from
	string output = argv[3];

	ifstream xfile(filex); // opening files to read contents into the fstream
	ifstream yfile(filey); // ^^

	xfile >> x; // set strings to their respective file's contents
	yfile >> y; // ^^


	//NOW LET'S RUN IT

	auto start = high_resolution_clock::now(); //begin timing program right before any necessary variables are initialized
	//^the other programs have a similar timing method
	
	int answer; // this will have the total length of the LCS

	int iMax = x.length()+1; //the length and width of the 2D array, used to allocate an appropriate amount of memory.
	int jMax = y.length()+1;

	matrix.resize(iMax);  // allocate space for matrix
	for(int i = 0; i < iMax; i++){
		matrix[i].resize(jMax);
//		for(int j = 0; j < jMax ; j++){
//			matrix[i][j] = (-1);
//		}

	}


	iMax -= 1;
	jMax -= 1;

	answer = sub(); // sub() calculates LCS and puts it into answer

	auto stop = high_resolution_clock::now(); // finish timing program after it gets an answer
	//^^^The same timing is used for the other programs

	auto duration = duration_cast<microseconds>(stop - start); // calculate the total time spent

	string lcs; // this will have the lcs once it is found
//	string temp; //this will have the character we want to add to the lcs

	int xIt=0; // x iterator
	int yIt=0; // y iterator

	while(xIt < iMax && yIt < jMax){ //trace the matrix to find the LCS
		if(x[xIt] == y[yIt]){
			lcs += x[xIt];
			xIt++;
			yIt++;
		}else{
			if(matrix[xIt+1][yIt] >= matrix[xIt][yIt+1]){
				xIt++;
			}else{
				yIt++;
			}
		}
	}


	ofstream out; // opening an output file to print into
	out.open(output);

	if(iMax <10 && jMax < 10){ // write the matrix out if its smaller than 10x10
		for(int i = 0; i < iMax; i++){  // loops through matrix and prints out the appropriate elements in order into output.txt
			for(int j = 0; j < jMax; j++){
				out << matrix[i][j];
			}
			out << "\n";
		}
	}

	out << lcs << "\n"; 
	out << duration.count();



	xfile.close(); //closing all the files I opened to read/write in
	yfile.close();
	out.close();





}
