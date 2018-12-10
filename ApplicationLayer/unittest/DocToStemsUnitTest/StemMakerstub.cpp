
#include "StemmedList.h"
#include "WordListParserStub.h"
#include "StemMaker.h"
#include "PorterStemmer.h"
#include "WordCount.h"

StemMaker::StemMaker()
{
}

StemMaker::~StemMaker()
{
}

bool StemMaker::setStopList(std::string stopFileName)
{
	pStopList = new WordList();
	pStopList->readFile(stopFileName);
	cout << "Setting stop list from stop file.\n";
	cout << "Actual list: ";
	pStopList->display();
	return true;
}
StemmedList StemMaker::getStems(WordList* allWords)
{
	StemmedList stemList;
	std::string tempString;
	for (int i = 0; i < allWords->getLength(); i++)
	{
		tempString = allWords->getWord(i);
		if (pStopList->searchWord(tempString) == -1)
		{
			const int s_length = tempString.length() + 1;
			char *s_char = new char[s_length];
			strcpy_s(s_char, tempString.length() + 1, tempString.c_str());
			int index = PorterStemmer::stem(s_char, 0, tempString.length() - 1);
			WordCount *wordCount = new WordCount();
			wordCount->setWord(tempString);
			wordCount->setWordCount(1);
			stemList.addWord(tempString.substr(0, index), wordCount);
		}

	}
	cout << "Adding stems to stem list\n";
	cout << "Actual stem list: ";
	stemList.printList();
	
	return stemList;
}