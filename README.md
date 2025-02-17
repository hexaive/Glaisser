
# 🚨 2023_Geekble_Project-Glaisser

> ***2023년 미래산업과학고등학교 메이커창작과 Geekble 프로젝트 - Portal 게임 시리즈의 시즌 2 보스 Glados를 이용한 학교 경비 로봇***

<video src="https://github.com/hyun0810d/2023_Geekble_Project-Glaisser/assets/84117112/fdaa14c3-3bab-4185-89e1-f17258067645"></video>

## 🎞 Product Video
🔗 [Watch here](https://youtube.com/shorts/zjXd_HjklBY?feature=share) 

## ⚡ Team
**미래산업과학고 메이커창작과 5인 X Geekble 잭키(feat. 나모, 수드래곤) / PD: 모루** ⚗

## 🛠️ Maker
김강현(AI & Web Dev), 조윤혁(Leader & Electronic), 송승현(Electronic), 장한수(Engineering), 김선우(Engineering) 

## 📅 Production Period
⏳ 2023.9 ~ 2023.10

## 📂 Engineering Files
📁 None

<br>

## 📺 Youtube Upload Date
📆 2023.11.4

## 🎥 Youtube Link
🎞 [https://www.youtube.com/watch?v=lbPWybNbxP8](https://www.youtube.com/watch?v=lbPWybNbxP8)

## 🌐 WEB
🌐 [www.Glaisser.com🔗](www.Glaisser.com) (단, 현재는 운영 종료)

---

### 🏆 프로젝트 성과
- ✅ **미래산업과학고 메이커창자과 대표 작품** 🎓
- ✅ **2023 Seoul Maker Fair & Science Festival 등 다양한 전시회 참여 ** 💡
- ✅ **첫 웹 개발 성공(개인)** 🎯
  
---

## 💡 Software 및 기술 설명

> **웹을 통한 글라도스 제어와 인공지능을 사용하여 사람 인식을 하여 경비 로봇을 만들고 이를 웹페이지를 통해 경비 결과를 보여준다.** 👀

### 🤖 [AI]

**Roboflow를 사용하여 데이터를 수집하고 사람을 라벨링하여 학습시켰습니다.** 📊

1. **데이터 수집** 📸
   - 사람을 직접 촬영 및 Roboflow에서 지원하는 Public 데이터를 가져와 데이터를 수집함. 🌙
   - 어두운 환경에서도 사람을 인식하기 위해 어두운 환경을 조성하여 촬영 및 데이터 수집 🔦.

2. **데이터 라벨링** 📝
   - 이렇게 수집한 데이터에 바운더리 박스를 쳐 라벨링을 진행함. ✍️
   - 이를 학습시켜 사람 인식 인공지능을 제작함. 💡

### 🌐 [WEB]

1. **웹서버 구축 및 도메인 연결** 🔗
   - **AWS EC2 서비스를 통해 웹서버를 호스팅하고 외부에서 접속할 수 있도록 하였음.** ☁️
   - 호스팅한 서비스에 도메인을 연결하여 브라우저 상에서 주소를 입력해 접속할 수 있도록 함. 🌍
     - [www.po-glos.com](www.po-glos.com) 🌐
     - www.glaisser.com
   - **웹서버 구축을 위해 Node.js의 Express.js를 사용하여 기본적인 웹서버의 뼈대를 구축하였음.** 🖥️

2. **웹페이지 및 기능 구현** 📑

**[웹에서 구현한 기능]** ⚙️
   - 경비를 시작하고 실시간으로 로봇이 촬영한 사진을 반별로 웹페이지 상에서 볼 수 있도록 함. 📸
   - 경비를 마친 후 과거의 경비 기록도 웹페이지에서 확인 가능 (history 기능 구현). 📜
   - HTML, CSS를 통해 웹페이지 UI를 구현함. 🎨
   - **동적 웹페이지를 이해하고 Node.js를 통해 동적 웹페이지를 구현함.** 🔄
     - 동적 웹페이지란 서버에서 저장된 HTML 파일이 그대로 브라우저에 나오는 것이 아니라, 동적으로 요청 및 조건에 따라 다른 웹페이지가 만들어지는 웹페이지. ⚙️

3. **로봇(Arduino)과 웹서버의 통신** 🔌
   - 로봇과 웹서버 간의 통신을 위해 중간 매체인 노트북을 사용하여 Socket 통신을 구현함. 🔐
   - 이미지를 주고받기 위해 SCP 통신을 사용함. 📤

4. **이미지 및 데이터 관리** 💾
   - 실시간으로 받은 이미지를 웹페이지에 띄우기 위해 Polling 기술을 사용함. 🔄
     - Polling이란 클라이언트가 데이터나 특정 조건의 업데이트를 반복적으로 확인하는 기술로, 주기적으로 서버에 요청을 보내 정보를 갱신함. 🕹️
   - 이미지는 JavaScript의 filesystem 라이브러리와 JSON 파일을 이용해 저장하고 관리함. 🗃️

5. **통신 방법** 📡
   - **중간매체 (WEB)** 
     - 웹에서 로봇을 제어하기 위해 Socket 통신을 사용함. 🔌
     - 중간매체인 노트북에 Socket 서버를 구축하여 웹서버와 로봇을 연결. 🔗
   - **로봇(Arduino) - 중간매체** 
     - Python의 pyserial을 사용한 Serial 통신. 📡
     - 웹에서 받은 신호를 변환하여 아두이노로 보내줌. 🔄

6. **기록 관리** 📚
   - 경비 후 얻은 데이터를 저장하고, 웹페이지에서 조회할 수 있도록 하여 기록을 관리함. 🗂️
   - 이미지는 filesystem 라이브러리를 사용하여 불러와 보여줌. 📂

---

**PS**: 이렇게 만든 웹페이지를 공개하고 사람들이 접속할 수 있도록 하여 Google Analytics를 사용해 방문률을 분석한 결과, 약 150~200명이 방문한 것을 확인. 📊 이를 통해 웹서버 관리를 조금 더 이해하고 연습할 기회를 가짐. 🎯
