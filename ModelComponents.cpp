#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <list>
#include "ModelComponents.h"

void Stick::Functionality() {
    std::cout << "This stick does something!";
}

std::string Stick::showName() {
    return "My name is: " + name;
}

void Stick::Functionality() {
    std::cout << "This stick does something!";
}

std::string Stick::showName() {
    return "My name is: " + name;
}

void Bone::Functionality() {
    std::cout << "This bone does something!";
}

std::string Bone::showName() {
    return "My name is: " + name;
}

std::shared_ptr<Item> StickFactory::produceItem() {
    return std::make_unique<Stick>();
}

std::shared_ptr<Item> BoneFactory::produceItem() {
    return std::make_unique<Bone>();
}

std::vector<std::shared_ptr<Item>>& Inventory::getEquipment() {
    return equipment;
}

void Inventory::addItem(std::shared_ptr<Item> item) {
    item->showName();
    equipment.push_back(item);
}

void Inventory::removeItem(std::shared_ptr<Item>& item) {
    for (int i = 0; i < equipment.size(); i++) {
        if (equipment[i] == item) {
            equipment.erase(equipment.begin() + i);
            break;
        }
    }
}

void Inventory::displayItems() {
    for (int i = 0; i < equipment.size(); i++) {
        std::cout << equipment[i]->showName() << std::endl;
    }
}

int XCoordinate::getXPos() {
    return xPos;
}

void XCoordinate::setXPos(int x) {
    xPos = x;
}

int YCoordinate::getYPos() {
    return yPos;
}

void YCoordinate::setYPos() {
    return yPos;
}

Entity::Entity(int x, int y) {
    yPos.setYPos(y);
    xPos.setXPos(x);
}

int Entity::getYPos() {
    yPos.getYPos();
}

int Entity::getXPos() {
    xPos.getXPos();
}

void Entity::setYPos(int y) {
    yPos.setYPos(y);
}

void Entity::setXPos(int x) {
    xPos.setXPos(x);
}

std::vector<std::shared_ptr<Item>>& Entity::getEquipment() {
    return inventory.getEquipment();
}

void Entity::addInventoryItem(std::shared_ptr<Item> item) {
}

void Model::addObserver(View* view) {
    views.push_back(view);
}

void Model::notify(std::string passedEvent) {
    std::list<View*>::iterator iterator = views.begin();
    while (iterator != views.end()) {
        (*iterator)->update(passedEvent);
    }
}








