#include "ColumnLayout.h"
#include "WordMapMaker.h"
#include "DocList.h"
#include "FreqList.h"
#include "WordCount.h"
#include "WordMap.h"
#include "MapItem.h"
#include "Rectangle.h"
#include "FontSize.h"
//#include "LatexFactory.h"
#include "IRenderFactory.h"
#include "latexutil.h"
#include "LatexMaker.h"

#include <iostream>

int main()
{ 
	DocList* doclist = new DocList("page.txt", new FreqList());
	WordMapMaker* mapmaker = new WordMapMaker();
	WordMap* map = new WordMap();
	doclist->read(doclist->getFileName());
	doclist->getFreqList().write("output.txt");
	map=mapmaker->convertFreqList(doclist);
    ICloudLayout* layout = NewLayout();
	LatexMaker* maker = new LatexMaker();
	layout->updateWordMap(map);
	cout << "created file maker.tex"<<endl;
	cout << "testing all mapitems in the map" << endl;
	maker->generateDoc(map, "maker");
	for (int i = 0; i < map->size(); i++)
	{
		cout << i << ". width= " << map->at(i)->getWidth() << "\t";
		cout << " height= " << map->at(i)->getHeight() << "\t";
		cout << " x= " << map->at(i)->getX() << "\t";
		cout << " y= " << map->at(i)->getY() << "\t" << endl << endl;
	}
	system("pause");
}