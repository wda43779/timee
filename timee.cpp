#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

void timer(char *name);

int main(int argc, char **argv) {
	if (argc == 2) {
		timer(argv[1]);
	} else {
		printf("Usage: timer mission\n");
	}
	return 0;
}

void timer(char *name) {
	
	FILE *f;
	string loc = "./timeedata/";
	loc = loc + name;

	system("mkdir timeedata 2> /dev/null");
	f = fopen (loc.c_str(),"r");
	int record = 0;
	if (f != NULL) {
		fscanf(f, "%d", &record);
	}
	fclose(f);

	time_t start = time(NULL);
	printf("Timing...");
	getc(stdin);
	time_t end = time(NULL);
	record += (end - start);
	printf(
		"You working on %s for about %02d:%02d:%02d.\n",
		name,
		record / 3600,
		(record % 3600) / 60,
		record % 60
		);

	f = fopen(loc.c_str(), "w");
	if (f != NULL) {
		fprintf(f, "%d", record);
	}
	fclose(f);
}
