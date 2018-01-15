#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, const char* argv[]){
	if(argc != 3){
		printf("Usage: <time HH:MM> <url>\n");
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
		
		int time_off = abs((atoi(userHour) * 3600) - (hour * 3600)); // hour difference calculation
		time_off += abs((atoi(userMin) * 60) - (min * 60)); // min difference calculation

		sleep(time_off);		

		char* command = malloc(strlen("xdg-open ") + strlen(argv[2]) + 1);
		strcpy(command, "xdg-open ");
		strcat(command, argv[2]);
		
		system(command);
	}
}
