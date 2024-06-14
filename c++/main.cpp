#include "include/headfile.hpp"
#include <boost/asio.hpp>
#include <iostream>

namespace asio = boost::asio;

void print_ui();
void start_sock();
void start() {
  whms::Analyser analyser;
  while (true) {
    int choice;
    std::cin >> choice;
    switch (choice) {
    case 1:
      analyser.update_information();
      break;
    case 2:
      analyser.in_house();
      break;
    case 3:
      analyser.out_house();
      break;
    case 4:
      analyser.show_all_information();
      break;
    case 5:
      analyser.save_data();
      return;
    default:
      std::cout << "输入错误\n";
    }
  };
}

int main(int argc, char **argv) {
  print_ui();
  start();
  std::cout << "bye~\n";
  return 0;
}

void print_ui() {
  std::cout << "===================================================\n"
            << "|                                                 |\n"
            << "|                 超市仓库管理系统                |\n"
            << "|                                                 |\n"
            << "|                 1.更新货物信息                  |\n"
            << "|                 2.新货物入库                    |\n"
            << "|                 3.货物移出仓库                  |\n"
            << "|                 4.显示所有货物信息              |\n"
            << "|                 5.退出系统                      |\n"
            << "|                                                 |\n"
            << "===================================================\n";
}