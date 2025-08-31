#pragma once
#include "item.hpp"
#include "math.hpp"

class Slider : public Item {
public:
	Slider(string name, int& value, int min, int max, int step) : Item(name), m_iValue(value), m_iMin(min), m_iMax(max), m_iStep(step) {};
	int getValue() { return m_iValue; };
	void display(string extraText) override {
		printf("%i. %s [%i] %s\n", this->getKeyValue(), this->getName().c_str(), m_iValue, extraText.c_str());
	}
	void execute() override {
		m_iValue = Math::wrap(m_iValue + m_iStep, m_iMin, m_iMax);
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
	int m_iStep;
	int m_iMin;
	int m_iMax;
};