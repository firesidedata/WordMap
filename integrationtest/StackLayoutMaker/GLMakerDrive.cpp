//Driver for StackedLayout.cpp Group 7
#define NDEBUG  // link in non-debug version of freeglut.dll
#include <iostream>
#include "WordList.h"
#include "WordMap.h"
#include "WordCount.h"
#include "MapItem.h"
#include "StemmedList.h"
#include "StemMaker.h"
#include "DocList.h"
#include "FreqMaker.h"
#include "WordMapMaker.h"
#include "WordListParser.h"
#include "IRenderFactory.h"
#include "GLFactory.h"
#include "IRenderMaker.h"
#include "ICloudLayout.h"
#include "GLMaker.h"
#include "glut.h"
#include <string>

using namespace std; 



int main(int argc, char **argv) {
	//glutInit(&argc, argv);

	string inputFileName = "";
	string stopFileName = "";

	try
	{		
		inputFileName = argv[1];
		stopFileName = argv[2];

	if (argc > 3) {
		cout << "Error: Incorrect command line arguments." << endl;
		cout << "First arguement: inputfile name" << endl;
		cout << "Second argument: stopfile name" << endl;
		system("pause");
		return 0;
	}

	WordListParser* parser = new WordListParser();
	WordList* wordList = new WordList();
	string input = parser->Read(inputFileName);
	wordList = parser->wordListCreator(inputFileName);
	cout << "The WordListParser created word list below:\n";
	wordList->display();
	cout << "\n" << endl;

	WordList *stopList = new WordList();
	stopList->readFile(stopFileName);
	cout << endl << "Printing StopList:" << endl << endl;
	stopList->display();

	StemMaker* stemMaker = new StemMaker();
	stemMaker->setStopList(stopFileName);
	StemmedList* stems = stemMaker->getStems(wordList);
	cout << "\n" << endl;
	cout << endl << "Printing stemmed words and removed words that were part of stop list:" << endl << endl;
	stems->printList();
	cout << "\n" << endl;
	stems->writeToFile(inputFileName);
	


	FreqMaker* freqMaker = new FreqMaker();
	DocList* docList = freqMaker->getDocList(stems);
	docList->write(inputFileName);
	docList->sort();	


	WordMapMaker* wordMapMaker = new WordMapMaker();
	WordMap* wordMap;
	wordMap = wordMapMaker->convertFreqList(docList);
	wordMap->write(inputFileName);
	
	
	IRenderFactory* ifactory = NewRenderFactory();
	IRenderMaker* imaker = ifactory->NewRenderMaker();
	ICloudLayout* ilayout = NewLayout();
	cout << "Layout --> \n";
	ilayout->updateWordMap(wordMap);
	imaker->generateDoc(wordMap, "Awesome Layout");

	cout << "Done....!!!\n";
	system("pause");

	}
	catch (exception e)
	{
		cout << e.what();
		return 1;
	}

	return 0;
}