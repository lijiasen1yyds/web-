#pragma once

#include <iostream>
namespace whms {
struct Type {
  friend std::ostream &operator<<(std::ostream &os, Type type);
};

template <typename _Tp>
concept STp = requires(_Tp a, _Tp b) {
  a.write(b);
  // decltype(b.get_data()) v{};
  // a.read(v);
};
} // namespace whms