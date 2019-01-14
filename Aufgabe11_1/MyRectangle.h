#pragma once

class MyClass
{
private:
	int x1, y1, x2, y2;

public:
	MyClass();

	int get_x1() const { return x1; }
	void set_x1(int new_x1) const { x1 = new_x1; }
	int get_y1() const { return y1; }
	int get_x2() const { return x2; }
	int get_y2() const { return y2; }


};