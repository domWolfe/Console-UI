#pragma once
#include "item.hpp"
#include "math.hpp"

class Combo : public Item {
public:
	Combo(string name, int& value, vector<string> values) : Item(name), m_iValue(value), m_vCombo(values) { if (m_iValue >= m_vCombo.size()) m_iValue = 0; };
	int getValue() { return m_iValue; };
	string renderComboText() {
		string combo = "";
		for (int i = 0; i < m_vCombo.size(); i++) {
			combo += m_vCombo.at(i) + " ";
		}
		combo.pop_back();
		return combo;
	}
	void display(string extraText) override {
		printf("%i. %s [%s] { %s } %s\n", this->getItemNum(), this->getName().c_str(), m_vCombo.at(m_iValue).c_str(), renderComboText().c_str(), extraText.c_str());
	}
	virtual void execute() override {
		m_iValue = Math::wrap(m_iValue + 1, 0, m_vCombo.size() - 1);
	}
	virtual string createConfig() override {
		return this->getName() + ":" + to_string(m_iValue) + "\n";
	}
	virtual void loadConfig(string data) override {
		istringstream d(data);
		string line;
		while (getline(d, line)) {
			vector<string> sData = Util::splitString(line, ':');
			if (this->getName() == sData.at(0)) {
				m_iValue = stoi(sData.at(1));
			}
		}
	}
private:
	int &m_iValue;
	vector<string> m_vCombo;
};