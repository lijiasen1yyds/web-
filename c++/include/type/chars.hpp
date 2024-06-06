#pragma once
#include "type.hpp"
#include <stdexcept>
#include <string>
namespace whms {
class Chars : Type {
  std::string data_;

public:
  Chars() = default;
  Chars(const std::string data) : data_(data) {}
  Chars(Chars &other) : data_(other.data_) {}

  friend std::ostream &operator<<(std::ostream &os, Chars chars) {
    os << chars.data_;
    return os;
  }

  friend std::istream &operator>>(std::istream &is, Chars &chars) {
    is >> chars.data_;
    return is;
  }

  std::string get_data() { return data_; }

  void write(Chars &other) { data_ = other.data_; }

  void write(const std::string other) { data_ = other; }

  void read(std::string &v) { v = data_; }

  // 特化时会尝试匹配所有下边函数，如果不自定义会编译错误
  void write(double &v) { throw std::runtime_error("Bind error"); }
  void write(int &v) { throw std::runtime_error("Bind error"); }
  void read(double &v) { throw std::runtime_error("Bind error"); }
  void read(int &v) { throw std::runtime_error("Bind error"); }
};
} // namespace whms