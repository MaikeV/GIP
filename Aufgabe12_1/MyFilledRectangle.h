#pragma once
#include "MyRectangle.h"

class MyFilledRectangle : public MyRectangle {
private:

public:
	MyFilledRectangle(int x1, int y1, int x2, int y2) : MyRectangle(x1, y1, x2, y2) {}

	void draw();
};