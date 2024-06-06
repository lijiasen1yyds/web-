#pragma once
#include "data/data.hpp"

#include <iostream>
namespace whms {
enum class Info { Name, Id, Amount, OpenPrice, SellPrice };
class Analyser {
  Data data_;

public:
  // 显示所有商品信息
  void show_all_information() {
    std::cout << "ID                information\n";
    for (auto &v : data_.get_data()) {
      std::cout << v.first << ' ' << v.second << std::endl;
    }
    std::cout << "Show Information Done!\n";
  }

  void update_information() {}

  void out_house() {}

  void in_house() {}
};
} // namespace whms