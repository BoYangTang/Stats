#include "effect.h"
#include "stats.h"
#include "permanent.h"
#include <string>

Permanent::Permanent(std::string stat, char op, float value, int duration) : Effect(), stat(stat), op(op), effect(value), duration(duration) {}

void Permanent::apply() {
  if (isActive()) {
    switch (op) {
      case '+':
        source->add(stat, effect);
        break;
      case '-':
        source->sub(stat, effect);
        break;
      case '*':
        source->dot(stat, effect);
        break;
      case '/':
        source->div(stat, effect);
        break;
    }
    -- duration;
  }
  if (component) {
    component->apply();
  }
}

inline bool Permanent::isActive() {
  return duration ? true : false;
}