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
  int steps = 0;
  while (!curr->light && curr != first) {
      curr = curr->next;
      steps++;
      countOp++;
  }
    
  if (!curr->light) return steps;
    
  curr->light = false;
  countOp++;

  for (int i = 0; i < steps; i++) {
    curr = curr->prev;
    countOp++;
  }
    
  if (!curr->light) return steps;
}

int Train::getOpCount() {
    return countOp;
}
