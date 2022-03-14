//����������� ���������� �������� - STL 
	//���������� ����������� ���������� - vector
	//���������

#include <iostream>
#include <vector>
#include "Print.h"
#include "myString.h"
#include "Point.h"
#include "ContFunc.h"
#include <list>
#include <deque>
#pragma warning(disable: 4786)


using namespace std;	

#define	  stop __asm nop


int main()
{
	// ��������� ����������� ���������� vector 

//////////////////////////////////////////////////////////////////////
	//�������� ��������. 

	//�������� ��������� �������:
	//---------------------------
	//������ ������ ����� ����� - vInt � ��������� � ������� ������� size(),
	//��� ��� ������ �������. 

	std::vector<int> vInt;
	std::cout << vInt.size()<<std::endl;
	
	//���������������� ��������� ��������, ��������� - ��� �� ���������
	//���� ���� ��������������, - ���������
	vInt.push_back(2);
	vInt.front()=1;
	stop


	//� ������� ������� push_back() � ����� ��������� ������ ������-���� ����������.
	//�� ������ �������� ����� ������� �� �������� ������� � ������� �������
	//size(), capacity(), max_size() � �������� �������� ���������. 
	for (int i = 0; i < 5; i++) {
			vInt.push_back(i);
			PrintInfo(vInt);
		}
	//���������: ��� ��� ����� �������� ����������� ��� � � ��������� ��������,
	//�������� ������ �������, ������� ��� �������, ����������� �������� ������ ����
	//������� ��� "���������" � �������� ��������� �� �������.
	


	//������ ������������ - vDouble1 � �������� ���� ��������� ��������  �
	//��������� ��������� � ������� ���������� ���� �������. ��� �����
	//������������������� �������� �������?
	std::vector<double>vDouble1(5);
	PrintInfo(vDouble1);


	//������ �������� ���� MyString � ��������� �������� - 5 ���������
	//� �������������� ������� �������� ������� "A"
	//C ������� ������� at() � ����� � ������� ���������
	//�������������� []  �������� �������� �����-���� ���������.
	//���������� "�����" �� ������� ������� � ������� at() �
	//� ������� []. 
	std::vector<MyString> vString(5, "A");
	vString[1] = "B";
	vString.at(2) = "C";
	try {
		vString.at(5) = "D";
	}
	catch (std::out_of_range)
	{std::cout << "ERROR! Out of range!\n";}




	//������ ������������ - vDouble3, ������� �������� ������ ���������
	// [0,5) ������� ������������ ����� dMas. �������������� ������ dMas 
	//����� ������� � �������������������!
	double dMas[6];
	for (int i = 0; i < 6; i++) {
		dMas[i] = i+0.25;
	}
	std::vector<double>vDouble3(begin(dMas), begin(dMas) + 5);
	PrintInfo(vDouble3);
	stop

	//������ ������������ - vDouble4, ������� �������� ������ ���������
	// [2,5) ������� vDouble3. 
	std::vector<double>vDouble4(begin(vDouble3)+2, begin(vDouble3) + 5);
	PrintInfo(vDouble4);



	//������ ��������� ���� Point - vPoint1 �) � ��������� �������� 3. ����� �����������
	//����� ������ ��� ������� ��������?
	//b) vPoint2 � ��������� �������� 5 � ������������������ ������ ������� ������������ (1,1).
	std::vector<Point>vPoint1(3); //���������
	std::vector<Point>vPoint2(5, Point(1, 1));


	//������ ���������� �� Point - vpPoint � ��������� �������� 5
	//���������: ��� ��������� ��������� ��� ��������� "���������" �� ������� Point
	{
		std::vector<Point*>vpPoint(5);
		int size = vpPoint.size();
		for (int i = 0; i < size; i++) {
			vpPoint[i] = new Point(i, i);
		}
		PrintInfo(vpPoint);
		//���������: ��� ������ �� ������ �������� ������ ����� ��� �����������
			//�) ������������� ����� ��������� �������
			//�) ��� ���������� operator<< ��� Point*

		//����� �������������� �������� ����� ����������� ��� ������ �������?
		for (int i = 0; i < size; i++) {
			delete vpPoint[i];
		}
	}
	///////////////////////////////////////////////////////////////////////
	//�������������� ������.
	//���������, ������ �� ����� ����������� ���� ��������?
		
		{
		size_t n = 2;
		vector<int> v(n);
		v.resize(n/2);
		bool x = 0;
		x = (v.capacity() == n);
		if (v.capacity() == n);//true, cap=2 size=1
		}
		

		
		{
			int n = 4;
			size_t m = 4;
		vector<int> v(n);
		v.reserve(m);
		bool x = 0;
		x = (v.capacity() == n);
		if (v.capacity() == m); //��� m>n - false; ��� m<=n - true;
		}
		

		
		{
		vector<int> v(3,5);
		v.resize(4,10); //��������? 5,5,5,10
		v.resize(5); //��������? 5,5,5,10,0
	
		}
		

	//�������� ��� "������" ������� � ����������
	//������ (�� ������ � ���� �� ����) ����. 
	//� ������ ������� �������������� ������ ��� 5 ���������, � ����� ���������
	//��� ���������� � ������� push_back.
	//������ ������ ������ ��������� ���������� ����������� push_back.
	//
	//�������� ������, ������� �������� � �������� ���������
		vector<int> v1(5);
		vector<int> v2;
		for (int i = 0; i < 5; i++) {
			v1.push_back(i);
			v2.push_back(i+1);
		}
		PrintInfo(v1); // Size: 10   Capacity: 10
		PrintInfo(v2); // Size: 5   Capacity: 6
	



	//!!! shrink_to_fit - ���������� ������� �������.
	//��� ������ ������� �� ����������� ������� ��������� ��������� �������
	//�� size.
		v2.shrink_to_fit();
		PrintInfo(v2);
	

	//�������� "����������� �������" - ������� ��������
	//����� ���������� ������ int ar[] = {11,2,4,3,5};
	//�������� ������ �������� ��������� �������:
	//������ vv[0] - �������� 11 ��������� �� ��������� 11
	//vv[1] - �������� 2,2
	//vv[2] - �������� 4,4,4,4
	//...
	//������������ ���������� ������ ����������� ������� �� �������
	//� �������:
	
	//std::cout<<vv<<std::endl;
		{
			int 	ar[] = { 11, 2, 4, 3, 5 };
			size_t 	size = sizeof(ar) / sizeof(int);
			vector<vector<int>> vv(size);

			for (int i = 0; i < size; i++)
			{
				vv[i] = vector<int>(ar[i], ar[i]);
			}

			std::cout << vv <<std::endl;
		}
	 stop

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//������� �������� ������������������ insert().
	//���������� �������, ������� ������ ��������� ����� �������
		//� ������ ������� ������ ��� �������, ��� � ������� ������
		 //�������� ��� ���.
	//��������� ����������������� ������� - � ������ vChar2 �������� � ������ ������� ������ ������ ���
	//�������, ��� � ������� ������ ������� ��� ���.
		 //��������: vChar2 - abc 
		 //��� ������� �������� 'a' ������� ������ ���� ���������������
		 //��� ������� �������� 'q' vChar2 - qabc 
		 vector<char> vChar2{ 'a','b','c' };
		MyInsert(vChar2, 'd');
		MyInsert(vChar2, 'b');
	 stop
	
	//���������� �������, ������� ������ ��������� ����� �������
		 //����� ������ ��������� �������
	//��������� ����������������� ������� - �������� ����� ������ ��������� ������� vChar2 ����� 'W'
		 InsertVal(vChar2, 'W');
	 stop
		 PrintInfo(vChar2);

///////////////////////////////////////////////////////////////////
	//�������� �������, ������� ������ ������� ������ ������������� ������������������.
	//��������: ���� - "qwerrrrty12222r3", ����� - "qwety1r3"
	 vector<char> vChar3{ 'q', 'w', 'e', 'r', 'r' , 'r', 'r', 't' , 'y', '1', '2', '2', '2', '2', 'r', '3' };
	 MyErase(vChar3);
	 PrintInfo(vChar3);

	 stop

		 ///////////////////////////////////////////////////////////////////

			 //�������� �������� ������������������ erase()
			 //�������� ������� �������� �� ������ ������� ���� ������ 
				  //��������: ���� - "qwerrrrty12222r3", ����� - "qwerty123"
	vector<char> vChar4{ 'q', 'w', 'e', 'r', 'r' , 'r', 'r', 't' , 'y', '1', '2', '2', '2', '2', 'r', '3' };
	 MyEraseD(vChar4);
	 PrintInfo(vChar4);

	 stop
	
			

///////////////////////////////////////////////////////////////////
	//�������� ����� ������ ����� �������, ����� ��� �������� �����
	//������� ��������� ������ �� ��������� ����� ��������, �� �����������
	//���� �� � �������� �������
	 {
		auto itBeg = vChar4.rbegin();
		auto itEnd = vChar4.rend();
		vector<char> vCharRev(itBeg, itEnd);
		PrintInfo(vCharRev);
	 }





///////////////////////////////////////////////////////////////////

	//������� 1. ������. ��������, ����������� ��� �������.
	//�������� ������ ������ �� ��������� Point - ptList1 � ���������
	//��� ���������� � ������� ������� push_back(),
	//push_front, insert()
	 list<Point>	ptList;
	 ptList.push_back(Point(1, 1));
	 ptList.push_back(Point(1, 2));
	 ptList.push_back(Point(1, 3));
	 ptList.push_front(Point(2, -1));
	 ptList.push_front(Point(2, 2));
	 ptList.push_front(Point(2, -3));
	 list<Point>::iterator itBeg = ptList.begin();
	 itBeg++;
	 itBeg++;
	 ptList.insert(itBeg, Point(3, 1));
	 stop

		 //�������� ������ �������, ������� ����� �������� ��������
		 //������ ���������� �� ������. ��������� ������ ������� �� �����������
		 //vector � list. ��������� - �������� �� ������� ��� ����������.
	Print(ptList);
	 Print(vChar4);
	//�������� ����� �� ������� "�����������" - reverse()
	 reverse(ptList.begin(), ptList.end());
	 Print(ptList);

	//�������� ������ ptList2 �� ��������� Point ����� �������, ����� �� ���� 
	//������ ������� ��������� ���� Point, �� �������� ��������� ������ �������������
	//�� � �������� ������� 
	 list<Point> ptList2(ptList.rbegin(), ptList.rend());
	 Print(ptList2);

	//������������ ������  ptList1 � ptList2 - ������� ������ list - sort()
	//�� �����������.
	//���������: ��� ������ ���� ����������� � ������ Point ��� ����, �����
	//�������� ����������
	 ptList.sort();
	 ptList2.sort();
	 Print(ptList);
	 Print(ptList2);


	stop

	//���������� ��������������� ������ - merge(). ����������: ���
	//��� ���� ���������� � ������ �������.
		list<Point> ptListMerged(ptList.size() + ptList2.size());

	merge(ptList.begin(), ptList.end(), ptList2.begin(), ptList2.end(), ptListMerged.begin());
	Print(ptListMerged);
	stop

		//���������� �������� �� ������ - remove()
		//��������� �� ������ ������� � ������������ ���������.
		//���������: ��� ������ ���� ����������� � ������ Point? ==
		//ptListMerged.erase(remove(ptListMerged.begin(), ptListMerged.end(), Point(3, 1)), ptListMerged.end()); ///////////////////////////////FLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAG
	list<Point>::iterator rmv = remove(ptListMerged.begin(), ptListMerged.end(), Point(3, 1));
	ptListMerged.erase(rmv, ptListMerged.end());
	//ptListMerged.remove(Point(3, 1));
	Print(ptListMerged);

	//���������� �������� �� ������, ���������������� ��������� �������:
	//����� �� ��������� ������������ - remove_if(). 
	/*ptListMerged.erase(remove_if(ptListMerged.begin(), ptListMerged.end(),
						[](Point p) {return ((p.GetX() < 0) || (p.GetY() < 0));}), ptListMerged.end());*/
	
	list<Point>::iterator rmvif = remove_if(ptListMerged.begin(), ptListMerged.end(), [](Point& p) {return ((p.GetX() < 0) || (p.GetY() < 0)); });
	ptListMerged.erase(rmvif, ptListMerged.end());
	//ptListMerged.remove_if([](Point p) {return ((p.GetX() < 0) || (p.GetY() < 0)); });
	Print(ptListMerged);
	//���������� �� ������ ������ ������������� ������ - unique(). 
	auto last = std::unique(ptListMerged.begin(), ptListMerged.end());
	ptListMerged.erase(last, ptListMerged.end());
	Print(ptListMerged);
	stop

///////////////////////////////////////////////////////////////////
	//������� 2.������� � ����� ������� - ��������� deque

	//�������� ������ deque � ���������� ���� Point. � �������
	//assign ��������� deque ������� ��������� �������. � �������
	//�������������� ���� � ���������� ������� �������������� �������
	//�������� �������� ��������� �� ������
	deque<Point> ptDeque;
	ptDeque.assign(ptListMerged.begin(), ptListMerged.end());
	Print(ptDeque);


	//�������� deque � ���������� ���� MyString. ��������� ��� ����������
	//� ������� push_back(), push_front(), insert()
	//� ������� erase ������� �� deque ��� ��������, � ������� �������
	//���������� � 'A' ��� 'a'
	{deque<MyString> strDeque;
	strDeque.push_back("Abc");
	strDeque.push_back("xyz");
	strDeque.push_back("Xyz");
	strDeque.push_front("abc");
	strDeque.push_front("bac");
	deque<MyString>::iterator itBeg = strDeque.begin();
	++itBeg;
	strDeque.insert(itBeg, "zyx");
	Print(strDeque);
	itBeg = remove_if(strDeque.begin(), strDeque.end(), [](MyString& str) {return (str.GetString()[0] == 'A') || (str.GetString()[0] == 'a'); });
	strDeque.erase(itBeg, strDeque.end());
	//strDeque.erase(
	//	remove_if(strDeque.begin(), strDeque.end(),
	//		//[](MyString str) {return (!strncmp((str.GetString()), "A", 1) || !strncmp((str.GetString()), "a", 1)); }), ///////////////////////////////FLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAG
	//		[](MyString& str) {return (str.GetString()[0] == 'A') || (str.GetString()[0] == 'a'); }),
	//		strDeque.end());
	Print(strDeque);
	}
	

	return 0;
}