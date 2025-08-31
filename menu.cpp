#pragma once
#include "menu.hpp"
#include <fstream>

Menu::Menu(string name, vector<Tab>&& tabs) {
	m_sName = name;
	m_tTabs = move(tabs);
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

void Menu::think() {
	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE)) {
			save_config();
			break;
		}

		if (!m_bInMain) {
			if (GetAsyncKeyState(VK_BACK)) {
				system("cls");
				start();
				m_bInMain = true;
			}
			m_tTabs.at(m_iSelectedTab).think();
			continue;
		}
		else {
			for (int i = 0x31; i <= 0x39; i++) {
				if (GetAsyncKeyState(i) && m_tTabs.size() > (i - 49)) {
					system("cls");
					Sleep(50);
					m_tTabs.at(i - 49).display();
					m_iSelectedTab = i - 49;
					m_bInMain = false;
				}
			}
		}
	}
}