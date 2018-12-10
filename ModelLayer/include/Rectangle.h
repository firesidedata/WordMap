#if !defined(RECTANGLE_H)
#define RECTANGLE_H

class Rectangle {
private:
	int x;
	int y;
	int height;
	int width;
public:
	Rectangle();
	Rectangle(int x, int y, int height, int width);
	virtual int getX();
	virtual int getY();
	virtual int getHeight();
	virtual int getWidth();
	virtual void setX(int);
	virtual void setY(int);
	virtual void setHeight(int);
	virtual void setWidth(int);
};

#endif