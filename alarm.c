#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc, const char* argv[]){
	if(argc != 3){
		printf("Usage: <time HH:MM> <url>");
	} else {
		char userTime[4];
		strcpy(userTime, argv[1]);
		char userHour[3], userMin[3];
		memcpy(userHour, userTime, 2);
		memcpy(userMin, &userTime[3], 4);
		userHour[2] = '\0';
		userMin[2] = '\0';
		printf("Alarm set for %s:%s \n", userHour, userMin);

		time_t now;
		struct tm *now_tm;
		int min, hour;

		now = time(NULL);
		now_tm = localtime(&now);
		hour = now_tm->tm_hour;
		min  = now_tm->tm_min;		

		printf("Current time is: %d:%d \n", hour, min);
	}
} 
