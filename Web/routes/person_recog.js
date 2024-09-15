var express = require('express');
var router = express.Router();
const axios = require("axios");
const fs = require("fs");
const { spawn, exec } = require('child_process');

/* GET users listing. */
router.get('/:id/:imagename', function(req, res, next) {
    const imagename = req.params.imagename;
    const id = req.params.id;
    console.log(imagename,id);
    const image = fs.readFileSync(`public/data/id_${id}/${imagename}.JPG`, {
        encoding: "base64"
    });
    
    axios({
        method: "POST",
        url: "https://detect.roboflow.com/person-wozrc/1",
        params: {
            api_key: "px1uTQC3WV6c9JsQUO4L"
        },
        data: image,
        headers: {
            "Content-Type": "application/x-www-form-urlencoded"
        }
    })
    .then(function(response) {
        res_message=""
        console.log(response.data);
        if (response.data.predictions.length>0){
            recog_message="recog_true"
        }
        else if (response.data.predictions.length==0){
            recog_message="recog_false"
        }
        const jsonContent = JSON.stringify(response.data, null, 2); // JSON 데이터를 문자열로 변환하고 들여쓰기를 추가
        fs.writeFile('data.json', jsonContent, (err) => {
        if (err) {
            console.error('파일 쓰기 오류:', err);
        } else {   
            console.log('파일이 성공적으로 쓰여졌습니다.');
            const pythonProcess = exec(`python routes/image_proc.py ${id} ${imagename}`, (error, stdout, stderr) => {
                if (error) {
                  console.error(`실행 중 에러 발생: ${error}`);
                  return;
                }
                console.log(`Python 스크립트 출력: ${stdout}`);
                res.status(200).send(recog_message);
              });
        }
        });
    })
    .catch(function(error) {
        console.log(error.message);
    });

    
});

module.exports = router;
