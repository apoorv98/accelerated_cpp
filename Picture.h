#ifndef PICTURE_H_
#define PICTURE_H_

#include "Ptr.h"
#include <iostream>
#include <vector>

// private classes for use in implementation only
class Pic_base {};

class String_Pic : public Pic_base {};
class Frame_Pic : public Pic_base {};
class VCat_Pic : public Pic_base {};
class HCat_Pic : public Pic_base {};

// public interface class and operations
class Picture {
public:
  Picture(const std::vector<std::string> & = std::vector<std::string>());
  Picture frame(const Picture &);
  Picture hcat(const Picture &, const Picture &);
  Picture vcat(const Picture &, const Picture &);
  std::ostream &operator<<(std::ostream &, const Picture &);

private:
  Ptr<Pic_base> p;
};

#endif // PICTURE_H_
