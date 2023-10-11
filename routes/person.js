const axios = require("axios");
const fs = require("fs");
const { spawn, exec } = require('child_process'); // child_process 모듈에서 exec 함수 가져오기

const image = fs.readFileSync("../public/images/pic01.jpg", {
    encoding: "base64"
});

axios({
    method: "POST",
    url: "https://detect.roboflow.com/person-wozrc/1",
    params: {
        api_key: "px1uTQC3WV6c9JsQUO4L",
        confidence: 0.2,
    },
    data: image,
    headers: {
        "Content-Type": "application/x-www-form-urlencoded"
    }
})
.then(function(response) {
    const robo_recog = response.data;
    console.log(response.data.predictions.length)
    console.log(robo_recog)
    // JSON 데이터를 문자열로 변환
    const jsonString = JSON.stringify(robo_recog, null, 2); // null, 2는 들여쓰기와 관련된 옵션입니다.

    // JSON 파일 쓰기
    fs.writeFile('data.json', jsonString, 'utf8', (err) => {
    if (err) {
        console.error('파일 쓰기 오류:', err);
        return;
    }
    console.log('JSON 파일이 성공적으로 쓰여졌습니다.');
    });
    // // Python 스크립트 실행
    // const pythonProcess = exec(`python image_proc.py`, (error, stdout, stderr) => {
    //     if (error) {
    //     console.error(`실행 중 오류 발생: ${error}`);
    //     return;
    //     }
    //     console.log(`Python 표준 출력:\n${stdout}`);
    //     console.error(`Python 표준 오류:\n${stderr}`);
    // });
    
    // Python 프로세스 종료 이벤트 처리
    pythonProcess.on('exit', (code) => {
        console.log(`Python 프로세스 종료 코드: ${code}`);
    });
})
.catch(function(error) {
    console.log(error.message);
});
