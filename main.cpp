#include "common_includes.hpp"
#include "math.hpp"

#include "item.hpp"
#include "button.hpp"
#include "slider.hpp"
#include "combo.hpp"

#include "tab.hpp"
#include "menu.hpp"

void run_menu() {
	vector<unique_ptr<Item>> items;
	bool val = true;
	items.push_back(make_unique<Button>("Button", val));

	vector<unique_ptr<Item>> items_b;
	int slider = 100;
	items_b.push_back(make_unique<Slider>("Slider", slider, 0, 100, 5));

	vector<unique_ptr<Item>> items_c;
	items_c.push_back(make_unique<Item>("Basic Item"));

	int choice = 0;
	vector<string> choices = { "X", "Y", "Z" };
	items_c.push_back(make_unique<Combo>("Combo", choice, choices));

	bool val_1 = true;
	bool val_2 = true;
	items_c.push_back(make_unique<Button>("Button#1", val_1));
	items_c.push_back(make_unique<Button>("Button#2", val_2));

	int slider_1 = 100;
	items_c.push_back(make_unique<Slider>("Slider#1", slider_1, 0, 100, 5));

	vector<unique_ptr<Tab>> tabs;
	tabs.push_back(make_unique<Tab>("A", move(items)));
	tabs.push_back(make_unique<Tab>("B", move(items_b)));
	tabs.push_back(make_unique<Tab>("C", move(items_c)));

	Menu menu = Menu("Console User Interface", move(tabs));
	menu.init();
	menu.think();
}

int main()
{
	#ifdef _DEBUG
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	#endif
	run_menu();
	return 0;
}