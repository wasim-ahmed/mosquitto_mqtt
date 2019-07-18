//sample mosquitto publisher

#include <stdio.h>
#include <mosquitto.h>
#include <string.h>

int main()
{
	int rc;
	struct mosquitto *mosq = NULL;

	mosquitto_lib_init();
	
	mosq = mosquitto_new(NULL,true,NULL);
	
	const char* broker_address = "localhost";
	int connection_port = 1883;
	int keep_alive = 60;
	
	rc = mosquitto_connect(mosq,broker_address,connection_port,keep_alive);
	
	if(rc == MOSQ_ERR_SUCCESS){
		printf("Connected to Broker\n");
	}
	else if(rc == MOSQ_ERR_INVAL){
		printf("the input parameters were invalid\n");
	}
	else if(rc == MOSQ_ERR_ERRNO){
		printf("a system call returned an error\n");
	}
	else{
		printf("valar morghulis\n");
	}
	
	const char* topic = "test";
	const char* msg = "my publish message"; 
	int msglen = strlen(msg);
	
	rc = mosquitto_publish(mosq,NULL,topic,msglen,msg,0,false);
	
	if(rc == MOSQ_ERR_SUCCESS){
		printf("Message successfully published\n");
	}
	else if(rc == MOSQ_ERR_INVAL){
		printf("the input parameters were invalid.\n");
	}
	else if(rc == MOSQ_ERR_NOMEM){
		printf("an out of memory condition occurred.\n");
	}
	else if(rc == MOSQ_ERR_NO_CONN){
		printf("the client isn’t connected to a broker.\n");
	}
	else if(rc == MOSQ_ERR_PROTOCOL){
		printf("there is a protocol error communicating with the broker.\n");
	}
	else if(rc == MOSQ_ERR_PAYLOAD_SIZE){
		printf("payloadlen is too large.\n");
	}
	else if(rc == MOSQ_ERR_MALFORMED_UTF8){
		printf("the topic is not valid UTF-8\n");
	}
	else{
		printf("valar morghulis\n");
	}

	rc = mosquitto_disconnect(mosq);
	if(rc == MOSQ_ERR_SUCCESS){
		printf("Disconnected from Broker\n");
	}
	else if(rc == MOSQ_ERR_INVAL){
		printf("the input parameters were invalid\n");
	}
	else if(rc == MOSQ_ERR_NO_CONN){
		printf("the client isn’t connected to a broker\n");
	}
	else{
		printf("valar morghulis\n");
	}
	
	
	mosquitto_destroy(mosq);
	mosquitto_lib_cleanup();

	return 0;
}