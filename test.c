#include "points_segments.h"

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);	
	}
	printf("\n");
}

void print_array_2D(int **arr, int rows, int cols){
	for (int i=0; i<rows; i++){
		printf("[");
		for (int j=0; j<cols; j++)
			printf("%d ",arr[i][j]);
		printf("] ");
	}
	printf("\n");
}

int main() {	
	const char * files[] = {"input1.txt", "input2.txt", "input3.txt"};   

	for (int f=0; f < 3; f++){
		FILE *pfile = fopen(files[f], "r");
		if(pfile == NULL)  {
			printf("Error opening file %s\n", files[f]);
			return 1;
		}
		
		int s, p;
		while(fscanf(pfile, "%d %d", &s, &p)!=EOF){		
		
			//allocate 2D array to hold s segments
			int ** segments = malloc(s*sizeof(int *));
			for (int i=0; i < s; i++){
				segments[i] = malloc(2*sizeof(int));
			}
		
			//scan all segment lines and populate the segments
			for (int i=0; i < s; i++){
				fscanf(pfile, "%d %d", &segments[i][0], &segments[i][1]);
			}		
		
			//allocate a single array to hold p points
			int * points = malloc(p*sizeof(int));
		
			//scan all point coordinates into points array
			for (int i=0; i < p; i++){
				fscanf(pfile, "%d", &points[i]);
			}
			
			int ** array1 = malloc(p*sizeof(int *));
			for (int i=0; i < p; i++){
				array1[i] = malloc(2*sizeof(int));
			}
			int ** array2 = malloc(p*sizeof(int *));
			for (int i=0; i < p; i++){
				array2[i] = malloc(2*sizeof(int));
			}
			
			naive_points_segments(s, p, segments, points, array1);
			good_points_segments(s, p, segments, points, array2);

			for(int i = 0; i < p; i++) {
				if(array1[i][1] != array2[i][1]) {
					print_array_2D(array1, p, 2);
					print_array_2D(array2, p, 2);
					printf("Doesn't match\n");
				}
			}
		
			free(segments);
			free(points);
			free(array1);
			free(array2);
		}
		fclose(pfile);
	}
	return 0;
}
