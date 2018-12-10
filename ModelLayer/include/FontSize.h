#if !defined(FONTSIZE_H)
#define FONTSIZE_H

class FontSize {
private:
	int fontSize=0;
	static const int smallest;
	static const int largest;
public:
	FontSize(int);
	virtual int getFontSize();
	virtual void setFontSize(int fSize);
	static int getSmallest();
	static int getLargest();
};

#endif