#include "effect.h"
#include "stats.h"
#include "temporary.h"
#include <string>
#include <iostream>

Temporary::Temporary(std::string stat, char op, float value, int duration, int lifetime) : Effect(), stat(stat), op(op), effect(value), duration(duration), lifetime(lifetime) {
  if (op == '+' || op == '-') {
    change = 0;
  }
  else {
    change = 1;
  }
}

void Temporary::apply() {  
  if (duration) {    
    float old = source->get(stat);
    switch (op) {
      case '+':
        change += source->add(stat, effect) - old;
        break;
      case '-':
        change += source->sub(stat, effect) - old;
        break;
      case '*':
        source->dot(stat, effect);
        change *= effect;
        break;
      case '/':
        source->div(stat, effect);
        change /= effect;
        break;
    }
    -- duration;
  }
  -- lifetime;
  if (component) {
    component->apply();
  }
}

inline bool Temporary::isActive() {
  return lifetime ? true : false;
}

Temporary::~Temporary() {
  switch (op) {
    case '+':
      source->sub(stat, change);
      break;
    case '-':
      source->add(stat, change);
      break;
    case '*':
      source->div(stat, change);
      break;
    case '/':
      source->dot(stat, change);
      break;
  }
  delete component;
}