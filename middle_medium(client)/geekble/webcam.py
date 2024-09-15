import cv2

# 웹캠을 엽니다 (일반적으로 웹캠 인덱스는 0입니다).
cap = cv2.VideoCapture(0)

# 웹캠이 정상적으로 열렸는지 확인합니다.
if not cap.isOpened():
    print("웹캠을 열 수 없습니다.")
    exit()

print("사진 촬영 시작")
ret, frame = cap.read()
print("사진 촬영 종료")
if ret:
    # 촬영한 프레임을 파일로 저장합니다.
    cv2.imwrite("webcam_photo.jpg", frame)
    print("사진을 저장했습니다.")
else:
    print("사진을 촬영할 수 없습니다.")

# 웹캠과 관련된 리소스를 해제합니다.
cap.release()
cv2.destroyAllWindows()