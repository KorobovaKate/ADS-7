// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car *newCar = new Car{light, nullptr, nullptr};
    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        Car *last = first->prev;
        last->next = newCar;
        newCar->prev = last;
        newCar->next = first;
        first->prev = newCar;
    }
}

int Train::getLength() {
  if (!first) return 0;
  int countOp = 0;
  Car *curr = first;
  
  if (!curr->light) {
    curr->light = true;
  }

  int steps = 1;
  
  while (true) {
    for (int i = 0; i < steps; i++) {
        curr = curr->next;
        countOp++;
    }
      
    if (curr->light) {
        curr->light = false;
        countOp++;
        
        for (int i = 0; i < steps; i++) {
            curr = curr->prev;
            countOp++;
        }
        
        if (!curr->light) {
            return steps;
        }
        steps++;
    } else {
        steps++;
    }
  }
    return steps;
}

int Train::getOpCount() {
    return countOp;
}
