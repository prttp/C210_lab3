//Стандартная библиотека шаблонов - STL 
	//Контейнеры стандартной библиотеки - vector
	//Итераторы

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
	// Контейнер стандартной библиотеки vector 

//////////////////////////////////////////////////////////////////////
	//Создание векторов. 

	//Создайте следующие вектора:
	//---------------------------
	//пустой вектор целых чисел - vInt и проверьте с помощью функции size(),
	//что его размер нулевой. 

	std::vector<int> vInt;
	std::cout << vInt.size()<<std::endl;
	
	//Раскомментируйте следующий фрагмент, подумайте - все ли корректно
	//Если есть некорректности, - исправьте
	vInt.push_back(2);
	vInt.front()=1;
	stop


	//С помощью функции push_back() в цикле заполните вектор какими-либо значениями.
	//На каждой итерации цикла следите за размером вектора с помощью методов
	//size(), capacity(), max_size() и выводите значения элементов. 
	for (int i = 0; i < 5; i++) {
			vInt.push_back(i);
			PrintInfo(vInt);
		}
	//Подсказка: так как такая проверка понадобится Вам и в следующих заданиях,
	//напишите шаблон функции, которая для вектора, содержащего элементы любого типа
	//выводит его "реквизиты" и значения элементов на консоль.
	


	//вектор вещественных - vDouble1 с заданным Вами начальным размером  и
	//проверьте результат с помощью созданного Вами шаблона. Как будут
	//проинициализированы элементы вектора?
	std::vector<double>vDouble1(5);
	PrintInfo(vDouble1);


	//вектор объектов типа MyString с начальным размером - 5 элементов
	//и инициализацией каждого элемента строкой "A"
	//C помощью функции at() а также с помощью оператора
	//индексирования []  измените значения каких-либо элементов.
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. 
	std::vector<MyString> vString(5, "A");
	vString[1] = "B";
	vString.at(2) = "C";
	try {
		vString.at(5) = "D";
	}
	catch (std::out_of_range)
	{std::cout << "ERROR! Out of range!\n";}




	//вектор вещественных - vDouble3, который является копией элементов
	// [0,5) массива вещественных чисел dMas. Предворительно массив dMas 
	//нужно создать и проинициализировать!
	double dMas[6];
	for (int i = 0; i < 6; i++) {
		dMas[i] = i+0.25;
	}
	std::vector<double>vDouble3(begin(dMas), begin(dMas) + 5);
	PrintInfo(vDouble3);
	stop

	//вектор вещественных - vDouble4, который является копией элементов
	// [2,5) вектора vDouble3. 
	std::vector<double>vDouble4(begin(vDouble3)+2, begin(vDouble3) + 5);
	PrintInfo(vDouble4);



	//вектор элементов типа Point - vPoint1 а) с начальным размером 3. Какой конструктор
	//будет вызван для каждого элемента?
	//b) vPoint2 с начальным размером 5 и проинициализируйте каждый элемент координатами (1,1).
	std::vector<Point>vPoint1(3); //дефолтный
	std::vector<Point>vPoint2(5, Point(1, 1));


	//вектор указателей на Point - vpPoint с начальным размером 5
	//Подумайте: как корректно заставить эти указатели "указывать" на объекты Point
	{
		std::vector<Point*>vpPoint(5);
		int size = vpPoint.size();
		for (int i = 0; i < size; i++) {
			vpPoint[i] = new Point(i, i);
		}
		PrintInfo(vpPoint);
		//Подсказка: для вывода на печать значений скорее всего Вам понадобится
			//а) специализация Вашей шаблонной функции
			//б) или перегрузка operator<< для Point*

		//Какие дополнительные действия нужно предпринять для такого вектора?
		for (int i = 0; i < size; i++) {
			delete vpPoint[i];
		}
	}
	///////////////////////////////////////////////////////////////////////
	//Резервирование памяти.
	//Подумайте, всегда ли верны приведенные ниже проверки?
		
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
		if (v.capacity() == m); //при m>n - false; при m<=n - true;
		}
		

		
		{
		vector<int> v(3,5);
		v.resize(4,10); //значения? 5,5,5,10
		v.resize(5); //значения? 5,5,5,10,0
	
		}
		

	//Создайте два "пустых" вектора с элементами
	//любого (но одного и того же типа) типа. 
	//В первом векторе зарезервируйте память под 5 элементов, а потом заполните
	//его значениями с помощью push_back.
	//Второй вектор просто заполните значениями посредством push_back.
	//
	//Сравните размер, емкость векторов и значения элементов
		vector<int> v1(5);
		vector<int> v2;
		for (int i = 0; i < 5; i++) {
			v1.push_back(i);
			v2.push_back(i+1);
		}
		PrintInfo(v1); // Size: 10   Capacity: 10
		PrintInfo(v2); // Size: 5   Capacity: 6
	



	//!!! shrink_to_fit - Уменьшение емкости вектора.
	//Для любого вектора из предыдущего задания требуется уменьшить емкость
	//до size.
		v2.shrink_to_fit();
		PrintInfo(v2);
	

	//Создание "двухмерного вектора" - вектора векторов
	//Задан одномерный массив int ar[] = {11,2,4,3,5};
	//Создайте вектор векторов следующим образом:
	//вектор vv[0] - содержит 11 элементов со значением 11
	//vv[1] - содержит 2,2
	//vv[2] - содержит 4,4,4,4
	//...
	//Распечатайте содержимое такого двухмерного вектора по строкам
	//с помощью:
	
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
	
	//Вставка элемента последовательности insert().
	//Реализуйте функцию, которая должна вставлять новый элемент
		//в начало вектора только при условии, что в векторе такого
		 //значения еще нет.
	//Проверьте работоспособность функции - в вектор vChar2 вставьте в начало вектора символ только при
	//условии, что в векторе такого символа еще нет.
		 //например: vChar2 - abc 
		 //При попытке вставить 'a' попытка должна быть проигнорирована
		 //При попытке вставить 'q' vChar2 - qabc 
		 vector<char> vChar2{ 'a','b','c' };
		MyInsert(vChar2, 'd');
		MyInsert(vChar2, 'b');
	 stop
	
	//Реализуйте функцию, которая должна вставлять новый элемент
		 //перед каждым элементом вектора
	//Проверьте работоспособность функции - вставьте перед каждым элементом вектора vChar2 букву 'W'
		 InsertVal(vChar2, 'W');
	 stop
		 PrintInfo(vChar2);

///////////////////////////////////////////////////////////////////
	//Напишите функцию, которая должна удалять только повторяющиеся последовательности.
	//Например: было - "qwerrrrty12222r3", стало - "qwety1r3"
	 vector<char> vChar3{ 'q', 'w', 'e', 'r', 'r' , 'r', 'r', 't' , 'y', '1', '2', '2', '2', '2', 'r', '3' };
	 MyErase(vChar3);
	 PrintInfo(vChar3);

	 stop

		 ///////////////////////////////////////////////////////////////////

			 //Удаление элемента последовательности erase()
			 //Напишите функцию удаления из любого вектора всех дублей 
				  //Например: было - "qwerrrrty12222r3", стало - "qwerty123"
	vector<char> vChar4{ 'q', 'w', 'e', 'r', 'r' , 'r', 'r', 't' , 'y', '1', '2', '2', '2', '2', 'r', '3' };
	 MyEraseD(vChar4);
	 PrintInfo(vChar4);

	 stop
	
			

///////////////////////////////////////////////////////////////////
	//Создайте новый вектор таким образом, чтобы его элементы стали
	//копиями элементов любого из созданных ранее векторов, но расположены
	//были бы в обратном порядке
	 {
		auto itBeg = vChar4.rbegin();
		auto itEnd = vChar4.rend();
		vector<char> vCharRev(itBeg, itEnd);
		PrintInfo(vCharRev);
	 }





///////////////////////////////////////////////////////////////////

	//Задание 1. Списки. Операции, характерные для списков.
	//Создайте пустой список из элементов Point - ptList1 и наполните
	//его значениями с помощью методов push_back(),
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

		 //Напишите шаблон функции, которая будет выводить элементы
		 //ЛЮБОГО КОНТЕЙНЕРА на печать. Проверьте работу шаблона на контейнерах
		 //vector и list. Подсказка - хотелось бы увидеть тип контейнера.
	Print(ptList);
	 Print(vChar4);
	//Сделайте любой из списков "реверсивным" - reverse()
	 reverse(ptList.begin(), ptList.end());
	 Print(ptList);

	//Создайте список ptList2 из элементов Point таким образом, чтобы он стал 
	//копией вектора элементов типа Point, но значения элементов списка располагались
	//бы в обратном порядке 
	 list<Point> ptList2(ptList.rbegin(), ptList.rend());
	 Print(ptList2);

	//Отсортируйте списки  ptList1 и ptList2 - методом класса list - sort()
	//по возрастанию.
	//Подумайте: что должно быть перегружено в классе Point для того, чтобы
	//работала сортировка
	 ptList.sort();
	 ptList2.sort();
	 Print(ptList);
	 Print(ptList2);


	stop

	//Объедините отсортированные списки - merge(). Посмотрите: что
	//при этом происходит с каждым списком.
		list<Point> ptListMerged(ptList.size() + ptList2.size());

	merge(ptList.begin(), ptList.end(), ptList2.begin(), ptList2.end(), ptListMerged.begin());
	Print(ptListMerged);
	stop

		//Исключение элемента из списка - remove()
		//Исключите из списка элемент с определенным значением.
		//Подумайте: что должно быть перегружено в классе Point? ==
		//ptListMerged.erase(remove(ptListMerged.begin(), ptListMerged.end(), Point(3, 1)), ptListMerged.end()); ///////////////////////////////FLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAG
	list<Point>::iterator rmv = remove(ptListMerged.begin(), ptListMerged.end(), Point(3, 1));
	ptListMerged.erase(rmv, ptListMerged.end());
	//ptListMerged.remove(Point(3, 1));
	Print(ptListMerged);

	//Исключение элемента из списка, удовлетворяющего заданному условию:
	//любая из координат отрицательна - remove_if(). 
	/*ptListMerged.erase(remove_if(ptListMerged.begin(), ptListMerged.end(),
						[](Point p) {return ((p.GetX() < 0) || (p.GetY() < 0));}), ptListMerged.end());*/
	
	list<Point>::iterator rmvif = remove_if(ptListMerged.begin(), ptListMerged.end(), [](Point& p) {return ((p.GetX() < 0) || (p.GetY() < 0)); });
	ptListMerged.erase(rmvif, ptListMerged.end());
	//ptListMerged.remove_if([](Point p) {return ((p.GetX() < 0) || (p.GetY() < 0)); });
	Print(ptListMerged);
	//Исключение из списка подряд расположенных дублей - unique(). 
	auto last = std::unique(ptListMerged.begin(), ptListMerged.end());
	ptListMerged.erase(last, ptListMerged.end());
	Print(ptListMerged);
	stop

///////////////////////////////////////////////////////////////////
	//Задание 2.Очередь с двумя концами - контейнер deque

	//Создайте пустой deque с элементами типа Point. С помощью
	//assign заполните deque копиями элементов вектора. С помощью
	//разработанного Вами в предыдущем задании универсального шаблона
	//выведите значения элементов на печать
	deque<Point> ptDeque;
	ptDeque.assign(ptListMerged.begin(), ptListMerged.end());
	Print(ptDeque);


	//Создайте deque с элементами типа MyString. Заполните его значениями
	//с помощью push_back(), push_front(), insert()
	//С помощью erase удалите из deque все элементы, в которых строчки
	//начинаются с 'A' или 'a'
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