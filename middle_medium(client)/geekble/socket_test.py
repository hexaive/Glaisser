import socket
import cv2
from _thread import *
import os

HOST = '13.125.175.70' ## server에 출력되는 ip를 입력해주세요 ##
PORT = 9999
cap=""
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((HOST, PORT))
cap = cv2.VideoCapture(0)
def recv_data(client_socket):
    global cap
    while True:
        data = client_socket.recv(1024)
        data=data.decode()
        print("recive : ", data)
        data=data.split(":")
        if (data[0]=="촬영"):
            print("촬영")
            ret, frame = cap.read()
            if ret:
                # 촬영한 프레임을 파일로 저장합니다.
                cv2.imwrite("data2/{}.jpg".format(data[1]), frame)
                print("사진을 저장했습니다.")
                message="촬영완료"
                client_socket.send(message.encode())
            else:
                print("사진을 촬영할 수 없습니다.")
            # 웹캠과 관련된 리소스를 해제합니다.
            cap.release()
            cv2.destroyAllWindows()
            quit()

start_new_thread(recv_data, (client_socket,))
print('>> Connect Server')

while True:
    message = input()
    if message == 'quit':
        close_data = message
        break

    client_socket.send(message.encode())

client_socket.close()

4
