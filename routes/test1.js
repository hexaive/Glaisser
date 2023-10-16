const fs = require('fs');

// 원본 파일 경로
const sourceFilePath = '../public/data/new/1022.jpg';

// 대상 파일 경로
const destinationFilePath = '../public/data/id_56/1022.JPG';

// 파일 복사 함수
function copyFile(source, destination) {
  fs.copyFile(source, destination, (err) => {
    if (err) {
      console.error(`파일 복사 중 오류 발생: ${err}`);
    } else {
      console.log('파일이 성공적으로 복사되었습니다.');
    }
  });
}

// 파일 복사 실행
copyFile(sourceFilePath, destinationFilePath);
