#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <set>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	vector<string> tokens;
	set <string> unique;
	string filename = argv[1];
	string next_line;  // Each data line
	ifstream in(filename);
	while (getline(in, next_line)) {
			istringstream iss(next_line);
			string token;
			while (iss >> token) {
				string nopunct = "";
				for(auto &c : token) { // Remove Punctuation      
				if (isalpha(c)) {
					nopunct +=c;       
					}
				}
				tokens.push_back(nopunct);
				unique.insert(nopunct);
			}
	}
	cout << "Number of words "<<tokens.size()<<endl;
	cout << "Number of unique words "<<unique.size()<<endl;
	ofstream setfile(filename+"_set.txt");
	for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it) {
		cout << ' ' << *it;
		setfile << ' ' << *it;
		cout << endl;
	}
}