#pragma once
#include "item.hpp"

class Button : public Item {
public:
	Button(string name, bool& value) : Item(name), m_bValue(value) {};
	bool getValue() { return m_bValue; };
	void display(string extraText) override {
		printf("%i. %s [%s] %s\n", this->getItemNum(), this->getName().c_str(), m_bValue ? "X" : "", extraText.c_str());
	}
	virtual void execute() override {
		m_bValue = !m_bValue;
	}
	virtual string createConfig() override {
		return this->getName() + ":" + to_string(m_bValue) + "\n";
	}
	virtual void loadConfig(string data) override {
		istringstream d(data);
		string line;
		while (getline(d, line)) {
			vector<string> sData = Util::splitString(line, ':');
			if (this->getName() == sData.at(0)) {
				m_bValue = sData.at(1) == "1" ? true : false;
			}
		}
	}
private:
	bool &m_bValue;
};