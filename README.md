# mosquitto_mqtt

The simplest publisher/subscriber of mosquitto mqtt on planet earth. Publisher Subscriber examples of Mosquitto MQTT in C

# Prerequisites:
1. mosquitto source code for header files. Can be obtained @ https://github.com/eclipse/mosquitto 
2. mosquitto shared library. "mosquitto.dll" which can be obtained from your installation folder when you install mosquitto on your system. Installer
can be obtained @ https://mosquitto.org/download/   

# Compilation:
Current compilation is done for Windows in MinGW 4.8.1
 
 Publisher
 
	gcc -c mosq_pub.c -I path to\mosquitto-master\mosquitto-master\lib

	gcc -o mosq_pub.exe mosq_pub.o -l mosquitto -L .
	
	Note : mosquitto.dll should be present in current folder 
 
 Subscriber
	
	gcc -c mosq_sub.c -I path to\mosquitto-master\mosquitto-master\lib

	gcc -o mosq_sub.exe mosq_sub.o -l mosquitto -L .
	
	Note : mosquitto.dll should be present in current folder 
	
# Execution:
1.Start the mosquitto broker mosquitto.exe, which is present in installation folder of mosquitto.

2.Start the mosq_sub.exe

3.Start the mosq_pub.exe

message will be received in subscriber window. Can use this piece of code in your project to integrate mosquitto. 

# Additional Info (not related to this project):

The github repository of mosquitto also contains elegant & standard C examples of mosquitto mqtt publisher/subscriber. 


Following are the commands for building mosquitto publisher/subscriber example @ https://github.com/eclipse/mosquitto/tree/master/client 

pub_client.c

gcc -c pub_client.c -I path to\mosquitto-master\mosquitto-master\lib -I path to\mosquitto-master\mosquitto-master

gcc -c client_shared.c -I path to\mosquitto-master\mosquitto-master -I path to\mosquitto-master\mosquitto-master\lib

gcc -c client_props.c -I path to\mosquitto-master\mosquitto-master -I path to\mosquitto-master\mosquitto-master\lib

gcc -c pub_shared.c -I path to\mosquitto-master\mosquitto-master -I path to\mosquitto-master\mosquitto-master\lib

gcc -o mosquitto_pub.exe pub_client.o client_shared.o client_props.o pub_shared.o -l mosquitto -L path to\mosquitto 


sub_client.c

gcc -c sub_client.c -I path to\mosquitto-master\mosquitto-master -I path to\mosquitto-master\mosquitto-master\lib

gcc -c sub_client_output.c -I path to\mosquitto-master\mosquitto-master -I path to\mosquitto-master\mosquitto-master\lib

gcc -o mosquitto_sub.exe sub_client.o client_shared.o client_props.o sub_client_output.o -l mosquitto -L path to\mosquitto
