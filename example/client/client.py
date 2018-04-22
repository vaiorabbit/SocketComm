import socket

if __name__ == "__main__":
    HOST, PORT = "LOCALHOST", 2323
    clientsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    clientsocket.connect((HOST, PORT))
    clientsocket.send(b'hello\n')
    clientsocket.send(b'bye\n')
