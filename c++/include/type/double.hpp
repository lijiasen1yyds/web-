#pragma once
#include "type.hpp"
namespace whms {
class Double : Type {
  double data_;

public:
  Double() = default;
  Double(double data) : data_(data) {}
  Double(Double &other) : data_(other.data_) {}

  friend std::ostream &operator<<(std::ostream &os, Double dou) {
    os << dou.data_;
    return os;
  }

  friend std::istream &operator>>(std::istream &is, Double &dou) {
    is >> dou.data_;
    return is;
  }
  double get_data() { return data_; }

  void write(Double &other) { data_ = other.data_; }

  void write(const double other) { data_ = other; }

  void read(double &v) { v = data_; }

  // 特化时会尝试匹配所有下边函数，如果不自定义会编译错误
  void write(int &v) { throw std::runtime_error("Bind error"); }
  void write(std::string &v) { throw std::runtime_error("Bind error"); }
  void read(int &v) { throw std::runtime_error("Bind error"); }
  void read(std::string &v) { throw std::runtime_error("Bind error"); }
};
} // namespace whms