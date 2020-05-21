#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int InRectangle( float pt[2], float rect[4] ){
	float point_x = pt[0];
	float point_y = pt[1];
	float compare_min_x = MIN(rect[0],rect[2]);
	float compare_max_x = MAX(rect[0],rect[2]);
	float compare_min_y = MIN(rect[1],rect[3]);
	float compare_max_y = MAX(rect[1],rect[3]);

	if((point_x >= compare_min_x) && (point_x <= compare_max_x )){
		if((point_y <= compare_max_y) && (point_y >= compare_min_y)){
			return 1;
		}
		else{
			return 0;		
		}
	}
	else{
		return 0;
	}
	
}
