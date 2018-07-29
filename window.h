/*
* TIME : 2018-07-16
* To Do : window 窗口控制类头文件
*
*/

#ifndef __WINDOW__
#define __WINDOW__

#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>


//Screen类
class Screen {
	friend class Window_mgr;   //清屏函数
public:
	//using pos = std::string::size_type;
	typedef std::string::size_type pos;           //类型别名，类内类型成员 
	//构造函数 
	Screen();
	Screen(pos ht, pos wd, char c);
	//成员函数

	char get() const;		//隐式内联		      //读取光标处的字符 		 
	inline char get(pos ht, pos wd) const; //显式内联 
	Screen &move(pos r, pos c);					  //能在之后被设为内联 
	Screen &set(char);
	Screen &set(pos r, pos, char);
	Screen &display(std::ostream &os);            //
	const Screen &display(std::ostream &os) const;// { do_display(os); return *this; }
private:
	//public:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents = "";
	void do_display(std::ostream &os) const;

};

//Window_mgr类
class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
private:
	std::vector<Screen> Screens{ Screen(24,80,' ') };
};


#endif

