#pragma once
#include "tab.hpp"

class Menu {
public:
	Menu(string name, vector<Tab>&& tabs);
	void init();
	void start();
	void think();
	void setInMain(bool val);
	bool save_config();
	bool load_config();

private:
	string m_sName;
	vector<Tab> m_tTabs;
	bool m_bInMain;
	int m_iSelectedTab = NULL;
};