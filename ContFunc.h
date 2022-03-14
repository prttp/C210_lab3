#pragma once
template<typename C, typename T>
bool Find(C& cont, T& val) {
	for (size_t i = 0; i < cont.size(); i++) {
		if (val == cont[i]) { return 1; }
	}
	return 0;
}

template<typename C, typename T>
bool MyInsert(C& cont, const T& val) {   
	if (Find(cont, val)) {
		return 0;
	}
	cont.insert(cont.begin(), val);
	return 1;
}

template<typename C, typename T>
void InsertVal(C& cont, const T& val) {
	auto itPos = cont.begin();
	auto itEnd = cont.end();
	while (itPos != itEnd) {
		
		itPos = cont.insert(itPos, val);
		itPos+=2;
		itEnd = cont.end();
	}
	
}
template<typename C>
void MyErase(C& cont) {
	auto itBeg = cont.begin();
	auto itEnd = cont.end();

	while (itBeg != itEnd) {
		auto itTmp = std::next(itBeg);

		while ((itTmp != itEnd) && (*itBeg == *itTmp)) {
			++itTmp;
		}
		if (itBeg != --itTmp) {
			itBeg = cont.erase(itBeg, ++itTmp);
			itEnd = cont.end();
		}
		else {
			++itBeg;
		}
	}
}
template<typename C>
void MyEraseD(C& cont) {
	auto itBeg = cont.begin();
	auto itEnd = cont.end();


	while (itBeg != itEnd) {
		auto itTmp = std::next(itBeg);

		while (itTmp != itEnd) {
			if (*itBeg == *itTmp) {
				itTmp = cont.erase(itTmp);
				itEnd = cont.end();
			}
			else {
				++itTmp;
			}
		}

		++itBeg;
	}
}