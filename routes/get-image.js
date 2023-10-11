var express = require('express');
var router = express.Router();
const axios = require("axios");
const fs = require("fs");
const path = require('path');
const { json } = require('body-parser');

const jsonFilePath = './routes/query.json';

const fileArray = [];
function listFilesInDirectory(directory) {
  const fileArray = [];
  const files = fs.readdirSync(directory);
  for (const file of files) {
      const filePath = path.join(directory, file);
      const stat = fs.statSync(filePath);
      if (stat.isFile()) {
          fileArray.push(filePath);
      }
  }

  return fileArray;
}

/* GET users listing. */
router.get('/:index', function(req, res, next) {
  const index = parseInt(req.params.index);

  fs.readFile(jsonFilePath, 'utf8', (err, data) => {
    if (err) {
      console.error('파일을 읽는 도중 오류가 발생했습니다.');
      return res.status(500).json({ error: '파일 읽기 오류' });
    }
    try {
      const jsonData = JSON.parse(data);
      const select_data = jsonData[jsonData.length - 1];
      const folderPath = `./public/data/id_${select_data.id}`;
      const fileArray = listFilesInDirectory(folderPath);
      console.log(fileArray)
      if (index >= 0) {
        // 이미지 파일을 읽어서 응답으로 보내줍니다.
        fs.readFile(fileArray[index], (err, data) => {
          if (err) {
            console.error('이미지 파일을 읽는 중 오류 발생:', err);
            res.status(500).send('이미지를 불러올 수 없습니다.');
            } else {
                res.setHeader('Content-Type', 'image/jpeg');
                res.send(data);
            }
        });
    } else {
        res.status(404).send('이미지를 찾을 수 없습니다.');
    }
    } catch (jsonError) {
      console.error('JSON 데이터를 파싱하는 도중 오류가 발생했습니다.');
      return res.status(400).json({ error: 'JSON 파싱 오류' });
    }
  });
});

module.exports = router;

