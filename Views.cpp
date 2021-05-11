#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <list>
#include "Views.h"

View::View(std::shared_ptr<Model> model) {
    model->addObserver(this);
}

class View1 : public View {
public:
    View1(std::shared_ptr<Model> model) : View(model) {}
    virtual void update(std::string receivedEvent) {
        if (receivedEvent == "QUIT") {
            std::cout << "Viewing received!" << std::endl;
        }
    }
};

View1::View1(std::shared_ptr<Model> model) : View(model) {}

void View1::update(std::string receivedEvent) {
    if (receivedEvent == "QUIT") {
        std::cout << "Viewing received!" << std::endl;
    }
}