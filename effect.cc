#include "effect.h"
#include "stats.h"

/*Effect::Effect(const Effect &other) {
  this->active = other.active;
  this->source = other.source;
  if (other.component) {
    this->component = other.component->clone();
  }
  else {
    this->component = 0;
  }
}
*/

void Effect::clean() {
  if (component) {
    if (component->isActive()) {
      component->clean();
    }
    else {
      Effect * garbage = component;
      this->component = garbage->component;
      garbage->component = 0;
      delete garbage;
      clean();
    }
  }
}

Effect::Effect() : active(false), component(0), source(0) {}

void Effect::setSource(Stats * source) {
  this->source = source;
  if (component) {
    component->setSource(source);
  }
}

void Effect::add(Effect * e) {
  if (e) {
    if (component) {
      component->add(e);    
    }
    else {
      component = e;
      component->setSource(source);
    }
  }
}

void Effect::apply() {
  clean();
  if (component) {
    component->apply();
  }
}

void Effect::reset() {
  delete component;
  component = 0;
}

inline bool Effect::isActive() {
  return component ? true : false;
}

Effect::~Effect() {
  delete component;
}
