#include "points_segments.h"

int compare(const void *pa, const void *pb) {
    const int *a = *(const int **)pa;
    const int *b = *(const int **)pb;
	if (a[0] != b[0]) {
		return a[0] - b[0];
	}
	return a[1] - b[1];
}

void good_points_segments(int s, int p, int ** segments, int * points, int ** array) {
	int ** point_types = malloc((s*2 + p)*sizeof(int *));
			for (int i = 0; i < s*2 + p; i++){
				point_types[i] = malloc(2*sizeof(int));
			}
	for(int i = 0; i < p; i++) {
		point_types[i][0] = points[i];
		point_types[i][1] = 1;
	}
	for(int i = 0; i < s; i++) {
		point_types[i*2 + p][0] = segments[i][0];
		point_types[i*2 + p][1] = 0;
		point_types[i*2 + p + 1][0] = segments[i][1];
		point_types[i*2 + p + 1][1] = 2;
	}
	qsort(point_types, s*2 + p, sizeof(point_types[0]), compare);
	int n = 0;
	int a = 0;
	for(int i = 0; i < s*2 + p; i++) {
		if(point_types[i][1] == 0) {
			n++;
		}
		if(point_types[i][1] == 2) {
			n--;
		}
		if(point_types[i][1] == 1) {
			array[a][0] = point_types[i][0];
			array[a][1] = n;
			a++;
		}
	}
	free(point_types);
}