var express = require('express');
var router = express.Router();
const ejs = require('ejs'); // EJS 모듈
var qs = require('querystring');
const fs = require('fs');
const bodyParser = require('body-parser');
router.use(bodyParser.urlencoded({ extended: false }));
router.post('/', function(req, res, next) {
  console.log("*******************query_process.js - post recieve******************")
  const queryData = req.body;
  console.log('Received post data:', queryData);
  console.log("***query_process.js - start write file(inquire_data.json) & redirection***")
  fs.readFile('./routes/inquire_data.json', 'utf8', (err, data) => {
    if (err) {
        console.error('파일을 읽을 수 없습니다:', err);
        return;
    }

    // 데이터를 JSON 객체로 파싱
    const inquire_data = JSON.parse(data);

    // JSON 데이터 수정
    inquire_data.id = queryData.query_select;

    // 수정된 JSON 데이터를 문자열로 변환
    const updatedJsonString = JSON.stringify(inquire_data, null, 4);

    // 파일에 쓰기
    fs.writeFile('./routes/inquire_data.json', updatedJsonString, 'utf8', (err) => {
        if (err) {
            console.error('파일을 쓸 수 없습니다:', err);
        } else {
            console.log('파일이 성공적으로 수정되었습니다.');
            res.redirect("http://po-glos.com:3000/#inquire");
        }
    });
    console.log("***query_process.js end  write file(inquire_data.json) & redirection***")
});
});
module.exports = router;