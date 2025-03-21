# 🚨 2023 Geekble Project: Glaisser - 학교 경비 로봇 🤖

미래산업과학고등학교 메이커창작과 Geekble 프로젝트, Portal 게임 시리즈의 Glados를 모티브로 한 학교 경비 로봇 "Glaisser"입니다.

<p align="center">
  <img src="https://github.com/hyun0810d/2023_Geekble_Project-Glaisser/assets/84117112/fdaa14c3-3bab-4185-89e1-f17258067645" alt="Glaisser Robot Demo" width="600">
</p>

## 🎞 Product Video

🔗 [Watch here](https://youtube.com/shorts/zjXd_HjklBY?feature=share)

## ✨ Key Features

*   **AI 기반 사람 인식:** Roboflow를 활용한 AI 모델로 사람을 정확하게 식별합니다.
*   **웹 기반 제어 및 모니터링:** 웹 인터페이스를 통해 Glaisser를 원격으로 제어하고 실시간 경비 상황을 확인할 수 있습니다.
*   **과거 경비 기록 조회:** 경비 이력을 웹페이지에서 확인하여 효율적인 경비 관리를 지원합니다.

## 🧑‍🤝‍🧑 Team

미래산업과학고 메이커창작과 5인 X Geekble 잭키(feat. 나모, 수드래곤) / PD: 모루 ⚗

*   **Maker:** 김강현(AI & Web Dev), 조윤혁(Leader & Electronic), 송승현(Electronic), 장한수(Engineering), 김선우(Engineering)

## 📅 Production Period

⏳ 2023.9 ~ 2023.10

## 📂 Engineering Files

📁 None

## 📺 Youtube Upload Date

📆 2023.11.4

## 🎥 Youtube Link

🎞 [https://www.youtube.com/watch?v=lbPWybNbxP8](https://www.youtube.com/watch?v=lbPWybNbxP8)

## 🌐 Web (운영 종료)

🌐 [www.Glaisser.com](www.Glaisser.com) (현재는 운영 종료)

---

### 🏆 프로젝트 성과

*   ✅ **미래산업과학고 메이커창자과 대표 작품** 🎓
*   ✅ **2023 Seoul Maker Fair & Science Festival 등 다양한 전시회 참여** 💡
*   ✅ **첫 웹 개발 성공(개인)** 🎯

---

## 💡 Software 및 기술 설명

> **웹을 통한 글라도스 제어, 인공지능을 활용한 사람 인식, 그리고 웹페이지를 통한 경비 결과 시각화로 완성된 학교 경비 로봇** 👀

### 🤖 AI: Roboflow 기반 사람 인식 시스템

Roboflow를 사용하여 데이터를 수집 및 라벨링하여 학습시킨 인공지능 모델은 Glaisser의 핵심 기능입니다. 📊

1.  **데이터 수집** 📸

    *   직접 촬영한 이미지와 Roboflow의 Public 데이터를 활용하여 데이터셋을 구축했습니다. 🌙
    *   특히, 어두운 환경에서의 인식률 향상을 위해 어두운 환경에서 촬영한 데이터도 포함했습니다. 🔦
2.  **데이터 라벨링** 📝

    *   수집된 데이터에 바운더리 박스를 사용하여 사람 영역을 라벨링했습니다. ✍️
    *   이 과정을 통해 학습된 인공지능은 사람을 정확하게 인식합니다. 💡

### 🌐 Web: 웹 기반 제어 및 모니터링 시스템

웹 기술을 활용하여 Glaisser를 원격으로 제어하고, 경비 상황을 실시간으로 모니터링할 수 있습니다. 💻

1.  **웹서버 구축 및 도메인 연결** 🔗

    *   **AWS EC2 서비스를 통해 웹서버를 호스팅하고 외부에서 접속 가능하도록 설정했습니다.** ☁️
    *   호스팅된 서비스에 도메인을 연결하여 브라우저에서 쉽게 접근할 수 있도록 했습니다. 🌍

        *   [www.po-glos.com](www.po-glos.com) 🌐
        *   www.glaisser.com
    *   **Node.js의 Express.js를 사용하여 웹서버의 기본적인 구조를 구축했습니다.** 🖥️
2.  **웹페이지 및 기능 구현** 📑

    **[웹에서 구현한 기능]** ⚙️

    *   실시간으로 로봇이 촬영한 사진을 반별로 웹페이지에서 확인할 수 있도록 했습니다. 📸
    *   경비 완료 후에는 과거 경비 기록을 웹페이지에서 조회할 수 있는 History 기능을 구현했습니다. 📜
    *   HTML, CSS를 사용하여 직관적이고 사용하기 쉬운 웹페이지 UI를 디자인했습니다. 🎨
    *   **동적 웹페이지를 구현하여 사용자 인터랙션과 실시간 데이터 업데이트를 가능하게 했습니다.** 🔄

        *   동적 웹페이지는 서버에서 동적으로 생성되는 페이지로, 사용자 요청 및 조건에 따라 내용이 변경됩니다. ⚙️
3.  **로봇(Arduino)과 웹서버의 통신** 🔌

    *   로봇과 웹서버 간의 통신을 위해 중간 매체(노트북)를 사용하여 Socket 통신을 구현했습니다. 🔐
    *   이미지 전송을 위해 SCP 통신을 사용했습니다. 📤
4.  **이미지 및 데이터 관리** 💾

    *   실시간으로 수신되는 이미지를 웹페이지에 표시하기 위해 Polling 기술을 사용했습니다. 🔄

        *   Polling은 클라이언트가 서버에 주기적으로 요청을 보내 데이터를 갱신하는 기술입니다. 🕹️
    *   이미지는 JavaScript의 filesystem 라이브러리와 JSON 파일을 사용하여 저장하고 관리했습니다. 🗃️
5.  **통신 방법** 📡

    *   **중간매체 (WEB)**

        *   웹에서 로봇을 제어하기 위해 Socket 통신을 사용했습니다. 🔌
        *   중간 매체인 노트북에 Socket 서버를 구축하여 웹서버와 로봇을 연결했습니다. 🔗
    *   **로봇(Arduino) - 중간매체**

        *   Python의 pyserial을 사용한 Serial 통신을 사용했습니다. 📡
        *   웹에서 받은 신호를 변환하여 아두이노로 전송했습니다. 🔄
6.  **기록 관리** 📚

    *   경비 후 얻은 데이터를 저장하고 웹페이지에서 조회할 수 있도록 하여 기록을 관리했습니다. 🗂️
    *   이미지는 filesystem 라이브러리를 사용하여 불러와 표시했습니다. 📂

---

**PS**: 웹페이지 공개 후 Google Analytics를 사용하여 방문자 수를 분석한 결과, 약 150~200명이 방문한 것을 확인했습니다. 📊 이를 통해 웹서버 관리에 대한 이해를 높이고 경험을 쌓을 수 있었습니다. 🎯
