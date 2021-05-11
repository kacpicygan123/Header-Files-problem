#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <list>
#include "ModelComponents.h"

class Model;

class Event {
public:
    virtual std::string displayEventType() = 0;
};

class FightEvent : public Event {
private:
    std::string eventType;
public:
    virtual std::string displayEventType();
};

class QuitEvent : public Event {
private:
    std::string eventType;
public:
    virtual std::string displayEventType();
};

class DialogueEvent : public Event {
private:
    std::string eventType;
public:
    virtual std::string displayEventType();

class ShowEquipmentEvent : public Event {
private:
    std::string eventType;
public:
    virtual std::string displayEventType();
};

class MoveEvent : public Event {
private:
    std::string eventType{ "MOVE" };
public:
    virtual std::string displayEventType();
};

class MoveLeftEvent : public MoveEvent {
public:
    virtual std::string displayEventType();

class EventHandler {
private:
    bool isNull{ false };
    std::shared_ptr<Event> handledEvent;
    std::shared_ptr<Model> model;
public:
    bool checkEvent(std::shared_ptr<Event> event);
    void setHandledEvent(std::shared_ptr<Event> event);
    void handleEvent();
};

class EventEmitter {
private:
    std::shared_ptr<Event> emittedEvent{ NULL };
public:
    void setEmittedEvent(std::shared_ptr<Event> toEmit);
    void emitQuitEvent();
    void emitMoveLeft();
    std::shared_ptr<Event> getCurrentEvent();
    void clearEvent();
};

class EventSystem {
private:
    EventHandler eventHandler;
    EventEmitter eventEmitter;
public:
    void trackEvents();
    EventHandler getHandler();
    EventEmitter getEmitter();

};
