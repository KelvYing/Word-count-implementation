#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct Total{//struct to help with returning total numbers of char,words,lines
	int totalchar;
	int totalwords;
	int totallines;
};

Total count(istream& in, string name, Total tmp){
	int cha = 0;
	int word = 0;
	int line = 0;
	string v, tmpString;
	while(getline(in,v)){//while function to count each line
		cha = cha + v.length();
		line ++;
		cha ++;
		stringstream countWords(v);
		while(countWords >> tmpString){
			word ++;
		}
	}
	Total tmp1 = tmp;
	tmp1.totalchar += cha;
	tmp1.totalwords += word;
	tmp1.totallines += line;
	if(name == "no"){
		cout << line << " " << word << " " << cha << endl;
		return tmp1;
	}else{

		cout << line << " " << word << " " << cha << " " << name << endl;
		return tmp1;
	}
}


int main(int argc, char **argv){
	Total result {0,0,0};
	if(argc == 1){				//Case for no args
		count(cin,"no",result);
	}else if(argc == 2){                   //When there is one args, we will check if its - or just one file
		string tmp = argv[1];
		if(tmp == "-"){
			count(cin,"-",result);
		}else{
			ifstream file{argv[1]};
			count(file,argv[1],result);
		}
	}else{                                // two or more files, just loop through them. We will also have to put a total section
		for(int i = 1; i < argc; i ++){
			ifstream file{argv[i]};
			result = count(file,argv[i],result);
		}
			cout << result.totallines << " " << result.totalwords << " " << result.totalchar << " total" << endl;
	}
}

