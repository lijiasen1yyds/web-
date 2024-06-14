#pragma once
#include "data/data.hpp"
#include "other/tuple.hpp"
#include "type/chars.hpp"
#include "type/double.hpp"
#include "type/int.hpp"
#include "type/type.hpp"

#include <boost/unordered/unordered_flat_map.hpp>
#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
namespace whms {
class Disk {
  std::filesystem::path path_;
  std::fstream fs_;
  uint i = 0;

public:
  Disk() = default;
  Disk(std::string path) : fs_(path, std::ios_base::in | std::ios_base::out) {
    if (!fs_) {
      std::fstream(path, std::ios_base::out);
      fs_.open(path, std::ios_base::in | std::ios_base::out);
    }
  }
  ~Disk() = default;

  void read_data(boost::unordered::unordered_flat_map<
                 uint, Tuple<Chars, Int, Int, Double, Double>> &data) {
    if (!fs_) {
      throw std::runtime_error(
          "The data file path is empty, pls open a data file\n");
    }
    fs_.seekg(0);
    Chars name;
    Int id, amount;
    Double opening_price, sell_price;
    while (!fs_.eof()) {
      fs_ >> name >> id >> amount >> opening_price >> sell_price;
      Tuple<Chars, Int, Int, Double, Double> t{name, id, amount, opening_price,
                                               sell_price};
      data.emplace(i++, t);
    }
    // 会读到最后一行，但是最后一行
    i--;
    data.erase(i);
  }

  void open_file(const std::string &path) {
    if (fs_.is_open()) {
      fs_.close();
    }
    fs_.open(path, std::ios_base::in | std::ios_base::out);
    // 如果文件不存在那么先创建
    if (!fs_) {
      std::fstream(path, std::ios_base::out);
      fs_.open(path, std::ios_base::in | std::ios_base::out);
    }
    path_ = path;
  }

  void write_file(boost::unordered::unordered_flat_map<
                  uint, Tuple<Chars, Int, Int, Double, Double>> &data) {
    if (!fs_) {
      open_file(path_.native());
    }
    if (fs_.is_open()) {
      fs_.seekg(0);
      for (auto &v : data) {
        fs_ << v.second << std::endl;
      }
    } else {
      throw std::runtime_error("File not open\n");
    }
  }
};
} // namespace whms
