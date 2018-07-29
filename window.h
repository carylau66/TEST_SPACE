/*
* TIME : 2018-07-16
* To Do : window ���ڿ�����ͷ�ļ�
*
*/

#ifndef __WINDOW__
#define __WINDOW__

#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>


//Screen��
class Screen {
	friend class Window_mgr;   //��������
public:
	//using pos = std::string::size_type;
	typedef std::string::size_type pos;           //���ͱ������������ͳ�Ա 
	//���캯�� 
	Screen();
	Screen(pos ht, pos wd, char c);
	//��Ա����

	char get() const;		//��ʽ����		      //��ȡ��괦���ַ� 		 
	inline char get(pos ht, pos wd) const; //��ʽ���� 
	Screen &move(pos r, pos c);					  //����֮����Ϊ���� 
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

//Window_mgr��
class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
private:
	std::vector<Screen> Screens{ Screen(24,80,' ') };
};


#endif

