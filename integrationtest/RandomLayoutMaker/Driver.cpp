//Driver for LatexMaker.cpp Group 4
#include <iostream>

#include "IRenderMaker.h"
#include "ICloudLayout.h"
#include "WordMap.h"
#include "FontSize.h"
#include "Rectangle.h"
#include "MapItem.h"
#include "LatexMaker.h"
#include "RandomLayout.h"

using namespace std;


int main()
{
	WordMap map = WordMap();
	WordMap* testMap;
	testMap = &map;
	IRenderMaker* newMaker = new LatexMaker;
	ICloudLayout* newlayout = new RandomLayout;
	string filename = "integrationCreatedFile";

	testMap->addItem(MapItem("dog", 1));
	testMap->addItem(MapItem("cat", 2));
	testMap->addItem(MapItem("giraffe", 3));
	testMap->addItem(MapItem("fish", 4));
	testMap->addItem(MapItem("lion", 5));
	testMap->addItem(MapItem("bird", 6));

	newlayout->updateWordMap(testMap);
	newMaker->generateDoc(testMap, filename);
	cout << "Created a latex file labeled unitTestFile.tex in the same directory as Driver_LatexMaker.cpp" << endl;
	system("pause");
}