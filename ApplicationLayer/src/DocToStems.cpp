#include <string>
#include <iostream>
#include <fstream>
#include "WordListParser.h"
#include "StemMaker.h"
#include "StemmedList.h"
#include "WordList.h"

using namespace std;

//This is only a main 
int main(int argc, char * argv[])
{
	string inputFileName="", stemFileName = "", stopFileName = "";
    //Takes command line input of input file name,
    //stop list file name, and stemmed list file name
	//Precondition: Read ascii input file
	try
	{
		inputFileName = argv[1];
		stemFileName = argv[2];
		stopFileName = argv[3];

		//Takes input file and turns it into wordList object
		WordListParser * wordLPS = new WordListParser();
		WordList * input = new WordList();
		input = wordLPS->wordListCreator(inputFileName);
		cout << "The WordListParser created the input word list below:\n";
		input->display();
		cout << "\n" << endl;

		//Takes stop file and creates wordList object
		WordList *stopList = new WordList();
		stopList->readFile(stopFileName);
		cout << endl << "Printing StopList:" << endl << endl;
		stopList->display();

		//creating stemmedlist
		StemMaker makeStems;
		makeStems.setStopList(stopFileName);
		StemmedList *stemList;
		stemList = makeStems.getStems(input);
		cout << "\n" << endl;
		cout << endl << "Printing stemmed words and removed words that were part of stop list:" << endl << endl;
		stemList->printList();
		cout << "\n" << endl;
		stemList->writeToFile(stemFileName);

		//Waiting for user to quit
		cout << endl << "Press and character and hit enter to quit." << endl;
		int p;
		cin >> p;
	}
	catch (exception e)
	{
		cout << e.what();
		return 1;
	}
	//Post: Produce a file containing stemmed list

	return 0;
}
