#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <list>
#include "Views.h"

class View;

class Item {
public:
    virtual void Functionality();
    virtual std::string showName();
};

class Stick : public Item {
private:
    std::string name{ "STICK" };
public:
    virtual void Functionality();
    virtual std::string showName();
};

class Bone : public Item {
private:
    std::string name{ "BONE" };
public:
    virtual void Functionality();
    virtual std::string showName();
};

class ItemFactory {
public:
    virtual std::shared_ptr<Item> produceItem();
};

class StickFactory : public ItemFactory {
public:
    virtual std::shared_ptr<Item> produceItem();
};

class BoneFactory : public ItemFactory {
public:
    virtual std::shared_ptr<Item> produceItem();
};

class Inventory {
private:
    std::vector<std::shared_ptr<Item>> equipment;
public:
    std::vector<std::shared_ptr<Item>>& getEquipment();
    void addItem(std::shared_ptr<Item> item);
    void removeItem(std::shared_ptr<Item>& item);
    void displayItems();

};

class XCoordinate
{
private:
    int xPos;
public:
    int getXPos();
    void setXPos(int x);
};

class YCoordinate
{
private:
    int yPos;
public:
    int getYPos();
    void setYPos(int y);
};

class Entity
{
private:
    YCoordinate yPos;
    XCoordinate xPos;
    Inventory inventory;
    int hp{ 0 };
public:
    Entity(int x, int y);
    int getYPos();
    int getXPos();
    void setYPos(int y);
    void setXPos(int x);
    std::vector<std::shared_ptr<Item>>& getEquipment();
    void addInventoryItem(std::shared_ptr<Item> item);

};

class Model {
private:
    Entity entity{ 100, 100 };
    Inventory inventory;
    std::list<View*> views;

public:
    void addObserver(View* view);
    void notify(std::string passedEvent);
};
