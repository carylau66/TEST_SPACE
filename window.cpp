#include"window.h"


/*
* TIME : 2018-07-16
* To Do : window 窗口控制类实现
*
*/

/*
*	Window_mgr类
*	void clear(ScreenIndex i)				清空屏幕
*/
void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = Screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}

/*
*	Screen类:
*
*	char get(pos ht, pos wd)				返回屏幕指定位置字符
*	char get()								返回屏幕光标处字符
*	Screen &set(char c)						设置某一屏幕光标处字符
*	Screen &set(pos r, pos col, char ch)	设置某一屏幕指定位置处字符
*	Screen &display(std::ostream &os)		显示Screen到屏幕
*	const Screen &display(std::ostream &os)	显示const Screen到屏幕
*	void do_display(std::ostream &os)		显示内容
*	Screen &move(pos r, pos c)				移动光标到指定位置
*
*/
//Screen类构造函数
Screen::Screen() = default;
Screen::Screen(pos ht, pos wd, char c) :height(ht), width(wd),contents(ht * wd, c) { }
//inline需要inline函数和类定义都在同一个文件中

char Screen::get(pos ht, pos wd) const
{
	pos row = ht * width;
	return contents[row + wd];
}

char Screen::get() const
{
	return contents[cursor];
}

Screen &Screen::set(char c) 
{
	contents[cursor] = c;
	return *this;
}

Screen &Screen::set(pos r, pos col, char ch) 
{
	pos row = r * width;
	contents[row + col] = ch;
	return *this;
}

Screen &Screen::display(std::ostream &os) 
{
	do_display(os);
	return *this;
}

const Screen &Screen::display(std::ostream &os) const 
{
	do_display(os);
	return *this;
}

void Screen::do_display(std::ostream &os) const
{
	os << contents;
}

Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}