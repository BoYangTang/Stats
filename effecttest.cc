#include "effect.h"
#include "stats.h"
#include "permanent.h"
#include "temporary.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
  char comm;
  string stat;
  float value;
  int duration;
  int life;
  Stats lol;
  /* 
     o stat - outputs the current value of stat
              e.g. o hp (outputs the hp value)
     p stat operator value duration - creates a permanent effect that changes the stat by the operator and 
                                     value specified for duration amount of turns
                                      e.g. p hp + 10 5 (permanent effect that adds 10 to hp for 5 turns)
     t stat operator value duration lifetime - similar to permanent effect except temporary effects are
                                               removed after lifetime amount of turns
                                               e.g. t hp + 10 5 8 (adds 10 to hp for 5 turns lasts 8 turns)
     r - removes active permanent and temporary effects
     i - applies all active effects for one turn
     s stat value - sets stat to value. This should only be used before applying any effects.
                    e.g. s hp 20 (sets hp value to 20)
    
     e.g. s hp 20
          o hp -> 20
          t hp + 50 1 10
          p hp - 3 3
          i
          o hp -> 67
          r
          o hp -> 17
          i
          o hp -> 17
  */
  while (cin >> comm) {
    switch (comm) {
      case 'o':
        cin >> stat;
        cout << stat << ": " << lol.get(stat) << endl;
        break;
      case 'p':
        cin >> stat;
        cin >> comm;
        cin >> value;
        cin >> duration;
        lol.addEffect(new Permanent(stat, comm, value, duration));
        break;
      case 't':
        cin >> stat;
        cin >> comm;
        cin >> value;
        cin >> duration;
        cin >> life;
        lol.addEffect(new Temporary(stat, comm, value, duration, life));
        break;
      case 'r':
        lol.clearEffects();
        break;
      case 'i':
        lol.applyEffects();
        break;
      case 's':
        cin >> stat;
        cin >> value;
        lol.set(stat, value);
        break;
    }
  }
}
