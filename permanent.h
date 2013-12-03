#ifndef __PERMANENT_H__
#define __PERMANENT_H__
#include "effect.h"
#include "stats.h"
#include <string>

class Permanent : public Effect {
  std::string stat;
  char op;
  float effect;
  int duration;
public:
  Permanent(std::string stat, char op, float value, int duration);
  //Permanent(const Permanent &other);
  //Permanent * clone();
  void apply();
  inline bool isActive();
};

#endif
