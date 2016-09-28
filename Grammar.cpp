#include "Grammar.h"

#include <iostream>
#include <fstream>
#include <time.h>


using namespace std;


#include <sstream>

void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

Grammar::Grammar() {

}

Grammar::Grammar(string fileName) {
  srand(time(NULL));
	cout << fileName << " is now the name of the file" << endl;
	this->fileName = fileName;
	Grammar::readFile();
}

void Grammar::readFile() {

	ifstream file(this->fileName);
	if(file) {

		string line;
		int currentLine = 0;
		int partBegin;
		string currentDiam;
		bool isAxiome = true;

		while(getline(file, line)) {
			currentLine++;
			//cout << "line " << currentLine << " ";
			if(line.find("{") != string::npos) {
				partBegin = currentLine;
			}
			if(line.find("{") == string::npos && line.find("}") == string::npos) {
				if(currentLine == partBegin+1) {
					currentDiam = line;
					productions.insert(
						pair<string, vector<string> >(currentDiam, {})
					);
				}else{
					if(isAxiome) {
						this->axiome = split(line.substr(0, line.length() -1), ' ');
						isAxiome = false;
					}else{
						productions[currentDiam].push_back( line.substr(0, line.length() -1) );
            // std::cout << line.substr(0, line.length() -1) << std::endl;
					}
				}
			}
			//cout << endl;
		}
		//cout << productions["<Phrase>"].size() << endl;
	}else{
		cout << "error while trying to open the file" << endl;
	}
}


 map<string, vector<string> > Grammar::getProductions() {
	return this->productions;
}

string Grammar::getProduction(string nonTerminal) {
  int rd;
  rd = rand() %  Grammar::getProductions()[nonTerminal].size();
  std::cout << "size = " << Grammar::getProductions()[nonTerminal].size() << std::endl;
  std::cout << "rd = " << rd << std::endl;
  return Grammar::getProductions()[nonTerminal][rd];
}
