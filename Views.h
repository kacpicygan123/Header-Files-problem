#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <list>
#include "ModelComponents.h"

class Model;

class View {
public:
	virtual void update(std::string receivedEvent);
	View(std::shared_ptr<Model> model);
};

class View1 : public View {
public:
	View1(std::shared_ptr<Model> model);
	virtual void update(std::string receivedEvent);
};
