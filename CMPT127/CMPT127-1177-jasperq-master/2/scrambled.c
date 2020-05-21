int scrambled(unsigned int a[], unsigned int b[], unsigned int len){
/*	int match = 0;	
	int a_duplicates = 0;
	int b_duplicates = 0;
	for(int x = 0; x < len; x++){
		a_duplicates = 1;
		b_duplicates = 0;
///////////////////////////////////////////////////////////
		for(int n = 0; n < len; n++){
			if(a[x] == b[n]){
				match = 1;
				b_duplicates++;
			}
			if(a[x] == a[n]){
				if(x != n){
					a_duplicates++;
				}
			}
		}
		if(a_duplicates != b_duplicates){
			return 0;
		}
		if (match == 0){
			return 0;
		}
		match = 0;
///////////////////////////////////////////////////////////
		for(int m = 0; m < len; m++){
			if(b[x] == a[m]){
				match = 1;
			}
		}
		if(match == 0){
			return 0;
		}
		match = 0;
	}
	return 1;
*/
	int sum_a = 0;
	int sum_b = 0;
	int product_a = 1;
	int product_b = 1;
	for (int x = 0; x < len; x++){
		sum_a += a[x];
		sum_b += b[x];
		product_a *= a[x];
		product_b *= b[x];
	}
	if ((sum_a == sum_b) && (product_a == product_b)){
		return 1;
	}

	return 0;
}
