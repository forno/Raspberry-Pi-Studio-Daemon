# kobo_notify_project  

鍵を借りに行くまで工房が開いているか定かでないことが多いので、「ものつくり工房開けました」をLINEグループに自動通知するシステムを作成した。  
  
## LINE notifyの使い方  

1. オンラインサービスの「LINE notify」に自分のLineIDでログインしてLine notifyのアクセストークンを発行しておく。  
2. 送りたいLINEグループにLINE notifyを招待しておく。  
3. ubuntuターミナルで  
` curl -X POST -H 'Authorization: Bearer アクセストークン' -F 'message=送りたいメッセージ' https://notify-api.line.me/api/notify `  
を実行するとメッセージをLINEグループに送ることができる。  
  
以上の手順は<https://qiita.com/takeshi_ok_desu/items/576a8226ba6584864d95>を参照。
  
  
## 実行手順  
  
0. 下の図の通りにプルアップ抵抗を挟んだ回路を作る。
1. raspberry pi3内(microSDに何かマークつけときます)を立ち上げ、  
`cd monitor_project'  
2. `g++ -std=c++0x monitor.cpp -lwiringPi`  
3. `sudo ./a.out`  
あとは照明が切り替わった時だけ自動でメッセージが飛ぶ。  

メッセージの送信には前述のオンラインサービスLINE notifyを利用(現在は丸橋が通知用トークン作ってます)。  

## 回路  

準備中  
  
## 備考  
  
- 現在、昼間でも照明を誤認識しない設置場所を探し中。。。  
- プログラムの稼働中はraspberry piに給電し続ける必要アリ(工房から帰る前〜工房に来るまで)。 
- 光センサの読み取りに問題が多発するなら、物理的なスイッチを使うかも。
