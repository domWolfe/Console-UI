#include "item.hpp"

void Item::setItemNum(int val) {
	m_iItemNum = val;
}

int Item::getItemNum() {
	return m_iItemNum;
}

string Item::getName() {
	return m_sName;
}

string Item::setDisplayName(const string& name) {
	string tmp {};
	for (const auto& c : name) {
		if (c == '#')
			break;
		else
			tmp += c;
	}
	return tmp;
}

string Item::getDisplayName() {
	return m_sDisplayName;
}

Item::Item(string name) {
	m_sDisplayName = setDisplayName(name);
	m_sName = name;
}