![image](https://github.com/nmd29io/BTL_LTNC/assets/85045877/8a16f071-8458-4b9f-9874-d7f79c1145cd)

#  SNAKE -NMD-Edition
- Họ và tên Nguyễn Minh Đức
- Khóa K68 CN1 lớp B-C UET-VNU
- Mã sinh viên 23020049
- [Thử nghiệm game](https://youtu.be/aIwp53ujmKk)

# Giới thiệu game
Game **Snake** là một thể loại game hành động nơi người chơi điều khiển đầu của một đường đang phát triển, thường được tạo hình như một con rắn. Trong game người chơi phải điều khiểu đầu rắn. Khi bạn ăn được thức ăn rắn sẽ phát triển dài ra. Nếu, hoặc khi nào, con rắn va vào cạnh màn hình hoặc ăn phải chính mình thì trò chơi sẽ kết thúc.<br/>
Game được viết bằng C++ và thư viện SDL2

# Download 
[Window](https://github.com/nmd29io/BTL_LTNC/releases/download/master/BTL_Release.zip) Tải file giải nén và chạy file .exe (application)<br/>
Game đã được chạy thử trên vài máy Window 10,11 một vài máy không cài bất kì compiler hay IDE nào
# Nhiệm vụ
Điều khiển rắn ăn thức ăn phá kỉ lục, Tránh ăn các bức tường và cơ thể rắn
# Bắt đầu 
- Nhấn Start để bắt đầu


https://github.com/nmd29io/BTL_LTNC/assets/85045877/5b5814db-7cde-4da5-abf1-7968d10077d2


- Bạn có thể bắt đầu chơi luôn hoặc chuyển chế độ khác:
## Các phím tắt chức năng và điều khiển
- `W, A, S, D` hoặc `UP, LEFT, DOWN, RIGHT`: Điểu khiển con rắn
- `SPACE` hoặc ![Option](https://github.com/nmd29io/BTL_LTNC/assets/85045877/5b6cee90-d681-4363-b2aa-890d9839e6ad)
 : Tạm dừng trò chơi và mở OPTION chuyển chế độ
- `M` hoặc ![MusicNotes](https://github.com/nmd29io/BTL_LTNC/assets/85045877/b930ccc5-ad84-4330-84c2-10454042f0eb) ![SpeakerOn](https://github.com/nmd29io/BTL_LTNC/assets/85045877/2cf0990e-4445-4c5a-bdfc-cf1e3e427816): Tắt hoặc Bật âm thanh
- `R`: Chơi lại
## Các chế độ
![image](https://github.com/nmd29io/BTL_LTNC/assets/85045877/a219e974-f66a-4fbd-ae59-11687f8afff1)
- `Normal`: Chế độ bình thường không có gì khác biệt
- `Tele`: Xuất hiện 2 hoa quả, bạn sẽ dịch chuyển đến vị trí quả còn lại khi ăn một hoa quả <br/>



https://github.com/nmd29io/BTL_LTNC/assets/85045877/ca133744-799c-461f-9d90-0e8a00ffb3c3


- `Fly`: Các hoa quả sẽ di chuyển và nảy lại khi chạm tường hoặc cơ thể<br/>


https://github.com/nmd29io/BTL_LTNC/assets/85045877/b6b5134e-2ad9-4c06-8da0-728191d3a662


- `Wall`: Khi bạn ăn hoa quả các bước tường gẫu nhiên sẽ xuất hiện<br/>


https://github.com/nmd29io/BTL_LTNC/assets/85045877/7ab65480-c5fd-4ebe-a4f4-7a81d52f17d4


- **Lock**: Bạn phải nhặt chìa khóa để mở các hộp hoa quả bị khóa, nếu bạn ăn hộp chưa mở GAME OVER<br/>


https://github.com/nmd29io/BTL_LTNC/assets/85045877/dedbec48-3c9c-4a05-8f0d-3f969be1208d


# Mô tả mã nguồn
## Code
- main.cpp: khai báo các đồ họa, âm thanh và game loop
- sdl_setup.h: initialize vào  thư viện SDL
- global.h: khai báo các biến toàn 
- menu.h: bao gồm các hàm sử lý lưu điểm cao, render điểm và sử lý các sự kiện Menu Bắt đầu
- text.h: liên quan đến render chữ
- game.h: logic game
- ingame.h: sử lý sự kiện trong trò chơi, dùng các hàm của game.h

## Tham khảo 
- Tham khảo logic: [Youtube](https://www.youtube.com/watch?v=3kw1-dOikMA&t=508s&pp=ugMICgJ2aRABGAHKBQlzbmFrZSBzZGw%3D) [ChatGPT](https://chat.openai.com)
- Đồ họa icon sử dụng: [Google Snake Game](https://www.spriters-resource.com/browser_games/googlesnakegame/) [itch.io](https://itch.io)
- Music: [Head Empty](https://www.youtube.com/watch?v=1-Bgs27hB5k)
# Tổng kết
## Bài học
- Cải thiện kĩ năng lập trình
- Biết cách set up môi trường và sử dụng các thư viện ngoài(SDL2)
- Sử dụng thư viện SDL2.0, SDL2.0_image, SDL2.0_mixer, SDL2.0_ttf
- ... 
## Nhược điểm
- Chưa có AI và chế độ multiplayer
- Code chưa chuyên nghiệp, khó cải tiến
- Chưa thành thạo OOP
- Chưa biết áp dụng các design pattern
## Định hướng phát triển
- Thêm chế độ multiplayer
- Thêm bản đồ vô hạn và chơi online
- Học thêm OOP và design pattern
# Em xin chân thành cảm ơn 2 thầy lớp LTNC
- TS. Lê Đức Trọng
- CN. Trần Trường Thủy


