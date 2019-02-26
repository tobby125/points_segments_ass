#include "points_segments.h"

void naive_points_segments(int s, int p, int ** segments, int * points, int ** array) {
	for(int i = 0; i < p; i++) {
		int count = 0;
		for(int j = 0; j < s; j++) {
			if(segments[j][0] <= points[i] && segments[j][1] >= points[i]) {
				count += 1;
			}
		}
		array[i][0] = points[i];
		array[i][1] = count;
	}
	qsort(array, p, sizeof(array[0]), compare);
}