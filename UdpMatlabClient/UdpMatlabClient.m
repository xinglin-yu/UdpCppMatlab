clc
clear

ip='192.168.1.102'; 
port=8085;

data_all=[];%用于存储所有的数据
u = udp(ip, port, 'Timeout', 60,'InputBufferSize',10240);%连接这个ip和这个端口的UDP服务器，60秒超时，缓冲大小1024
fopen(u);
fwrite(u,-15.6,'float');    %发送一段数据给udp服务器。服务器好知道matlab的ip和端口

t=1;
recLen=1;
while(1)
    %接收
    receive = fread(u,recLen,'float')
    %发送
    fwrite(u,-125.622,'float');
    t=t+1
end

fclose(u);
delete(u);
