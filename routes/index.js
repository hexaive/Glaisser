var express = require('express');
var router = express.Router();
var url = require('url');
const fs = require('fs'); // 파일 시스템 모듈
const ejs = require('ejs'); // EJS 모듈
const path = require('path');
var qs = require('querystring');
const { json } = require('body-parser');
const { table } = require('console');
const select_data={
  "id": null,
  "floor": null,
  "name": null,
  "date": null,
  "time": null

}
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
/* GET home page. */
router.get('/', function(req, res, next) {
  table_data = JSON.parse(fs.readFileSync('./routes/query.json', 'utf8'));
  console.log(table_data)
    // JSON 파일 경로
  const filePath = './routes/inquire_data.json';

  // JSON 파일 읽기
  fs.readFile(filePath, 'utf8', (err, inquire_ok_data) => {
    if (err) {
      console.error('파일을 읽을 수 없습니다.', err);
      return;
    }
    try {
      const inquire_data = JSON.parse(inquire_ok_data);
      if (inquire_data.id=="0"){
        console.log("**********************index.js - zero rendering**********************")
        res.render("index", {table_data,select_data,fileArray});
        console.log("*                                                                   *")
        console.log("********************index.js - zero rendering-end********************")
      }
      else{
        const select_data = table_data.find(item => item.id === parseInt(inquire_data.id));
        // 조회할 폴더 경로
        const folderPath = "./public/data/id_"+inquire_data.id;
        const fileArray = listFilesInDirectory(folderPath);

        // 결과 출력  
        console.log("**************************index.js - result*************************")
        console.log(inquire_data);
        console.log(select_data);
        fileArray.forEach((file) => {
          console.log(file);
        });
        console.log("*********************index.js - print result-end********************")
        console.log("************************index.js - rendering************************")
        res.render("index", {table_data,select_data,fileArray});
        console.log("**********************index.js - rendering-end**********************")
      }
    } catch (parseError) {
      console.error('JSON 데이터를 파싱하는 동안 오류가 발생했습니다.', parseError);
    }
    console.log("*************************index.js - reset 0*************************")
    // 0초기화
    fs.readFile('./routes/inquire_data.json', 'utf8', (err, data) => {
      if (err) {
          console.error('파일을 읽을 수 없습니다:', err);
          return;
      }
      // 데이터를 JSON 객체로 파싱
      const zero_inquire_data = JSON.parse(data);
      // JSON 데이터 수정
      zero_inquire_data.id = "0";
      // 수정된 JSON 데이터를 문자열로 변환
      const updatedJsonString = JSON.stringify(zero_inquire_data, null, 4);
      // 파일에 쓰기
      fs.writeFile('./routes/inquire_data.json', updatedJsonString, 'utf8', (err) => {
        if (err) {
          console.error('파일을 쓸 수 없습니다:', err);
        } else {
          console.log('파일이 성공적으로 수정되었습니다.');
          console.log("***********************index.js - reset 0-end***********************")
        }
      });
    });
  });
});
module.exports = router;
