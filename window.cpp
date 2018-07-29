#include"window.h"


/*
* TIME : 2018-07-16
* To Do : window ���ڿ�����ʵ��
*
*/

/*
*	Window_mgr��
*	void clear(ScreenIndex i)				�����Ļ
*/
void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = Screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}

/*
*	Screen��:
*
*	char get(pos ht, pos wd)				������Ļָ��λ���ַ�
*	char get()								������Ļ��괦�ַ�
*	Screen &set(char c)						����ĳһ��Ļ��괦�ַ�
*	Screen &set(pos r, pos col, char ch)	����ĳһ��Ļָ��λ�ô��ַ�
*	Screen &display(std::ostream &os)		��ʾScreen����Ļ
*	const Screen &display(std::ostream &os)	��ʾconst Screen����Ļ
*	void do_display(std::ostream &os)		��ʾ����
*	Screen &move(pos r, pos c)				�ƶ���굽ָ��λ��
*
*/
//Screen�๹�캯��
Screen::Screen() = default;
Screen::Screen(pos ht, pos wd, char c) :height(ht), width(wd),contents(ht * wd, c) { }
//inline��Ҫinline�������ඨ�嶼��ͬһ���ļ���

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