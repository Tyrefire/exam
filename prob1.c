#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>		/* For exit */

struct time
{
	int hour;
	int minutes;
	int seconds;
};
/* Function Prototypes */
struct time ElapseTime(struct time a, struct time b);

/* Main Program */
int main(int argc, char* argv[])
{
	struct time elapsed_time (struct time t1, struct time t2);
	struct time t1 = { 3, 45, 15 }, t2 = { 9, 44, 03 },
				t3 = {22, 50, 59 }, t4 = { 7, 30, 0 };
	struct time result;

	result = ElapseTime (t1, t2);
	printf ("Time between %.2i:%.2i:%.2i and %.2i:%.2i:%.2i "
			"is %.2i:%.2i:%.2i\n",
			t1.hour, t1.minutes, t1.seconds, t2.hour, t2.minutes,
			t2.seconds, result.hour, result.minutes, result.seconds);

	result = ElapseTime (t2, t1);
	printf ("Time between %.2i:%.2i:%.2i and %.2i:%.2i:%.2i "
			"is %.2i:%.2i:%.2i\n",
			t2.hour, t2.minutes, t2.seconds, t1.hour, t1.minutes,
			t1.seconds, result.hour, result.minutes, result.seconds);

	result = ElapseTime (t3, t4);
	printf ("Time between %.2i:%.2i:%.2i and %.2i:%.2i:%.2i "
			"is %.2i:%.2i:%.2i\n",
			t3.hour, t3.minutes, t3.seconds, t4.hour, t4.minutes,
			t4.seconds, result.hour, result.minutes, result.seconds);

	return 0;
}


/* Function Definitions */
struct time ElapseTime(struct time a, struct time b)
{
	struct time value = {0, 0, 0};
	int i;
	i = a.seconds;
	while(i != b.seconds)
	{
		if(b.seconds == 0)
		{
			b.seconds = 60;
		}
		if(i > 60)
		{
			i = 1;
			a.minutes += 1;
		}
		(value.seconds)++;
		i++;
	};
	i = a.minutes;
	while(i != b.minutes)
	{
		if(i > 60)
		{
			i = 1;
			a.hour += 1;
		}
		(value.minutes)++;
		i++;
	};
	i = a.hour;
	while(i != b.hour)
	{
		if(i > 24)
		{
			i = 1;
		}
		(value.hour)++;
		i++;
	};

	return value;
}

// calculate elapsed time (assume t2 is later than t1)
