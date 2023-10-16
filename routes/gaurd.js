var express = require('express');
var router = express.Router();
const fs = require("fs");
const path = require('path');
const { json } = require('body-parser');

const jsonFilePath = './routes/query.json';
const ImageDisplay=['imageDisplay1', 'imageDisplay2', 'imageDisplay3', 'imageDisplay4','imageDisplay5', 'imageDisplay6', 'imageDisplay7', 'imageDisplay8','imageDisplay9', 'imageDisplay10', 'imageDisplay11', 'imageDisplay12'];

const fileArray = [];

function listFilesInDirectory(directory) {
  const fileArray = [];

  const files = fs.readdirSync(directory);
  for (const file of files) {
      const filePath = path.join(directory, file);
      const stat = fs.statSync(filePath);
      if (stat.isFile()) {
          let f_path=filePath.replace("public/", '');
          fileArray.push(f_path);
      }
  }

  return fileArray;
}
/* GET users listing. */
router.get('/', function(req, res, next) {
  fs.readFile(jsonFilePath, 'utf8', (err, data) => {
    if (err) {
      console.error('파일을 읽는 도중 오류가 발생했습니다.');
      return res.status(500).json({ error: '파일 읽기 오류' });
    }
    try {
      const jsonData = JSON.parse(data);
      const select_data = jsonData[jsonData.length - 1];
      const folderPath = `./public/data/new`;
      const fileArray = listFilesInDirectory(folderPath);
      const folderName = `./public/data/id_${select_data.id}`; // 새로 만들 폴더의 이름

      // fs.mkdir() 함수를 사용하여 폴더를 만듭니다.
      fs.mkdir(folderName, (err) => {
        if (err) {
          // 폴더를 만들지 못한 경우 오류 처리
          console.error('폴더를 만들 수 없습니다.', err);
        } else {
          // 폴더가 성공적으로 만들어진 경우
          console.log('폴더가 성공적으로 만들어졌습니다.');
          // 복사할 파일 경로와 대상 파일 경로를 배열로 정의합니다.
          const filePairs = [
            { source: './public/data/new/1011.jpg', destination: `./public/data/id_${select_data.id}/1011.JPG` },
            { source: './public/data/new/1012.jpg', destination: `./public/data/id_${select_data.id}/1012.JPG` },
            { source: './public/data/new/1021.jpg', destination: `./public/data/id_${select_data.id}/1021.JPG` },
            { source: './public/data/new/1022.jpg', destination: `./public/data/id_${select_data.id}/1022.JPG` },
            { source: './public/data/new/2011.jpg', destination: `./public/data/id_${select_data.id}/2011.JPG` },
            { source: './public/data/new/2012.jpg', destination: `./public/data/id_${select_data.id}/2012.JPG` },
            { source: './public/data/new/2021.jpg', destination: `./public/data/id_${select_data.id}/2021.JPG` },
            { source: './public/data/new/2022.jpg', destination: `./public/data/id_${select_data.id}/2022.JPG` },
            { source: './public/data/new/3011.jpg', destination: `./public/data/id_${select_data.id}/3011.JPG` },
            { source: './public/data/new/3012.jpg', destination: `./public/data/id_${select_data.id}/3012.JPG` },
            { source: './public/data/new/3021.jpg', destination: `./public/data/id_${select_data.id}/3021.JPG` },
            { source: './public/data/new/3022.jpg', destination: `./public/data/id_${select_data.id}/3022.JPG` },
          ];

          // 각 파일을 복사하고 붙여넣기를 비동기적으로 수행합니다.
          filePairs.forEach((filePair) => {
            const { source, destination } = filePair;

            fs.copyFile(source, destination, (err) => {
              if (err) {
                console.error(`파일 복사 중 오류 발생 (${source} -> ${destination}):`, err);
              } else {
                console.log(`파일 복사 완료 (${source} -> ${destination})`);
                // 필요에 따라 다른 작업을 수행할 수 있습니다.
              }
            });
          });
        }
      });
      res.render('gaurd', {select_data,fileArray,ImageDisplay});
    } catch (jsonError) {
      console.error('JSON 데이터를 파싱하는 도중 오류가 발생했습니다.');
      return res.status(400).json({ error: 'JSON 파싱 오류' });
    }
  });
});

module.exports = router;
