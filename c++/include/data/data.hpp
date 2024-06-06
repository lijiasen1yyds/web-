#pragma once
#include "disk/disk.hpp"
#include "other/tuple.hpp"
#include "type/chars.hpp"
#include "type/double.hpp"
#include "type/int.hpp"
#include "type/type.hpp"

#include <boost/unordered/unordered_flat_map.hpp>
#include <string>
namespace whms {
class Data {
  // 仓库数据有 商品名，商品号，商品数量，商品进价，商品售价
  boost::unordered::unordered_flat_map<uint,
                                       Tuple<Chars, Int, Int, Double, Double>>
      data_;
  Disk disk_;

public:
  Data() : disk_() {
    std::string path = "data.dat";
    disk_.open_file(path);
    disk_.read_data(data_);
  }

  boost::unordered::unordered_flat_map<uint,
                                       Tuple<Chars, Int, Int, Double, Double>> &
  get_data() {
    return data_;
  }
};
} // namespace whms