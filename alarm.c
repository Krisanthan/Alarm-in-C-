#include <stdio.h>
#include <time.h>

int main(int argc, const char* argv[]){
	if(argc != 3){
		printf("Usage: <time> <url>");
	} else {
		time_t now;
		struct tm *now_tm;
		int min, hour;

		now = time(NULL);
		now_tm = localtime(&now);
		hour = now_tm->tm_hour;
		min  = now_tm->tm_min;		

		printf("time is: %d:%d \n", hour, min);
	}
} 
