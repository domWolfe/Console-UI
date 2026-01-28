#pragma once
#include "menu.hpp"
#include <fstream>

Menu::Menu(string name, vector<Tab>&& tabs) {
	m_sName = name;
	m_tTabs = move(tabs);

	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);

	DWORD mode = 0;
	GetConsoleMode(hInput, &mode);

	mode &= ~ENABLE_QUICK_EDIT_MODE;
	mode |= ENABLE_EXTENDED_FLAGS;
	mode |= ENABLE_WINDOW_INPUT;
	mode |= ENABLE_MOUSE_INPUT;

	SetConsoleMode(hInput, mode);
}

void Menu::setInMain(bool val) {
	m_bInMain = val;
}

void typeInText(string text) {
	for (int i = 0; i < text.size(); i++) {
		printf("%c", text[i]);
		Sleep(50);
	}
	printf("\n");
}

void Menu::init() {
	SetConsoleTitle(wstring(m_sName.begin(), m_sName.end()).c_str());
	m_bInMain = true;
	typeInText("<<< " + m_sName + " >>>");
	for (int i = 1; i <= m_tTabs.size(); i++) {
		typeInText(to_string(i) + ". " + m_tTabs.at(i - 1).getName().c_str());
		m_tTabs.at(i - 1).setKeyValue(0x31 + (i - 1));
	}
	load_config();
}

bool Menu::load_config() {
	ifstream  configFile;
	configFile.open("config.txt");
	string line;
	if (configFile.is_open()) {
		for (int i = 0; i < m_tTabs.size(); i++) {
			m_tTabs.at(i).loadConfig(configFile);
		}
		configFile.close();
		return true;
	}
	else {
		std::cerr << "Error opening config for reading." << std::endl;
		return false;
	}
}

bool Menu::save_config() {
	ofstream configFile;
	configFile.open("config.txt");
	if (configFile.is_open()) {
		for (int i = 0; i < m_tTabs.size(); i++) {
			configFile << m_tTabs.at(i).createConfig();
		}
		configFile.close();
		return true;
	}
	else {
		std::cerr << "Error opening config for writing." << std::endl;
		return false;
	}
}

void Menu::start() {
	m_bInMain = true;
	printf("<<< %s >>>\n", m_sName.c_str());
	for (int i = 1; i <= m_tTabs.size(); i++) {
		printf("%i. %s\n", i, m_tTabs.at(i - 1).getName().c_str());
		m_tTabs.at(i - 1).setKeyValue(0x31 + (i - 1));
	}
}

void Menu::handleKey(WORD key) {

	if (key == VK_ESCAPE) {
		save_config();
		exit(0);
	}

	if (!m_bInMain) {

		if (key == VK_BACK) {
			system("cls");
			start();
			m_bInMain = true;
			return;
		}

		m_tTabs.at(m_iSelectedTab).think();
		return;
	}

	if (key >= 0x31 && key <= 0x39) { //0x31 -> Key 1 to 0x39 -> Key 9
		int index = key - 0x31;

		if (index < m_tTabs.size()) {
			system("cls");
			m_tTabs.at(index).display();
			m_iSelectedTab = index;
			m_bInMain = false;
		}
	}
}

void Menu::think() {
	INPUT_RECORD record;
	DWORD eventsRead;

	while (true) {
		ReadConsoleInput(m_hInput, &record, 1, &eventsRead);

		switch (record.EventType) {

		case FOCUS_EVENT:
			m_bFocused = record.Event.FocusEvent.bSetFocus;
			break;

		case KEY_EVENT:
			if (!m_bFocused)
				break;

			if (!record.Event.KeyEvent.bKeyDown)
				break;

			handleKey(record.Event.KeyEvent.wVirtualKeyCode);
			break;
		}
	}
}
