#pragma once
#include "data/data.hpp"

#include <iostream>
namespace whms {
enum class Info { Name, Id, Amount, OpenPrice, SellPrice };
class Analyser {
  Data data_;

public:
  Analyser() : data_() {}
  ~Analyser() = default;

  // 显示所有商品信息
  void show_all_information() {
    std::cout << "ID                information\n";
    for (auto &v : data_.get_data()) {
      std::cout << v.first << ' ' << v.second << std::endl;
    }
    std::cout << "返回上一级..\n";
  }

  void update_information() {
    uint index;
    std::cout << "请输入你要更改的物品的索引：";
    std::cin >> index;
    auto &elem = data_.get_data()[index];
    std::cout << "输入你要执行的操作：\n1.入仓\n2.出仓\n3.更新信息\n";
    std::cin >> index; // 废物利用
    int num;
    switch (index) {
    case 1:
      elem.read(2, num);
      elem.write(2, num + 1);
      break;
    case 2:
      elem.read(2, num);
      elem.write(2, num - 1);
      break;
    case 3: {
      Chars name;
      Int id, amount;
      Double opening_price, sell_price;
      std::cout << "请依次输入 名称、商品ID、商品数量、进价、售价\n";
      std::cin >> name >> id >> amount >> opening_price >> sell_price;
      Tuple<Chars, Int, Int, Double, Double> update{name, id, amount,
                                                    opening_price, sell_price};
      elem = update;
    } break;
    default:
      std::cout << "输入操作错误\n";
    }
    std::cout << "返回上一级..\n";
  }

  void out_house() {
    std::cout << "请输入要移出仓库的货物的索引：";
    uint index;
    std::cin >> index;
    data_.get_data().erase(index);
    std::cout << "货物已移出\n";
    std::cout << "返回上一级..\n";
  }

  void in_house() {
    std::cout
        << "输入新进仓库的物品的信息（名称、商品ID、商品数量、进价、售价）\n";
    Chars name;
    Int id, amount;
    Double opening_price, sell_price;
    std::cout << "请依次输入 名称、商品ID、商品数量、进价、售价\n";
    std::cin >> name >> id >> amount >> opening_price >> sell_price;
    Tuple<Chars, Int, Int, Double, Double> t{name, id, amount, opening_price,
                                             sell_price};
    data_.get_data().try_emplace(data_.get_data().size(), t);
    std::cout << "货物已添加\n";
    std::cout << "返回上一级..\n";
  }

  void save_data() { data_.save(); }
};
} // namespace whms