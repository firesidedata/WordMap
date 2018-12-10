#if !defined(WORDMAP_H)
#define WORDMAP_H
#include <vector>
#include <string>
#include "MapItem.h"

class MapItem; // Forward declaration 

class WordMap {
private:
	static bool ascend(MapItem &, MapItem &);
	static bool descend(MapItem &, MapItem &);
	std::vector<MapItem> mapItemList;
public:
	WordMap();
	virtual MapItem* at(int position);
	virtual MapItem* getFirst();
	virtual MapItem* getLast();
	virtual void addItem(MapItem item);
	virtual void removeItem(int position);
	virtual int size();
	virtual void read(std::string inputFileName);
	virtual void write(std::string outputFileName);
	virtual void sortByFontAscending();
	virtual void sortByFontDescending();
	virtual void randomize();
};
#endif