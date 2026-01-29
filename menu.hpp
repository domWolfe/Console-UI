#pragma once
#include "tab.hpp"

class Menu {
public:
	Menu(string name, vector<unique_ptr<Tab>>&& tabs);
	void init();
	void start();
	void think();
	void setInMain(bool val);
	bool save_config();
	bool load_config();
	void handleKey(WORD key);

private:
	string m_sName;
	vector<unique_ptr<Tab>> m_tTabs;
	bool m_bInMain;
	int m_iSelectedTab = NULL;
	HANDLE m_hInput = GetStdHandle(STD_INPUT_HANDLE);
	bool m_bFocused = true;
	bool m_bRunning = true;
};