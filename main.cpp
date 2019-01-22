#include <iostream>
#include <algorithm>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;
struct Score
{
	float Chinese;
	float Math;
	float English;
	float Sum;
};
struct Student1
{
	string name;
	int  number;
	Score score;
};
struct Class
{
	Student1 student[200];
	int mark;
	string Demo;
};
void give(Student1 &one,Student1 &two)
{
	one.name=two.name;
	one.number=two.number;
	one.score.Chinese=two.score.Chinese;
	one.score.English=two.score.English;
	one.score.Math=two.score.Math;
	one.score.Sum=two.score.Sum;
};
Class c;
int book()
{
	cout << "注意：" << endl;
	cout << "输入数字时，务必小心，否则会使程序崩溃！" << endl;
	system("pause");
	system("cls");
	return 0;
}
int add()
{
	for(int i=0;i<200;i++)
	{
		c.student[i].name="00";
		c.student[i].number=0;
		c.student[i].score.Chinese=0;
		c.student[i].score.English=0;
		c.student[i].score.Math=0;
		c.student[i].score.Sum=0;
	}
	string str,str1;
	int num,num1,num2;
	cout << "请输入考试名称：";
	cin >> c.Demo;
	cout << "请输入学生总数:";
	cin >> num;
	cout << "接下来，请依次输入学生的名字，学号，语文成绩，数学成绩，英语成绩:" << endl;
	for(int i=1;i<=num;i++)
	{
		cout << i << ":"; 
		cin >> c.student[c.mark].name 
			>> c.student[c.mark].number 
			>> c.student[c.mark].score.Chinese 
			>> c.student[c.mark].score.Math
			>> c.student[c.mark].score.English;
		int p1=c.student[c.mark].score.Chinese,p2=c.student[c.mark].score.Math,p3=c.student[c.mark].score.English;
		c.student[c.mark].score.Sum=(p1+p2+p3);
		c.mark++;
	}
	cout << "添加成功！" << endl;
	system("pause");
	system("cls");
	cout << "数据分析中：" << endl;
	for(int i=0;i<c.mark;i++)
	{
		cout << i << " ";
		for(int j=0;j<i;j++)
		{
			if(c.student[i].score.Sum>c.student[j].score.Sum)
			{
				Student1 l;
				give(l,c.student[i]);
				give(c.student[i],c.student[j]);
				give(c.student[j],l);
			}
		}
	}
	cout << "\n排序完毕！" << endl;
	cout << "分析完毕！" << endl;
	system("pause");
	system("cls");
	return 0;
}
int look()
{
	system("cls");
	for(int i=0;i<c.mark;i++)
	{
		cout << "第" << i+1 << "名" 
			 << c.student[i].name << c.student[i].number << ":" 
			 << " 语文：" << c.student[i].score.Chinese 
			 << " 数学：" << c.student[i].score.Math 
			 << " 英语" << c.student[i].score.English 
			 << " 总分" << c.student[i].score.Sum 
			 << endl; 
	}
	system("pause");
	system("cls");
}
int analyze()
{
	system("cls");//前方高能，代码奇绝 
	double n=0.00;
	for(int i=0;i<c.mark;i++)
		n+=c.student[i].score.Chinese;
	cout << "语文平均分：" << n/c.mark << endl;
	n=0.00;
	for(int i=0;i<c.mark;i++)
		n+=c.student[i].score.Math;
	cout << "数学平均分：" << n/c.mark << endl;
	n=0.00;
	for(int i=0;i<c.mark;i++)
		n+=c.student[i].score.English;
	cout << "英语平均分：" << n/c.mark << endl;
	n=0.00;
	for(int i=0;i<c.mark;i++)
		n+=c.student[i].score.Sum;
	cout << "总计平均分：" << n/c.mark/3 << endl;
	system("pause");
	system("cls");
	return 0;
}
int main()
{
	char ch;
	while(1)
	{
		cout << "1.添加成绩" << endl;
		cout << "2.查看成绩" << endl;
		cout << "3.分析成绩" << endl;
		cout << "4.使用必读" << endl;
		cout << "5.退出系统" << endl;
		_kbhit();
		ch=_getch();
		switch(ch)
		{
			case'1':add();break;
			case'2':look();break;
			case'3':analyze();break;
			case'4':book();break;
			case'5':return 0;
		}
	}
	return 0;
}
