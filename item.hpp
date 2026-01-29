#pragma once
#include "common_includes.hpp"

class Item {
public:
	Item(string name);
	virtual ~Item() = default;
	string getName();
	string setDisplayName(const string& name);
	string getDisplayName();
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
	string m_sDisplayName;
	int m_iItemNum;
};