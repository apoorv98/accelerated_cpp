#ifndef GRAD_H_
#define GRAD_H_

#include "Core.h"

class Grad : public Core {
public:
  Grad() : thesis(0) {}
  Grad(std::istream &is) { read(is); }
  double grade() const;
  std::istream &read(std::istream &);

protected:
  Grad *clone() const { return new Grad(*this); }

private:
  double thesis;
};

#endif // GRAD_H_
