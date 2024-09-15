const fetch = require('node-fetch');
// GET 요청을 보낼 URL 설정
const url = 'po-glos.com:3000/4/2011';

// fetch를 사용하여 GET 요청 보내기
fetch(url)
  .then(response => {
    if (!response.ok) {
      throw new Error(`Network response was not ok: ${response.status}`);
    }
    return response.json(); // JSON 응답을 파싱
  })
  .then(data => {
    console.log(data); // 응답 데이터 처리
  })
  .catch(error => {
    console.error('Fetch 오류:', error);
  });
