#include "item.hpp"

void Item::setKeyValue(int val) {
	m_iKeyValue = val;
}

int Item::getKeyValue() {
	return m_iKeyValue;
}

string Item::getName() {
	return m_sName;
}

Item::Item(string name) {
	m_sName = name;
}