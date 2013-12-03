#include "effect.h"
#include "stats.h"
#include <map>
#include <string>

Stats::Stats(){
  effects = new Effect();
  effects->setSource(this);
}

void Stats::addEffect(Effect * e) {
  effects->add(e);
}

void Stats::applyEffects() {
  effects->apply();
}

void Stats::clearEffects() {
  effects->reset();
}

void Stats::init(std::string stat) {
  base[stat] = 0;
  current[stat] = 0;
  factor[stat] = 1;
}

void Stats::reset(std::string stat) {
  current[stat] = 0;
  factor[stat] = 1;
}

void Stats::resetAll() {
  for(std::map<std::string, float>::iterator i = base.begin(); i != base.end(); ++ i) {
    reset(i->first);
  }
}

inline float min(float a, float b) {
  return a < b ? a : b;
}

inline float max(float a, float b) {
  return a < b ? b : a;
}

float Stats::get(std::string stat) {
  return max(min(current[stat] * factor[stat], base[stat]), 0);
}

float Stats::set(std::string stat, float value) {
  base[stat] = value;
  factor[stat] = 1;
  current[stat] = value;
  return get(stat);
}

float Stats::add(std::string stat, float value) {
  current[stat] += min(value, base[stat] - current[stat]) / factor[stat];
  return get(stat);
}

float Stats::sub(std::string stat, float value) {
  current[stat] -= min(value, current[stat]) / factor[stat];
  return get(stat);
}

float Stats::dot(std::string stat, float value) {
  factor[stat] *= value;
  return get(stat);
}

float Stats::div(std::string stat, float value) {
  factor[stat] /= value;
  return get(stat);
}

Stats::~Stats() {
  delete effects;
}