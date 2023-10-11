var express = require('express');
var router = express.Router();
var qs = require('querystring');
const fs = require('fs');
const { exec } = require('child_process');
const path = require('path');

router.post('/', async function(req, res, next) {
  const queryData = req.body;
  console.log('Received post data:', queryData);
  const jsonFilePath = './routes/query.json';

  fs.readFile(jsonFilePath, 'utf8', (err, data) => {
    if (err) {
      console.error('파일을 읽는 도중 오류가 발생했습니다.');
      return res.status(500).json({ error: '파일 읽기 오류' });
    }

    try {
      const jsonData = JSON.parse(data);
      const lastItem = jsonData[jsonData.length - 1];
      const lastItemId = lastItem ? lastItem.id : 0;
      console.log('가장 마지막 항목의 id 값:', lastItemId);
      const newItem = {
        "id": lastItemId + 1,
        "floor": queryData.floor,
        "name": queryData.name,
        "date": queryData.date,
        "time": queryData.time
      };
      jsonData.push(newItem);
      fs.writeFile(jsonFilePath, JSON.stringify(jsonData), 'utf8', (writeErr) => {
        if (writeErr) {
          console.error('파일에 데이터를 쓰는 도중 오류가 발생했습니다.');
          return res.status(500).json({ error: '파일 쓰기 오류' });
        }
        console.log('새로운 항목이 JSON 파일에 추가되었습니다.');
        let py_arg1=newItem.floor
        let py_arg2=newItem.id
        const pythonProcess = exec(`python routes/socket_client.py ${py_arg1} ${py_arg2}`, (error, stdout, stderr) => {
          if (error) {
            console.error(`실행 중 에러 발생: ${error}`);
            return;
          }
          console.log(`Python 스크립트 출력: ${stdout}`);
        });
        res.redirect("http://glassier.com:3000/gaurd");
      });
    } catch (jsonError) {
      console.error('JSON 데이터를 파싱하는 도중 오류가 발생했습니다.');
      return res.status(400).json({ error: 'JSON 파싱 오류' });
    }
  });
});


module.exports = router;
