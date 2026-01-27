#include "common_includes.hpp"
#include "math.hpp"

#include "item.hpp"
#include "button.hpp"
#include "slider.hpp"
#include "combo.hpp"

#include "tab.hpp"
#include "menu.hpp"

/*

TODO:
	- Add in window only functionality

*/

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	vector<unique_ptr<Item>> items;
	bool val = true;
	items.push_back(make_unique<Button>("Button", val));

	vector<unique_ptr<Item>> items_b;
	int slider = 100;
	items_b.push_back(make_unique<Slider>("Slider", slider, 0, 100, 5));

	vector<unique_ptr<Item>> items_c;
	items_c.push_back(make_unique<Item>("Basic Item"));

	int choice = 0;
	vector<string> choices = {"X", "Y", "Z"};
	items_c.push_back(make_unique<Combo>("Combo", choice, choices));

	bool val_1 = true;
	bool val_2 = true;
	items_c.push_back(make_unique<Button>("Button_1", val_1));
	items_c.push_back(make_unique<Button>("Button_2", val_2));

	int slider_1 = 100;
	items_c.push_back(make_unique<Slider>("Slider_1", slider_1, 0, 100, 5));

	vector<Tab> tabs;
	tabs.emplace_back(Tab("A", move(items)));
	tabs.emplace_back(Tab("B", move(items_b)));
	tabs.emplace_back(Tab("C", move(items_c)));

	Menu menu = Menu("Console User Interface", move(tabs));
	menu.init();
	menu.think();

	_CrtDumpMemoryLeaks();
	return 0;
}