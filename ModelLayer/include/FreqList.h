#ifndef FREQLIST_H
#define FREQLIST_H

#include <string>
#include <vector>
#include "WordCount.h"
class FreqList
{
private:
	std::vector<WordCount> myVector;
public:
	FreqList();
	virtual void read(std::string fileName);
	virtual void write(std::string fileName);
	virtual void sortByCount();
	virtual void reduceList(double reducePercent);
	virtual void add(std::string str);
	virtual void remove();
	virtual size_t size();
	virtual WordCount& at(int i);
	virtual WordCount& first();
	virtual WordCount& last();
	~FreqList();
};

#endif