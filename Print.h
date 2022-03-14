#pragma once
template<typename T>
void PrintInfo(const T& s) {
	std::cout << typeid(s).name() << std::endl <<	"Size: " << s.size() <<	"   Capacity: " << s.capacity() <<"   Maximal size: " << s.max_size() << std::endl;
	int size = s.size();
	for (int i = 0; i < size; i++) {
		std::cout << s[i] << std::endl;
	}
}
template<typename T>

std::ostream& operator<<(std::ostream& os, const std::vector<T>& vv) {
	int size = vv.size();
	for (int i = 0; i < size; i++) {
	
			std::cout << vv[i] << "  ";
		
		
	}
	std::cout << std::endl;
	return os;
}
template<typename C>
void Print(const C& cont) {
	std::cout << typeid(cont).name() << std::endl << "Size: " << cont.size() <<  "   Maximal size: " << cont.max_size() << std::endl;
	typename C::const_iterator itBeg = cont.begin();
	int size = cont.size();
	for (int i = 0; i < size; i++) {
		std::cout << *itBeg << std::endl;
		++itBeg;
	}
}