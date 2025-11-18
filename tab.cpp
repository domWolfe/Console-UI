#include "tab.hpp"

void Tab::display() {
	printf("<<< %s >>>\n", m_sName.c_str());
	for (int i = 1; i <= m_iItems.size(); i++) {
		m_iItems.at(i - 1)->setItemNum(i);
		(m_iSelectedItem == i - 1) ? m_iItems.at(i - 1)->display("<--") : m_iItems.at(i - 1)->display("");
	}
}

void Tab::think() {
	bool up = (GetAsyncKeyState(VK_UP) & 0x8000) != 0;
	bool down = (GetAsyncKeyState(VK_DOWN) & 0x8000) != 0;
	if (up != down && (up || down)) {
		Sleep(75);
		down ? m_iSelectedItem++ : m_iSelectedItem--;
		m_iSelectedItem = down ? Math::menu_wrap(m_iSelectedItem, 0, m_iItems.size() - 1) : Math::menu_wrap(m_iSelectedItem, m_iItems.size() - 1, 0);
		system("cls");
		display();
	}
	else if (GetAsyncKeyState(VK_RETURN)) {
		Sleep(100);
		m_iItems.at(m_iSelectedItem)->execute();
		system("cls");
		display();
	}
}

void Tab::setKeyValue(int val) {
	m_iKeyValue = val;
}

string Tab::createConfig() {
	string fig = "";
	for (int i = 0; i < m_iItems.size(); i++) {
		fig += m_iItems.at(i)->createConfig();
	}
	fig += m_sName + "\n";
	return fig;
}

void Tab::loadConfig(ifstream& file) {
	string lines;
	string line;
	while (getline(file, line))
	{
		if (line == this->getName())
			break;
		lines += line + "\n";
	}
	for (int i = 0; i < m_iItems.size(); i++) {
		m_iItems.at(i)->loadConfig(lines);
	}
}

Tab::Tab(string name, vector<unique_ptr<Item>>&& items) {
	m_sName = name;
	m_iItems = move(items);
	m_iSelectedItem = 0;
}