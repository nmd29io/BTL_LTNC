![image](https://github.com/nmd29io/BTL_LTNC/assets/85045877/8a16f071-8458-4b9f-9874-d7f79c1145cd)

# SNAKE-nmd29io-Edition
- Học sinh **Nguyễn Minh Đức** K68CB-UET
- Mã sinh viên **23020049**
- Lơp **INT2215_50**
- [**`Video thử nghiệm game`**](https://youtu.be/1uaxNIu2VxA)

# Giới thiệu game
- _Rắn săn mồi_ là một thể loại game hành động nơi người chơi điều khiển đầu của một đường đang phát triển, thường được tạo hình như một con rắn. Trong game người chơi phải điều khiểu đầu rắn. Khi bạn ăn được thức ăn rắn sẽ phát triển dài ra. Nếu, hoặc khi nào, con rắn va vào cạnh màn hình hoặc ăn phải chính mình thì trò chơi sẽ kết thúc.<br/>
- Game được viết bằng C++ và sử dụng thư viện SDL2

# Download 
 [**`Window`**](https://github.com/nmd29io/BTL_LTNC/releases/download/master/BTL_Release.zip)<br/>
 _Tải_, _giải nén_ và _chạy_ ![image](https://github.com/nmd29io/BTL_LTNC/assets/85045877/23a95a07-d94f-4fd4-9178-d61f0d443a4f)<br/>
Game đã được chạy thử trên vài máy Window 10,11 không cần compiler, IDE và **`không có virus`**<br/>
![image](https://github.com/nmd29io/BTL_LTNC/assets/85045877/92066254-e2c6-4035-ae04-79f76b8397d9)

# Cách chơi 
- Nhấn `Start` để bắt đầu, `Exit` để thoát


https://github.com/nmd29io/BTL_LTNC/assets/85045877/5b5814db-7cde-4da5-abf1-7968d10077d2


- Bạn có thể bắt đầu chơi luôn chế độ bình thường hoặc chuyển [`chế độ khác`](#các-chế-độ) bằng các nhấn `SPACE`
## Các phím tắt chức năng và điều khiển
- `W, A, S, D` hoặc `UP, LEFT, DOWN, RIGHT`: Điểu khiển con rắn
- `SPACE` hoặc ![Option](https://github.com/nmd29io/BTL_LTNC/assets/85045877/5b6cee90-d681-4363-b2aa-890d9839e6ad)
 : Tạm dừng trò chơi và mở `option` chuyển chế độ
- `M` hoặc ![MusicNotes](https://github.com/nmd29io/BTL_LTNC/assets/85045877/b930ccc5-ad84-4330-84c2-10454042f0eb) ![SpeakerOn](https://github.com/nmd29io/BTL_LTNC/assets/85045877/2cf0990e-4445-4c5a-bdfc-cf1e3e427816): Tắt hoặc Bật music, sound effect
- `R`: Chơi lại
## Nhiệm vụ
- Điều khiển rắn ăn thức ăn phá kỉ lục, Tránh ăn các bức tường và cơ thể rắn
- Điểm hiện tại:![Sprite-0001](https://github.com/nmd29io/BTL_LTNC/assets/85045877/399e1718-f1d2-4e2d-a03e-d42f2e09e1ed)


- Điểm cao:![Trophy](https://github.com/nmd29io/BTL_LTNC/assets/85045877/1b56d469-eb64-42d8-9706-2ef6d1eb9c65)


## Các chế độ
![image](https://github.com/nmd29io/BTL_LTNC/assets/85045877/a219e974-f66a-4fbd-ae59-11687f8afff1)
- `Normal`: Chế độ bình thường không có gì khác biệt
- `Tele`: Xuất hiện 2 hoa quả, bạn sẽ dịch chuyển đến vị trí quả còn lại khi ăn một hoa quả <br/>



https://github.com/nmd29io/BTL_LTNC/assets/85045877/ca133744-799c-461f-9d90-0e8a00ffb3c3


- `Fly`: Các hoa quả sẽ di chuyển và nảy lại khi chạm tường hoặc cơ thể<br/>


https://github.com/nmd29io/BTL_LTNC/assets/85045877/b6b5134e-2ad9-4c06-8da0-728191d3a662


- `Wall`: Khi bạn ăn hoa quả các bước tường gẫu nhiên sẽ xuất hiện<br/>


https://github.com/nmd29io/BTL_LTNC/assets/85045877/7ab65480-c5fd-4ebe-a4f4-7a81d52f17d4


- `Lock`: Bạn phải nhặt chìa khóa để mở các hộp hoa quả bị khóa, nếu bạn ăn hộp chưa mở GAME OVER<br/>


https://github.com/nmd29io/BTL_LTNC/assets/85045877/dedbec48-3c9c-4a05-8f0d-3f969be1208d


# Mô tả mã nguồn
## Code
- [`main.cpp`](https://github.com/nmd29io/BTL_LTNC/blob/12ebc93007065fa301e91ff0ae49435877f30447/Snake/main.cpp): khai báo các biến đồ họa, âm thanh, FPS và game loop
- [`sdl_setup.h`](https://github.com/nmd29io/BTL_LTNC/blob/master/Snake/sdl_setup.h): dùng để Init và Release thư viện SDL
- [`global.h`](https://github.com/nmd29io/BTL_LTNC/blob/master/Snake/global.h): khai báo các biến toàn 
- [`menu.h`](https://github.com/nmd29io/BTL_LTNC/blob/master/Snake/menu.h): bao gồm các hàm sử lý lưu điểm cao, render điểm và sử lý các sự kiện Menu Bắt đầu
- [`text.h`](https://github.com/nmd29io/BTL_LTNC/blob/master/Snake/text.h): bao gồm các hàm liên quan đến render chữ
- [`game.h`](https://github.com/nmd29io/BTL_LTNC/blob/master/Snake/game.h): bao gồm các hàm liên quan đến logic game
- [`ingame.h`](https://github.com/nmd29io/BTL_LTNC/blob/master/Snake/ingame.h): sử lý sự kiện trong trò chơi, dùng các hàm của game.h

## Nguồn tham khảo 
- Các kiến thức học trên lớp LTNC
- Tham khảo, học tập logic, mã nguồn: [Youtube(Snake in 130 lines)](https://www.youtube.com/watch?v=3kw1-dOikMA&t=508s&pp=ugMICgJ2aRABGAHKBQlzbmFrZSBzZGw%3D), [Google](https://www.google.com/) và [ChatGPT](https://chat.openai.com)
- Đồ họa icon sử dụng: [game rắn săn mồi của Google](https://www.spriters-resource.com/browser_games/googlesnakegame/) và [itch.io](https://itch.io)
- Tham khảo các chế độ trong [game rắn săn mồi của Google](https://g.co/kgs/V8a3RU2)
- Music: [Head Empty](https://www.youtube.com/watch?v=1-Bgs27hB5k)
# Tổng kết
## Bài học
- Cải thiện kĩ năng lập trình
- Biết cách set up môi trường và sử dụng các thư viện ngoài(SDL2)
- Sử dụng thư viện SDL2.0, SDL2.0_image, SDL2.0_mixer, SDL2.0_ttf
- Học được thêm nhiều thuật toán hay và tự mình cài đặt vào chương trình.
- Học được kĩ thuật làm game cơ bản.
- Rèn tính kiên trì, tìm và sửa lỗi
- ... 
## Nhược điểm
- Game chưa có AI và chế độ multiplayer
- Code chưa chuyên nghiệp, khó cải tiến
- Chưa tiếp thu kĩ thuật lập trình hướng đối tượng
- Chưa biết áp dụng các design pattern
## Định hướng phát triển
- Thêm chế độ multiplayer
- Thêm bản đồ vô hạn và chơi online
- Học thêm OOP và design pattern
# Em xin chân thành cảm ơn 2 thầy lớp LTNC
- `TS. Lê Đức Trọng`
- `CN. Trần Trường Thủy`


