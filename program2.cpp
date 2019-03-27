#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

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

	int answer;

	answer = sub(0, 0);

	ofstream out;
	out.open(output);
	out << answer ;

	xfile.close();
	yfile.close();
	out.close();



}

