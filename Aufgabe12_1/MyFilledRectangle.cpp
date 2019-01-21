#include "MyFilledRectangle.h"
#include "CImgGIP05.h"

void MyFilledRectangle::draw() {
	int height = this->get_y2() - this->get_y1();

	MyRectangle::draw();

	if (height > 4) {
		for (int index = 2; index < (height - 2); index += 2) {
			int x1 = this->get_x1() + 2;
			int y1 = this->get_y1() + index;
			int x2 = this->get_x2() - 2;
			int y2 = this->get_y2() - height + index;

			gip_draw_line(x1, y1, x2, y2, red);
		}
	}
}
