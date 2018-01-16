#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, const char* argv[]){
	if(argc != 3){
		printf("Usage: <time in HH:MM format> <url in https://www.#URL.com format>\n");
	} else {
		char userTime[4];
		strcpy(userTime, argv[1]);
		char userHour[3], userMin[3];
		memcpy(userHour, userTime, 2);
		memcpy(userMin, &userTime[3], 4);
		userHour[2] = '\0';
		userMin[2] = '\0'; //setting user inputted hour and minutes

		printf("Alarm set for %s:%s \n", userHour, userMin);

		time_t now;
		struct tm *now_tm;
		int min, hour;

		now = time(NULL);
		now_tm = localtime(&now);
		hour = now_tm->tm_hour;
		min  = now_tm->tm_min; //setting current time into hours and mins	
		
		int time_off = abs((atoi(userHour) * 3600) - (hour * 3600)); // hour difference calculation
		time_off += abs((atoi(userMin) * 60) - (min * 60)); // min difference calculation

		sleep(time_off); // sleep until alarm time reached		

		char* command = malloc(strlen("xdg-open ") + strlen(argv[2]) + 1);
		strcpy(command, "xdg-open ");
		strcat(command, argv[2]);
		
		system(command);
	}
}
