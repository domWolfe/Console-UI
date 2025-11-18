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

Item::Item(string name) {
	m_sName = name;
}