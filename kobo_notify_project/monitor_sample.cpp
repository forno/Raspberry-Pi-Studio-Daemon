#include <iostream>
#include <cstdlib> //system関数用
#include <wiringPi.h>

constexpr int get_pin = 17;

int main(){
  if (wiringPiSetupGpio()) return 1;

  pinMode(get_pin, INPUT);
  auto last = digitalRead(get_pin);

  while (true) {
    auto get = digitalRead(get_pin);
    sleep(1);

    if (get == last) continue;
    //前回値と変わってないならループ先頭へ、変わったならその時の前回値で分岐
    //プルアップ抵抗を使っているためOPENとCLOSEが逆転している
    if (last == LOW) {
      std::system("curl -X POST -H 'Authorization: Bearer **************** 'message=MONOTSUKURI workshop has been CLOSED.' https://notify-api.line.me/api/notify");
    } else {   
      std::system("curl -X POST -H 'Authorization: Bearer **************** 'message=MONOTSUKURI workshop has been OPENED.' https://notify-api.line.me/api/notify");
    }

    last = get;
  }

  return 0;
}
