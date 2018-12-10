#if !defined(MAPITEM_H)
#define MAPITEM_H
#include <string>

class FontSize;
//class Rectangle;
#include "Rectangle.h"

using namespace std;

class MapItem {
private:
	std::string word;
	Rectangle* rectangle;
	FontSize* fontSize;
public:
	MapItem(std::string newword, int size);
	virtual std::string getWord();
	virtual void setWord(std::string newword);
	virtual int getFontSize();
	virtual void setFontSize(int size);
	virtual int getX();
	virtual int getY();
	virtual int getHeight();
	virtual int getWidth();
	virtual void setPosition(int x, int y);
	virtual void setSize(int height, int width);
	virtual void setRectangle(int x, int y, int height, int width);
	virtual std::string asString();
	virtual void fromString(std::string mapItemString);
};

#endif