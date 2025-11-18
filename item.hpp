#pragma once
#include "common_includes.hpp"

class Item {
public:
	Item(string name);
	string getName();
	void setItemNum(int val);
	virtual void display(string extraText) {
		printf("%i. %s %s\n", m_iItemNum, m_sName.c_str(), extraText.c_str());
	}
	int getItemNum();
	virtual void execute() {
		return;
	}
	virtual string createConfig() {
		return "";
	}
	virtual void loadConfig(string data) {
		return;
	}
private:
	string m_sName;
	int m_iItemNum;
};