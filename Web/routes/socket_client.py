## CLIENT ##

import socket
from _thread import *
import sys

HOST = '172.31.4.68' ## server에 출력되는 ip를 입력해주세요 ##
PORT = 9999

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((HOST, PORT))

def recv_data(client_socket):
    while True:
        data = client_socket.recv(1024)
        print("recive : ", repr(data.decode()))

start_new_thread(recv_data, (client_socket,))
print('>> Connect Server')
message="server :{}:{}".format(sys.argv[1],sys.argv[2])
client_socket.send(message.encode())

client_socket.close()