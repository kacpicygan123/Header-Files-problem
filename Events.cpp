#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <list>
#include "Events.h"

std::string FightEvent::displayEventType() {
    std::cout << "GO!" << std::endl;
    return this->eventType;
}

std::string QuitEvent::displayEventType() {
    return this->eventType;
}

std::string DialogueEvent::displayEventType() {
    return this->eventType;
}

std::string ShowEquipmentEvent::displayEventType() {
    return this->eventType;
}


std::string MoveEvent::displayEventType() {
    return this->eventType;
}

std::string MoveLeftEvent::displayEventType() {
    return this->eventType;
}

bool EventHandler::checkEvent(std::shared_ptr<Event> event) {
    if (event != NULL) {
        isNull = false;
        this->setHandledEvent(event);
    }
    else {
        isNull = true;

    }
    return isNull;
}

void EventHandler::setHandledEvent(std::shared_ptr<Event> event) {
    handledEvent = event;
}

void EventHandler::handleEvent() {
    handledEvent->displayEventType();
    this->setHandledEvent(NULL);

}

void EventEmitter::setEmittedEvent(std::shared_ptr<Event> toEmit) {
    this->emittedEvent = toEmit;
}

void EventEmitter::emitQuitEvent() {
    this->setEmittedEvent(std::make_shared<QuitEvent>());
}

void EventEmitter::emitMoveLeft() {
    this->setEmittedEvent(std::make_shared<MoveLeftEvent>());
}

std::shared_ptr<Event> EventEmitter::getCurrentEvent() {
    return emittedEvent;
}

void EventEmitter::clearEvent() {
    this->emittedEvent = NULL;
}

void EventSystem::trackEvents() {
    Sleep(1000);
    if (eventHandler.checkEvent(eventEmitter.getCurrentEvent())) {
        eventHandler.handleEvent();
        eventEmitter.clearEvent();
    }
    else {
        std::cout << "No event emitted." << std::endl;
    }
}

EventHandler EventSystem::getHandler() {
    return eventHandler;
}

EventEmitter EventSystem::getEmitter() {
    return eventEmitter;
}