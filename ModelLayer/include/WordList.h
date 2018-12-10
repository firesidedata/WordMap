#ifndef WORDLIST_H  
#define WORDLIST_H
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm> 
#include <sstream>
using namespace std;

struct Node {
	std::string word;
	Node* next;
};
class WordList {

public:
	WordList();
	~WordList();
	virtual void readFile(std::string filename);
	virtual void writeFile(std::string filename);
	virtual void addWord(std::string s);
	virtual void display();
	virtual void removeWord(int i);
	virtual std::string getWord(int i);
	virtual int getLength();
	virtual int searchWord(std::string s);
private:
	int length = 0;
	Node* head = NULL;
	Node* tail = NULL;
	



};

#endif