# kobo_notify_project  

鍵を借りに行くまで工房が開いているか定かでないことが多いので、「ものつくり工房開けました」をLINEグループに自動通知するシステムを作成しました。  
  
## LINE notifyの使い方  

1. オンラインサービスの「LINE notify」に自分のLineIDでログインしてLine notifyのアクセストークンを発行しておく。  
2. 送りたいLINEグループにLINE notifyを招待しておく。  
3. ubuntuターミナルで  
` curl -X POST -H 'Authorization: Bearer アクセストークン' -F 'message=送りたいメッセージ' https://notify-api.line.me/api/notify `  
を実行するとメッセージをLINEグループに送ることができる。  
  
以上の手順は<https://qiita.com/takeshi_ok_desu/items/576a8226ba6584864d95>を参照。
  
  
## 実行手順  
  
1. 下の図の通りにプルアップ抵抗を挟んだ回路を作って適当な場所に設置。 
2. raspberry pi3の電源を入れると/etc/project.d/に置いてあるmonitor.shが自動実行され、照明が切り替わったときだけLINEを飛ばす。  
  
以上。 
   
## 回路  

準備中。少々お待ちください。  
  
## 備考  
  
- /etc/project.d/においてある実行ファイルのコピー元はraspberry pi内の~/monitor_project/に置いてあります。
- 現在、LINE notifyのトークンは丸橋のアカウントで作成済み。 
- CdSセンサの読み込みにはGPIO17を使用。 
- 監視用のraspberry piは現在、ものつくり工房玄関付近に設置中。  
- プログラムの稼働中はraspberry piに給電し続ける必要アリ(工房から帰る前〜工房に来るまで)。 
- 光センサの読み取りに問題が多発するなら、物理的なスイッチを使うかも。
