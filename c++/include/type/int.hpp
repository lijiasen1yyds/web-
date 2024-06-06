#pragma once
#include "type.hpp"
namespace whms {
class Int : Type {
  int data_;

public:
  Int() = default;
  Int(int data) : data_(data) {}
  Int(Int &other) : data_(other.data_) {}

  friend std::ostream &operator<<(std::ostream &os, Int &int_) {
    os << int_.data_;
    return os;
  }

  friend std::istream &operator>>(std::istream &is, Int &int_) {
    is >> int_.data_;
    return is;
  }

  int get_data() { return data_; }

  void write(Int &other) { data_ = other.data_; }

  void write(const int other) { data_ = other; }

  void read(int &v) { v = data_; }

  // 特化时会尝试匹配所有下边函数，如果不自定义会编译错误
  void write(std::string &v) { throw std::runtime_error("Bind error"); }
  void write(double &v) { throw std::runtime_error("Bind error"); }
  void read(std::string &v) { throw std::runtime_error("Bind error"); }
  void read(double &v) { throw std::runtime_error("Bind error"); }
};
} // namespace whms