# 2023_Geekble_Project-Glaisser
2023년 미래산업과학고등학교 메이커창작과 Geekble 프로젝트 - Portal 게임 시리즈의 시즌 2 보스 Glados를 이용한 학교 경비 로봇<br>
<video src="https://github.com/hyun0810d/2023_Geekble_Project-Glaisser/assets/84117112/fdaa14c3-3bab-4185-89e1-f17258067645"></video>
Date: 2023.8.25 ~ 2023.10.25<br>
Youtube Upload Date: 2023.11.4<br>
Youtube Link: [https://www.youtube.com/watch?v=lbPWybNbxP8]<br>
WEB: [www.Glaisser.com]

<!-----



Conversion time: 0.327 seconds.


Using this Markdown file:

1. Paste this output into your source file.
2. See the notes and action items below regarding this conversion run.
3. Check the rendered output (headings, lists, code blocks, tables) for proper
   formatting and use a linkchecker before you publish this page.

Conversion notes:

* Docs to Markdown version 1.0β35
* Thu Jan 11 2024 04:07:34 GMT-0800 (PST)
* Source doc: [2023 Geekble Project] Software 설명서
----->


<h1>[2023 Geekble Project] Software 설명서</h1>

**웹을 통한 글라도스 제어와 인공지능을 사용하여 사람인식을 하여 경비로봇을 만들고 이를 웹페이지를 통해 경비 결과를 보여준다.**

**[AI]**

**Roboflow를 사용하여 데이터를 수집하고 사람을 라벨링하여 학습시켰습니다.**

**1.데이터 수집**



* 사람을 직접 촬영 및 Roboflow에서 지원하는 Public데이터를 가져와 데이터를 수집함.
* 어두운 환경에서도 사람을 인식하기 위하여 어두운 환경을 조성하여 직접 촬영을 하여 데이터를 일부 수집하였음.

**2.데이터 라벨링**



* 이렇게 수집한 데이터에 직접 바운더리 박스를 쳐 라벨링을 진행함.

이렇게 데이터를 수집하여 라벨링한 데이터를 학습시켜 사람 인식 인공지능을 제작하였음.

**[WEB]**

**1. 웹서버 구축 및 도메인 연결**



* **AWS EC2 서비스를 통하여 웹서버를 호스팅하여 웹페이지에 외부에서도 접속할 수 있도록 하였다.**
* 호스팅한 서비스에 <span style="text-decoration:underline;">도메인을 연결하여 브라우저 상에서 주소를 입력하여 접속 할 수 있도록 하였다.</span>
    * [www.po-glos.com](www.po-glos.com)
    * www.glaisser.com
* **웹서버 구축을 위하여 javascript의 프레임워크인 Node.js의 Express.js를 사용하여 기본적인 웹서버의 뼈대를 구축하였습니다.**

**2. 웹페이지 및 기능 구현**

**[웹에서 구현한 기능]**



* 경비를 시작하고 실시간으로 로봇이 촬영한 사진을 반별로 웹페이지 상에서 볼 수 있도록 함.
* 이렇게 한번 경비를 돌고나면 이는 기록으로 남아 예전에 돌았던 경비들과 함께 웹페이지상에서 볼 수 있음(history  기능 구현)
* HTML, CSS를 통해 웹페이지의 UI를 구현함
* **동적 웹페이지를 이해하고 Node.js를 통해 동적 웹페이지를 구현해봄.**
    * 여기서 동적 웹페이지란….서버에 저장된 HTML파일이 그대로 브라우저에 나오는 것이 아닌 동적으로 요청 및 조건에 따라 다른 웹페이지가 만들어지는 웹페이지
* 로봇(Arduino)과 웹서버가 통신하기 위하여 로봇에 중간 통신 매체인 노트북을 둠.
1. **경비를 시작하고 실시간으로 로봇이 촬영한 사진을 반별로 웹페이지 상에서 볼 수 있도록 함.**
* 로봇이 복도를 돌아다니면서 반별로 사진을 찍어서 웹서버에 보내 웹페이지에 실시간으로 띄워줌.
* <span style="text-decoration:underline;">카메라 제어는 python의 opencv를 사용하여 웹캠을 제어하였습니다.</span>
* **이미지를 웹페이지에 실시간으로 띄우기 위해서 각 이미지가 띄워질 요소마다 Polling기술을 적용하였습니다.**
    * 여기서 Polling이란?....클라이언트 측에서 데이터 또는 특정 조건의 업데이트나 변경을 반복적으로 확인하는 기술입니다. 이는 주기적으로 서버에 요청을 보내 새로운 정보를 가져와 사용자 인터페이스를 업데이트하는 것을 포함합니다. 
* 이렇게 받은 이미지를 저장하고 관리하기 위해 javascript의 filesystem라이브러리와 json파일을 이용하여 데이터화하고 관리함.

**[통신 방법]**



1. **중간매체 - WEB**
    1. **웹에서 로봇을 제어하기 위해서는 서로 통신이 필요한데 여기서 사용한 통신  방법은 python의 Socket통신을 사용하였음**
    2. 중간매체인 노트북에 socket 서버를 구축하여 웹서버와 로봇을 이어주도록 함.
    3. **이미지를 주고 받기 위해서 SCP통신을 사용하였음.**
2. **로봇(Arduino) - 중간매체**
    4. <span style="text-decoration:underline;">Python의 pyserial을 사용한 Serial 통신</span>
    5. Web에서 받은 신호를 변환하여 아두이노로 보내줌.
2. **이렇게 한번 경비를 돌고나면 이는 기록으로 남아 예전에 돌았던 경비들과 함께 웹페이지상에서 볼 수 있음(history  기능 구현)**
* 이렇게 위에서 경비로 얻은 데이터를 후에도 볼 수 있도록 이미지 정보들을 저장해 두고 해당 기록을 조회하면 웹페이지 상에서도 볼 수 있도록 함.
* 이미지와 데이터를 관리하기 위해 Database를 구축하고 웹서버와 연결해서 관리함.
* 해당 기록을 조회하면 filesystem라이브러리를 사용하여 이미지들을 불러옴.

ps. 이렇게 만든 웹페이지를 공개하고 사람들이 접속할 수 있도록 하여 google analytics를 사용하여 방문률을 분석 해본 결과 꽤 많은 사람(150~200명)이 온 것을 확인할 수 있었고 이렇게 공개함으로써 웹서버 관리를 조금 더 이해하고 연습해볼 기회가 되었음.
