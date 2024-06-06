#include "headfile.hpp"
#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace whms;
// template Tuple<Int, Double, Chars>;

void tuple_test() {
  std::cout << "TupleTest Begin:\n";
  Tuple<Int, Double, Chars> t{1214, 3.14159, std::string("A")};
  std::cout << t << std::endl;
  int a;
  double b;
  std::string c;
  t.read<int>(0, a);
  assert(a == 1214);
  t.read<double>(1, b);
  assert(b == 3.14159);
  t.read<std::string>(2, c);
  assert(c == std::string("A"));
  t.write(0, 1314);
  t.write(1, 1.41421);
  t.write(2, std::string("L"));
  t.read<int>(0, a);
  assert(a == 1314);
  t.read<double>(1, b);
  assert(b == 1.41421);
  t.read<std::string>(2, c);
  assert(c == std::string("L"));
  std::cout << t << std::endl;
  std::cout << "TupleTest Success!\n";
}

void disk_test() {
  std::cout << "DiskTest Begin:\n";
  std::string path = "test.txt";
  Disk disk{path};
  Tuple<Chars, Int, Int, Double, Double> t{std::string("AAA"), 1214, 3317,
                                           3.14159, 6.08};
  boost::unordered::unordered_flat_map<uint,
                                       Tuple<Chars, Int, Int, Double, Double>>
      data;
  data.try_emplace(0, t);
  disk.write_file(data);
  data.clear();
  disk.read_data(data);
  std::cout << data[0] << std::endl;
  t = data[0];
  int a;
  double b;
  std::string c;
  t.read<std::string>(0, c);
  assert(c == std::string("AAA"));
  t.read<int>(1, a);
  assert(a == 1214);
  t.read<int>(2, a);
  assert(a == 3317);
  t.read<double>(3, b);
  assert(b == 3.14159);
  t.read<double>(4, b);
  assert(b == 6.08);
  system("rm -rf ./test.txt");
  std::cout << "DiskTest Success!\n";
}

void bench_test() {}

int main() {
  tuple_test();
  disk_test();
}