from socket import *

serverName = 'hostname'
serverPort = 12000
clinetSocket = socket(AF_INET,SOCK_DGRAM)
message = raw_input('Input lowercase sentence: ')
clinetSocket.sendto(message.encode(),(serverName, serverPort))
modifiedMessage, serverAddress = clinetSocket.recvfrom(2048)
print(modifiedMessage.decode())
clinetSocket.close()