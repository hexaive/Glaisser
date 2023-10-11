import cv2
import sys
import json
#이미지 파일 경로
n_id=sys.argv[1]
imagename=sys.argv[2]
file_path = 'data.json'  # JSON 파일의 경로를 설정합니다. 필요에 따라 경로를 조정하세요.

try:
    with open(file_path, 'r') as json_file:
        data = json.load(json_file)
        print('JSON 데이터:', data)
except FileNotFoundError:
    print(f'파일을 찾을 수 없습니다: {file_path}')
except json.JSONDecodeError as e:
    print(f'JSON 파일 파싱 오류: {e}')
except Exception as e:
    print(f'오류 발생: {e}')

image_path = 'public/data/id_{}/{}.JPG'.format(n_id,imagename)
# 원하는 크기로 이미지를 조정할 너비와 높이 설정
desired_width = int(data.get('image').get('width'))
desired_height = int(data.get('image').get('height'))
# 이미지 불러오기
image = cv2.imread(image_path)
# 이미지 크기 조정
resized_image = cv2.resize(image, (desired_width, desired_height))
# 분류 결과와 좌표값 (예: [class, x, y, width, height]) 설정
# "predictions" 항목에서 결과 배열 "results" 생성
predictions = data.get("predictions", [])

results = []

for prediction in predictions:
    class_name = "person"
    x = prediction.get("x", 0)
    y = prediction.get("y", 0)
    width = prediction.get("width", 0)
    height = prediction.get("height", 0)
    
    # 결과 배열에 추가
    results.append([class_name, x, y, width, height])

# 결과 출력
for result in results:
    print(result)
# 바운딩 박스 그리기
for result in results:
    class_name, x, y, width, height = result
    x1, y1 = int(x - width / 2), int(y - height / 2)  # 바운딩 박스 좌측 상단 꼭짓점 계산
    x2, y2 = int(x + width / 2), int(y + height / 2)  # 바운딩 박스 우측 하단 꼭짓점 계산
    color = (0, 255, 0)  # 바운딩 박스 색상 (여기서는 녹색)
    thickness = 2  # 바운딩 박스 두께

    # 바운딩 박스 그리기
    cv2.rectangle(resized_image, (x1, y1), (x2, y2), color, thickness)

    # 클래스 이름 표시
    text = f"{class_name}"
    cv2.putText(resized_image, text, (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, thickness)

# 조정된 크기의 이미지 저장
output_image_path = 'public/data/id_{}/{}.JPG'.format(n_id,imagename)
cv2.imwrite(output_image_path, resized_image)

