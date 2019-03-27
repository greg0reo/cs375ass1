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

int sub(int xi, int yi){
	if(xi == x.length() || yi == y.length()){
		return 0;
	}
	char one = x.at(xi);
	char two = y.at(yi);
	if(one == two ){
		return 1 + sub(xi+1, yi+1);
	}else{
		return max(sub(xi+1, yi), sub(xi, yi+1));
	}
}


int main(int argc, char *argv[]){

	string filex = argv[1]; //these are set to the files given in the program call
	string filey = argv[2];
	string output = argv[3];

	ifstream xfile(filex); // reading in info
	ifstream yfile(filey);

	xfile >> x; //set the file contents to their respective strings
	yfile >> y;


	//NOW LET'S RUN IT!

	auto start = high_resolution_clock::now(); //begin timing function

	int answer;

	answer = sub(0, 0);

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	ofstream out;
	out.open(output);
	out << answer << "\n";
	out << duration.count();

	xfile.close();
	yfile.close();
	out.close();



}

