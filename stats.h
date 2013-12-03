#ifndef __STATS_H__
#define __STATS_H__
#include <map>
#include <string>

class Effect;

class Stats {
  std::map<std::string, float> base;
  std::map<std::string, float> current;
  std::map<std::string, float> factor;
  Effect * effects;
public:
  Stats();
  void addEffect(Effect * e);
  void applyEffects();
  void clearEffects();
  void init(std::string stat);
  void reset(std::string stat);
  void resetAll();
  float get(std::string stat);
  float set(std::string stat, float value);
  float add(std::string stat, float value);
  float sub(std::string stat, float value);
  float dot(std::string stat, float value);
  float div(std::string stat, float value);
  ~Stats();
};

#endif
