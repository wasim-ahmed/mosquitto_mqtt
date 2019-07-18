//sample mosquitto subscriber

#include <stdio.h>
#include <mosquitto.h>

void my_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
	printf("%s\n",message->payload);
}

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
	
	mosquitto_message_callback_set(mosq, my_message_callback);
	
	const char* topic = "test";
	
	rc = mosquitto_subscribe(mosq, NULL, topic, 0);
	
	if(rc == MOSQ_ERR_SUCCESS){
		printf("Subscribed to topic %s\n",topic);
	}
	else if(rc == MOSQ_ERR_INVAL){
		printf(" the input parameters were invalid\n");
	}
	else if(rc == MOSQ_ERR_NOMEM){
		printf("an out of memory condition occurred\n");
	}
	else if(rc == MOSQ_ERR_NO_CONN){
		printf("the client isn’t connected to a broker\n");
	}
	else if(rc == MOSQ_ERR_MALFORMED_UTF8){
		printf("the topic is not valid UTF-8\n");
	}
	else{
		printf("valar morghulis\n");
	}
	
	
	rc = mosquitto_loop_forever(mosq, -1, 1);
	
	if(rc == MOSQ_ERR_SUCCESS){
		printf("Waiting for messages\n");
	}
	else if(rc == MOSQ_ERR_INVAL){
		printf("the input parameters were invalid\n");
	}
	else if(rc == MOSQ_ERR_NOMEM){
		printf("an out of memory condition occurred\n");
	}
	else if(rc == MOSQ_ERR_NO_CONN){
		printf("the client isn’t connected to a broker\n");
	}
	else if(rc == MOSQ_ERR_CONN_LOST){
		printf("the connection to the broker was lost\n");
	}
	else if(rc == MOSQ_ERR_PROTOCOL){
		printf("there is a protocol error communicating with the broker\n");
	}
	else if(rc == MOSQ_ERR_ERRNO){
		printf("a system call returned an error\n");
	}
	else{
		printf("valar morghulis");
	}
	
	mosquitto_destroy(mosq);
	mosquitto_lib_cleanup();
	
	return 0;
}