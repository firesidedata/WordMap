#include <string>
#include "DocList.h"
#include "FreqList.h"
#include "WordCount.h"
#include <iostream>

using namespace std;

DocList::DocList()
{
}

//DocList holds a filename and a FreqList
DocList::DocList(string filename, FreqList *frL)
{
    this->filename = filename;
    this->fl=frL;
}

DocList::~DocList()
{
}

//Read a FreqList out of a file
void DocList::read(string fileName)
{
	fl->read(fileName);
}

//Writes a FreqList to a file
void DocList::write(string fileName)
{
	fl->write(fileName);
}

//Getter for Frequency List
FreqList DocList::getFreqList()
{
	cout << "Getting freq list" << &fl << "\n";
	return *fl;
}

//Setter for Frequency List
void DocList::setFreqList(FreqList *frL)
{
	cout << "setting freq list" << &frL << "\n";
    this->fl = frL;
	
}

//Getter for File Name
string DocList::getFileName()
{
	//cout << this->filename << "\n";
	return this->filename;
}

//Setter for File Name
void DocList::setFileName(string filename)
{
    this->filename = filename;
	cout << this->filename << "\n";
}

//basic methods for manipulating DocList/FreqList
void DocList::addToList(std::string s){
	fl->add(s);
}

void DocList::removeFromList(){
	fl->remove();
}

WordCount DocList::firstOfList(){
	return fl->first();
}

WordCount DocList::lastOfList(){
	return fl->last();
}

size_t DocList::sizeOfList()
{
	return fl->size();
}

WordCount DocList::atListPosition(int i)
{
	return fl->at(i);
}

void DocList::sort()
{
	fl->sortByCount();
}
