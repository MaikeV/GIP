#include "MyRectangle.h"
#define CIMGGIP_MAIN
#include "CImgGIP05Mock.h"

//MyRectangle::MyRectangle(){
	//void draw();
//}

void MyRectangle::draw() {
	gip_draw_rectangle(get_x1(), get_y1(), get_x2(), get_y2(), blue);
}

bool MyRectangle::does_not_collide_with(const MyRectangle& other) {

	if (this->get_x2() < other.get_x1()) { //left edge of first rectangle before left edge of second rectangle
		return true;
	} else if (other.get_x2() < this->get_x1()) { //left edge of second rectangle before right edge of first rectangle
		return true;
	} else if (other.get_y2() < this->get_y1()) { //bottom edge of second rectangle above upper edge of first rectangle
		return true;
	} else if (this->get_y2() < other.get_y1()) { //bottom edge of first rectangle above upper edge of second rectangle
		return true;
	} else {
		return false;
	}
}
