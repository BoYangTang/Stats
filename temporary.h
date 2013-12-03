#ifndef __TEMPORARY_H__
#define __TEMPORARY_H__
#include "effect.h"
#include "stats.h"
#include <string>

class Temporary : public Effect {
  std::string stat;
  char op;
  float effect;
  int duration;
  int lifetime;
  float change;
public:
  Temporary(std::string stat, char op, float value, int duration, int lifetime);
  void setSource(Stats * source);
  void apply();
  inline bool isActive();
  ~Temporary();
};

#endif