#ifndef __EFFECT_H__
#define __EFFECT_H__
#include <map>
#include <string>

class Stats;

class Effect {
  bool active;
  void clean();
protected:
  Effect * component;
  Stats * source;
public:
  Effect();
  //Effect(const &other);
  //virtual Effect * clone() = 0;
  void setSource(Stats * source);
  void add(Effect * e);
  virtual void apply();
  void reset();
  virtual inline bool isActive();
  virtual ~Effect();
};

#endif