#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

string x; // These strings will store teh contents of filex.txt and filey.txt
string y;

vector<vector<int>> matrix; // This is the matrix that will memo


int sub(){
	for(int i = x.length(); i >= 0; i--){
		for(int j = y.length(); j >= 0; j--){
			if(i == x.length() || j == y.length()){
				matrix[i][j] = 0;
			}else{
				char one = x.at(i);
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
	string filey = argv[2];
	string output = argv[3];

	ifstream xfile(filex); // opening files to read contents
	ifstream yfile(filey);

	xfile >> x; // set strings to their respective file's contents
	yfile >> y;


	//NOW LET'S RUN IT

	auto start = high_resolution_clock::now(); //begin timing program right before any necessary variables are initialized

	int answer;

	int iMax = x.length()+1;
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

	answer = sub();

	auto stop = high_resolution_clock::now(); // finish timing program after it gets an answer
	//^^^The same timing is used for the other programs

	auto duration = duration_cast<microseconds>(stop - start);

	ofstream out;
	out.open(output);

	if(iMax <10 && jMax < 10){ // write the matrix out if its smaller than 10x10
		for(int i = 0; i < iMax; i++){
			for(int j = 0; j < jMax; j++){
				out << matrix[i][j];
			}
			out << "\n";
		}
	}

	out << answer << "\n";
	out << duration.count();



	xfile.close();
	yfile.close();
	out.close();





}
