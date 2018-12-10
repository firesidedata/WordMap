//Group 3
//StemmedList.h
#if !defined(STEMMEDLIST_H)
#define STEMMEDLIST_H
#include <string>
#include <vector>

class FreqList;
class WordCount;


class StemmedList {
private:
	int _length;
	std::vector<FreqList> _stemlist;
public:
	StemmedList();
	~StemmedList();
	virtual bool readFromFile(std::string);
	virtual bool writeToFile(std::string);
	virtual void addWord(std::string, WordCount*);
	virtual void remove(std::string stem);
	virtual std::vector<FreqList>::iterator begin();
	virtual std::vector<FreqList>::iterator end();
	virtual FreqList& at(int index);
	virtual int getLength();
	virtual void printList();
};

#endif