# Console-UI

**Console-UI** is a C++ framework for building interactive Windows console user interfaces.  
A modular menu framework to support tabs, buttons, sliders, combo boxes, and other UI components—all displayed directly in the terminal.
Built upon my [Menu Framework](https://github.com/domWolfe/menu-framework) to expand the framework so tabs are no longer limited to containing a maximum of 9 items.

> Designed for native Windows console applications.

---

## Features

- Interactive console-based UI components
  - Tabs
  - Buttons
  - Sliders
  - Combo boxes
- Modular menu framework
- Keyboard-driven navigation
- Clean separation between UI elements and logic
- Ideal for tools, utilities, installers, and terminal apps

---

## Requirements

- **Windows**
- **C++17 or later**
- **Visual Studio** (recommended)

---

## Example Menu Code

```c++
	vector<unique_ptr<Item>> items;
	bool val = true;
	items.push_back(make_unique<Button>("Button", val));

	vector<unique_ptr<Tab>> tabs;
	tabs.push_back(make_unique<Tab>("A", move(items)));

	Menu menu = Menu("Console User Interface", move(tabs));
	menu.init();
	menu.think();
```
