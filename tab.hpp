#pragma once
#include "item.hpp"
#include "math.hpp"

class Tab {
public:
	Tab(string name, vector<unique_ptr<Item>>&& items);
	string getName() { return m_sName; };
	void display();
	void think();
	void setKeyValue(int val);
	int getKeyValue() { return m_iKeyValue; };
	int getItemsSize() { return m_iItems.size(); };
	string createConfig();
	void loadConfig(ifstream& file);
private:
	string m_sName;
	vector<unique_ptr<Item>> m_iItems;
	int m_iSelectedItem;
	int m_iKeyValue;
};